CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic --std=c++11 -g
CXXSANFLAGS = -Wall -Werror -pedantic --std=c++11 -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@ 

.SUFFIXES:

.PHONY: clean
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump