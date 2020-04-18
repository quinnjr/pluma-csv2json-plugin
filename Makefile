PROJECT = libpluma-csv2json-plugin
TARGET = $(PROJECT).so
PLUMA_DIRECTORY := $(PWD)/../pluma/src
CXXFLAGS := -std=c++11 -fPIC -pedantic -Wall -O2
CXXFLAGS += -I$(PLUMA_DIRECTORY)
LDFLAGS += -shared

RMDIR = rmdir

SOURCES = src/csv2json.cxx

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p lib
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wl,-soname,lib$(PROJECT) -o lib/$@ $^

clean:
	$(RM) $(OBJECTS) lib/$(TARGET)
	$(RMDIR) lib
