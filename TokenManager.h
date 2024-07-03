#pragma once
#include "TokenDefine.h"
#include "Scanner.h"

namespace jf
{
	class Token;

	// Tokenを登録管理するだけのstaticクラス
	class TokenManager
	{
	public:
		using size_type = std::size_t;
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// コンパイラが扱うトークンをすべて登録する
		static void registerTokens();

		// 語彙に対応するトークンを探す
		static TokenPointer searchToken(
			// 語彙
			LEXEME_TYPE lexeme
		);

		// ソース文字列から次のトークンを取得する
		static TokenPointer getNextToken(
			// スキャナの情報
			Scanner::Info& info
		);

	private:
		// トークンを登録する
		static void registerToken(TokenPointer token);

	private:
		// 登録トークン
		inline static std::vector<TokenPointer> registeredTokens{};
	};
}
