// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "../src/csv2json.h"
#include <fstream>

TEST_CASE("Plugin loads with all correct constuctor values",
  "[pluma-plugin-csv2json]")
{
  Csv2JsonPlugin *plugin = new Csv2JsonPlugin;

  REQUIRE(plugin->GetRowSeparator() == ',');
  REQUIRE(plugin->GetColSeparator() == '\n');
  REQUIRE(plugin->GetTextSeparator() == '"');
  REQUIRE(plugin->GetMaxCellLength() == 100000);
  REQUIRE(plugin->GetKeys() == 0);
}

TEST_CASE("Plugin can load CSV file", "[pluma-plugin-csv2json]") {
  Csv2JsonPlugin *plugin = new Csv2JsonPlugin;
  REQUIRE_NOTHROW(plugin->input("test/test.csv"));
}

TEST_CASE("Plugin runs through the resource file", "[pluma-plugin-csv2json]") {
  Csv2JsonPlugin *plugin = new Csv2JsonPlugin;
  ifstream *input = new ifstream("test/test.csv");
  vector<string> *expected = new vector<string>;

  plugin->SetInputStream(input);
  expected->push_back("foo,bar,baz,\"foo bar\"\n");
  expected->push_back("hello,1,100000000000,\"bar baz\"");

  REQUIRE(expected->size() == 2);

  REQUIRE_NOTHROW(plugin->run());

  vector<string> *output = plugin->GetOutputData();

  REQUIRE(output->size() != 0);
  REQUIRE(plugin->GetKeys() == 4);
  REQUIRE(plugin->GetOutputData() == expected);
}
