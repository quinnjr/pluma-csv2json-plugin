// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#include "csv2json.h"

using namespace std;

/**
  Highly customizable constructor for the Csv2Json plugin. Allows for complete
  control of all attributes of the Csv2JsonPlugin class, which allows for
  use of the plugin as a generic Delimiter-separated file to JSON file plugin.

  As a trade-off, a greater number of parameters cannot be assumed to be
  CSV defaults.
*/
Csv2JsonPlugin::Csv2JsonPlugin(char row_sep, char col_sep, char text_sep,
  int max, unsigned char esc)
{
  row_separator = row_sep;
  col_separator = col_sep;
  text_separator = text_sep;
  max_cell_length = max;
  escape = esc;
  input_fd = (ifstream *) malloc(sizeof(ifstream *));
  output_data =(string *) malloc(sizeof(string *));
}

Csv2JsonPlugin::Csv2JsonPlugin(char col_sep, char text_sep, int max,
  unsigned char esc)
{
  Csv2JsonPlugin(',', col_sep, text_sep, max, esc);
}

Csv2JsonPlugin::Csv2JsonPlugin(char text_sep, int max, unsigned char esc) {
  Csv2JsonPlugin(',', '\n', text_sep, max, esc);
}

Csv2JsonPlugin::Csv2JsonPlugin(int max, unsigned char esc) {
  Csv2JsonPlugin(',', '\n', '"', max, esc);
}

Csv2JsonPlugin::Csv2JsonPlugin(unsigned char esc) {
  Csv2JsonPlugin(',', '\n', '"', 100000, esc);
}

/**
  Default constructor. Assumes all common CSV values for class attributes.
*/
Csv2JsonPlugin::Csv2JsonPlugin() {
  Csv2JsonPlugin(',', '\n', '"', 100000, 0);
}

Csv2JsonPlugin::~Csv2JsonPlugin() {
  free(input_fd);
  free(output_data);
}

/**
 */
void Csv2JsonPlugin::input(std::string filename) {
  ifstream csv_file(filename);
  if (!csv_file) perror("Csv2Json input: ");
  SetInputStream(&csv_file);
}

/**
 */
void Csv2JsonPlugin::run() {
  ifstream *csv_file = GetInputStream();
  string input_data, output_data;
  try {

  } catch (...) {

  }
  /*
    for getline in ifstream to input_data buffer {
      manipulate the data to a JSON string
      save the line to the output_data buffer
    }

    save the output_data buffer to the class
  */

  csv_file->close();
}

/**
 */
void Csv2JsonPlugin::output(std::string filename) {
  ofstream json_file(filename);
  if (!json_file) perror("Csv2Json output: ");

  string *data = GetOutputData();

  json_file << *data;

  json_file.close();
}
