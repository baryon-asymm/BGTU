#include "../interfaces/i_parsed_object_visitable.h"
#include "parsed_object.h"
#include "../interfaces/i_parsed_operator_visitable.h"

#include "parsed_operator.h"

void ParsedOperator::Accept(IParsedObjectVisitor& visitor) const {
    visitor.Visit(*this);
}
