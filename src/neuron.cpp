#include <stdio.h>
#include <vector>
#include <cstdint>

#include <headers/neuron.h>

using namespace PCNN;

Neuron::Neuron(neuron input) {
    i = input.i;
    j = input.j;

    feed_decay = input.feed_decay;
    link_decay = input.link_decay;
    thre_decay = input.thre_decay;

    feed_amp = input.feed_amp;
    link_amp = input.link_amp;
    thre_amp = input.thre_amp;

    step = input.step;
    bias = input.bias;

    feed = input.feed;
    link = input.link;
    internal_activation = input.internal_activation; 
    threshold = input.threshold;
    sigmoid_activation = input.sigmoid_activation;
    binary_activation = input.binary_activation;


    feed_weights = *input.feed_weights;
    link_weights = *input.link_weights;
}

void Neuron::populate(float **layer, size_t rows, size_t cols)
{

    for (int8_t y = i - 1; y < i + 1; ++y)
    {

        if (y >= rows)
        {
            --y;
        } else if (y < 0)
        {
            ++y;
        }

        for (int8_t x = j - 1; x < j + 1; ++x)
        {

            if (x >= cols)
            {
                --x;
            }
            else if (x < 0)
            {
                ++x;
            }

            inputs[y - i][x - j] = layer[y][x];

        }

    }

}