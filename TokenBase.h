#pragma once
#include "TokenDefine.h"
#include "Scanner.h"

namespace jf
{
	// TODO: 各トークンオブジェクトは1つであることを保証したい→シングルトンにすべき？
	class Token
	{
	public:
		using size_type = std::size_t;

	public:
		// デフォルトコンストラクタ
		Token();
		// コンストラクタ
		Token(
			// トークンに対応する語彙
			 LEXEME_TYPE lexeme
		);

	public:
		// トークンに対応する語彙を取得
		LEXEME_TYPE getLexeme() const
		{
			return m_lexeme;
		}

		// ソース文字列からトークンが見つかるか
		virtual bool isFindToken(
			// スキャナの情報
			Scanner::Info& info
		);

	protected:
		// 現在参照中の位置から検索してソースコードがlexemeで始まるか
		bool isBeginWithThisLexeme(
			// スキャナの情報
			const Scanner::Info& info,
			// 検索対象の語彙
			LEXEME_TYPE lexeme
		);

	protected:
		// トークンに対応する語彙
		 LEXEME_TYPE m_lexeme;
	};
}