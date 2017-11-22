app.exe: main.o functions.o
	gcc -o app.exe main.o functions.o
main.o: main.c functions.h
	gcc  -pedantic -c main.c
functions.o: functions.c functions.h
	gcc  -pedantic -c functions.c
clean:
	rm *.o *.exe