obj-m := hello_dev.o 

KDIR  := /lib/modules/$(shell uname -r)/build
PWD   := $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
