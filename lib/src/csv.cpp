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

    vector<vector<float_matrix>> read_csv(char* filepath)
    {
        // cout << filepath << endl;
        cout << sizeof(filepath) << endl;
        cout << "Hello2" << endl;
        vector<vector<float_matrix>> out;
        fstream fptr;
        fptr.open(filepath, ios::in);
        vector<char> row;
        string temp, img;
        cout << "Hello3" << endl;
        do
        {
            cout << "Hello4" << endl;
            row.clear();
            cout << "Hello4.1" << endl;
            getline(fptr, img);
            cout << "img: " << img << ", temp: " << temp << endl;
            size_t j = 0;
            for (size_t i = 0; i < img.size(); ++i)
            {
                cout << "Image " << i << ": " << img[i] << endl;
                if (img[i] == '"')
                {
                    cout << "A" << endl;
                    j++;
                    do{
                        ++i;
                        cout << "Skipping: " << img[i] << endl;
                        if (img[i] == '"')
                        {
                            break;
                        }
                    } while (true);
                    i--;
                }
                if (img[i + 1] == ',' || img[i + 1] == '"')
                {
                    cout << "B" << endl;
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
        } while(fptr >> temp);
        cout << "While over" << endl;
        return out;
    }

}