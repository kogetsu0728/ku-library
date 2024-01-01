AC_LIBRARY_PATH := $(shell echo $$AC_LIBRARY_PATH)
MY_LIBRARY_PATH := $(shell echo $$MY_LIBRARY_PATH)

BIN := .bundled.cpp a.out

all: $(BIN)

clean:
	rm -f $(BIN)

.bundled.cpp: main.cpp
	@oj-bundle -I $(MY_LIBRARY_PATH)  $^ |\
	grep -v '^#line ' | \
	grep -v '^#pragma once' | \
	cat -s \
	> $@

a.out: .bundled.cpp
	g++ -I$(AC_LIBRARY_PATH) -std=gnu++23 -Wall -Wextra -march=native -O2 -DLOCAL -o $@ $^
