main:main.o server.o
	gcc -o main main.o server.o
main.o:main.c
	gcc -c main.c -o main.o
server.o:server.c
	gcc -c server.c -o server.o
clean:
	rm -rf *.o main