#include "pch.h"
#include "ExpressionVisitor.h"
#include "Binary.h"

namespace jf
{
	// コンストラクタ
	Binary::Binary(
		// 左辺項
		ExpressionPointer leftExpression,
		// 二項演算子
		TokenPointer binaryOperator,
		// 右辺項
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_binaryOperator{ binaryOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitorを実行する
	std::any Binary::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
