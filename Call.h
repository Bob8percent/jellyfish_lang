#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// Call
	struct Call :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;
		using ExpressionPointer = std::shared_ptr<Expression>;
		
	public:
		// コンストラクタ
		Call(
			// 呼び出し先
			ExpressionPointer callee,
			// 左かっこトークン
			TokenPointer leftParen,
			// 引数リスト
			std::vector<ExpressionPointer> arguments,
			// 右かっこトークン
			TokenPointer rightParen
		);

		// visitorを実行する
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// 呼び出し先
		ExpressionPointer m_callee;
		// 左かっこトークン
		TokenPointer m_leftParen;
		// 引数リスト
		std::vector<ExpressionPointer> m_arguments;
		// 右かっこトークン
		TokenPointer m_rightParen;
	};

}
