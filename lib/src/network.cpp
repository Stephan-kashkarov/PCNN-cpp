#include "neuron.h"
#include "network.h"
#include <cstring>

using namespace std;
using namespace PCNN;

vector<float_matrix> PCNN::update_layer(layer *row, vector<float_matrix> &inputs, size_t y, size_t x)
{
    // Shifts row pos
    for (uint i = 0; i < row->output.size(); ++i)
    {
        float_matrix& src = row->output[i];
        float_matrix& dest = row->prevoutput[i];
        copy(src.begin(), src.end(), dest.begin());
    }

    for (size_t k = 0; k < y; ++k)
    {
        for (size_t l = 0; l < x; ++l)
        {
            row->neurons[k][l].populate(inputs, y, x);
            row->output[k][l] = row->neurons[k][l].calculate();
        }
    }
    if (!(row->next))
    {
        return row->output;
    }
    return update_layer(row->next, row->output, row->size_y, row->size_y);
}