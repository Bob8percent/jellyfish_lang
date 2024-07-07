#pragma once

// ソースコードのエラー処理
namespace jf::debug
{
// コンパイル時のエラー処理のインターフェース
#define JF_COMPILE_ERROR(file, line, message) jf::debug::compile_error(file, line, message)

	// コンパイル時のエラーを処理
	void compile_error(
		// エラーが起きたソースファイル
		const std::string& file,
		// エラーが起きた行
		std::size_t line,
		// エラーメッセージ
		const std::string& message
	);

	// ログ処理
	void log(
		// ログのタイプ
		const std::string& type,
		// ログを出力するファイル
		const std::string& file,
		// ログを出力する行
		std::size_t line,
		// 出力メッセージ
		const std::string& message
	);

	// エラー状態をセット
	void setIsHadError(
		bool isError
	);
	// エラー状態を取得
	bool getIsHadError();
}

