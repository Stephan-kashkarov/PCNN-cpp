#include <iostream>
#include <stdlib.h>

#include "network.h"
#include "neuron.h"

using namespace std;
using namespace PCNN;

bool input_provided = false;
vector<float_matrix> input;
layer root;
long layers;


layer* gen_layer(vector<float_matrix>& inputs, bool base)
{

}

int main(int argc, const char *argv[])
{
    size_t i = -1;
    while (++i <= argc)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'j')
            {
                input_provided = true;
                input = get_json(argv[i + 1]);
            }
            else if (argv[i][1] == 'l')
            {
                layers = strtol(argv[i + 1], NULL, 10);
            }
            else if (argv[i][1] == 'h')
            {
                cout << "Options:\n '-j' -> Json filepath\n '-l' -> num of layers excluding root\n '-h' -> this text" << endl;
                return 0;
            }
            else if (argv[i][1] == '-')
            {
                size_t j = -1;
                while (argv[i+1])
                {
                    break;
                }
            }
        }
    }

    if (!(input_provided))
    {
        cout << "Please provide input. To see options run `./pcnn -h`" << endl;
        return 0;
    }
}
