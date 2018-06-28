build.out: main.o Sequence.o
	g++ -o build.out main.o Sequence.o -std=gnu++11

main.o : main.cpp Sequence.h
	g++ -c  main.cpp Sequence.h -std=gnu++11

Sequence.o : Sequence.cpp Sequence.h
	g++ -c  Sequence.h Sequence.cpp -std=gnu++11
