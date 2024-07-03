#include "pch.h"

#include "SystemMain.h"
#include "SystemDebug.h"

#include "Debug.h"
#include "TokenManager.h"

namespace jf
{
	SystemMain::SystemMain()
	{
		// トークンの登録
		TokenManager::registerTokens();
	}
	// ファイルを読み込み実行
	void SystemMain::runFile(
		// ファイルパス
		const std::string& path
	)
	{
		// ファイルを開く
		std::ifstream ifs{path, std::ios_base::in};
		if (!ifs.is_open())
		{
			JF_SYSTEM_ERROR("Can't open file.");
		}

		// ファイル内の内容を取得
		std::stringstream ss;
		ss << ifs.rdbuf();
		std::string source = ss.str();
		ifs.close();

		// ビルドを実行
		run(source);

		// エラーが発生すれば終了
		if (debug::getIsHadError())
		{
			return;
		}
	}

	// プロンプトを起動
	void SystemMain::runPrompt()
	{
		// コマンドプロンプトに入力されたコードを1行ずつ実行
		std::string line;
		while (1)
		{
			std::cout << "> ";
			if (!std::getline(std::cin, line))
				break;
			run(line);
		}
	}

	// 実行
	void SystemMain::run(
		// ソースコード文字列
		const std::string& source
	)
	{
		// スキャニング
		//jf::Scanner scanner(source);
		//std::vector<jf::Token> tokens = scanner.scanTokens();

		// 
		
	}
}


