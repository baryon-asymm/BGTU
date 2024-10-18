#pragma once

#include "i_parsed_number_visitor.h"

class IParsedNumberVisitable {
public:
	virtual ~IParsedNumberVisitable() = default;

	virtual void Accept(IParsedNumberVisitor& visitor) const = 0;
};
