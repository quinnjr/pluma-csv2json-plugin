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
  int max)
{
  row_separator = row_sep;
  col_separator = col_sep;
  text_separator = text_sep;
  max_cell_length = max;
  input_fd = new ifstream;
  output_data = new vector<string>;
  keys = new vector<string>;
}

Csv2JsonPlugin::Csv2JsonPlugin(char col_sep, char text_sep, int max) {
  row_separator = ',';
  col_separator = col_sep;
  text_separator = text_sep;
  max_cell_length = max;
  input_fd = new ifstream;
  output_data = new vector<string>;
  keys = new vector<string>;
}

Csv2JsonPlugin::Csv2JsonPlugin(char text_sep, int max) {
  row_separator = ',';
  col_separator = '\n';
  text_separator = text_sep;
  max_cell_length = max;
  input_fd = new ifstream;
  output_data = new vector<string>;
  keys = new vector<string>;
}

Csv2JsonPlugin::Csv2JsonPlugin(int max) {
  row_separator = ',';
  col_separator = '\n';
  text_separator = '"';
  max_cell_length = max;
  input_fd = new ifstream;
  output_data = new vector<string>;
  keys = new vector<string>;
}

/**
  Default constructor. Assumes all common CSV values for class attributes.
*/
Csv2JsonPlugin::Csv2JsonPlugin() {
  row_separator = ',';
  col_separator = '\n';
  text_separator = '"' ;
  max_cell_length = 100000;
  keys = 0;
  input_fd = new ifstream;
  output_data = new vector<string>;
  keys = new vector<string>;
}

Csv2JsonPlugin::~Csv2JsonPlugin() {
}

/**
 */
void Csv2JsonPlugin::input(std::string filename) {
  ifstream *csv_file = new ifstream(filename);
  if (!csv_file) {
    perror("Csv2Json input: ");
    throw;
  }
  SetInputStream(csv_file);
}

/**
 */
void Csv2JsonPlugin::run() {
  string idata, current, next;
  int_fast32_t col = 0;
  int_fast16_t keys_parsed = 0, cell_with_sep = 0,
    cell_without_sep = 0, row_begin_parse = 0;

  try {
    /*
      for getline in ifstream to input_data buffer {
        regex ([a-zA-Z0-9"\s]+) for column data.
        if it's the first row {
          set keys
        } else {
          manipulate the data to a JSON string
        }
        save the line to the output_data buffer
      }

      save the output_data buffer to the class
    */
    string re = "([a-zA-Z0-9\\s";
    re.push_back(text_separator);
    re.append("]+)");
    regex matchable(re, regex::optimize);

    while (getline(*input_fd, idata, col_separator)) {
      smatch sm;
      if(regex_match(idata, sm, matchable)) {
        // If we're extracting the keys from the tablular dataset.
        if (col == 0) {
          // The size of the vector of initial keys is the number of keys to expect.
          SetKeys(sm.size());
          col++;
          // Push the opening array bracket.
          push_output("[");
        } else {
          // parse each match as a key-value pair of output strings.
        }
      }
    }

    input_fd->close();
    // Push the closing array bracket.
    push_output("]");

  } catch (const exception &e) {
    throw;
  }
}

/**
 */
void Csv2JsonPlugin::output(std::string filename) {
  ofstream json_file(filename);

  if (!json_file) {
    perror("Csv2Json output: ");
    throw;
  }

  vector<string> *data = GetOutputData();

  for(vector<string>::iterator it = data->begin(); it != data->end(); it++) {
    json_file << *it;
  }

  json_file.close();
}
