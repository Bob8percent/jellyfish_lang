#include "pch.h"
// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
#include "ExpressionVisitor.h"
#include "Variable.h"

namespace jf
{
	// �R���X�g���N�^
	Variable::Variable(
		// ���ʎq
		TokenPointer identifier
	) :
		m_identifier{ identifier }
	{
	}

	// visitor�����s����
	std::any Variable::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
