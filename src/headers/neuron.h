#pragma once
#include <stdio.h>
#include <vector>
#include <cstdint>

using namespace std;

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
        float feed_weights[3][3];
        float link_weights[3][3];

        
    };
    

    class Neuron {

        private:

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

            // Main internal variables
            float feed;                // F
            float link;                // L
            float internal_activation; // U
            float threshold;           // T
            float sigmoid_activation;  // Y
            bool binary_activation;    // Y

            // matricies
            float feed_weights[3][3];
            float link_weights[3][3];
            float inputs[3][3];

            // Misc
            int link_sum;
            int feed_sum;

        public:

            // Functuons
            Neuron(neuron);
            void populate(float **layer, size_t rows, size_t cols);
            float calculate(void);
            bool get_output_bool(void);
            float get_output_sig(void);
    };

}