#include <vector>
#include <cstdint>
#include <cstring>
#include <bits/stdc++.h>

#include "neuron.h"
#include "network.h"

using namespace std;
using namespace PCNN;

Neuron::Neuron(neuron input) {
    i = input.i;
    j = input.j;

    feed_decay = exp(-input.feed_decay);
    link_decay = exp(-input.link_decay);
    thre_decay = exp(-input.thre_decay);

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

    memcpy(&feed_weights, &input.feed_weights, sizeof(feed_weights));
    memcpy(&link_weights, &input.link_weights, sizeof(link_weights));

    stimulus = input.stimulus;
}

void Neuron::populate(vector<float_matrix> layer, size_t rows, size_t cols)
{
    for (size_t y = i - 1; y < i + 1; ++y)
    {
        // ensure no segfaults
        if (y >= rows)
        {
            --y;
        } else if (y < 0)
        {
            ++y;
        }

        for (size_t x = j - 1; x < j + 1; ++x)
        {
            // ensure no segfaults
            if (x >= cols)
            {
                --x;
            }
            else if (x < 0)
            {
                ++x;
            }

            // update value
            inputs[y - i][x - j] = layer[y][x];
        }
    }
}

float Neuron::calculate(void){
    
    // multiplies and sums two arrays
    feed_sum = 0;
    link_sum = 0;

    for (size_t y = 0; y < 3; ++y)
    {
        for (size_t x = 0; x < 3; ++x)
        {
            feed_sum += inputs[y][x] * feed_weights[y][x];
            link_sum += inputs[y][x] * link_weights[y][x];
        }
    }

    feed = (feed_decay * feed) + (feed_amp * feed_sum) + stimulus;
    link = (link_decay * link) + (link_amp * link_sum);

    internal_activation = feed + (1 + (bias * link));

    threshold = (thre_decay * threshold) + (thre_amp * binary_activation);

    binary_activation = (internal_activation > threshold);
    sigmoid_activation = 1/(1 + exp(step * (internal_activation - threshold)));
    return sigmoid_activation;
}