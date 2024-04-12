obj-m := module1.o
obj-m += module2.o

all: 
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean