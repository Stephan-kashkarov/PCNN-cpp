#pragma once
#include "neuron.h"
#include "network.h"
#include <vector>

using namespace std;

typedef vector<PCNN::Neuron> neuron_matrix;
typedef vector<float> float_matrix;

namespace PCNN {

    struct layer {

        // Layer linking
        layer* next;

        // outputs
        vector<float_matrix > output;
        vector<float_matrix > prevoutput;
        
        // Size defenition
        size_t size_x;
        size_t size_y;

        //neurons
        vector<neuron_matrix> neurons;

    };
    
    vector<float_matrix> update_layer(layer*, vector<float_matrix>&, size_t, size_t);
}