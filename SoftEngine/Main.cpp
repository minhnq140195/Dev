#include <iostream>
#include "SDL.h"
using namespace std;

int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
        cout << "Hello world!" << endl;
    return 0;
}
