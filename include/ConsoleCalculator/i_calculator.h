#pragma once

#include <string>

class ICalculator {
public:
    virtual double Evaluate(const std::string& math_expression) = 0;
};
