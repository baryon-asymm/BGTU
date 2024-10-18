#pragma once

class ParsedOperator;
class ParsedNumber;

class IParsedObjectVisitor {
public:
    virtual ~IParsedObjectVisitor() = default;

    virtual void Visit(const ParsedOperator& parsed_operator) = 0;
    virtual void Visit(const ParsedNumber& parsed_number) = 0;
};
