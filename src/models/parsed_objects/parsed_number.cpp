#include "../interfaces/i_parsed_object_visitable.h"
#include "parsed_object.h"
#include "../interfaces/i_parsed_number_visitable.h"

#include "parsed_number.h"

void ParsedNumber::Accept(IParsedObjectVisitor& visitor) const {
    visitor.Visit(*this);
}
