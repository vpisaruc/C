app.exe : functions.o main.o
	gcc -o app.exe functions.o main.o -lm -ggdb

functions.o: functions.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c functions.c -lm -ggdb 

main.o: main.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c -lm -ggdb

test.exe : functions.o module_tests.o
	gcc -o test.exe functions.o module_tests.o -lm -ggdb

module_tests.o: module_tests.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c module_tests.c -lm -ggdb
	
timer.exe : functions.o timer.o
	gcc -o timer.exe functions.o timer.o -lm -ggdb

timer.o: timer.c functions.h
	gcc -std=c99 -Wall -Werror -pedantic -c timer.c -lm -ggdb

clean :
	rm *.o *.exe
