VPATH = chapter1/gettime:common
run : client.o
	cc client.o -o run

client.o : client.cc
	cc -c chapter1/gettime/client.cc -I common/
clean :
	rm client.o run
