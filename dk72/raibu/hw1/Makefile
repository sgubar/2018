CC=gcc
FLAGS=-O2 -Wall
EXE=main
SRCS=dk_tool.c main.c
HDRS=dk_tool.h
OBJS=$(SRCS:.c=.o)

all:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS) $(HDRS)


clean:
	rm -f $(EXE)
