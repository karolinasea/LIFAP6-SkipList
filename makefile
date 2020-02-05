CPP_SRC = cellule.cpp skipList.cpp testSkipList.cpp 

CXX=g++
CFLAGS=-g -O0 -Wall -Wextra 

sl: $(CPP_SRC) $(wildcard *.hpp) $(wildcard *.tpp)
	$(CXX) $(CPP_SRC) $(CFLAGS) -o $@

clean:
	-$(RM) *.o sl