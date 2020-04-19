PROJECT = libpluma-csv2json-plugin
TARGET = $(PROJECT).so
PLUMA_DIRECTORY := $(PWD)/../pluma/src
CXXFLAGS := -std=c++11 -fPIC -pedantic -Wall -O2 -pipe
CXXFLAGS += -I$(PLUMA_DIRECTORY)

RMDIR = rmdir

SOURCES = src/csv2json.cxx
TEST_SOURCES = test/test_plugin.cxx $(SOURCES)

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p lib
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -shared -Wl,-soname,lib$(PROJECT) -o lib/$@ $^

clean:
	$(RM) lib/$(TARGET) test_plugin
	$(RMDIR) lib

test: $(TEST_SOURCES)
	$(CXX) $(CFLAGS) $(CXXFLAGS) -I./include -DDEBUG -g $(LDFLAGS) -o test/test_plugin $^
	# $(RM) test/test_plugin
