#pragma once

#include <string>

class ICalculator;

class Calculator : public ICalculator {
public:
    double Evaluate(const std::string& math_expression) override;
};
