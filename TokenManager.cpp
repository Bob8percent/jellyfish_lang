#include "pch.h"
#include "SystemDebug.h"

#include "Debug.h"
#include "TokenManager.h"
#include "Tokens.h"
#include "Scanner.h"

namespace jf
{
	// コンパイラが扱うトークンをすべて登録する
	void TokenManager::registerTokens()
	{
		// 記号トークンの登録
		registerToken(std::make_shared<LeftParen>());
		registerToken(std::make_shared<RightParen>());
		registerToken(std::make_shared<LeftBrace>());
		registerToken(std::make_shared<RightBrace>());
		registerToken(std::make_shared<Comma>());
		registerToken(std::make_shared<Dot>());
		registerToken(std::make_shared<Semicoron>());
		registerToken(std::make_shared<Plus>());
		registerToken(std::make_shared<Minus>());
		registerToken(std::make_shared<Slash>());
		registerToken(std::make_shared<Star>());
		registerToken(std::make_shared<Bang>());
		registerToken(std::make_shared<BangEqual>());
		registerToken(std::make_shared<Equal>());
		registerToken(std::make_shared<EqualEqual>());
		registerToken(std::make_shared<Greater>());
		registerToken(std::make_shared<GreaterEqual>());
		registerToken(std::make_shared<Less>());
		registerToken(std::make_shared<LessEqual>());
		registerToken(std::make_shared<Comment>());
		registerToken(std::make_shared<CReturn>());
		registerToken(std::make_shared<Newline>());
		registerToken(std::make_shared<Tab>());

	}

	// 語彙に対応するトークンを探す
	TokenManager::TokenPointer TokenManager::searchToken(
		// 語彙
		LEXEME_TYPE lexeme
	)
	{
		for (auto token : registeredTokens)
		{
			if (isSameLexeme(token->getLexeme(), lexeme))
			{
				return token;
			}
		}

		// 対応する語彙がない場合はエラー
		JF_SYSTEM_ERROR("Invalid Lexeme!");

		return nullptr;
	}

	// ソース文字列から次のトークンを取得する
	TokenManager::TokenPointer TokenManager::getNextToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		for (auto token : registeredTokens)
		{
			if (token->isFindToken(info))
			{
				return token;
			}
		}

		// 何も見つからない場合は進める

		// 対応する語彙がない場合はエラー
		// TODO: file出力
		JF_COMPILE_ERROR("TODO: source file path", info.line, std::string("Invalid Token!"));

		return nullptr;
	}

	// トークンを登録する
	void TokenManager::registerToken(TokenPointer token)
	{
		registeredTokens.push_back(token);
	}
}
