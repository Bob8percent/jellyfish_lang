#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// 論理演算子
	struct Logical :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		Logical(
			// 左辺項
			ExpressionPointer leftExpression,
			// 論理演算子
			TokenPointer logicalOperator,
			// 右辺項
			ExpressionPointer rightExpression
		)
			// visitorを実行する
			std::any accept(
				// visitor
				ExpressionVisitor& visitor
			) override;

	private:
		// 左辺項
		ExpressionPointer m_leftExpression;
		// 論理演算子
		TokenPointer m_logicalOperator;
		// 右辺項
		ExpressionPointer m_rightExpression;
	};
}
