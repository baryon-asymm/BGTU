#pragma once

class INode;

class BaseOperand : public INode {
protected:
    double value;

public:
    BaseOperand(double value) : value(value) {}

    virtual double GetValue() const = 0;
};
