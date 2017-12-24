app.exe: functions.o main.o
	gcc -o app.exe functions.o main.o
functions.o: functions.c functions.h
	gcc -Wall -Werror -pedantic -c functions.c
main.o: main.c functions.h
	gcc -Wall -Werror -pedantic -c main.c
test.exe: test.o functions.o
	gcc -o test.exe test.o functions.o
test.o: test.c functions.h
	gcc -Wall -Werror -pedantic -c test.c
clean:
	rm *.o *.exe