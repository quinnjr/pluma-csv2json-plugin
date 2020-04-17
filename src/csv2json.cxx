// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#include "csv2json.h"

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

}

Csv2JsonPlugin::Csv2JsonPlugin(char col_sep, char text_sep, int max, unsigned char esc) {

}

Csv2JsonPlugin(char text_sep, int max, unsigned char esc) {

}

Csv2JsonPlugin(int max, unsigned char esc) {

}

Csv2JsonPlugin(unsigned char esc) {

}

/**
  Default constructor. Assumes all common CSV values for class attributes.
*/
Csv2JsonPlugin() {

}

Csv2JsonPlugin::~Csv2JsonPlugin() {

}

void Csv2JsonPlugin::input(std::string filename) {

}

void Csv2JsonPlugin::run() {

}

void Csv2JsonPlugin::output(std::string filename) {

}

void SetInputFD(std::string filename) {

}

void SetOutputFD(std::string filename) {

}
