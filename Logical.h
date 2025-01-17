#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// _Zq
	struct Logical :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		Logical(
			// ΆΣ
			ExpressionPointer leftExpression,
			// _Zq
			TokenPointer logicalOperator,
			// EΣ
			ExpressionPointer rightExpression
		)
			// visitorπΐs·ι
			std::any accept(
				// visitor
				ExpressionVisitor& visitor
			) override;

	private:
		// ΆΣ
		ExpressionPointer m_leftExpression;
		// _Zq
		TokenPointer m_logicalOperator;
		// EΣ
		ExpressionPointer m_rightExpression;
	};
}
