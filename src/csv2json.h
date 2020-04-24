// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#pragma once

#ifndef _JSON2CSV_H
#define _JSON2CSV_H

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
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

/**
  The Csv2Json plugin class.
*/
class Csv2JsonPlugin: public Plugin {
private:
  char row_separator, col_separator, text_separator;
  ifstream *input_fd;
  int max_cell_length;
  vecotr<string> *keys;
  vector<string> *output_data;
  void push_ouput(string odata) { output_data->push_back(odata); }
public:
  Csv2JsonPlugin(char row_sep, char col_sep, char text_sep, int max);
  Csv2JsonPlugin(char col_sep, char text_sep, int max);
  Csv2JsonPlugin(char text_sep, int max);
  Csv2JsonPlugin(int max);
  Csv2JsonPlugin();
  ~Csv2JsonPlugin();
  // Getters
  ifstream * GetInputStream() const { return input_fd; }
  vector<string> * GetOutputData() const { return output_data; }
  char GetRowSeparator() const { return row_separator; }
  char GetColSeparator() const { return col_separator; }
  char GetTextSeparator() const { return text_separator; }
  int GetMaxCellLength() const { return max_cell_length; }
  int_fast8_t GetKeys() const { return keys; }
  // Setters
  void SetInputStream(ifstream *d) { input_fd = d; }
  void SetOutputData(vector<string> *s) { output_data = s; }
  void SetRowSeparator(char r) { row_separator = r; }
  void SetColSeparator(char c) { col_separator = c; }
  void SetTextSeparator(char t) { text_separator = t; }
  void SetMaxCellLength(int m) { max_cell_length = m; }
  void SetKeys(int_fast8_t k) { keys = k; }
  // Implementing Plugin interface
  void input(string filename);
  void run();
  void output(string filename);
};
#endif
