#include "../interfaces/i_node.h"
#include "base_binary_operator.h"

#include "multiply_operator.h"

double MultiplyOperator::GetValue() const
{
    return left->GetValue() * right->GetValue();
}
