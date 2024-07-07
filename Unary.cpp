#include "pch.h"
// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
#include "ExpressionVisitor.h"
#include "Unary.h"

namespace jf
{

	// �R���X�g���N�^
	Unary::Unary(
		// �P�����Z�q
		TokenPointer unaryOperator,
		// ��
		ExpressionPointer expression
	) :
		m_unaryOperator{ unaryOperator },
		m_expression{ expression }
	{
	}

	// visitor�����s����
	std::any Unary::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
