obj-m := symbol_export.o
symbol_export-objs := export.o

all: 
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules

clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean