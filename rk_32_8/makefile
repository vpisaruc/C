app.exe: functions.o main.o
	gcc -o app.exe functions.o main.o
functions.o: functions.c functions.h
	gcc -Wall -Werror -pedantic -c functions.c
main.o: main.c functions.h
	gcc -Wall -Werror -pedantic -c main.c
clean:
	rm *.o *.exe