// Copyright (c) 2020 Joseph R. Quinn <quinn.josephr@protonmail.com>
// SPDX-License-Identifier: ISC

#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "../src/csv2json.h"

Csv2JsonPlugin plugin;

TEST_CASE("Plugin can load CSV file", "[pluma-plugin-csv2json]") {
  REQUIRE_NOTHROW(plugin.input("test/test.csv"));
}
