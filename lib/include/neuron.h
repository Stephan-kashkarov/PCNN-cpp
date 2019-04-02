#pragma once
#include <stdio.h>
#include <vector>
#include <cstdint>
#include <array>
#include "neuron.h"

using namespace std;

typedef array<float, 3> float_array;

namespace PCNN {

    struct neuron
    {
        uint8_t i;
        uint8_t j;

        // Main internal constants
        float feed_decay;
        float link_decay;
        float thre_decay;
        float feed_amp;
        float link_amp;
        float thre_amp;
        uint8_t step;
        uint8_t bias;
        float stimulus;

        // Main internal variables
        float feed;                // F
        float link;                // L
        float internal_activation; // U
        float threshold;           // T
        float sigmoid_activation;  // Y
        bool binary_activation;    // Y

        // matricies
        array<float_array, 3> feed_weights;
        array<float_array, 3> link_weights;

        
    };
    

    class Neuron {

        private:
            // matricies
            array<float_array, 3> feed_weights; // 2D 3x3 array of floats
            array<float_array, 3> link_weights; // 2D 3x3 array of floats
            array<float_array, 3> inputs;       // 2D 3x3 array of floats

            // Main internal variables
            float feed;                // F
            float link;                // L
            float internal_activation; // U
            float threshold;           // T
            float sigmoid_activation;  // Y
            bool binary_activation;    // Y

            // Positionals
            uint8_t i;
            uint8_t j;
            
            // Main internal consts 
            float feed_decay;
            float link_decay;
            float thre_decay;
            float feed_amp;
            float link_amp;
            float thre_amp;
            uint8_t step;
            uint8_t bias;
            float stimulus;

            // Misc
            int link_sum;
            int feed_sum;

        public:
            // Functuons
            Neuron(neuron);
            void populate(vector<float_matrix>layer, size_t rows, size_t cols);
            float calculate(void);
    };

}