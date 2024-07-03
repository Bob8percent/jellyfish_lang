#include "pch.h"
#include "TokenBase.h"
#include "TokenManager.h"

namespace jf
{
	// �f�t�H���g�R���X�g���N�^
	Token::Token()
		:m_lexeme{ "" }
	{
	}
	// �R���X�g���N�^
	Token::Token(
		// �g�[�N��������
		LEXEME_TYPE lexeme
	)
		:m_lexeme{ lexeme }
	{
	}

	// �\�[�X�����񂩂�g�[�N���������邩
	bool Token::isFindToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		auto isFind = isBeginWithThisLexeme(info, m_lexeme);
		// �g�[�N����������Ȃ�Q�ƈʒu���X�V
		if (isFind)
		{
			info.current += getLexemeStringLength(m_lexeme);
		}
		return isFind;
	}

	// ���ݎQ�ƒ��̈ʒu���猟�����ă\�[�X�R�[�h��lexeme�Ŏn�܂邩
	bool Token::isBeginWithThisLexeme(
		// �X�L���i�̏��
		const Scanner::Info& info,
		// �����Ώۂ̌�b
		LEXEME_TYPE lexeme
	)
	{
		auto lexeme_length = getLexemeStringLength(lexeme);

		// �����͈͂��\�[�X�R�[�h�T�C�Y�𒴂��Ă����ꍇ�͑����U�Ƃ���
		if (info.isReachSourceEnd(lexeme_length))
		{
			return false;
		}

		auto str_start = std::begin(info.source) + info.current;
		auto str_end = str_start + lexeme_length;

		return std::equal(
			str_start,
			str_end,
			lexeme
		);
	}
}
