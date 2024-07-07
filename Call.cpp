#include "pch.h"
// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
#include "ExpressionVisitor.h"
#include "Call.h"

namespace jf
{
	// �R���X�g���N�^
	Call::Call(
		// �Ăяo����
		ExpressionPointer callee,
		// ���������g�[�N��
		TokenPointer leftParen,
		// �������X�g
		std::vector<ExpressionPointer> arguments,
		// �E�������g�[�N��
		TokenPointer rightParen
	) :
		m_callee{ callee },
		m_leftParen{ leftParen },
		m_arguments{ arguments },
		m_rightParen{ rightParen }
	{
	}

	// visitor�����s����
	std::any Call::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
