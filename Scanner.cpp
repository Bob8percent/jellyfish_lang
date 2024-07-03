#include "pch.h"
#include "Scanner.h"
#include "TokenManager.h"
#include "TokenDefine.h"

namespace jf
{
	// 参照位置がソースコードの最後に到達したか
	bool Scanner::Info::isReachSourceEnd(
		// 現在参照位置からのオフセット
		size_type offset
	) const
	{
		return source.length() <= (current + offset);
	}

	// コンストラクタ
	Scanner::Scanner(
		// スキャン対象のソースコード文字列
		const std::string& source
	)
		:m_info{ 0, 0, source },
		m_tokens{}
	{
	}

	// ソース文字列をスキャンしてトークン列を取得
	std::vector<Scanner::TokenPointer> Scanner::scanTokens()
	{
		while (!isScanEnd())
		{
			scanToken();
		}

		// EOFを追加
		addEOF();

		return m_tokens;
	}

	// スキャンが終了したか
	bool Scanner::isScanEnd() const
	{
		return m_info.isReachSourceEnd(0);
	}

	// ソース文字列をスキャンして1つだけトークンを取得
	void Scanner::scanToken()
	{
		// ソース文字列からトークンを取得
		auto token = TokenManager::getNextToken(m_info);

		// 取得したトークンを登録
		m_tokens.push_back(token);
	}

	// EOFを追加
	void Scanner::addEOF()
	{
		// EOFトークンへのポインタを取得
		auto eof = TokenManager::searchToken(END_OF_FILE);

		// EOFを追加
		m_tokens.push_back(eof);
	}
}
