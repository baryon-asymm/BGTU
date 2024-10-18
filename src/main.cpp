#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "../include/ConsoleCalculator/i_calculator.h"

#include "calculator.h"

int main() {
    try
    {
        std::string str;
        std::cout << "Enter math expression: ";
        std::getline(std::cin, str);

        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

        auto calculator = std::make_unique<Calculator>();

        std::cout << "Result: " << calculator->Evaluate(str) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
