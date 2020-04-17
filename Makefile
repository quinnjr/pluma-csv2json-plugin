# Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
# SPDX-License-Identifier: ISC

# This Makefile assumes that the main PluMA system is cloned as a sibling
# to this repository.

PROJECT = pluma-csv2json

PLUMA_DIR := $(PWD)/../pluma/src
PLUMA_PLUGIN_DIR := $(PLUMA_DIR)/plugin

CXXFLAGS += -I./src -I$(PLUMA_DIR) -I$(PLUMA_PLUGIN_DIR) -Wall -pedantic -O2 -fPIC
LDFLAGS += -shared

SRCS = src/csv2json.cxx
OBJS = $(SRCS:.cxx=.o)
LIB = lib$(PROJECT).so

.PHONY: clean

$(LIB): $(OBJS)
	$(shell mkdir -p lib)
	$(CXX) $(LDFLAGS) -o lib/$@ $^

$(SRCS:.cxx=.o):%.o:%.cxx
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) lib/$(LIB) $(OBJS) $(SRCS:.cxx=.o)
