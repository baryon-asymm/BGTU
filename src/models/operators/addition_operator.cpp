#include "../interfaces/i_node.h"
#include "base_binary_operator.h"

#include "addition_operator.h"

double AdditionOperator::GetValue() const
{
    return left->GetValue() + right->GetValue();
}
