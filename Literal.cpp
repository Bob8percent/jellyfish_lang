#include "pch.h"
// TODO: これはあくまでVisitorのベースクラス定義。具象クラスをインクルードするよう変更
#include "ExpressionVisitor.h"
#include "Literal.h"

namespace jf
{
	// コンストラクタ
	Literal::Literal(
		// リテラル
		TokenPointer token
	) :
		m_token{ token }
	{
	}

	// visitorを実行する
	std::any Literal::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
