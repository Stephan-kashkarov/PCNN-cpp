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

        // Main internal variables
        float feed;                // F
        float link;                // L
        float internal_activation; // U
        float threshold;           // T
        float sigmoid_activation;  // Y
        bool binary_activation;    // Y

        // matricies
        vector<vector<float>> feed_weights;
        vector<vector<float>> link_weights;
    };
    

    class Neuron {

        private:

            // Positionals
            uint8_t i;
            uint8_t j;
            
            // Main internal constants 
            const float feed_decay;
            const float link_decay;
            const float thre_decay;

            const float feed_amp;
            const float link_amp;
            const float thre_amp;

            const uint8_t step;
            const uint8_t bias;

            // Main internal variables
            float feed;                // F
            float link;                // L
            float internal_activation; // U
            float threshold;           // T
            float sigmoid_activation;  // Y
            bool binary_activation;    // Y

            // matricies
            float[float[]] feed_weights;
            vector<vector<float>> link_weights;

            vector<vector<float>> inputs;

        public:

            // Functuons
            void populate(vector<vector<float>>);
            float calculate(void);
            bool get_output_bool(void);
            float get_output_sig(void);
    };

}