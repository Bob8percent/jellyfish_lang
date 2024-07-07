#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// ()���Z�q
	struct Grouping :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;

	public:
		// �R���X�g���N�^
		Grouping(
			// ���������g�[�N��
			TokenPointer leftParen,
			// ()���Z�q���̎�
			ExpressionPointer expression,
			// �E�������g�[�N��
			TokenPointer rightParen
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// ���������g�[�N��
		TokenPointer m_leftParen;
		// ()���Z�q���̎�
		ExpressionPointer m_expression;
		// �E�������g�[�N��
		TokenPointer m_rightParen;
	};
}
