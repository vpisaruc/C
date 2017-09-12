main.out : functions.o main.o
	gcc -o main.out functions.o main.o -lm

functions.o: functions.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c functions.c -lm

main.o: main.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c -lm

clean :
	rm *.o *.out

