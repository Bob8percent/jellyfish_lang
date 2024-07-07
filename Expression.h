#pragma once
#include "pch.h"

namespace jf
{
	// ����visitor
	class ExpressionVisitor;
	
	// ���̒��ۃN���X
	struct Expression
	{
	public:
		// ���N���X��visitor�����s����
		// �߂�l: visitor���C�ӂɌ���
		virtual std::any accept(
			// visitor
			ExpressionVisitor& visitor
		) = 0;
	};
}
