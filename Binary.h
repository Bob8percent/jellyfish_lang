#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// �񍀉��Z�q
	struct Binary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;

	public:
		// �R���X�g���N�^
		Binary(
			// ���Ӎ�
			ExpressionPointer leftExpression,
			// �񍀉��Z�q
			TokenPointer binaryOperator,
			// �E�Ӎ�
			ExpressionPointer rightExpression
		);

		// �������visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// ���Ӎ�
		ExpressionPointer m_leftExpression;
		// �񍀉��Z�q
		TokenPointer m_binaryOperator;
		// �E�Ӎ�
		ExpressionPointer m_rightExpression;
	};
}
