#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// 代入式
	struct Assign :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;
	
	public:
		// コンストラクタ
		Assign(
			// 代入先トークン
			TokenPointer token, 
			// 代入元の式
			ExpressionPointer expression
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// 代入先トークン
		TokenPointer m_token;
		// 代入元の式
		ExpressionPointer m_expression;
	};
}
