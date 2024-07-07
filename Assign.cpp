#include "pch.h"+
#include "ExpressionVisitor.h"
#include "Assign.h"

namespace jf
{

	// �R���X�g���N�^
	Assign::Assign(
		// �����g�[�N��
		TokenPointer token,
		// ������̎�
		ExpressionPointer expression
	)
		:m_token{ token },
		m_expression{ expression }
	{
	}

	// visitor�����s����
	std::any Assign::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
