#include "pch.h"
// TODO: これはあくまでVisitorのベースクラス定義。具象クラスをインクルードするよう変更
#include "ExpressionVisitor.h"
#include "Unary.h"

namespace jf
{

	// コンストラクタ
	Unary::Unary(
		// 単項演算子
		TokenPointer unaryOperator,
		// 式
		ExpressionPointer expression
	) :
		m_unaryOperator{ unaryOperator },
		m_expression{ expression }
	{
	}

	// visitorを実行する
	std::any Unary::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
