#include "../interfaces/i_parsed_object_visitable.h"
#include "../interfaces/i_parsed_operator_visitable.h"
#include "parsed_object.h"
#include "parsed_operator.h"

#include "parsed_addition_operator.h"

void ParsedAdditionOperator::Accept(IParsedOperatorVisitor& visitor) const {
    visitor.Visit(*this);
}
