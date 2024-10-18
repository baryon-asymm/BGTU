#include <iostream>

#include "../models/interfaces/i_parsed_object_visitable.h"
#include "../models/interfaces/i_parsed_number_visitable.h"
#include "../models/interfaces/i_parsed_operator_visitable.h"

#include "../models/parsed_objects/parsed_object.h"
#include "../models/parsed_objects/parsed_number.h"
#include "../models/parsed_objects/parsed_operator.h"

#include "../interfaces/i_parsed_object_router.h"

#include "../models/parsed_objects/parsed_addition_operator.h"
#include "../models/parsed_objects/parsed_division_operator.h"
#include "../models/parsed_objects/parsed_multiply_operator.h"
#include "../models/parsed_objects/parsed_subtraction_operator.h"

#include "../models/interfaces/i_node.h"

#include "../models/operands/base_operand.h"
#include "../models/operands/number.h"

#include "../models/operators/base_binary_operator.h"
#include "../models/operators/addition_operator.h"
#include "../models/operators/division_operator.h"
#include "../models/operators/multiply_operator.h"
#include "../models/operators/subtraction_operator.h"

#include "math_expression_controller.h"

void MathExpressionController::Route(std::unique_ptr<ParsedObject> parsed_object) {
    parsed_object->Accept(*this);
}

void MathExpressionController::Visit(const ParsedOperator& parsed_operator) {
    IParsedOperatorVisitor& parsed_operator_visitor = *this;

    parsed_operator.Accept(parsed_operator_visitor);
}

void MathExpressionController::Visit(const ParsedNumber& parsed_number) {
    auto operand = std::make_unique<Number>(parsed_number.GetValue());

    if (tmp_number_ == nullptr) {
        tmp_number_ = std::move(operand);
    }
    else {
        throw std::runtime_error("Operation expected.");
    }
}

void MathExpressionController::Visit(const ParsedAdditionOperator& parsed_addition_operator) {
    auto operation = std::make_unique<AdditionOperator>();
    HandleOperation(std::move(operation), parsed_addition_operator.GetRank());
}

void MathExpressionController::Visit(const ParsedDivisionOperator& parsed_division_operator) {
    auto operation = std::make_unique<DivisionOperator>();
    HandleOperation(std::move(operation), parsed_division_operator.GetRank());
}

void MathExpressionController::Visit(const ParsedMultiplyOperator& parsed_multiply_operator) {
    auto operation = std::make_unique<MultiplyOperator>();
    HandleOperation(std::move(operation), parsed_multiply_operator.GetRank());
}

void MathExpressionController::Visit(const ParsedSubtractionOperator& parsed_subtraction_operator) {
    auto operation = std::make_unique<SubtractionOperator>();
    HandleOperation(std::move(operation), parsed_subtraction_operator.GetRank());
}

void MathExpressionController::HandleOperation(std::unique_ptr<BaseBinaryOperator> operation, int operation_rank) {
    if (tmp_number_ != nullptr) {
        if (current_operation_rank_ == empty_operation_rank_) {
            root_binary_operation_ = std::move(operation);
            root_binary_operation_->SetLeft(std::move(tmp_number_));
        }
        else if (current_operation_rank_ == operation_rank) {
            root_binary_operation_->SetRight(std::move(tmp_number_));
            operation->SetLeft(std::move(root_binary_operation_));
            root_binary_operation_ = std::move(operation);
        }
        else if (current_operation_rank_ < operation_rank) {
            tmp_binary_operation_ = std::move(root_binary_operation_);
            operation->SetLeft(std::move(tmp_number_));
            root_binary_operation_ = std::move(operation);
        }
        else if (current_operation_rank_ > operation_rank) {
            root_binary_operation_->SetRight(std::move(tmp_number_));
            if (tmp_binary_operation_ == nullptr) {
                operation->SetLeft(std::move(root_binary_operation_));
                root_binary_operation_ = std::move(operation);
            }
            else {
                tmp_binary_operation_->SetRight(std::move(root_binary_operation_));
                operation->SetLeft(std::move(tmp_binary_operation_));
                root_binary_operation_ = std::move(operation);
            }
        }
        else {
            throw std::runtime_error("Invalid operation rank.");
        }

        current_operation_rank_ = operation_rank;
    }
    else {
        throw std::runtime_error("Number expected.");
    }
}

std::unique_ptr<INode> MathExpressionController::GetRootNode() {
    if (root_binary_operation_ != nullptr) {
        auto empty_addition_operator = std::make_unique<ParsedAdditionOperator>();
        this->Route(std::move(empty_addition_operator));

        auto zero_number = std::make_unique<Number>(0);
        root_binary_operation_->SetRight(std::move(zero_number));

        return std::move(root_binary_operation_);
    }
    else {
        return std::move(tmp_number_);
    }
}
