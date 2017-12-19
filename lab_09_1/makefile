app.exe : functions.o main.o
	gcc -o app.exe functions.o main.o -lm -ggdb -g

functions.o: functions.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c functions.c -lm -ggdb -g 

main.o: main.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c -lm -ggdb -g

clean :
	rm *.o *.exe