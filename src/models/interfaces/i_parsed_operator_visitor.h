#pragma once

class ParsedAdditionOperator;
class ParsedDivisionOperator;
class ParsedMultiplyOperator;
class ParsedSubtractionOperator;

class IParsedOperatorVisitor {
public:
    virtual ~IParsedOperatorVisitor() = default;
    
    virtual void Visit(const ParsedAdditionOperator& parsed_addition_operator) = 0;
    virtual void Visit(const ParsedDivisionOperator& parsed_division_operator) = 0;
    virtual void Visit(const ParsedMultiplyOperator& parsed_multiply_operator) = 0;
    virtual void Visit(const ParsedSubtractionOperator& parsed_subtraction_operator) = 0;
};
