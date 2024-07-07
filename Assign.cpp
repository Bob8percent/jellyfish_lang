#include "pch.h"+
#include "ExpressionVisitor.h"
#include "Assign.h"

namespace jf
{

	// コンストラクタ
	Assign::Assign(
		// 代入先トークン
		TokenPointer token,
		// 代入元の式
		ExpressionPointer expression
	)
		:m_token{ token },
		m_expression{ expression }
	{
	}

	// visitorを実行する
	std::any Assign::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
