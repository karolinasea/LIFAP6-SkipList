CXX      = g++

.DEFAULT_GOAL := testSkipList

SOURCES = 
SOURCES += cellule.cpp
SOURCES += skipList.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  += -g -Wall -std=c++11 -pedantic
LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 

LISTE_SOURCES = testSkipList.cpp
LISTE_OBJECTS = $(LISTE_SOURCES:.cpp=.o)

test_liste : $(LISTE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(LISTE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(LISTE_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : testSkipList
TARGETS += testSkipList
CLEAN_OBJECTS += $(LISTE_OBJECTS)

