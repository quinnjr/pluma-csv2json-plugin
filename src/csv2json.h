// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#pragma once

#ifndef _JSON2CSV_H
#define _JSON2CSV_H

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include "Plugin.h"
#include "PluginManager.h"
#include "PluginProxy.h"
#include "plugin/PluMA.h"

// Versioning
#define PLUGIN_VERSION = "0.1.0"

// Debugging
#ifndef DEBUG
#define DEBUG 0
#endif

using namespace std;

// Return codes
enum Status {
  SUCCESS = 0,
  ERROR_INVALID_INPUT = 1,
  ERROR_INVALID_OUTPUT = 2,
  ERROR_MEM = 3,
  ERROR_FILE_READ = 4,
  ERROR_CELL_LENTH = 5,
  ERROR_ENCODING = 6
};

/**
  The Csv2Json plugin class.
*/
class Csv2JsonPlugin: public Plugin {
private:
  ifstream *input_fd;
  vector<string> output_data;
  char row_separator;
  char col_separator;
  char text_separator;
  int max_cell_length;
  unsigned char escape;
  int_fast16_t keys;

public:
  Csv2JsonPlugin(char row_sep, char col_sep, char text_sep, int max,
    unsigned char esc);
  Csv2JsonPlugin(char col_sep, char text_sep, int max,
      unsigned char esc);
  Csv2JsonPlugin(char text_sep, int max, unsigned char esc);
  Csv2JsonPlugin(int max, unsigned char esc);
  Csv2JsonPlugin(unsigned char esc);
  Csv2JsonPlugin();
  ~Csv2JsonPlugin();
  // Implementing Plugin interface
  void input(std::string filename);
  void run();
  void output(std::string filename);
  // Inline getter methods
  ifstream * GetInputStream() const { return input_fd; }
  vector<string> GetOutputData() const { return output_data; }
  char GetRowSeparator() const { return row_separator; }
  char GetColSeparator() const { return col_separator; }
  char GetTextSeparator() const { return text_separator; }
  int GetMaxCellLength() const { return max_cell_length; }
  unsigned char GetEscape() const { return escape; }
  int_fast16_t GetKeys() const { return keys; }
  // Setter methods.
  void SetInputStream(ifstream *d) { input_fd = d; };
  void SetOutputData(vector<string> s) { output_data = s; };
  void SetRowSeparator(char r) { row_separator = r; };
  void SetColSeparator(char c) { col_separator = c; };
  void SetTextSeparator(char t) { text_separator = t; };
  void SetMaxCellLength(int m) { max_cell_length = m; };
};
#endif
