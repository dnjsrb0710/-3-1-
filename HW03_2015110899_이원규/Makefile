all : thread10.exe thread100.exe thread1000.exe

thread10.exe : thread10.c
	gcc -o thread10.exe thread10.c -lpthread

thread100.exe : thread100.c
	gcc -o thread100.exe thread100.c -lpthread

thread1000.exe: thread1000.c
	gcc -o thread1000.exe thread1000.c -lpthread

clean : 
	rm thread10.exe
	rm thread100.exe
	rm thread1000.exe

