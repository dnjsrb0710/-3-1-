all : threadfail.exe threadsuccess.exe


threadfail.exe : threadfail.c
	gcc -o threadfail.exe threadfail.c -lpthread

threadsuccess.exe: threadsuccess.c
	gcc -o threadsuccess.exe threadsuccess.c -lpthread

clean : 
	rm threadfail.exe
	rm threadsuccess.exe
	

