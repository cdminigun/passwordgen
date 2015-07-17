# ***************************************************************
# Executable programs
passwordGen:
	gcc -c driver.c;
	gcc -c passwordgen.c;
	gcc -o passwordgen driver.o passwordgen.o;
