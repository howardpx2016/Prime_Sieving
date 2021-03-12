CC = g++
CXXFLAGS = -O3 -mcx16 -march=native -std=c++17 -Wall -Wextra -Werror -fcilkplus -DCILK -fpic

all: sieve-E-parallel

reduce: sieve-E-parallel.cpp get_time.h
	$(CC) $(CXXFLAGS) reduce.cc -o reduce

clean:
	rm reduce

.PHONY: clean
