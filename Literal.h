#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// ���e����
	struct Literal :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// �R���X�g���N�^
		Literal(
			// ���e����
			TokenPointer token
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	private:
		// ���e����
		TokenPointer m_token;
	};
}
