#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

class PythonInterpreter
{
private:
    py::scoped_interpreter guard; // Manages the interpreter's lifetime

public:
    PythonInterpreter()
    {
        // Interpreter is initialized when guard is constructed
        std::cout << "Python interpreter initialized." << std::endl;
    }

    ~PythonInterpreter()
    {
        // Interpreter is shut down when guard is destroyed
        std::cout << "Python interpreter shut down." << std::endl;
    }

    void runPythonClassExample()
    {
        try
        {
            // Add current directory to Python path so it finds python_script.py
            py::module_ sys = py::module_::import("sys");
            sys.attr("path").attr("insert")(0, ".");

            // Import the module and get the class
            py::module_ script = py::module_::import("example_class");
            py::object pythonClass = script.attr("PythonClass");

            // Instantiate the Python class from C++
            py::object instance = pythonClass("World");

            // Call a method and cast the result
            py::object greeting = instance.attr("greet")();
            std::string result = greeting.cast<std::string>();
            std::cout << "Result of Python greet() method: " << result << std::endl;

            // Call another method with arguments
            py::object sum = instance.attr("add")(10, 20);
            int sum_result = sum.cast<int>();
            std::cout << "Result of Python add() method: " << sum_result << std::endl;
        }
        catch (const py::error_already_set &e)
        {
            PyErr_Print(); // Print Python errors
        }
    }
};