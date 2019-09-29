#target exe
myexe: utilities.o Project2.o array_functions.o
	g++ $(CFLAGS) -o myexe utilities.o Project2.o array_functions.o

utilities.o: utilities.cpp utilities.h
	g++ $(CFLAGS) -c utilities.cpp

Project2.o: Project2.cpp
	g++ $(CFLAGS) -c Project2.cpp

array_functions.o: array_functions.cpp array_functions.h
	g++ $(CFLAGS) -c array_functions.cpp

clean:
	rm -f *.o myexe
