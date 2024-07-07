#include "pch.h"
// TODO: これはあくまでVisitorのベースクラス定義。具象クラスをインクルードするよう変更
#include "ExpressionVisitor.h"
#include "Variable.h"

namespace jf
{
	// コンストラクタ
	Variable::Variable(
		// 識別子
		TokenPointer identifier
	) :
		m_identifier{ identifier }
	{
	}

	// visitorを実行する
	std::any Variable::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
