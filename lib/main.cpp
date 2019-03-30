#include <iostream>
#include <stdlib.h>

#include "network.h"
#include "neuron.h"

using namespace std;
using namespace PCNN;

bool input_provided = false;
vector<float_matrix> input;
layer root;
long cols;

vector<float_matrix> get_json(const char* filepath)
{

}

layer* gen_layer(vector<float_matrix>& inputs, bool base)
{

}

int main(int argc, const char *argv[])
{
    

    for (size_t i = 1; i < argc; i += 2)
    {
        if (argv[i] == "-j")
        {
            input_provided = true;
            input = get_json(argv[i+1]);
        }
        else if (argv[i] == "-c")
        {
            cols = strtol(argv[i+1], NULL, 10);
        }
        else if (argv[i] == "-h")
        {
            cout << "Options:\n'-j' ~ Json filepath\n'-c' ~ num of cols excluding root\n '-h' ~ this text" << endl;
            return 0;
        }
    }

    if (!(input_provided))
    {
        cout << "Please provide input. To see options run `./pcnn -h`" << endl;
        return 0;
    }
}
