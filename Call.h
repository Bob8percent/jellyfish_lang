#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// Call
	struct Call :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;
		
	public:
		// �R���X�g���N�^
		Call(
			// �Ăяo����
			ExpressionPointer callee,
			// ���������g�[�N��
			TokenPointer leftParen,
			// �������X�g
			std::vector<ExpressionPointer> arguments,
			// �E�������g�[�N��
			TokenPointer rightParen
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// �Ăяo����
		ExpressionPointer m_callee;
		// ���������g�[�N��
		TokenPointer m_leftParen;
		// �������X�g
		std::vector<ExpressionPointer> m_arguments;
		// �E�������g�[�N��
		TokenPointer m_rightParen;
	};

}
