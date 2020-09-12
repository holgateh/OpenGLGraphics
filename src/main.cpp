#include <iostream>
#include "Engine.hpp"

int main()
{
    Engine engine;
    std::cout << "Started engine from entry point [int main()].\n";
    engine.run();
    return 0;
}