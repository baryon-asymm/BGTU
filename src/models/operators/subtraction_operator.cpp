#include "../interfaces/i_node.h"
#include "base_binary_operator.h"

#include "subtraction_operator.h"

double SubtractionOperator::GetValue() const
{
    return left->GetValue() - right->GetValue();
}
