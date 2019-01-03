main:main.o server.o request.o response.o
	g++ -g -o main main.o server.o request.o response.o
main.o:main.c
	gcc -c main.c -o main.o
server.o:server.c
	gcc -c server.c -o server.o
request.o:request.c
	gcc -c request.c -o request.o
response.o:response.c
	gcc -c response.c -o response.o
clean:
	rm -rf *.o main