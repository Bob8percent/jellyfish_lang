#pragma once
#include "pch.h"

namespace jf
{
	// Expressionの型
	struct Assign;
	struct Binary;
	struct Call;
	struct Grouping;
	//struct Logical;
	struct Literal;
	struct Unary;
	struct Variable;

	// Expressionクラスのvisitor
	class ExpressionVisitor
	{
	public:
		// それぞれの式に相当するvisitorを実行する
		virtual std::any visit(Assign& exp) = 0;
		virtual std::any visit(Binary& exp) = 0;
		virtual std::any visit(Call& exp) = 0;
		virtual std::any visit(Grouping& exp) = 0;
		//virtual std::any visit(Logical& exp) = 0;	// TODO: Binaryと同じじゃね？確認して定義するか決める
		virtual std::any visit(Literal& exp) = 0;
		virtual std::any visit(Unary& exp) = 0;
		virtual std::any visit(Variable& exp) = 0;
	};
}
