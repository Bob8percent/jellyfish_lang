#include "pch.h"+
#include "ExpressionVisitor.h"
#include "Grouping.h"

namespace jf
{
	// コンストラクタ
	Grouping::Grouping(
		// 左かっこトークン
		TokenPointer leftParen,
		// ()演算子中の式
		ExpressionPointer expression,
		// 右かっこトークン
		TokenPointer rightParen
	) :
		m_leftParen{ leftParen },
		m_expression{ expression },
		m_rightParen{ rightParen }
	{
	}

	// visitorを実行する
	std::any Grouping::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
