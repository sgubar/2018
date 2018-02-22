CC=gcc
FLAGS=-O2 -Wall -lm 
EXE=main
SRCS=right_triangle.c main.c
HDRS=right_triangle.h
OBJS=$(SRCS:.c=.o)

release:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS) $(HDRS)


debug:
	$(CC) $(FLAGS) -DDEBUG -o $(EXE) $(SRCS) $(HDRS)

clean:
	rm -f $(EXE)
