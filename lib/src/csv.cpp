#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#include "csv.h"
#include "neuron.h"
#include "network.h"

float_matrix read_img(vector<char> &row)
{
    float_matrix out;
    size_t j = 0;
    char* int_string;
    float val;
    for (size_t i = 0; i < row.size(); ++i)
    {
        if (row[i] == '"')
        {
            while (row[i++] != '"');
        }
        if (row[i] == ','){
            int_string = "";
            memcpy(&int_string, &row[j], i);
            val = strtof(int_string, (&int_string + i));
            out.push_back(val);
        }
    }
    return out;
}

vector<float_matrix> read_csv(const char *filepath)
{
    fstream fptr;
    fptr.open(filepath, ios::in);
    vector<char> row;
    char* temp;
    while(fptr >> temp)
    {

    }


}