#include <iostream>
#include <stdlib.h>

#include "include/neuron.h"
#include "include/network.h"
#include "include/csv.h"

using namespace std;
using namespace PCNN;
using namespace CSV;





layer* gen_layer(vector<float_matrix>& inputs, bool base)
{

}

int main(int argc, char* argv[])
{
    cout << "Arguments: " << argc << endl;
    for (size_t i=0; i < argc; ++i)
    {
        cout << "Arg: " << argv[i] << endl;
    }
    vector<vector<float_matrix>> input;
    layer root;
    long layers = 0;
    bool input_provided = false;

    size_t i = 0;
    

    if (argc > 1)
    {
        while (i < argc)
        {
            if (argv[i][0] == '-')
            {
                if (argv[i][1] == 'c')
                {
                    input_provided = true;
                    cout << "Hello1" << endl;
                    input = read_csv(argv[++i]);
                    cout << "exited read_csv" << endl;
                    cout << "Input: ";
                    cout << sizeof(input[0][0][0]) << endl;
                }
                else if (argv[i][1] == 'l')
                {
                    layers = strtol(argv[++i], NULL, 10);
                }
                else if (argv[i][1] == 'h')
                {
                    cout << "Options:\n '-c' -> csv filepath\n '-l' -> num of layers excluding root\n '-h' -> this text" << endl;
                    return 0;
                }
                else if (argv[i][1] == '-')
                {
                    size_t j = -1;
                    while (argv[++i])
                    {
                        break;
                    }
                }
            }
            ++i;
        }
    }
    
    if (!(input_provided) || argc <= 1)
    {
        cout << "Please provide input. To see options run `./pcnn -h`" << endl;
        return 0;
    }
    else
    {
        cout << "Creating PCNN with " << layers << " extra layers" << endl;
        cout << "Input looks like: " << input[0][0][0] << endl;
    }
}
