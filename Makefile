PROJECT = libpluma-csv2json-plugin
TARGET = $(PWD)/lib/$(PROJECT).so
CXXFLAGS := -fPIC -Wall -O2 -I$(PWD)/../pluma/src -I$(PWD)/../pluma/src/plugin
LDFLAGS := -shared

SRCS = $(PWD)/src/csv2json.cxx
OBJS = $(SRCS:.cxx=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p lib
	$(CXX) $(LDFLAGS) -o $@ $^

$(SRCS:.cxx=.o):%.o:%.cxx
	$(CXX) $(CXXFLAGS) $< >$@

include $(SRCS:.cxx=.d)

clean:
	$(RM) $(TARGET) $(OBJS) $(SRCS:.cxx=.d)
