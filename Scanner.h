#pragma once

namespace jf
{
	class Token;
	class Scanner
	{
	public:
		using size_type = std::size_t;
		using TokenPointer = std::shared_ptr<Token>;

		// 現在の情報を示す構造体
		struct Info
		{
			// ソース文字列の現在参照中のインデックス
			size_type current;
			// ソース文字列の現在の行
			size_type line;
			// ソース文字列
			const std::string source;

			// 参照位置がソースコードの最後に到達したか
			bool isReachSourceEnd(
				// 現在参照位置からのオフセット
				size_type offset
			) const;
		};

	public:
		// コンストラクタ
		Scanner(
			// スキャン対象のソースコード文字列
			const std::string& source
		);

		// ソース文字列をスキャンしてトークン列を取得
		std::vector<TokenPointer> scanTokens();

	private:
		// スキャンが終了したか
		bool isScanEnd() const;

		// ソース文字列をスキャンして1つだけトークンを取得
		void scanToken();

		// EOFを追加
		void addEOF();

	private:
		// 現在の状況を示す情報
		Info m_info;
		// スキャンして取得したトークン列
		std::vector<TokenPointer> m_tokens;
	};
}