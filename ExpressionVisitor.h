#pragma once
#include "pch.h"

namespace jf
{
	// Expression�̌^
	struct Assign;
	struct Binary;
	struct Call;
	struct Grouping;
	//struct Logical;
	struct Literal;
	struct Unary;
	struct Variable;

	// Expression�N���X��visitor
	class ExpressionVisitor
	{
	public:
		// ���ꂼ��̎��ɑ�������visitor�����s����
		virtual std::any visit(Assign& exp) = 0;
		virtual std::any visit(Binary& exp) = 0;
		virtual std::any visit(Call& exp) = 0;
		virtual std::any visit(Grouping& exp) = 0;
		//virtual std::any visit(Logical& exp) = 0;	// TODO: Binary�Ɠ�������ˁH�m�F���Ē�`���邩���߂�
		virtual std::any visit(Literal& exp) = 0;
		virtual std::any visit(Unary& exp) = 0;
		virtual std::any visit(Variable& exp) = 0;
	};
}
