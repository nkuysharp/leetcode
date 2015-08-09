all: run-cpp run-js

run-cpp.out: ValidAnagram.h main.cpp
	g++ -std=c++11 -Wall -g main.cpp -o run-cpp.out
	@echo "--------- test for c++ ----------"
	./run-cpp.out

run-js: ValidAnagram.js main.js
	@echo "--------- test for javascript ---------"
	node main.js
