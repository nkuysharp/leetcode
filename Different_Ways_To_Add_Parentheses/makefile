CFLAG = -std=c++11 -Wall -g
all: run-c++ run-js

run-c++: DifferentWaysToAddParentheses.h main.cpp
	     g++ $(CFLAG) main.cpp -o run-c++
	     @echo "--------- test for c++ ----------"
	     ./run-c++




run-js: DifferentWaysToAddParentheses.js main.js
	    @echo "------------- test for javascript -------------"
	    node main.js




