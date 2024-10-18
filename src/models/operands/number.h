#pragma once

class BaseOperand;

class Number : public BaseOperand {
public:
    virtual ~Number() = default;
    Number(double value) : BaseOperand(value) {}

    double GetValue() const override;
};
