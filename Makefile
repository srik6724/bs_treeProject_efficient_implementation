PJ3	:main.o util.o MM.o BST.o
	 g++ -Wall -o PJ3 main.o util.o MM.o BST.o

main.o	:main.cpp data_structures.h util.h MM.h BST.h
	 g++ -Wall -c main.cpp

util.o	:util.cpp data_structures.h util.h
	 g++ -Wall -c util.cpp

MM.o	:MM.cpp data_structures.h
	 g++ -Wall -c MM.cpp

BST.o	:BST.cpp data_structures.h MM.h
	 g++ -Wall -c BST.cpp

clean	:
	rm *.o PJ3