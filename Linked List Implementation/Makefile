CC = gcc
CFLAGS = -Wall
BINARY = sampleProgram2
CSRC = LinkedListImpl.c $(BINARY).c
HSRC = StackAndQueue.h
OBJ = $(CSRC:.c=.o)

$(BINARY): $(OBJ) #combining all the object files together to make the final executable
	$(CC) -o $@ $(OBJ)

%.o: %.c $(HSRC) #compiling each .c file to object(.o) files
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean: #removing all the temporary files (i.e. all .o files)
	rm -f $(OBJ)

./PHONY: clobber
clobber: #removing all the temporary files including the final executable
	rm -f $(BINARY) $(OBJ)

run: $(BINARY)
	./$(BINARY)