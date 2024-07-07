#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// 二項演算子
	struct Binary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;

	public:
		// コンストラクタ
		Binary(
			// 左辺項
			ExpressionPointer leftExpression,
			// 二項演算子
			TokenPointer binaryOperator,
			// 右辺項
			ExpressionPointer rightExpression
		);

		// 代入式のvisitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// 左辺項
		ExpressionPointer m_leftExpression;
		// 二項演算子
		TokenPointer m_binaryOperator;
		// 右辺項
		ExpressionPointer m_rightExpression;
	};
}
