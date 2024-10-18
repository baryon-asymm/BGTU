#pragma once

class IParsedObjectVisitable;
class IParsedObjectVisitor;

class ParsedObject : public IParsedObjectVisitable {
public:
    virtual ~ParsedObject() = default;

	virtual void Accept(IParsedObjectVisitor& visitor) const = 0;
};
