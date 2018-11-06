#.PHONY: all say_hello generate clean

#CC = g++
#
#DIR_TEST2 = ./test2
#
#SRCS := $(wildcard *.cpp ${DIR_TEST2}/*.cpp)
#BINS := $(SRCS:%.cpp=%) #fetch filename but no exp part(etc. file.c = file)
#
#all: ${BINS} 
#
#%: %.o
#	@echo "Checking..."
#	${CC} $< -o $@
#
#%.o: %.c
#	@echo "Creating object.."
#	${CC} -c $< -std=c++
#
#clean:
#	@echo "Cleaning up..."
#	rm *.txt
#
all:
	$(MAKE) -C test2
	g++ test2/test2.o test.o -o all.out -std=c++11

test.o :test.cpp
	g++ -c test.cpp -std=c++11

  
