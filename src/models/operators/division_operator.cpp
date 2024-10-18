#include "../interfaces/i_node.h"
#include "base_binary_operator.h"

#include "division_operator.h"

double DivisionOperator::GetValue() const
{
    return left->GetValue() / right->GetValue();
}
