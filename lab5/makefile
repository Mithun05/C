
# Specify the compiler options or flags, linking libraries
# and any debugging information flags as a variables
CC = gcc

#
# Specify the target
all: lab5

# Specify how the executables should be created from source files
lab5: lab5.c lab5.h
	$(CC) -g lab5.c -o lab5

# Specify valgrind tool command options
run:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 ./lab5

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f lab5


