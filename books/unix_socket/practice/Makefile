all : client_exe server_exe

VPATH = chapter1/gettime
client_exe : client.o
	cc client.o -o client_exe

server_exe : server.o
	cc server.o -o server_exe

client.o : client.cc
	cc -c chapter1/gettime/client.cc -I common/

server.o : server.cc
	cc -c chapter1/gettime/server.cc -I common/
clean :
	rm client.o run
