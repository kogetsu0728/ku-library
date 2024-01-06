AC_LIBRARY_PATH := $(shell echo $$AC_LIBRARY_PATH)
MY_LIBRARY_PATH := $(shell echo $$MY_LIBRARY_PATH)

CURRENT_DATE := $(shell date +"%Y/%m/%d %H:%M:%S")
AUTHOR_NAME := $(shell echo $$COMPETITIVE_USER_NAME)

BIN := submit.cpp a.out

all: $(BIN)

clean:
	rm -f $(BIN)

submit.cpp: main.cpp
	@oj-bundle -I $(MY_LIBRARY_PATH)  $^ |\
	grep -v '^#line ' | \
	grep -v '^#pragma once' | \
	cat -s \
	> $@
	@sed -i '1i /**\n *    author  : $(AUTHOR_NAME)\n *    created : $(CURRENT_DATE) (UTC+9)\n**/' $@

a.out: submit.cpp
	g++ -I$(AC_LIBRARY_PATH) -std=gnu++23 -Wall -Wextra -march=native -O2 -DLOCAL -o $@ $^
