main.exe : str.o main.o
	gcc -o main.exe str.o main.o

str.o : str.c str.h defines.h
	gcc -std=c99 -Wall -Werror -pedantic -c str.c

main.o : main.c str.h defines.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c

clean :
	rm *.o *.exe
