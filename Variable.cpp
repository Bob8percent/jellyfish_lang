#include "pch.h"
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
