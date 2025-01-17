#include "pch.h"
#include "ExpressionVisitor.h"
#include "Binary.h"

namespace jf
{
	// RXgN^
	Binary::Binary(
		// ΆΣ
		ExpressionPointer leftExpression,
		// ρZq
		TokenPointer binaryOperator,
		// EΣ
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_binaryOperator{ binaryOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitorπΐs·ι
	std::any Binary::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
