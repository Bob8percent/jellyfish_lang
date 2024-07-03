#include "pch.h"
#include "TokenBase.h"
#include "TokenManager.h"

namespace jf
{
	// デフォルトコンストラクタ
	Token::Token()
		:m_lexeme{ "" }
	{
	}
	// コンストラクタ
	Token::Token(
		// トークン文字列
		LEXEME_TYPE lexeme
	)
		:m_lexeme{ lexeme }
	{
	}

	// ソース文字列からトークンが見つかるか
	bool Token::isFindToken(
		// スキャナの情報
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// トークンが見つかるなら参照位置を更新
		if (isFind)
		{
			info.current += getLexemeStringLength(m_lexeme);
		}
		return isFind;
	}

	// 現在参照中の位置から検索してソースコードがlexemeで始まるか
	bool Token::isBeginWithThisLexeme(
		// スキャナの情報
		const Scanner::Info& info,
		// 検索対象の語彙
		LEXEME_TYPE lexeme
	)
	{
		auto lexeme_length = getLexemeStringLength(lexeme);

		// 検索範囲がソースコードサイズを超えていた場合は即時偽とする
		if (info.isReachSourceEnd(lexeme_length))
		{
			return false;
		}

		auto str_start = std::begin(info.source) + info.current;
		auto str_end = str_start + lexeme_length;

		return std::equal(
			str_start,
			str_end,
			lexeme
		);
	}
}
