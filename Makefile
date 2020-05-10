hw4: main.o Log.o Knight.o Rabbit.o
	g++ main.o Log.o Knight.o Rabbit.o -o hw4

main.o: main.cpp
	g++ -c main.cpp

Log.o: Log.cpp Log.h
	g++ -c Log.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Rabbit.o: Rabbit.cpp Rabbit.h
	g++ -c Rabbit.cpp

clean:
	rm *.o