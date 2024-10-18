#pragma once

#include <memory>

class INode;
class BaseBinaryOperator;

class AdditionOperator : public BaseBinaryOperator {
public:
    AdditionOperator() = default;

    AdditionOperator(std::unique_ptr<INode> left, std::unique_ptr<INode> right)
        : BaseBinaryOperator(std::move(left), std::move(right)) {}

    double GetValue() const override;
};
