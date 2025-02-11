all: myshell

myshell: myshell.c utility.c
	gcc -o myshell myshell.c utility.c

ifeq ($(OS),Windows_NT)
    RM = del /F /Q
else
    RM = rm -f
endif

clean:
	$(RM) myshell.exe myshell.o utility.o