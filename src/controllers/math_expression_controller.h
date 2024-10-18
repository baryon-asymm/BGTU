#pragma once

class IParsedObjectRouter;

class IParsedObjectVisitor;
class IParsedNumberVisitor;
class IParsedOperatorVisitor;

class ParsedObject;
class ParsedNumber;
class ParsedOperator;

class ParsedAdditionOperator;
class ParsedDivisionOperator;
class ParsedMultiplyOperator;
class ParsedSubtractionOperator;

class BaseBinaryOperator;
class BaseOperand;
class Number;

class MathExpressionController : public IParsedObjectRouter, public IParsedObjectVisitor, public IParsedNumberVisitor, public IParsedOperatorVisitor {
private:
    const int empty_operation_rank_ = -1;
    int current_operation_rank_ = empty_operation_rank_;

    std::unique_ptr<BaseBinaryOperator> root_binary_operation_;

    std::unique_ptr<BaseBinaryOperator> tmp_binary_operation_;
    std::unique_ptr<Number> tmp_number_;

    void HandleOperation(std::unique_ptr<BaseBinaryOperator> operation, int operation_rank);

public:
    void Route(std::unique_ptr<ParsedObject> parsed_object) override;

    void Visit(const ParsedOperator& parsed_operator) override;
    void Visit(const ParsedNumber& parsed_number) override;

    void Visit(const ParsedAdditionOperator& parsed_addition_operator) override;
    void Visit(const ParsedDivisionOperator& parsed_division_operator) override;
    void Visit(const ParsedMultiplyOperator& parsed_multiply_operator) override;
    void Visit(const ParsedSubtractionOperator& parsed_subtraction_operator) override;

    std::unique_ptr<INode> GetRootNode();
};
