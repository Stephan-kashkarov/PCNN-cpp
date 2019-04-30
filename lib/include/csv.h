#pragma once
#include <fstream>
#include <vector>
#include "network.h"

using namespace std;
using namespace PCNN;

vector<string> read_title(const char* row);
float_matrix read_img(const char* row);
vector<float_matrix> read_csv(const char* filepath);
