#include "Logical.h"

// TODO: これはあくまでVisitorのベースクラス定義。具象クラスをインクルードするよう変更
#include "ExpressionVisitor.h"
namespace jf
{
	// コンストラクタ
	Logical::Logical(
		// 左辺項
		ExpressionPointer leftExpression,
		// 論理演算子
		TokenPointer logicalOperator,
		// 右辺項
		ExpressionPointer rightExpression
	) :
		m_leftExpression{ leftExpression },
		m_logicalOperator{ logicalOperator },
		m_rightExpression{ rightExpression }
	{
	}

	// visitorを実行する
	std::any Logical::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		visitor.visit(*this);
	}
}
