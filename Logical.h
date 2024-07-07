#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// �_�����Z�q
	struct Logical :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		Logical(
			// ���Ӎ�
			ExpressionPointer leftExpression,
			// �_�����Z�q
			TokenPointer logicalOperator,
			// �E�Ӎ�
			ExpressionPointer rightExpression
		)
			// visitor�����s����
			std::any accept(
				// visitor
				ExpressionVisitor& visitor
			) override;

	private:
		// ���Ӎ�
		ExpressionPointer m_leftExpression;
		// �_�����Z�q
		TokenPointer m_logicalOperator;
		// �E�Ӎ�
		ExpressionPointer m_rightExpression;
	};
}
