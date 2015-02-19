all:
	clang++-3.5 -std=c++11 -I ../gtest test.cpp ../gtest/gtest-all.o -lpthread -o test.o
	./test.o
