
HELLO_VERSION ?= "0.1"

HELLO_BUILD_USER ?= $(shell whoami)
HELLO_BUILD_HOST ?= $(shell hostname)
HELLO_BUILD_DATE ?= $(shell date)
HELLO_BUILD_TOPDIR ?= $(shell pwd)

build_date ?= $(shell date "+%Y/%m/%d %T")

objects = hello.o

.PHONY: all
all: .version $(objects)
	cc -o hello $(objects)
	@echo -e "\n\n\033[32m>>>     $(build_date)    <<<\033[m"
	@echo -e "\033[32m>>>     Congratulations!       <<<\033[m\n\n"

f="hello.h"

.PHONY: .version
.version:
	@#f="hello.h"
	@echo "#define HELLO_BUILD_VER \"$(HELLO_VERSION)\"" > $(f)	
	@echo "#define HELLO_BUILD_USER \"$(HELLO_BUILD_USER)\"" >> $(f)
	@echo "#define HELLO_BUILD_HOST \"$(HELLO_BUILD_HOST)\"" >> $(f)
	@echo "#define HELLO_BUILD_DATE \"$(HELLO_BUILD_DATE)\"" >> $(f)
	@echo "#define HELLO_BUILD_TOPDIR \"$(HELLO_BUILD_TOPDIR)\"" >> $(f)

.PHONY: clean
clean:
	@$(RM) $(objects) hello
