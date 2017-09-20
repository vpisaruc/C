main.out : functions.o main.o
	gcc -o main.out functions.o main.o 

functions.o: functions.c functions.h
	gcc -c functions.c 

main.o: main.c functions.h
	gcc -c main.c 

clean :
	rm *.o *.out

