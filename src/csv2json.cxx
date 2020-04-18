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
}

/**
 */
void Csv2JsonPlugin::input(std::string filename) {
  ifstream csv_file(filename);
  if (!csv_file) {
    perror("Csv2Json input: ");
    exit(Status::ERROR_INVALID_INPUT);
  }
  SetInputStream(&csv_file);
}

/**
 */
void Csv2JsonPlugin::run() {
  ifstream *csv_file = GetInputStream();
  string idata, cell_content, current, next;
  char right_row_delimiter[2], left_row_delimiter[2];
  vector<string> odata;
  int_fast32_t col = 0, known_keys = 0;
  int_fast16_t keys_number, keys_parsed = 0;
  uint_fast64_t to_read = 0;
  int_fast16_t cell_with_sep = 0;
  int_fast16_t cell_without_sep = 0;
  int_fast16_t row_begin_parsed = 0;
  char null = '\0';

  try {

    keys_number = 0;

    right_row_delimiter[1] = '\0';
    left_row_delimiter[1] = '\0';


    if (keys_number) {
      left_row_delimiter[0] = '{';
      right_row_delimiter[0] = '}';
    } else {
      left_row_delimiter[0] = '[';
      right_row_delimiter[0] = ']';
    }

    /*
      for getline in ifstream to input_data buffer {
        manipulate the data to a JSON string
        save the line to the output_data buffer
      }

      save the output_data buffer to the class
    */

    for(int i = 0; i <= 100; i++) {

    }

  } catch (...) {

  }

  csv_file->close();
}

/**
 */
void Csv2JsonPlugin::output(std::string filename) {
  ofstream json_file(filename);
  if (!json_file) {
    perror("Csv2Json output: ");
    exit(Status::ERROR_INVALID_OUTPUT);
  }

  vector<string> data = GetOutputData();

  for (uint_fast16_t i = 0; i < data.size(); i++) {
    json_file << data.at(i);
  }

  json_file.close();
}
