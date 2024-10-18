#pragma once

#include <memory>

class INode;
class BaseBinaryOperator;

class MultiplyOperator : public BaseBinaryOperator {
public:
    MultiplyOperator() = default;

    MultiplyOperator(std::unique_ptr<INode> left, std::unique_ptr<INode> right)
        : BaseBinaryOperator(std::move(left), std::move(right)) {}

    double GetValue() const override;
};
