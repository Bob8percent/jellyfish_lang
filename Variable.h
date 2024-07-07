#pragma once
#include "Expression.h"

namespace jf
{
	class Token;
	class ExpressionVisitor;

	// �ϐ�
	struct Variable :public Expression
	{
	public:
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// �R���X�g���N�^
		Variable(
			// ���ʎq
			TokenPointer identifier
		);

		// visitor�����s����
		std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) override;

	public:
		TokenPointer m_identifier;
	};
}
