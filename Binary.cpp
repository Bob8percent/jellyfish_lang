#include "pch.h"
#include "ExpressionVisitor.h"
#include "Binary.h"

namespace jf
{
	// �R���X�g���N�^
	Binary::Binary(
		// ���Ӎ�
		ExpressionPointer leftExpression,
		// �񍀉��Z�q
		TokenPointer binaryOperator,
		// �E�Ӎ�
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_binaryOperator{ binaryOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitor�����s����
	std::any Binary::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
