#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// �����
	struct Assign :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;
	
	public:
		// �R���X�g���N�^
		Assign(
			// �����g�[�N��
			TokenPointer token, 
			// ������̎�
			ExpressionPointer expression
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// �����g�[�N��
		TokenPointer m_token;
		// ������̎�
		ExpressionPointer m_expression;
	};
}
