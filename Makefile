SRC = main.c node.c hashtable.c
OBJ = main.o node.o hashtable.o
PROG = wordfreak

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)