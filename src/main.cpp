#include <iostream>
#include "Engine.hpp"


int main()
{
    std::cout << "This is the first line of the program. \n";
    Engine engine = Engine();
    std::cout << "Started engine from entry point [int main()].\n";
    engine.run();
    return 0;
}