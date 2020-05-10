#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include "Rabbit.h"
#include "Knight.h"
#include <algorithm>
#include <cctype>
#include <locale>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <iostream>
#include "Log.h"



/******************************/
//// 75-MVP attempt/////////////
/******************************/

using namespace std;

/**
 * Messages for logging info
 */
struct msg {
    char str[64];
};

/**
 * Messages for attacking info
 */
struct attackMsg{
    int from;   //Who sent this 0 == Rabbit, 1 == first knight, etc.
    int type;   //0 == bite, 1 ==quick, 2 == throat, 3 == first knight
    int damage; //How much damage caused
};


//Reference
//https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
}
// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}
// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}
// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}
// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}
// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
    trim(s);
    return s;
}



void sigtermHandler(int signum) {
    fflush(stdout);
    exit(143);
}

/**
 * Checks for valid input orders. Makes sure the user entered valid info
 * @param argc -  number of args
 * @param argv - array of the args
 * @param knightFileName - name of the knight file entered
 * @param logFileName - name of log file entered
 * @param logPipe - log pipe to send messages to log process
 * @param logMessageWrite - message to send to log file
 * @param rabbitFileName - name of rabbit
 */
void
checkingValidInputOrders(int argc, char *const *argv, string &knightFileName, string &logFileName, const int *logPipe,
                         string &logMessageWrite, string &rabbitFileName) {

    msg msg;

    if (argc == 3) {
        //Only Rabbit File entered
        if (strcmp(argv[1], "-r") == 0) {
            string s(argv[2]);
            rabbitFileName = argv[2];
            knightFileName = "None";
            logFileName = "None";


            //           logFileName = "DEFAULT KNIGHT will be used";

            memset(msg.str,0,64);
            strcpy(msg.str, logFileName.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));

            memset(msg.str,0,64);
            strcpy(msg.str, "DEFAULT KNIGHT will be used");
            write(logPipe[1], (char *) &msg, sizeof(msg));


        } else {


            memset(msg.str,0,64);
            strcpy(msg.str, "None");
            write(logPipe[1], (char *) &msg, sizeof(msg));


            logMessageWrite = "3 argument entered. -r not found";

            memset(msg.str,0,64);
            strcpy(msg.str,logMessageWrite.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));


            memset(msg.str,0,64);
            strcpy(msg.str, "END");
            write(logPipe[1], (char *) &msg, sizeof(msg));



        }

    }


    else if (argc == 5) {

        if (strcmp(argv[1], "-r") == 0 && strcmp(argv[3], "-k") == 0) {
            //cout << "\n  Rabbit then knight" << endl;
            rabbitFileName = argv[2];
            knightFileName = argv[4];
            logFileName = "None";

            memset(msg.str,0,64);
            strcpy(msg.str,logFileName.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));


        } else if (strcmp(argv[1], "-r") == 0 && strcmp(argv[3], "-l") == 0) {
            //cout << "\n  knight then log" << endl;
            rabbitFileName = argv[2];
            knightFileName = "None";
            logFileName = argv[4];

            memset(msg.str,0,64);
            strcpy(msg.str,logFileName.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));

        } else if (strcmp(argv[1], "-k") == 0 && strcmp(argv[3], "-r") == 0) {
            //cout << "\n  knight then Rabbit" << endl;
            rabbitFileName = argv[4];
            knightFileName = argv[2];
            logFileName = "None";

            memset(msg.str,0,64);
            strcpy(msg.str,logFileName.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));
        } else if (strcmp(argv[1], "-l") == 0 && strcmp(argv[3], "-r") == 0) {
            //cout << "\n  Log then Rabbit" << endl;
            rabbitFileName = argv[4];
            knightFileName = "None";
            logFileName = argv[2];

            memset(msg.str,0,64);
            strcpy(msg.str,logFileName.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));
        }


        else{


            memset(msg.str,0,64);
            strcpy(msg.str, "None");
            write(logPipe[1], (char *) &msg, sizeof(msg));


            logMessageWrite = "5 argument entered. Invalid Switches";
            memset(msg.str,0,64);
            strcpy(msg.str,logMessageWrite.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));


            memset(msg.str,0,64);
            strcpy(msg.str, "END");
            write(logPipe[1], (char *) &msg, sizeof(msg));


        }
    }



    else if (argc == 7) {

        if (strcmp(argv[1], "-r") == 0) {

            if (strcmp(argv[3], "-k") == 0) {
                // cout << "\n  Rabbit,knight,Log" << endl;
                rabbitFileName = argv[2];
                knightFileName = argv[4];
                logFileName = argv[6];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));

            } else {
                //cout << "\n  Rabbit,Log,knight" << endl;
                rabbitFileName = argv[2];
                knightFileName = argv[6];
                logFileName = argv[4];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));

            }
        } else if (strcmp(argv[3], "-r") == 0) {
            if (strcmp(argv[1], "-k") == 0) {
                //cout << "\n  knight,Rabbit,Log" << endl;
                rabbitFileName = argv[4];
                knightFileName = argv[2];
                logFileName = argv[6];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));


            } else {
                //cout << "\n  Log,Rabbit,knight" << endl;
                rabbitFileName = argv[4];
                knightFileName = argv[6];
                logFileName = argv[2];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));


            }
        } else if (strcmp(argv[5], "-r") == 0) {
            if (strcmp(argv[1], "-k") == 0) {
                //cout << "\n  knight,Log,Rabbit" << endl;
                rabbitFileName = argv[6];
                knightFileName = argv[2];
                logFileName = argv[4];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));


            } else if (strcmp(argv[1], "-l") == 0){
                rabbitFileName = argv[6];
                knightFileName = argv[4];
                logFileName = argv[2];

                memset(msg.str,0,64);
                strcpy(msg.str,logFileName.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));
            }
            else{


                memset(msg.str,0,64);
                strcpy(msg.str, "None");
                write(logPipe[1], (char *) &msg, sizeof(msg));


                logMessageWrite = "7 argument entered. Invalid Switches";
                memset(msg.str,0,64);
                strcpy(msg.str,logMessageWrite.c_str());
                write(logPipe[1], (char *) &msg, sizeof(msg));


                memset(msg.str,0,64);
                strcpy(msg.str, "END");
                write(logPipe[1], (char *) &msg, sizeof(msg));

            }
        }

    }


    else {

        logMessageWrite = "Error when reading in input files";
        memset(msg.str,0,64);
        strcpy(msg.str,logMessageWrite.c_str());
        write(logPipe[1], (char *) &msg, sizeof(msg));
    }
}


/**
 * Checks if the user entered valid sqirchs
 * @param argc -  number of args
 * @param argv - array of the args
 * @param logMessageWrite - string to would log message
 * @param logPipe - pipe to send message to log
 */
void checkingValidSwitches(int argc, char *const *argv, string &logMessageWrite, const int *logPipe) {
    for (int i = 0; i < (argc - 1); i++) {
        msg msg;
        //Check if valid switches are entered
        if (!(strcmp(argv[i + 1], "-r") || strcmp(argv[i + 1], "-k") || strcmp(argv[i + 1], "-l"))) {
            logMessageWrite = "Incorrect switch given. Only -r, -k, or -l";
            memset(msg.str,0,64);
            strcpy(msg.str,logMessageWrite.c_str());
            write(logPipe[1], (char *) &msg, sizeof(msg));
        }

    }

}


/**
 * Reads in the rabbit file. Will check for errors and log them.
 * @param logMessageWrite - message to send to log file
 * @param rabbitFileName - name of rabbit file
 * @param line - read each line from the file
 * @param delimiter - ':' to separate input lines
 * @param token - part of string to put in setter of rabbit
 * @param type - what type of setter element
 * @param rabbit - rabbit class to create from rabiit file info
 * @param logPipe -pipe to send logs to log process
 */
void readInRabbitFile(string &logMessageWrite, const string &rabbitFileName, string &line, const string &delimiter,
                      string &token, string &type, Rabbit &rabbit, const int *logPipe) {


    ifstream rabbitFile(rabbitFileName);


    if(rabbitFileName.compare("rabbit") == 0){
        //cout << "Good" << endl;
    }
    else{
        //cout << "Bad" << endl;

    }

    msg msg;

    //Reading in Rabbit File
    if (rabbitFile.is_open()) {
        while (getline(rabbitFile, line)) {
            // Output the text from the file



            trim(line);

            memset(msg.str,0,64);
            strcpy(msg.str, line.c_str());

            write(logPipe[1],(char*)&msg,sizeof(msg));






            token = line.substr((line.find(delimiter) + 1), line.length());
            type = line.substr(0, line.find(delimiter));


            if(stoi(token)<0){
                memset(msg.str,0,64);
                strcpy(msg.str, "Negative Value entered");
                write(logPipe[1],(char*)&msg,sizeof(msg));
                memset(msg.str,0,64);
                strcpy(msg.str, "END");
                write(logPipe[1],(char*)&msg,sizeof(msg));
                exit(0);
            }



            if (type.compare("hp") == 0) {
                rabbit.setRabbitHp(stoi(token));
                if(stoi(token)<25 || stoi(token)>100 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit HP must be [25,100]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }


            } else if (type.compare("rate") == 0) {
                rabbit.setRabbitAttackRate(stoi(token));

                if(stoi(token)<3 || stoi(token)>10 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Attack Rate must be [3,10]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }


            } else if (type.compare("bite") == 0) {
                rabbit.setRabbitBite(stoi(token));

                if(stoi(token)<60 || stoi(token)>75 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Bite must be [60,75]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }

            } else if (type.compare("quick") == 0) {
                rabbit.setRabbitQuick(stoi(token));

                if(stoi(token)<10 || stoi(token)>20 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Quick must be [10,20]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }


            } else if (type.compare("throat") == 0) {
                rabbit.setRabbitThroat(stoi(token));


                if(stoi(token)<5 || stoi(token)>20 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Throat must be [5,20]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }

            } else if (type.compare("weak") == 0) {
                rabbit.setRabbitWeak(stoi(token));

                if(stoi(token)<1 || stoi(token)>9 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Weak must be [1,9]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }


            } else if (type.compare("strong") == 0) {
                rabbit.setRabbitStrong(stoi(token));

                if(stoi(token)<30 || stoi(token)>40){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Strong must be [30,40]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }

            } else if (type.compare("evade") == 0) {
                rabbit.setRabbitEvasion(stoi(token));

                if(stoi(token)<5 || stoi(token)>95 ){
                    memset(msg.str,0,64);
                    strcpy(msg.str, "Rabbit Evade must be [5,95]");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    memset(msg.str,0,64);
                    strcpy(msg.str, "END");
                    write(logPipe[1],(char*)&msg,sizeof(msg));
                    exit(0);
                }



            } else {




                memset(msg.str,0,64);
                strcpy(msg.str, "Error when reading in Rabbit Files");
                write(logPipe[1],(char*)&msg,sizeof(msg));
            }

        }
    }
    else {


        memset(msg.str,0,64);
        strcpy(msg.str, "ERROR couldn't find the rabbit file");
        write(logPipe[1],(char*)&msg,sizeof(msg));

    }
}



/**
 *Reads in the knight file
 * @param logMessageWrite - mesage to send to the log process
 * @param knightFileName - name of knight file
 * @param line - read each line from the file
 * @param delimiter - ':' to separate input lines
 * @param token - part of string to put in setter of knight
 * @param type - what type of setter element
 * @param loopcounter - counts each knight info
 * @param knightIndexArray - index for each knight in the knights array
 * @param NumOfKnights - holds how many knights there are
 * @param knights - knights array
 * @param logPipe -pipe to send logs to log process
 * @return the pointer to the knights array that was filled up
 */
Knight* readInKnightFiles(string &logMessageWrite, string knightFileName, string &line, const string &delimiter,
                          string &token, string &type, int loopcounter, int knightIndexArray, int &NumOfKnights,
                          Knight * knights, const int *logPipe) {


    msg msg;

    loopcounter = 1;
    knightIndexArray = 0;
    if (knightFileName.compare("None") == 0) {
        //Make the default Knight
//        logMessageWrite = "DEFAULT KNIGHT will be used";

        NumOfKnights = 1;


        knights = new Knight[NumOfKnights];

        Knight dKnight("Default Knight", 100, 10, 20, 3);

        knights[0].setKnightName("Default Knight");
        knights[0].setKnightHp(100);
        knights[0].setKnightBravery(10);
        knights[0].setKnightAttackRate(20);
        knights[0].setKnightDamage(3);

//        memset(msg.str,0,64);
//        strcpy(msg.str, logMessageWrite.c_str());
//        write(logPipe[1], (char *) &msg, sizeof(msg));
    }
        //HANDLE Knight file entered
    else {
        ifstream knightFile(knightFileName);


        if (knightFile.is_open()) {


            try {

                while (getline(knightFile, line)) {

                    if (line.find(delimiter) != std::string::npos) {
                        // : found in line

                        trim(line);

                        //cout << line << endl;


                        memset(msg.str, 0, 64);
                        strcpy(msg.str, line.c_str());
                        write(logPipe[1], (char *) &msg, sizeof(msg));


                        token = line.substr((line.find(delimiter) + 1), line.length());
                        type = line.substr(0, line.find(delimiter));


                        if (type.compare("count") == 0) {
                            NumOfKnights = stoi(token);



                            if(stoi(token)<1 || stoi(token)>8 ){
                                memset(msg.str,0,64);
                                strcpy(msg.str, "Knight count must be [1,8]");
                                write(logPipe[1],(char*)&msg,sizeof(msg));
                                memset(msg.str,0,64);
                                strcpy(msg.str, "END");
                                write(logPipe[1],(char*)&msg,sizeof(msg));
                                exit(0);
                            }



                            //HOLDS ALL KNIGHTS FROM INPUT
                            knights = new Knight[NumOfKnights];
                        } else {
                            if (type.compare("count") == 0) {
                                //do nothing
                                if(stoi(token)<1 || stoi(token)>8 ){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight count must be [1,8]");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }
                            } else if (type.compare("name") == 0) {


                                if(token.length()<2 || token.length()>50){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight name must be [2,50] characters");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }

                                knights->incNumKnight();
                                loopcounter = 1;
                                knights[knightIndexArray].setKnightName(token);

                            } else if (type.compare("hp") == 0) {


                                if(stoi(token)<10 || stoi(token)>40 ){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight HP must be [10,40]");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }


                                knights[knightIndexArray].setKnightHp(stoi(token));
                                loopcounter += 1;
                            } else if (type.compare("bravery") == 0) {



                                if(stoi(token)<0 || stoi(token)>=knights[knightIndexArray].getKnightHp() ){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight Bravery must be above 0 and below knight hp");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }


                                knights[knightIndexArray].setKnightBravery(stoi(token));
                                loopcounter += 1;

                            } else if (type.compare("rate") == 0) {


                                if(stoi(token)<10 || stoi(token)>50 ){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight rate must be [10,50]");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }




                                knights[knightIndexArray].setKnightAttackRate(stoi(token));
                                loopcounter += 1;
                            } else if (type.compare("damage") == 0) {


                                if(stoi(token)<1 || stoi(token)>8 ){
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "Knight damage must be [1,8]");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    memset(msg.str,0,64);
                                    strcpy(msg.str, "END");
                                    write(logPipe[1],(char*)&msg,sizeof(msg));
                                    exit(0);
                                }


                                knights[knightIndexArray].setKnightDamage(stoi(token));
                                loopcounter += 1;

                            }


                            if (loopcounter == 5) {
                                knightIndexArray += 1;
                                loopcounter = 1;
                            }
                        }


                    }


                }


            }catch(int error){

                memset(msg.str, 0, 64);
                strcpy(msg.str, "ERROR read in Knight file -- Not correct format");
                write(logPipe[1], (char *) &msg, sizeof(msg));

                memset(msg.str, 0, 64);
                strcpy(msg.str, "END");
                write(logPipe[1], (char *) &msg, sizeof(msg));


            }




        }


    }


    return knights;

}


/**
 * Checks if rabbit evades attack
 * @param rabbit - rabbit class itself
 * @param attackMsg - attackMsg to log attacks
 * @param randomNum - random number to decide evasion chance
 * @param rabbitEvadeStr - "Evade<true>" or "Evade<false>"
 * @param logMessage - log message to write
 * @return logMessage
 */
string &
RabbitEvade(Rabbit &rabbit, const attackMsg &attackMsg, int randomNum, string &rabbitEvadeStr, string &logMessage) {
    bool rabbitEvade;
    if (randomNum <= rabbit.getRabbitEvasion()) {
        //Rabbit Evade
        rabbitEvade = true;
        rabbitEvadeStr = "Evade<true>";

    } else {
        //Rabbit hit
        rabbitEvade = false;
        rabbitEvadeStr = "Evade<false>";
        rabbit.knightAttack(attackMsg.damage);
    }

    logMessage = "Rabbit;"+rabbitEvadeStr+"Damage"+to_string(attackMsg.damage);
    return logMessage;
}


/**
 * Logging child function which will keep on reading from all processes until "END" is sent
 * @param msg - msg struct which holds the log message passed through the pipes
 * @param logPipe - log pipe to send and receive from other processes
 */
void LoggingChildFunction(msg &msg, const int *logPipe) {
    Log lo("None");

    read(logPipe[0],(char*)&msg,sizeof(msg));


    string s;

    s = msg.str;

    lo.setLogFileString(s);


    if(strcmp(msg.str,"None") != 0){
        s = msg.str;
        lo.setLogFileString(s);
    }


    lo.writeLineToLog(s);
    // cout << msg.str << endl;

    while(strcmp("END",msg.str) != 0){
        // cout << msg.str << endl;
        read(logPipe[0],(char*)&msg,sizeof(msg));
        s = msg.str;
        trim(s);
        lo.writeLineToLog(s);

    }

    lo.makeLogFile();
}


int main(int argc, char* argv[]) {

    int value,pid,i;
    string logMessageRead;
    string logMessageWrite;
    //Holds rabbit file as string
    string rabbitFileName="";
    //Holds knight file as string
    string knightFileName="";
    //Holds Log file as string
    string logFileName="";
    //Reads In a single line from the text file
    string line="";
    //delimiter for reading in files
    string delimiter = ":";
    //token for holding deliminated string
    string token = "";
    //type of value from input files
    string type = "";
    int loopcounter = 0;
    int knightIndexArray = 0;
    //Rabbit class
    Rabbit rabbit;
    Knight dKnight("Default Knight", 100, 10, 20, 3);
    int NumOfKnights = 0;
    //Initialize Knights in memory will set values to it later.
    Knight *knights;
    msg msg;    //Message for logs
    attackMsg attackMsg;    //Messages for attacks
    //log pipe
    int logPipe[2];



    //START FIRST FORK
    signal(SIGTERM, &sigtermHandler);
    pipe(logPipe);
    value = fork();
    if(value == -1)
    {kill(0,SIGKILL);}

    else if(value == 0){
        //CHILD CODE
        LoggingChildFunction(msg, logPipe);
        exit(0);

    }

    else {

        //Parent Code

        //Check for valid switches

        checkingValidSwitches(argc, argv, logMessageWrite, logPipe);

        //Checking for valid input orders
        checkingValidInputOrders(argc, argv, knightFileName, logFileName, logPipe, logMessageWrite, rabbitFileName);

        //Read in Rabbit file
        readInRabbitFile(logMessageWrite, rabbitFileName, line, delimiter, token, type, rabbit, logPipe);

        //Read in Knight file
        knights = readInKnightFiles(logMessageWrite, knightFileName, line, delimiter, token, type, loopcounter, knightIndexArray,NumOfKnights,knights, logPipe);

        //Declare knight and rabbit pipes
        int KnightPipes[NumOfKnights][2];
        int rabbitPipe[2];


       signal(SIGTERM, &sigtermHandler);


        //Initialize pipes
        for(int i=0; i < NumOfKnights; i++){
            pipe(KnightPipes[i]);
        }
        pipe(rabbitPipe);
        
        value = fork();

        if(value == -1)
        {kill(0,SIGKILL);}


            //RABBIT PROCESS
        else if(value == 0){
            //Child Code


            memset(msg.str,0,64);
            strcpy(msg.str,"ATTACK STARTS");
            write(logPipe[1], (char *) &msg, sizeof(msg));

            bool rabbitAlive = true;
            int randomNum = 0;
            int whichKnightNum =0;
            string whichKnightStr ="";
            int currentKnight = 0;
            string rabbitEvadeStr = "";
            string logMessage = "";


            while(rabbitAlive){
                //Rabbit Will attack
                randomNum = rand() % 100 + 1;
                //Let the chance of a bite attack be
                if (randomNum <= rabbit.getRabbitBite()) {

                    //Bite Attack
                    attackMsg.from = 0; // From the the rabbit
                    attackMsg.type = 0; //Bite
                    attackMsg.damage = rabbit.getRabbitBite();
                    write(KnightPipes[currentKnight][1], (char *) &attackMsg, sizeof(attackMsg));

                } else if ((randomNum > rabbit.getRabbitBite()) &&
                           randomNum <= (rabbit.getRabbitBite() + rabbit.getRabbitQuick())) {

                    //Quick Attack
                    attackMsg.from = 0; // From the the rabbit
                    attackMsg.type = 1; //Quick
                    attackMsg.damage = rabbit.getRabbitQuick();
                    for(i=0; i < NumOfKnights; i++){
                        write(KnightPipes[i][1], (char *) &attackMsg, sizeof(attackMsg));
                    }

                }else {

                    //Throat attack
                    attackMsg.from = 0; // From the the rabbit
                    attackMsg.type = 2; //Throat
                    attackMsg.damage = rabbit.getRabbitThroat();
                    write(KnightPipes[currentKnight][1], (char *) &attackMsg, sizeof(attackMsg));

                }




                read(rabbitPipe[0], (char *) &attackMsg, sizeof(attackMsg));


                //Let the rabbit attack the knight that just attacked
                whichKnightNum = attackMsg.type-3;
                currentKnight = whichKnightNum;


                randomNum = rand() % 100 + 1;


                //Does Rabbit Evade?
                logMessage = RabbitEvade(rabbit, attackMsg, randomNum, rabbitEvadeStr, logMessage);


                if (rabbit.getRabbitHp() <= 0) {

                    rabbitAlive = false;
                    memset(msg.str,0,64);
                    strcpy(msg.str,"Rabbit Killed");
                    write(logPipe[1], (char *) &msg, sizeof(msg));
                    for(int i=0; i<NumOfKnights; i++) {
                        attackMsg.from = -1; // Rabbit is Killed

                        write(KnightPipes[i][1], (char *) &attackMsg, sizeof(attackMsg));
                    }
                    exit(0);
                }
                    memset(msg.str,0,64);
                    strcpy(msg.str,logMessage.c_str());
                    write(logPipe[1], (char *) &msg, sizeof(msg));
            }// end while(rabbitAlive)
        }// end Child code


        else{
            //Parent code


            int knightNum=0;

            int rabbitwin=0;


            //Making KNIGHT PROCESSES
            for(int i=0; i<NumOfKnights; i++){

                knightNum=i;
                value = fork();
                if(value == -1)
                {kill(0,SIGKILL);}

                else if(value == 0) {
                    //Child Code
                    bool knightAlive = true;
                    int randomNum = 0;
                    string type="";
                    string logMessage="";




                    while(knightAlive){

                        //Fill up attackMsg
                        attackMsg.from = knightNum+1; //What knight
                        attackMsg.type = 3+knightNum; //What knight
                        attackMsg.damage = knights[knightNum].getKnightDamage();

                        write(rabbitPipe[1], (char *) &attackMsg, sizeof(attackMsg));
                        read(KnightPipes[knightNum][0], (char *) &attackMsg, sizeof(attackMsg));

                        if(attackMsg.type == 0){
                            type="Bite";
                            knights[knightNum].rabbitAttack(attackMsg.damage);
                            logMessage = knights[knightNum].getKnightName() + ";"+ type+ ";" + to_string(attackMsg.damage);
                        }else if(attackMsg.type == 1){
                            type="Quick";
                            knights[knightNum].rabbitAttack(attackMsg.damage);
                            logMessage = "ALL KNIGHTS;"+ type+ ";" + to_string(attackMsg.damage);
                        }else if(attackMsg.type ==2){
                            type="Throat";
                            knights[knightNum].rabbitAttack(attackMsg.damage);
                            logMessage = knights[knightNum].getKnightName() + ";"+ type+ ";" + to_string(attackMsg.damage);
                        }else if(attackMsg.from ==-1){
                            knightAlive = false;
                            logMessage = knights[knightNum].getKnightName() + "; " "KILLED THE RABBIT";
                            memset(msg.str,0,64);
                            strcpy(msg.str,logMessage.c_str());
                            write(logPipe[1], (char *) &msg, sizeof(msg));
                            exit(0);
                        }


                        knights[knightNum].rabbitAttack(attackMsg.damage);
                        memset(msg.str,0,64);
                        strcpy(msg.str,logMessage.c_str());
                        write(logPipe[1], (char *) &msg, sizeof(msg));


                        if(knights[knightNum].getKnightHp() <= 0){
                            knightAlive = false;
                            logMessage = knights[knightNum].getKnightName() + "; " "KILLED BY; "+ type + "!";
                            memset(msg.str,0,64);
                            strcpy(msg.str,logMessage.c_str());
                            write(logPipe[1], (char *) &msg, sizeof(msg));
                            exit(0);
                        }else if(knights[knightNum].getKnightHp() <= knights[knightNum].getKnightBravery()){
                            knightAlive = false;
                            logMessage = knights[knightNum].getKnightName() + "; " "RUNS AWAY from; "+ type + "!";
                            memset(msg.str,0,64);
                            strcpy(msg.str,logMessage.c_str());
                            write(logPipe[1], (char *) &msg, sizeof(msg));
                            exit(0);
                        }//end knights[knightNum].getKnightHp() <= 0

                    }// end while(knightAlive)



                }//end child code
                else{

                    // Parent code for each knight forked
                    //Wait for each process
                    int status;
                    wait(&status);
                }// Parent code

            }//end for(int i=0; i<NumOfKnights; i++)
        }

        //Tell Logger to stop
        memset(msg.str,0,64);
        strcpy(msg.str,"END");
        write(logPipe[1], (char *) &msg, sizeof(msg));
        exit(0);
    }


    // Back in the original parent function
    //Wait for all processes to complete then finish
    int status;
    wait(&status);
    return 0;
}




