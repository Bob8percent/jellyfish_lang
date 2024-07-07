#include "pch.h"
// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
#include "ExpressionVisitor.h"
#include "Literal.h"

namespace jf
{
	// �R���X�g���N�^
	Literal::Literal(
		// ���e����
		TokenPointer token
	) :
		m_token{ token }
	{
	}

	// visitor�����s����
	std::any Literal::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
