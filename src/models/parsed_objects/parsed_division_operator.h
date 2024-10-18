#pragma once

class ParsedOperator;
class IParsedOperatorVisitor;

class ParsedDivisionOperator : public ParsedOperator {
public:
    const int GetRank() const override { return 2; }
    
    void Accept(IParsedOperatorVisitor& visitor) const override;
};
