#include "pch.h"
#include "Debug.h"

namespace jf::debug
{
	namespace
	{
		// エラーが起きたか
		bool isHadError = false;
	}

	// コンパイル時のエラー処理
	void compile_error(
		// エラーが起きたソースファイル
		const std::string& file,
		// エラーが起きた行
		unsigned line,
		// エラーメッセージ
		const std::string& message
	)
	{
		log("COMPILE ERROR", file, line, message);
		setIsHadError(true);
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
		std::printf("[%s] %s l%d, %s\n",
			type.c_str(), file.c_str(), line, message.c_str());
	}

	// エラー状態をセット
	void setIsHadError(
		bool isError
	)
	{
		// TODO: ロック処理
		isHadError = isError;
	}

	// エラー状態を取得
	bool getIsHadError()
	{
		// TODO: ロック処理
		return isHadError;
	}
}
