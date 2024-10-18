project(ConsoleCalculator)

file(GLOB_RECURSE all_headers LIST_DIRECTORIES FALSE "*.h")

add_executable(ConsoleCalculator)

target_sources(ConsoleCalculator PRIVATE
    ${all_headers}
    common/parse_cursor.cpp
    controllers/math_expression_controller.cpp
    models/operands/number.cpp
    models/operators/addition_operator.cpp
    models/operators/division_operator.cpp
    models/operators/multiply_operator.cpp
    models/operators/subtraction_operator.cpp
    models/parsed_objects/parsed_addition_operator.cpp
    models/parsed_objects/parsed_division_operator.cpp
    models/parsed_objects/parsed_multiply_operator.cpp
    models/parsed_objects/parsed_number.cpp
    models/parsed_objects/parsed_operator.cpp
    models/parsed_objects/parsed_subtraction_operator.cpp
    parsers/number_parser.cpp
    parsers/addition_operator_parser.cpp
    parsers/subtraction_operator_parser.cpp
    parsers/division_operator_parser.cpp
    parsers/multiply_operator_parser.cpp
    parsers/termination_parser.cpp
    calculator.cpp
    main.cpp
)

target_include_directories(ConsoleCalculator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
