#pragma once
#include <neuron.h>
#include <network.h>
#include <vector>

using namespace std;

namespace PCNN {

    struct layer {

        // Layer linking
        layer* next;
        layer* prev;

        // Size defenition
        size_t size_x;
        size_t size_y;

        // outputs
        float** output;
        float** prevoutput;

        //neurons
        Neuron** neurons;

    };
    float **get_inputs(layer, size_t&, size_t&);
    void update_layer(layer*);

}