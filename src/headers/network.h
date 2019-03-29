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
        int16_t size_x;
        int16_t size_y;

        // outputs
        float** output;
        float** prevoutput;

        //neurons
        Neuron** neurons;

    };
    float** get_inputs(layer*);
    void update_layer(layer*);

}