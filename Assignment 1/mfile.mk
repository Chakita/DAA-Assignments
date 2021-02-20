a.out:client.o server.o
	gcc client.o server.o
client.o: client.c proto.h
	gcc -c client.c
server.o: server.c proto.h
	gcc -c server.c
	
