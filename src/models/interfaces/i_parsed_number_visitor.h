#pragma once

class ParsedNumber;

class IParsedNumberVisitor {
public:
    virtual ~IParsedNumberVisitor() = default;

    virtual void Visit(const ParsedNumber& parsed_number) = 0;
};
