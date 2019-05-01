#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#include "../include/csv.h"
#include "../include/neuron.h"
#include "../include/network.h"

namespace CSV
{

    float_matrix read_col(string &col)
    {
        cout << "Greetings1" << endl;
        float_matrix out;
        char* col_val;
        strcpy(col_val, col.c_str());
        char* str_val;
        float val;
        size_t j = 0;
        for (size_t i = 0; i < col.size(); ++i)
        {
            cout << "Greetings2" << endl;
            while (col[i] != ',')
            {
                continue;
            }
            for (int k = j; k < i; ++k)
            {
                str_val;
            }
            val = strtof(str_val, (char**)(&str_val + sizeof(str_val)));
            out.push_back(val);
        }
        return out;
    }

    vector<float_matrix> read_img(string &img)
    {
        cout << "Welcome1" << endl;
        cout << "imgsize: " << img.size() << endl;
        vector<float_matrix> out;
        size_t j = 0;
        string val;
        cout << "Welcome2" << endl;
        for (size_t i = 0; i < img.size(); ++i)
        {
            if (img[i] == ',')
            {
                cout << "Welcome3" << endl;
                val.clear();
                for (int k = j; k < i; ++k)
                {
                    cout << "pushing " << img[k] << endl;
                    val.push_back(img[k]);
                }
                memcpy(&i, &j, sizeof(i));
                cout << "Welcome4" << endl;
                out.push_back(read_col(val));
            }
            // cout << "Welcome4" << endl;
        }
        return out;
    }

    vector<vector<float_matrix>> read_csv(char* filepath)
    {
        // cout << filepath << endl;
        cout << sizeof(filepath) << endl;
        cout << "Hello2" << endl;
        vector<vector<float_matrix>> out;
        vector<char> row;
        string temp, img;
        size_t j;

        fstream fptr;
        fptr.open(filepath, ios::in);

        cout << "Hello3" << endl;

        while(fptr >> temp)
        {
            j = 0;
            cout << "Hello4" << endl;

            row.clear();

            cout << "Hello4.1" << endl;

            getline(fptr, img);

            cout << "img: " << img << ", temp: " << temp << endl;

            for (size_t i = 0; i < img.size(); ++i)
            {
                cout << "Image " << i << ": " << img[i] << endl;
                if (img[i] == '"')
                {
                    j++;
                    while (true)
                    {
                        ++i;
                        cout << "Skipping: " << img[i] << endl;
                        if (img[i] == '"')
                        {
                            break;
                        }
                    }
                    i--;
                }
                if (img[i + 1] == ',' || img[i + 1] == '"')
                {
                    cout << "Hello5" << endl;
                    temp.erase(); // seg fault second time round
                    cout << "Hello6" << endl;
                    for (int k = j; k <= i; ++k)
                    {
                        cout << "pushing!" << img[k] << endl;
                        temp.push_back(img[k]);
                    }
                    memcpy(&j, &i, sizeof(j));
                    cout << "value: " << img << endl;
                    out.push_back(read_img(temp));
                    cout << "Hello7" << endl;
                }
            }
        }
        cout << "While over" << endl;
        return out;
    }

}