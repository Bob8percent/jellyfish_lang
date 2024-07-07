#include "Logical.h"

// TODO: ����͂����܂�Visitor�̃x�[�X�N���X��`�B��ۃN���X���C���N���[�h����悤�ύX
#include "ExpressionVisitor.h"
namespace jf
{
	// �R���X�g���N�^
	Logical::Logical(
		// ���Ӎ�
		ExpressionPointer leftExpression,
		// �_�����Z�q
		TokenPointer logicalOperator,
		// �E�Ӎ�
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_logicalOperator{ logicalOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitor�����s����
	std::any Logical::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		visitor.visit(*this);
	}
}
