obj-m := debugsym.o

#Kbuild understands a make variable named CFLAGS_modulename.o to add specific C flags when compiling this unit
CFLAGS_debugsym.o := -DDEBUG

#This will be applied to all of the source files compiled for your module with the Makefile
#ccflags-y := -DDEBUG

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean