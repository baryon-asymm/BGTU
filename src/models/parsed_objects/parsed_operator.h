#pragma once

class ParsedObject;

class IParsedOperatorVisitable;
class IParsedOperatorVisitor;

class IParsedObjectVisitor;

class ParsedOperator : public ParsedObject, public IParsedOperatorVisitable {
public:
    virtual ~ParsedOperator() = default;

    virtual const int GetRank() const = 0;

    void Accept(IParsedObjectVisitor& visitor) const override;
    virtual void Accept(IParsedOperatorVisitor& visitor) const = 0;
};
