#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// PZq
	struct Unary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr <Expression>;

	public:
		// RXgN^
		Unary(
			// PZq
			TokenPointer unaryOperator,
			// ฎ
			ExpressionPointer expression
		);

		// visitor๐ภsท้
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// PZq
		TokenPointer m_unaryOperator;
		// ฎ
		ExpressionPointer m_expression;
	};
}
