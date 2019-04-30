#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include "neuron.h"

using namespace std;
using namespace PCNN;

namespace CSV {
    // TODO: vector<string> read_title(const char* row);
    float_matrix read_col(string &col);
    vector<float_matrix> read_img(const char *row);
    vector<vector<float_matrix>> read_csv(const char *filepath);
}

