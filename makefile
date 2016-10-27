GCC = gcc -g

comp: dev.c
        $(GCC) -c dev.c
        $(GCC) dev.o -o devtest

run: comp
        ./devtest

clean:
        rm *.o
        rm *~
        rm rand.txt

debug: dev.c
        gdb devtest
