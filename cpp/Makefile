CXX := clang++
RM := rm -Force
MD := mkdir -p

CXXFLAGS += -std=c++17 -pedantic-errors
CXXFLAGS += -Wall -O0

CPPFLAGS += -Iinclude

LDFLAGS +=


PROG_SOURCES := $(wildcard  src/*.cpp)
TEST_SOURCES := $(wildcard test/*.cpp)
OBJECTS := $(patsubst  src/%.cpp, build/%.o, $(PROG_SOURCES))
OBJECTS += $(patsubst test/%.cpp, build/%.o, $(TEST_SOURCES))
DEPENDENCIES := $(patsubst   src/%.cpp, build/%.d, $(PROG_SOURCES)) 
DEPENDENCIES += $(patsubst  test/%.cpp, build/%.d, $(TEST_SOURCES)) 

CPPFILES = $(wildcard src/*.cpp)
SOURCEFILES = $(wildcard build/*.o)


all: build run

build: $(OBJECTS) bin/main.exe 
	@echo Successful! Running the program...

run:
	@bin/main.exe
	@echo START_TIME

build/%.o: src/%.cpp
	@echo Compiling [$(subst .o,, $<) ]
	@$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

-include $(DEPENDENCIES)


bin/main.exe: delete-main
	@echo Linking and building the executable...
	@$(CXX) $(CXXFLAGS) -o $@ $(SOURCEFILES)

delete-main:
ifneq (, $(wildcard bin/main.exe))
	@del bin\main.exe
endif