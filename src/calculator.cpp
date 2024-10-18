#include <iostream>
#include <memory>
#include <string>

#include "common/parse_cursor.h"
#include "parsers/interfaces/i_parser.h"
#include "parsers/base_parser.h"
#include "parsers/number_parser.h"
#include "parsers/addition_operator_parser.h"
#include "parsers/division_operator_parser.h"
#include "parsers/multiply_operator_parser.h"
#include "parsers/subtraction_operator_parser.h"
#include "parsers/termination_parser.h"

#include "interfaces/i_parsed_object_router.h"
#include "models/interfaces/i_parsed_object_visitable.h"
#include "models/interfaces/i_parsed_number_visitable.h"
#include "models/interfaces/i_parsed_operator_visitable.h"

#include "models/interfaces/i_node.h"

#include "models/operands/base_operand.h"
#include "models/operands/number.h"

#include "models/operators/base_binary_operator.h"
#include "models/operators/addition_operator.h"
#include "models/operators/division_operator.h"
#include "models/operators/multiply_operator.h"
#include "models/operators/subtraction_operator.h"

#include "controllers/math_expression_controller.h"

#include "../include/ConsoleCalculator/i_calculator.h"

#include "calculator.h"

double Calculator::Evaluate(const std::string& math_expression) {
    auto cursor = ParseCursor(std::make_unique<std::string>(math_expression));
    auto parsed_object_router = std::make_shared<MathExpressionController>();

    auto termination_parser = std::make_unique<TerminationParser>();

    auto addition_parser = std::make_unique<AdditionOperatorParser>(std::move(termination_parser), parsed_object_router);
    auto division_parser = std::make_unique<DivisionOperatorParser>(std::move(addition_parser), parsed_object_router);
    auto multiply_parser = std::make_unique<MultiplyOperatorParser>(std::move(division_parser), parsed_object_router);
    auto subtraction_parser = std::make_unique<SubtractionOperatorParser>(std::move(multiply_parser), parsed_object_router);

    auto number_parser = NumberParser(std::move(subtraction_parser), parsed_object_router);

    for (int i = 0; i < math_expression.length(); i++) {
        bool is_parsed = false;
        number_parser.Parse(cursor, is_parsed);

        if (is_parsed) {
            cursor.FlushSequence();
        }

        cursor.MakeStep();
    }

    bool is_parsed = false;
    number_parser.Parse(cursor, is_parsed);

    if (is_parsed == false) {
        throw std::runtime_error("Invalid expression");
    }

    auto root = parsed_object_router->GetRootNode();

    return root->GetValue();
}
