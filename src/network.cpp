#include <headers/neuron.h>
#include <headers/network.h>
#include <cstring>

using namespace std;
using namespace PCNN;

float** get_inputs(layer row, size_t& y, size_t& x)
{
    return row.prev->output;
}

void update_layer(layer* row)
{
    size_t y;
    size_t x;

    float** inputs = get_inputs(*row, &y, &x);

    // Shifts row pos
    memcpy(row->prev, row->output, sizeof(&row->output));

    for (size_t k = 0; k < y; ++k)
    {
        for (size_t l = 0; l < x; ++l)
        {
            row->neurons[k][l].populate(inputs, y, x);
            row->output[k][l] = row->neurons[k][l].calculate();
        }
    }
}