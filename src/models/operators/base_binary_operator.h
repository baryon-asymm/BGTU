#pragma once

#include <memory>

class INode;

class BaseBinaryOperator : public INode {
protected:
    std::unique_ptr<INode> left;
    std::unique_ptr<INode> right;

public:
    BaseBinaryOperator() = default;

    BaseBinaryOperator(std::unique_ptr<INode> left, std::unique_ptr<INode> right)
        : left(std::move(left)), right(std::move(right)) {}

    std::unique_ptr<INode> GetLeft() { return std::move(left); }
    std::unique_ptr<INode> GetRight() { return std::move(right); }

    void SetLeft(std::unique_ptr<INode> left) { this->left = std::move(left); }
    void SetRight(std::unique_ptr<INode> right) { this->right = std::move(right); }

    virtual double GetValue() const = 0;
};
