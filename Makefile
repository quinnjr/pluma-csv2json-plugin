PROJECT = libpluma-csv2json-plugin
TARGET = lib/$(PROJECT).so
PLUMA_DIRECTORY := $(PWD)/../pluma/src
CXXFLAGS := -std=c++11 -fPIC -pedantic -Wall -O2 -pipe
CXXFLAGS += -I$(PLUMA_DIRECTORY)

SHELL := /bin/sh

RMDIR = rmdir

SOURCES = src/csv2json.cxx
TEST_SOURCES = test/test_plugin.cxx $(SOURCES)
TEST_TARGET = test/test_plugin

.PHONY: all clean check

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p lib
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -shared -Wl,-soname,$(PROJECT) -o $@ $^

check: $(TEST_SOURCES)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -I./include -g $(LDFLAGS) -o $(TEST_TARGET) $^

clean:
	$(RM) $(TARGET) $(TEST_TARGET)
