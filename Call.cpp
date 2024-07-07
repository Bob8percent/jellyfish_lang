#include "pch.h"+
#include "ExpressionVisitor.h"
#include "Call.h"

namespace jf
{
	// コンストラクタ
	Call::Call(
		// 呼び出し先
		ExpressionPointer callee,
		// 左かっこトークン
		TokenPointer leftParen,
		// 引数リスト
		std::vector<ExpressionPointer> arguments,
		// 右かっこトークン
		TokenPointer rightParen
	) :
		m_callee{ callee },
		m_leftParen{ leftParen },
		m_arguments{ arguments },
		m_rightParen{ rightParen }
	{
	}

	// visitorを実行する
	std::any Call::accept(
		// visitor
		ExpressionVisitor& visitor
	)
	{
		return visitor.visit(*this);
	}
}
