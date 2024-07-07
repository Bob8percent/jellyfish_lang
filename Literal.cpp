#include "pch.h"
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
