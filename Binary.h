#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// ñZq
	struct Binary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;

	public:
		// RXgN^
		Binary(
			// ¶Ó
			ExpressionPointer leftExpression,
			// ñZq
			TokenPointer binaryOperator,
			// EÓ
			ExpressionPointer rightExpression
		);

		// ãü®ÌvisitorðÀs·é
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// ¶Ó
		ExpressionPointer m_leftExpression;
		// ñZq
		TokenPointer m_binaryOperator;
		// EÓ
		ExpressionPointer m_rightExpression;
	};
}
