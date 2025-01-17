#include "pch.h"
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
