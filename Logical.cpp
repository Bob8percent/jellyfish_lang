#include "pch.h"
#include "ExpressionVisitor.h"
#include "Logical.h"

namespace jf
{
	// RXgN^
	Logical::Logical(
		// ΆΣ
		ExpressionPointer leftExpression,
		// _Zq
		TokenPointer logicalOperator,
		// EΣ
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_logicalOperator{ logicalOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitorπΐs·ι
	std::any Logical::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		visitor.visit(*this);
	}
}
