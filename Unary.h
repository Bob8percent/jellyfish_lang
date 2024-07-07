#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// 単項演算子
	struct Unary :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr <Expression>;

	public:
		// コンストラクタ
		Unary(
			// 単項演算子
			TokenPointer unaryOperator,
			// 式
			ExpressionPointer expression
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// 単項演算子
		TokenPointer m_unaryOperator;
		// 式
		ExpressionPointer m_expression;
	};
}
