#include <stdexcept>
#include <iostream>

#include "../common/parse_cursor.h"
#include "interfaces/i_parser.h"

#include "termination_parser.h"

void TerminationParser::Parse(const ParseCursor& cursor, bool& is_parsed) {
    throw std::runtime_error("Termination parser invoked");
}
