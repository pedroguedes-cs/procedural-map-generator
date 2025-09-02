#pragma once 

#include <string>

#include "map.hpp"

std::string normalize_float(std::string number);

bool is_integer(std::string number);

bool is_float(std::string number);

int read_choice();

int read_lines();

int read_columns();

float read_shade();

float read_roughness();

Map read_map();

int read_palette_choice();

