// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#pragma once

#ifndef _JSON2CSV_H
#define _JSON2CSV_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <iostream>
#include <fstream>
#include "PluginManager.h"
#include "PluMA.h"

// Versioning
#define PLUGIN_VERSION = "0.1.0"

// Return codes
enum Status {
  SUCCESS = 0,
  ERROR_BAD_ARG = 1,
  ERROR_INVALID_INPUT = 2,
  ERROR_INVALID_OUTPUT = 3,
  ERROR_MEM = 4,
  ERROR_FILE_READ = 5,
  ERROR_CELL_LENTH = 6,
  ERROR_ENCODING = 7
};

/**
  The Csv2Json plugin class.
*/
class Csv2JsonPlugin: public Plugin {
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
  std::string GetInputFD() const { return input_fd; }
  std::string GetOutputFD() const { return output_fd; }
  char GetRowSeparator() const { return row_separator; }
  char GetColSeparator() const { return col_separator; }
  char GetTextSeparator() const { return text_separator; }
  int GetMaxCellLength() const { return max_cell_length; }
  unsigned char GetEscape() const { return escape; }
  short int GetKeys() const { return keys; }
  // Setter methods.
  void SetInputFD(std::string filename);
  void SetOutputFD(std::string filename);
  // Inline setter methods
  void SetRowSeparator(char r) { row_separator = r; };
  void SetColSeparator(char c) { col_separator = c; };
  void SetTextSeparator(char t) { text_separator = t; };
  void SetMaxCellLength(int m) { max_cell_length = m; };

private:
  std::string input_fd;
  std::string output_fd;
  char row_separator;
  char col_separator;
  char text_separator;
  int max_cell_length;
  unsigned char escape;
  short int keys;
  int parse_file();
};

#endif
