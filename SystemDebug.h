#pragma once

namespace jf::sys_debug
{

// システムのエラー処理のインターフェース
#define JF_SYSTEM_ERROR(message) jf::sys_debug::error(__FILE__, __LINE__, message)

	// システムを異常終了させる
	void error(
		// エラーが起きたファイル
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
}

