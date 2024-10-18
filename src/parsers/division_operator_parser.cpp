#include <stdexcept>
#include <iostream>

#include "../common/parse_cursor.h"
#include "interfaces/i_parser.h"
#include "base_parser.h"
#include "../interfaces/i_parsed_object_router.h"

#include "../models/interfaces/i_parsed_object_visitable.h"
#include "../models/interfaces/i_parsed_operator_visitable.h"
#include "../interfaces/i_parsed_object_router.h"

#include "../models/parsed_objects/parsed_object.h"
#include "../models/parsed_objects/parsed_operator.h"
#include "../models/parsed_objects/parsed_division_operator.h"

#include "division_operator_parser.h"

#pragma region OperatorVerifyMethods

inline bool IsDivisionOperator(char c)
{
	return c == '/';
}

#pragma endregion

void DivisionOperatorParser::Parse(const ParseCursor& cursor, bool& is_parsed)
{
    if (cursor.HasCurrentChar() == false
        || IsDivisionOperator(cursor.GetCurrentChar()) == false
        || cursor.GetSequenceLength() > 1)
    {
        next_parser_->Parse(cursor, is_parsed);

        return;
    }

    auto parsed_division_operator = std::make_unique<ParsedDivisionOperator>();

    parsed_object_router_->Route(std::move(parsed_division_operator));

    is_parsed = true;

    return;
}
