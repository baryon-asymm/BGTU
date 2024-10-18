#pragma once

#include "i_parsed_operator_visitor.h"

class IParsedOperatorVisitable {
public:
	virtual ~IParsedOperatorVisitable() = default;

	virtual void Accept(IParsedOperatorVisitor& visitor) const = 0;
};
