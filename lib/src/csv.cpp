#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#include "../include/csv.h"
#include "../include/neuron.h"
#include "../include/network.h"

namespace CSV{

    float_matrix read_col(string &col){
        float_matrix out;
        char* temp;
        float val;
        size_t j = 0;
        for (size_t i = 0; i< col.size(); ++i){
            
            while (col[i] != ',')
            {
                continue;
            }
            temp = "";
            val = strtof(temp, (char**)(&temp + sizeof(temp)));
            out.push_back(val);
        }
        return out;
    }

    vector<float_matrix> read_img(string &img)
    {
        vector<float_matrix> out;
        size_t j = 0;
        string val;
        for (size_t i = 0; i < img.size(); ++i)
        {
            if (img[i + 1] == ',')
            {
                val = "";
                memcpy(&val, &img[j], i);
                memcpy(&i, &j, sizeof(i));
                out.push_back(read_col(val));
            }
        }
        return out;
    }

    vector<vector<float_matrix>> read_csv(const char* filepath)
    {
        cout << "Hello2" << endl;
        vector<vector<float_matrix>> out;
        fstream fptr;
        fptr.open(filepath, ios::in);
        cout << "Hello3" << endl;
        vector<char> row;
        string temp, img;
        while(fptr >> temp)
        {
            row.clear();
            getline(fptr, img);
            size_t j = 0;
            for (size_t i = 0; i < img.size(); ++i)
            {
                if (img[i] == '"')
                {
                    j++;
                    while (img[i++] != '"');
                    i--;
                }
                if (img[i + 1] == ',' || img[i + 1] == '"')
                {
                    cout << "Hello4" << endl;
                    temp.erase();
                    cout << "Hello5" << endl;
                    memcpy(&temp, &img[j], i);
                    memcpy(&j, &i, sizeof(j));
                    out.push_back(read_img(temp));
                    cout << "Hello6" << endl;
                }
            }
        }
        return out;
    }

}