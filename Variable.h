#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// 変数
	struct Variable :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// コンストラクタ
		Variable(
			// 識別子
			TokenPointer identifier
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	public:
		TokenPointer m_identifier;
	};
}
