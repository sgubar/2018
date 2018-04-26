CC=gcc
FLAGS=-O2 -Wall -lm
EXE=main
SRCS=main.c dk_tool.c

release:
	$(CC) $(FLAGS) -o $(EXE) $(SRCS)

debug:
	$(CC) $(FLAGS) -DDEBUG -o $(EXE) $(SRCS) 

clean:
	rm -f $(EXE)
