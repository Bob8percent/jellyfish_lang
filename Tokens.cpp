#include "pch.h"
#include "Tokens.h"
#include "TokenDefine.h"
#include "Debug.h"

namespace jf
{
	// (
	// �R���X�g���N�^
	LeftParen::LeftParen()
		:Token{ LEFT_PAREN }
	{
	}
	// )
	// �R���X�g���N�^
	RightParen::RightParen()
		:Token{ RIGHT_PAREN }
	{
	}
	// {
	// �R���X�g���N�^
	LeftBrace::LeftBrace()
		:Token{ LEFT_BRACE }
	{
	}
	// }
	// �R���X�g���N�^
	RightBrace::RightBrace()
		:Token{ RIGHT_BRACE }
	{
	}
	// ,
	// �R���X�g���N�^
	Comma::Comma()
		:Token{ COMMA }
	{
	}
	// .
	// �R���X�g���N�^
	Dot::Dot()
		:Token{ DOT }
	{
	}
	// ;
	// �R���X�g���N�^
	Semicoron::Semicoron()
		:Token{ SEMICORON }
	{
	}
	// +
	// �R���X�g���N�^
	Plus::Plus()
		:Token{ PLUS }
	{
	}
	// -
	// �R���X�g���N�^
	Minus::Minus()
		:Token{ MINUS }
	{
	}
	// /
	// �R���X�g���N�^
	Slash::Slash()
		:Token{ SLASH }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Slash::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		// //��/�Ƃ̋�ʂ��K�v
		auto isFindComment = Token::isBeginWithThisLexeme(info, COMMENT);
		if (!isFindComment)
		{
			auto isFindSlash = Token::isFindToken(info);
			return isFindSlash;
		}
		return isFindComment;
	}
	// *
	// �R���X�g���N�^
	Star::Star()
		:Token{ STAR }
	{
	}
	// !
	// �R���X�g���N�^
	Bang::Bang()
		:Token{ BANG }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Bang::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		// !=��!�Ƃ̋�ʂ��K�v
		auto isFindBangEqual = Token::isBeginWithThisLexeme(info, BANG_EQUAL);
		if (!isFindBangEqual)
		{
			auto isFindBang = Token::isFindToken(info);
			return isFindBang;
		}
		return isFindBangEqual;
	}
	// !=
	// �R���X�g���N�^
	BangEqual::BangEqual()
		:Token{ BANG_EQUAL }
	{
	}
	// =
	// �R���X�g���N�^
	Equal::Equal()
		:Token{ EQUAL }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Equal::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		// =��==�Ƃ̋�ʂ��K�v
		auto isFindEqualEqual = Token::isBeginWithThisLexeme(info, EQUAL_EQUAL);
		if (!isFindEqualEqual)
		{
			auto isFindEqual = Token::isFindToken(info);
			return isFindEqual;
		}
		return isFindEqualEqual;
	}
	// ==
	// �R���X�g���N�^
	EqualEqual::EqualEqual()
		:Token{ EQUAL_EQUAL }
	{
	}
	// >
	// �R���X�g���N�^
	Greater::Greater()
		:Token{ GREATER }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Greater::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		// >��>=�Ƃ̋�ʂ��K�v
		auto isFindGreaterEqual = Token::isBeginWithThisLexeme(info, GREATER_EQUAL);
		if (!isFindGreaterEqual)
		{
			auto isFindGreater = Token::isFindToken(info);
			return isFindGreater;
		}
		return isFindGreaterEqual;
	}
	// >=
	// �R���X�g���N�^
	GreaterEqual::GreaterEqual()
		:Token{ GREATER_EQUAL }
	{
	}
	// <
	// �R���X�g���N�^
	Less::Less()
		:Token{ LESS }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Less::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		// <��<=�Ƃ̋�ʂ��K�v
		auto isFindLessEqual = Token::isBeginWithThisLexeme(info, LESS_EQUAL);
		if (!isFindLessEqual)
		{
			auto isFindLess = Token::isFindToken(info);
			return isFindLess;
		}
		return isFindLessEqual;
	}
	// <=
	// �R���X�g���N�^
	LessEqual::LessEqual()
		:Token{ LESS_EQUAL }
	{
	}
	// //
	// �R���X�g���N�^
	Comment::Comment()
		:Token{ COMMENT }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Comment::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// �g�[�N����������Ȃ�Q�ƈʒu���X�V
		if (isFind)
		{
			// ���s�ʒu�܂ōX�V
			while (!isBeginWithThisLexeme(info, RETURN))
			{
				// ���s������������Ȃ��܂܃\�[�X�̍Ō�ɓ��B�����ꍇ
				if (info.isReachSourceEnd(0))
				{
					return isFind;
				}
				info.current += 1;
			}
			info.line += 1;
		}
		return isFind;
	}
	// \r
	// �R���X�g���N�^
	CReturn::CReturn()
		:Token{ CRETURN }
	{
	}
	// \n
	// �R���X�g���N�^
	Newline::Newline()
		:Token{ NEWLINE }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Newline::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		if (Token::isFindToken(info))
		{
			info.line += 1;
			return true;
		}
		return false;
	}

	// \t
	// �R���X�g���N�^
	Tab::Tab()
		:Token{ TAB }
	{
	}
	
	// "
	// �R���X�g���N�^
	String::String()
		:Token{ STRING },
		m_value{}
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool String::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// �g�[�N����������Ȃ�Q�ƈʒu���X�V
		if (isFind)
		{
			size_type start_index = info.current;
			// ����"�܂ōX�V
			while (!isBeginWithThisLexeme(info, STRING))
			{
				// "��������Ȃ��܂܃\�[�X�̍Ō�ɓ��B�����ꍇ
				if (info.isReachSourceEnd(0))
				{
					JF_COMPILE_ERROR("TODO:source file path", info.line,
						"String not closed with \"!");
					return isFind;
				}
				// ������̓r���ŉ��s����Ă����ꍇ
				if (isBeginWithThisLexeme(info, RETURN))
				{
					info.line += 1;
				}

				info.current += 1;
			}
			auto str_length = (info.current - start_index + 1);
			m_value = info.source.substr(start_index, str_length);
		}
		return isFind;
	}

	// ���l
	// �R���X�g���N�^
	Number::Number()
		:Token{},
		m_value{}
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Number::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		auto start_index = info.current;

		// [0-9]�����̘A�����擾
		while (std::isdigit(info.source[info.current]))
		{
			++info.current;
		}
		// [0-9]������1��������Ȃ������ꍇ�͑����U�Ƃ���
		if (start_index == info.current)
		{
			return false;
		}

		// �����_�����邩�`�F�b�N
		if (isBeginWithThisLexeme(info, "."))
		{
			bool isExistDecimalPoint = false;
			while (std::isdigit(info.source[info.current]))
			{
				isExistDecimalPoint = true;
				++info.current;
			}
			// �����_������̂ɏ����_�ȉ��̐��l�����݂��Ȃ��ꍇ�G���[
			if (!isExistDecimalPoint)
			{
				JF_COMPILE_ERROR("TODO:source file path", info.line,
					"Invalid Decimal Point!");
			}
		}

		// �����񂩂珬���_�ւ̕ϊ�
		auto number_length = info.current - start_index + 1;
		auto number_str = info.source.substr(start_index, number_length);
		m_value = std::stof(number_str);

		return true;
	}

	// ���ʎq
	// �R���X�g���N�^
	Identifier::Identifier()
		:Token{},
		m_name{}
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Identifier::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{

		// �L�[���[�h�����ʎq�̏����𖞂����̂ŁA�L�[���[�h�ł��邩�̊m�F���K�v
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return !isKeyword(word.c_str());
			},
			info,
			&m_name
		);
	}

	// �\�[�X�����񂩂�P��𔲂��o�����q��֐�Func�𖞂��������肷��
	template <class Func>
	bool Identifier::extractAndJudge(
		// ����֐�
		Func&& func,
		// �X�L���i�̏��
		Scanner::Info& info,
		// �����o�����P����o�͂���o�b�t�@
		std::string* name
	)
	{
		// �\�[�X�����񂩂�P��𔲂��o��
		auto identifier_length = Identifier::extractIdentifier(info) - info.current + 1;
		auto identifier = info.source.substr(info.current, identifier_length);

		// �P�ꂪ�����𖞂������𒲂ׂ�
		if (std::invoke(func, identifier.c_str()))
		{
			if (name != nullptr)
				*name = identifier;
			info.current += identifier.length();
			return true;
		}
		return false;
	}

	// �\�[�X�����񂩂环�ʎq�𔲂��o��
	// �߂�l�F���ʎq�̍Ō�̕����̎��̃C���f�b�N�X
	Scanner::size_type Identifier::extractIdentifier(
		// �X�L���i���
		const Scanner::Info& info
	)
	{
		auto identifier_end_index = info.current;
		while (Identifier::isAlphaOrUnderbar(info.source[identifier_end_index]))
		{
			++identifier_end_index;
		}
		return identifier_end_index;
	}
	// ch��_���A���t�@�x�b�g�ł��邩
	// �߂�l�F�ł���(true), �łȂ�(false)
	bool Identifier::isAlphaOrUnderbar(
		// �����Ώۂ̕���
		char ch
	)
	{
		return std::isalpha(ch) && (ch == '_');
	}

	// or
	// �R���X�g���N�^
	Or::Or()
		:Token{ OR }
	{

	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Or::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), OR);
			},
			info
		);
	}
	// and
	// �R���X�g���N�^
	And::And()
		:Token{ AND }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool And::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), AND);
			},
			info
		);
	}
	// false
	// �R���X�g���N�^
	False::False()
		:Token{ FALSE }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool False::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FALSE);
			},
			info
		);
	}
	// true
	// �R���X�g���N�^
	True::True()
		:Token{ TRUE }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool True::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), TRUE);
			},
			info
		);
	}
	// if
	If::If()
		:Token{ IF }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool If::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), IF);
			},
			info
		);
	}
	// else
	// �R���X�g���N�^
	Else::Else()
		:Token{ ELSE }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Else::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), ELSE);
			},
			info
		);
	}
	// for
	// �R���X�g���N�^
	For::For()
		:Token{ FOR }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool For::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FOR);
			},
			info
		);
	}
	// while
	// �R���X�g���N�^
	While::While()
		:Token{ WHILE }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool While::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), WHILE);
			},
			info
		);
	}
	// Func
	// �R���X�g���N�^
	Func::Func()
		:Token{ FUNC }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Func::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), FUNC);
			},
			info
		);
	}
	// return
	// �R���X�g���N�^
	Return::Return()
		:Token{ RETURN }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Return::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), RETURN);
			},
			info
		);

	}
	// class
	// �R���X�g���N�^
	Class::Class()
		:Token{ CLASS }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Class::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), CLASS);
			},
			info
		);
	}
	// super
	// �R���X�g���N�^
	Super::Super()
		:Token{ SUPER }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Super::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), SUPER);
			},
			info
		);
	}
	// this
	// �R���X�g���N�^
	This::This()
		:Token{ THIS }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool This::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	) 
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), THIS);
			},
			info
		);
	}
	// var
	// �R���X�g���N�^
	Var::Var()
		:Token{ VAR }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Var::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), VAR);
			},
			info
		);
	}
	// nil
	// �R���X�g���N�^
	Nil::Nil()
		:Token{NIL}
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Nil::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), NIL);
			},
			info
		);
	}
	// print
	// �R���X�g���N�^
	Print::Print()
		:Token{ PRINT }
	{
	}
	// �\�[�X�����񂩂�g�[�N���������邩
	bool Print::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		return Identifier::extractAndJudge(
			[](const std::string& word)
			{
				return isSameLexeme(word.c_str(), PRINT);
			},
			info
		);
	}
}
