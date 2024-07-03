#pragma once
#include "pch.h"

namespace jf
{
	// jellyfish言語のメインインターフェース
	class SystemMain
	{
	public:
		// コンストラクタ
		SystemMain();

	public:
		// ファイルを読み込み実行
		void runFile(
			// ファイルパス
			const std::string& path
		);

		// プロンプトを起動
		void runPrompt();

	private:
		// 実行
		void run(
			// ソースコード文字列
			const std::string& source
		);
	};
}