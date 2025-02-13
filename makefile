#Group Information:
#CRN: 74025
#Group 9
	
#Group Member 1: Nathaniel Kebere (100868890)
#Group Member 2: Anuj Shukla (100895219)
#Group Member 3: Syed Mesam Jafri (100869437)
#Group Member 4: Farzad Shahdad (100861389)
#Group Member 5: Danial Shaikh (100698628)

all: myshell

myshell: myshell.c utility.c
	gcc -o myshell myshell.c utility.c

ifeq ($(OS),Windows_NT)
    RM = del /F /Q
else
    RM = rm -f
endif

clean:
	$(RM) myshell
