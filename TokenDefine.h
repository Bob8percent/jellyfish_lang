#pragma once

namespace jf
{
	using LEXEME_TYPE = const char*;
	// �L��
	static constexpr LEXEME_TYPE LEFT_PAREN = "(";
	static constexpr LEXEME_TYPE RIGHT_PAREN = ")";
	static constexpr LEXEME_TYPE LEFT_BRACE = "{";
	static constexpr LEXEME_TYPE RIGHT_BRACE = "}";
	static constexpr LEXEME_TYPE COMMA = ",";
	static constexpr LEXEME_TYPE DOT = ".";
	static constexpr LEXEME_TYPE SEMICORON = ";";
	static constexpr LEXEME_TYPE PLUS = "+";
	static constexpr LEXEME_TYPE MINUS = "-";
	static constexpr LEXEME_TYPE SLASH = "/";
	static constexpr LEXEME_TYPE STAR = "*";
	static constexpr LEXEME_TYPE BANG = "!";
	static constexpr LEXEME_TYPE BANG_EQUAL = "!=";
	static constexpr LEXEME_TYPE EQUAL = "=";
	static constexpr LEXEME_TYPE EQUAL_EQUAL = "==";
	static constexpr LEXEME_TYPE GREATER = ">";
	static constexpr LEXEME_TYPE GREATER_EQUAL = ">=";
	static constexpr LEXEME_TYPE LESS = "<";
	static constexpr LEXEME_TYPE LESS_EQUAL = "<=";
	static constexpr LEXEME_TYPE COMMENT = "//";
	static constexpr LEXEME_TYPE CRETURN = "\r";
	static constexpr LEXEME_TYPE NEWLINE = "\n";
	static constexpr LEXEME_TYPE TAB = "\t";
	static constexpr LEXEME_TYPE STRING = "\"";

	// �L�[���[�h
	static constexpr LEXEME_TYPE AND = "and";
	static constexpr LEXEME_TYPE OR = "or";
	static constexpr LEXEME_TYPE FALSE = "false";
	static constexpr LEXEME_TYPE TRUE = "true";
	static constexpr LEXEME_TYPE IF = "if";
	static constexpr LEXEME_TYPE ELSE = "else";
	static constexpr LEXEME_TYPE FOR = "for";
	static constexpr LEXEME_TYPE WHILE = "while";
	static constexpr LEXEME_TYPE FUNC = "func";
	static constexpr LEXEME_TYPE RETURN = "return";
	static constexpr LEXEME_TYPE CLASS = "class";
	static constexpr LEXEME_TYPE SUPER = "super";
	static constexpr LEXEME_TYPE THIS = "this";
	static constexpr LEXEME_TYPE VAR = "var";
	static constexpr LEXEME_TYPE NIL = "nil";
	static constexpr LEXEME_TYPE PRINT = "print";

	static constexpr LEXEME_TYPE BLANK = " ";

	static constexpr LEXEME_TYPE END_OF_FILE = "";

	// �����œn������b��������
	// �߂�l�F����(true), �����ł͂Ȃ�(false)
	inline bool isSameLexeme(
		// ��r�Ώۂ̌�b1
		LEXEME_TYPE lexeme1,
		// ��r�Ώۂ̌�b2
		LEXEME_TYPE lexeme2
	)
	{
		return strcmp(lexeme1, lexeme2) == 0;
	}

	// lexeme�̒������擾����
	// �߂�l�Flexeme�̒���
	inline auto getLexemeStringLength(
		// �����Ώۂ̌�b
		LEXEME_TYPE lexeme
	)
	{
		return std::strlen(lexeme);
	}

	// word���L�[���[�h�ł��邩
	// NOTE: �n�b�V���}�b�v���g����������r���鐔�����Ȃ��̂ŕۗ�
	inline bool isKeyword(
		// �����Ώۂ̌�b
		LEXEME_TYPE word
	)
	{
		return(
			isSameLexeme(word, AND) ||
			isSameLexeme(word, OR) ||
			isSameLexeme(word, FALSE) ||
			isSameLexeme(word, TRUE) ||
			isSameLexeme(word, IF) ||
			isSameLexeme(word, ELSE) ||
			isSameLexeme(word, FOR) ||
			isSameLexeme(word, WHILE) ||
			isSameLexeme(word, FUNC) ||
			isSameLexeme(word, RETURN) ||
			isSameLexeme(word, CLASS) ||
			isSameLexeme(word, SUPER) ||
			isSameLexeme(word, THIS) ||
			isSameLexeme(word, VAR) ||
			isSameLexeme(word, NIL) ||
			isSameLexeme(word, PRINT)
			);
	}
}
