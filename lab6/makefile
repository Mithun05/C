
# Specify the compiler options or flags, linking libraries
# and any debugging information flags as a variables
CC = gcc

# Specify the target
all: lab6

# Specify how the executables should be created from source files
lab6: lab6.c lab6.h
	$(CC) -g lab6.c -o lab6

# Specify valgrind tool command options
run:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 ./lab6

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f lab6


