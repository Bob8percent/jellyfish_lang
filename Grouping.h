#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// ()演算子
	struct Grouping :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;

	public:
		// コンストラクタ
		Grouping(
			// 左かっこトークン
			TokenPointer leftParen,
			// ()演算子中の式
			ExpressionPointer expression,
			// 右かっこトークン
			TokenPointer rightParen
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// 左かっこトークン
		TokenPointer m_leftParen;
		// ()演算子中の式
		ExpressionPointer m_expression;
		// 右かっこトークン
		TokenPointer m_rightParen;
	};
}
