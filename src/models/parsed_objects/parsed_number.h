#pragma once

class ParsedObject;
class IParsedObjectVisitor;

class ParsedNumber : public ParsedObject {
private:
    double value_;

public:
    explicit ParsedNumber(double value) : value_(value) {}
    virtual ~ParsedNumber() = default;

    double GetValue() const { return value_; }

    void Accept(IParsedObjectVisitor& visitor) const override;
};
