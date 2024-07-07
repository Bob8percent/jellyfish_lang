#pragma once
#include "pch.h"
#include "TokenBase.h"

namespace jf
{
	// (
	class LeftParen :public Token
	{
	public:
		// コンストラクタ
		LeftParen();
	};
	// )
	class RightParen :public Token
	{
	public:
		// コンストラクタ
		RightParen();
	};
	// {
	class LeftBrace :public Token
	{
	public:
		// コンストラクタ
		LeftBrace();
	};
	// }
	class RightBrace :public Token
	{
	public:
		// コンストラクタ
		RightBrace();
	};
	// ,
	class Comma :public Token
	{
	public:
		// コンストラクタ
		Comma();
	};
	// .
	class Dot :public Token
	{
	public:
		// コンストラクタ
		Dot();
	};
	// ;
	class Semicoron :public Token
	{
	public:
		// コンストラクタ
		Semicoron();
	};
	// +
	class Plus :public Token
	{
	public:
		// コンストラクタ
		Plus();
	};
	// -
	class Minus :public Token
	{
	public:
		// コンストラクタ
		Minus();
	};
	// /
	class Slash :public Token
	{
	public:
		// コンストラクタ
		Slash();

		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// *
	class Star :public Token
	{
	public:
		// コンストラクタ
		Star();
	};
	// !
	class Bang :public Token
	{
	public:
		// コンストラクタ
		Bang();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// !=
	class BangEqual :public Token
	{
	public:
		// コンストラクタ
		BangEqual();
	};
	// =
	class Equal :public Token
	{
	public:
		// コンストラクタ
		Equal();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// ==
	class EqualEqual :public Token
	{
	public:
		// コンストラクタ
		EqualEqual();
	};
	// >
	class Greater :public Token
	{
	public:
		// コンストラクタ
		Greater();		
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// >=
	class GreaterEqual :public Token
	{
	public:
		// コンストラクタ
		GreaterEqual();
	};
	// <
	class Less :public Token
	{
	public:
		// コンストラクタ
		Less();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// <=
	class LessEqual :public Token
	{
	public:
		// コンストラクタ
		LessEqual();
	};
	// //
	class Comment :public Token
	{
	public:
		// コンストラクタ
		Comment();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// \r
	class CReturn :public Token
	{
	public:
		// コンストラクタ
		CReturn();
	};
	// \n
	class Newline :public Token
	{
	public:
		// コンストラクタ
		Newline();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// \t
	class Tab :public Token
	{
	public:
		// コンストラクタ
		Tab();
	};
	// \"
	class String :public Token
	{
	public:
		// コンストラクタ
		String();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;

	private:
		// "で囲まれる文字列
		std::string m_value;
	};
	// 数値 (TODO: 浮動小数点のみ対応。将来的にほかの数値型も対応したい。)
	class Number :public Token
	{
	public:
		// コンストラクタ
		Number();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;

	private:
		// "で囲まれる文字列
		float m_value;
	};
	// 識別子
	class Identifier :public Token
	{
	public:
		// コンストラクタ
		Identifier();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;

	public:
		// ソース文字列から単語を抜き出しが述語関数Funcを満たすか判定する
		template <class Func>
		static bool extractAndJudge(
			// 判定関数
			Func&& func,
			// スキャナの情報
			Scanner::Info& info,
			// 抜き出した単語を出力するバッファ
			std::string* name = nullptr
		);
		// ソース文字列から識別子を抜き出す
		// 戻り値：識別子の最後の文字の次のインデックス
		static Scanner::size_type extractIdentifier(
			// スキャナ情報
			const Scanner::Info& info
		);
		// chが_かアルファベットであるか
		// 戻り値：である(true), でない(false)
		static bool isAlphaOrUnderbar(
			// 調査対象の文字
			char ch
		);

	private:
		// 識別子名
		std::string m_name;
	};
	
	// or
	class Or :public Token
	{
	public:
		// コンストラクタ
		Or();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// and
	class And :public Token
	{
	public:
		// コンストラクタ
		And();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// false
	class False :public Token
	{
	public:
		// コンストラクタ
		False();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// true
	class True :public Token
	{
	public:
		// コンストラクタ
		True();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// if
	class If :public Token
	{
	public:
		// コンストラクタ
		If();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// else
	class Else :public Token
	{
	public:
		// コンストラクタ
		Else();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// for
	class For :public Token
	{
	public:
		// コンストラクタ
		For();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// while
	class While :public Token
	{
	public:
		// コンストラクタ
		While();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// Func
	class Func :public Token
	{
	public:
		// コンストラクタ
		Func();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// return
	class Return :public Token
	{
	public:
		// コンストラクタ
		Return();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// class
	class Class :public Token
	{
	public:
		// コンストラクタ
		Class();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// super
	class Super :public Token
	{
	public:
		// コンストラクタ
		Super();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// this
	class This :public Token
	{
	public:
		// コンストラクタ
		This();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// var
	class Var :public Token
	{
	public:
		// コンストラクタ
		Var();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// nil
	class Nil :public Token
	{
	public:
		// コンストラクタ
		Nil();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
	// print
	class Print :public Token
	{
	public:
		// コンストラクタ
		Print();
		// ソース文字列からトークンが見つかるか
		bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		) override;
	};
}

