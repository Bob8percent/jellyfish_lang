#include "pch.h"
#include "Tokens.h"
#include "TokenDefine.h"
#include "Debug.h"

namespace jf
{
	// (
	// コンストラクタ
	LeftParen::LeftParen()
		:Token{ LEFT_PAREN }
	{
	}
	// )
	// コンストラクタ
	RightParen::RightParen()
		:Token{ RIGHT_PAREN }
	{
	}
	// {
	// コンストラクタ
	LeftBrace::LeftBrace()
		:Token{ LEFT_BRACE }
	{
	}
	// }
	// コンストラクタ
	RightBrace::RightBrace()
		:Token{ RIGHT_BRACE }
	{
	}
	// ,
	// コンストラクタ
	Comma::Comma()
		:Token{ COMMA }
	{
	}
	// .
	// コンストラクタ
	Dot::Dot()
		:Token{ DOT }
	{
	}
	// ;
	// コンストラクタ
	Semicoron::Semicoron()
		:Token{ SEMICORON }
	{
	}
	// +
	// コンストラクタ
	Plus::Plus()
		:Token{ PLUS }
	{
	}
	// -
	// コンストラクタ
	Minus::Minus()
		:Token{ MINUS }
	{
	}
	// /
	// コンストラクタ
	Slash::Slash()
		:Token{ SLASH }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Slash::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		// //と/との区別が必要
		auto isFindComment = Token::isBeginWithThisLexeme(info, COMMENT);
		if (!isFindComment)
		{
			auto isFindSlash = Token::isFindToken(info);
			return isFindSlash;
		}
		return isFindComment;
	}
	// *
	// コンストラクタ
	Star::Star()
		:Token{ STAR }
	{
	}
	// !
	// コンストラクタ
	Bang::Bang()
		:Token{ BANG }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Bang::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		// !=と!との区別が必要
		auto isFindBangEqual = Token::isBeginWithThisLexeme(info, BANG_EQUAL);
		if (!isFindBangEqual)
		{
			auto isFindBang = Token::isFindToken(info);
			return isFindBang;
		}
		return isFindBangEqual;
	}
	// !=
	// コンストラクタ
	BangEqual::BangEqual()
		:Token{ BANG_EQUAL }
	{
	}
	// =
	// コンストラクタ
	Equal::Equal()
		:Token{ EQUAL }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Equal::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		// =と==との区別が必要
		auto isFindEqualEqual = Token::isBeginWithThisLexeme(info, EQUAL_EQUAL);
		if (!isFindEqualEqual)
		{
			auto isFindEqual = Token::isFindToken(info);
			return isFindEqual;
		}
		return isFindEqualEqual;
	}
	// ==
	// コンストラクタ
	EqualEqual::EqualEqual()
		:Token{ EQUAL_EQUAL }
	{
	}
	// >
	// コンストラクタ
	Greater::Greater()
		:Token{ GREATER }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Greater::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		// >と>=との区別が必要
		auto isFindGreaterEqual = Token::isBeginWithThisLexeme(info, GREATER_EQUAL);
		if (!isFindGreaterEqual)
		{
			auto isFindGreater = Token::isFindToken(info);
			return isFindGreater;
		}
		return isFindGreaterEqual;
	}
	// >=
	// コンストラクタ
	GreaterEqual::GreaterEqual()
		:Token{ GREATER_EQUAL }
	{
	}
	// <
	// コンストラクタ
	Less::Less()
		:Token{ LESS }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Less::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		// <と<=との区別が必要
		auto isFindLessEqual = Token::isBeginWithThisLexeme(info, LESS_EQUAL);
		if (!isFindLessEqual)
		{
			auto isFindLess = Token::isFindToken(info);
			return isFindLess;
		}
		return isFindLessEqual;
	}
	// <=
	// コンストラクタ
	LessEqual::LessEqual()
		:Token{ LESS_EQUAL }
	{
	}
	// //
	// コンストラクタ
	Comment::Comment()
		:Token{ COMMENT }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Comment::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// トークンが見つかるなら参照位置を更新
		if (isFind)
		{
			// 改行位置まで更新
			while (!isBeginWithThisLexeme(info, RETURN))
			{
				// 改行文字が見つからないままソースの最後に到達した場合
				if (info.isReachSourceEnd(0))
				{
					return isFind;
				}
				info.current += 1;
			}
			info.line += 1;
		}
		return isFind;
	}
	// \r
	// コンストラクタ
	CReturn::CReturn()
		:Token{ CRETURN }
	{
	}
	// \n
	// コンストラクタ
	Newline::Newline()
		:Token{ NEWLINE }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Newline::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		if (Token::isFindToken(info))
		{
			info.line += 1;
			return true;
		}
		return false;
	}

	// \t
	// コンストラクタ
	Tab::Tab()
		:Token{ TAB }
	{
	}
	
	// "
	// コンストラクタ
	String::String()
		:Token{ STRING },
		m_value{}
	{
	}
	// ソース文字列からトークンが見つかるか
	bool String::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// トークンが見つかるなら参照位置を更新
		if (isFind)
		{
			size_type start_index = info.current;
			// 次の"まで更新
			while (!isBeginWithThisLexeme(info, STRING))
			{
				// "が見つからないままソースの最後に到達した場合
				if (info.isReachSourceEnd(0))
				{
					JF_COMPILE_ERROR("TODO:source file path", info.line,
						"String not closed with \"!");
					return isFind;
				}
				// 文字列の途中で改行されていた場合
				if (isBeginWithThisLexeme(info, RETURN))
				{
					info.line += 1;
				}

				info.current += 1;
			}
			auto str_length = (info.current - start_index + 1);
			m_value = info.source.substr(start_index, str_length);
		}
		return isFind;
	}

	// 数値
	// コンストラクタ
	Number::Number()
		:Token{},
		m_value{}
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Number::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		auto start_index = info.current;

		// [0-9]文字の連続を取得
		while (std::isdigit(info.source[info.current]))
		{
			++info.current;
		}
		// [0-9]文字が1つも見つからなかった場合は即時偽とする
		if (start_index == info.current)
		{
			return false;
		}

		// 小数点があるかチェック
		if (isBeginWithThisLexeme(info, "."))
		{
			bool isExistDecimalPoint = false;
			while (std::isdigit(info.source[info.current]))
			{
				isExistDecimalPoint = true;
				++info.current;
			}
			// 小数点があるのに小数点以下の数値が存在しない場合エラー
			if (!isExistDecimalPoint)
			{
				JF_COMPILE_ERROR("TODO:source file path", info.line,
					"Invalid Decimal Point!");
			}
		}

		// 文字列から小数点への変換
		auto number_length = info.current - start_index + 1;
		auto number_str = info.source.substr(start_index, number_length);
		m_value = std::stof(number_str);

		return true;
	}

	// 識別子
	// コンストラクタ
	Identifier::Identifier()
		:Token{},
		m_name{}
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Identifier::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{

		// キーワードも識別子の条件を満たすので、キーワードであるかの確認が必要
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return !isKeyword(word.c_str());
			},
			info,
			&m_name
		);
	}

	// ソース文字列から単語を抜き出しが述語関数Funcを満たすか判定する
	template <class Func>
	bool Identifier::extractAndJudge(
		// 判定関数
		Func&& func,
		// スキャナの情報
		Scanner::Info& info,
		// 抜き出した単語を出力するバッファ
		std::string* name
	)
	{
		// ソース文字列から単語を抜き出す
		auto identifier_length = Identifier::extractIdentifier(info) - info.current + 1;
		auto identifier = info.source.substr(info.current, identifier_length);

		// 単語が条件を満たすかを調べる
		if (std::invoke(func, identifier.c_str()))
		{
			if (name != nullptr)
				*name = identifier;
			info.current += identifier.length();
			return true;
		}
		return false;
	}

	// ソース文字列から識別子を抜き出す
	// 戻り値：識別子の最後の文字の次のインデックス
	Scanner::size_type Identifier::extractIdentifier(
		// スキャナ情報
		const Scanner::Info& info
	)
	{
		auto identifier_end_index = info.current;
		while (Identifier::isAlphaOrUnderbar(info.source[identifier_end_index]))
		{
			++identifier_end_index;
		}
		return identifier_end_index;
	}
	// chが_かアルファベットであるか
	// 戻り値：である(true), でない(false)
	bool Identifier::isAlphaOrUnderbar(
		// 調査対象の文字
		char ch
	)
	{
		return std::isalpha(ch) && (ch == '_');
	}

	// or
	// コンストラクタ
	Or::Or()
		:Token{ OR }
	{

	}
	// ソース文字列からトークンが見つかるか
	bool Or::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), OR);
			},
			info
		);
	}
	// and
	// コンストラクタ
	And::And()
		:Token{ AND }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool And::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), AND);
			},
			info
		);
	}
	// false
	// コンストラクタ
	False::False()
		:Token{ FALSE }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool False::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FALSE);
			},
			info
		);
	}
	// true
	// コンストラクタ
	True::True()
		:Token{ TRUE }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool True::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), TRUE);
			},
			info
		);
	}
	// if
	If::If()
		:Token{ IF }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool If::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), IF);
			},
			info
		);
	}
	// else
	// コンストラクタ
	Else::Else()
		:Token{ ELSE }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Else::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), ELSE);
			},
			info
		);
	}
	// for
	// コンストラクタ
	For::For()
		:Token{ FOR }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool For::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FOR);
			},
			info
		);
	}
	// while
	// コンストラクタ
	While::While()
		:Token{ WHILE }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool While::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), WHILE);
			},
			info
		);
	}
	// Func
	// コンストラクタ
	Func::Func()
		:Token{ FUNC }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Func::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FUNC);
			},
			info
		);
	}
	// return
	// コンストラクタ
	Return::Return()
		:Token{ RETURN }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Return::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), RETURN);
			},
			info
		);

	}
	// class
	// コンストラクタ
	Class::Class()
		:Token{ CLASS }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Class::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), CLASS);
			},
			info
		);
	}
	// super
	// コンストラクタ
	Super::Super()
		:Token{ SUPER }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Super::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), SUPER);
			},
			info
		);
	}
	// this
	// コンストラクタ
	This::This()
		:Token{ THIS }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool This::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	) 
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), THIS);
			},
			info
		);
	}
	// var
	// コンストラクタ
	Var::Var()
		:Token{ VAR }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Var::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), VAR);
			},
			info
		);
	}
	// nil
	// コンストラクタ
	Nil::Nil()
		:Token{NIL}
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Nil::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), NIL);
			},
			info
		);
	}
	// print
	// コンストラクタ
	Print::Print()
		:Token{ PRINT }
	{
	}
	// ソース文字列からトークンが見つかるか
	bool Print::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), PRINT);
			},
			info
		);
	}
}
