#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// �P�����Z�q
	struct Unary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr <Expression>;

	public:
		// �R���X�g���N�^
		Unary(
			// �P�����Z�q
			TokenPointer unaryOperator,
			// ��
			ExpressionPointer expression
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// �P�����Z�q
		TokenPointer m_unaryOperator;
		// ��
		ExpressionPointer m_expression;
	};
}
