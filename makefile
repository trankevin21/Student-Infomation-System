HeapOfStudent: HeapStudent.o
	g++ HeapStudent.o -o HeapOfStudent
HeapStudent.o: HeapStudent.cpp HSHeader.h
	g++ -c HeapStudent.cpp
clean:
	rm -f *.o
	rm HeapOfStudent
run: HeapOfStudent
	./HeapOfStudent

