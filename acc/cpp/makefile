BIN=.bundled.cpp a.out

all: $(BIN)

clean:
	rm -f $(BIN)

.bundled.cpp: main.cpp
	oj-bundle -I ~/Competitive/my-library $^ |\
	grep -v '^#line ' | \
	grep -v '^#pragma once' | \
	cat -s \
	> $@

a.out: .bundled.cpp
	g++ -std=gnu++23 -Wall -Wextra -march=native -O2 -DLOCAL -o $@ $^
