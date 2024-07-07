#include "pch.h"
// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
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
