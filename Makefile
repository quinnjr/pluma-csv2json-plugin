PROJECT = libpluma-csv2json-plugin
TARGET = $(PROJECT).so
CXXFLAGS += -std=c++11 -fPIC -pedantic -Wall -O2 -I$(PWD)/../pluma/src
LDFLAGS += -shared

SOURCES = src/csv2json.cxx

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(LDFLAGS) -Wl,-soname,lib$(PROJECT) -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
