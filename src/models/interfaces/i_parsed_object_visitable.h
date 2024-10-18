#pragma once

#include "i_parsed_object_visitor.h"

class IParsedObjectVisitable {
public:
	virtual ~IParsedObjectVisitable() = default;

	virtual void Accept(IParsedObjectVisitor& visitor) const = 0;
};
