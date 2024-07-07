#pragma once
#include "pch.h"

namespace jf
{
	// 式のvisitor
	class ExpressionVisitor;
	
	// 式の抽象クラス
	struct Expression
	{
	public:
		// 式クラスのvisitorを実行する
		// 戻り値: visitorが任意に決定
		virtual std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) = 0;
	};
}
