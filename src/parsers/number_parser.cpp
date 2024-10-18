#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "../common/parse_cursor.h"
#include "interfaces/i_parser.h"
#include "base_parser.h"

#include "../models/interfaces/i_parsed_object_visitable.h"
#include "../interfaces/i_parsed_object_router.h"

#include "../models/parsed_objects/parsed_object.h"
#include "../models/parsed_objects/parsed_number.h"

#include "number_parser.h"

#pragma region NumberVerifyMethods

inline bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

inline bool isDot(char c)
{
	return c == '.' || c == ',';
}

inline bool isExponent(char c)
{
    return c == 'e' || c == 'E';
}

inline bool isSign(char c)
{
	return c == '+' || c == '-';
}

#pragma endregion

#pragma region NumberConversionMethods

inline bool tryParseDouble(std::unique_ptr<std::string> sequence, int length, double& result)
{
	std::string sequence_copy = *sequence;
	std::replace(sequence_copy.begin(), sequence_copy.end(), ',', '.');

	try
	{
		std::size_t pos;
		result = std::stod(sequence_copy, &pos);

        if (pos != sequence_copy.length())
        {
            return false;
        }

		return true;
	}
	catch (const std::runtime_error&)
	{
		return false;
	}
}

#pragma endregion

void NumberParser::Parse(const ParseCursor& cursor, bool& is_parsed)
{
	if (cursor.HasCurrentChar()
		&& isNumber(cursor.GetCurrentChar()) == false
		&& isDot(cursor.GetCurrentChar()) == false
		&& isExponent(cursor.GetCurrentChar()) == false)
	{
		if (cursor.HasPreviousChar()
			&& isExponent(cursor.GetPreviousChar())
			&& isSign(cursor.GetCurrentChar()))
		{
			return;
		}

		next_parser_->Parse(cursor, is_parsed);

		return;
	}

	if (cursor.HasNextChar()
		&& (isNumber(cursor.GetNextChar())
			|| isDot(cursor.GetNextChar())
			|| isExponent(cursor.GetNextChar())
			|| (isSign(cursor.GetNextChar()) && isExponent(cursor.GetCurrentChar()))))
	{
		return;
	}

	if (cursor.GetSequenceLength() > 0)
	{
		double number;
		if (tryParseDouble(cursor.GetSequence(), cursor.GetSequenceLength(), number))
		{
			auto parsed_number = std::make_unique<ParsedNumber>(number);

			parsed_object_router_->Route(std::move(parsed_number));

			is_parsed = true;

			return;
		}
	}

	next_parser_->Parse(cursor, is_parsed);
}
