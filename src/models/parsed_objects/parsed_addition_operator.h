#pragma once

class ParsedOperator;
class IParsedOperatorVisitor;

class ParsedAdditionOperator : public ParsedOperator {
public:
    const int GetRank() const override { return 1; }

    void Accept(IParsedOperatorVisitor& visitor) const override;
};
