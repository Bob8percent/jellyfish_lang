#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// リテラル
	struct Literal :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// コンストラクタ
		Literal(
			// リテラル
			TokenPointer token
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// リテラル
		TokenPointer m_token;
	};
}
