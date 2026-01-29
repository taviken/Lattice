#include <iostream>
#include <stdexcept>

#include "Window.h"

int main()
{
    Window app;

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}