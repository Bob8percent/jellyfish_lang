#include "pch.h"
#include "SystemDebug.h"

namespace jf::sys_debug
{
	namespace
	{
		// エラーが起きたか
		bool isHadError = false;
	}

	// システムを異常終了させる
	void error(
		// エラーが起きたファイル
		const std::string& file,
		// エラーが起きた行
		unsigned line,
		// エラーメッセージ
		const std::string& message
	)
	{
		log("ERROR", file, line, message);
		std::abort();
	}

	// ログ処理
	void log(
		// ログのタイプ
		const std::string& type,
		// ログを出力するファイル
		const std::string& file,
		// ログを出力する行
		unsigned line,
		// 出力メッセージ
		const std::string& message
	)
	{
		// ログ出力
		std::printf("!%s! %s l%d, %s\n",
			type.c_str(), file.c_str(), line, message.c_str());
	}
}
