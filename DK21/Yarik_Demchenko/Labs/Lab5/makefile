CC = gcc
LFLAGS = -Werror

C_FILES = main.cpp
O_FILES = main.o

EXE_NAME = main.exe

all:
	$(CC) $(LFLAGS) -c $(C_FILES)
	$(CC) $(LFLAGS) -o $(EXE_NAME) $(O_FILES) -lfreeglut -lglu32 -lopengl32
	$(EXE_NAME)
