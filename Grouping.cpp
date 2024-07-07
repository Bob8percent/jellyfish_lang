#include "pch.h"+
#include "ExpressionVisitor.h"
#include "Grouping.h"

namespace jf
{
	// �R���X�g���N�^
	Grouping::Grouping(
		// ���������g�[�N��
		TokenPointer leftParen,
		// ()���Z�q���̎�
		ExpressionPointer expression,
		// �E�������g�[�N��
		TokenPointer rightParen
	) :
		m_leftParen{ leftParen },
		m_expression{ expression },
		m_rightParen{ rightParen }
	{
	}

	// visitor�����s����
	std::any Grouping::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
