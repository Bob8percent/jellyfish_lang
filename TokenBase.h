#pragma once
#include "TokenDefine.h"
#include "Scanner.h"

namespace jf
{
	// TODO: �e�g�[�N���I�u�W�F�N�g��1�ł��邱�Ƃ�ۏ؂��������V���O���g���ɂ��ׂ��H
	class Token
	{
	public:
		using size_type = std::size_t;

	public:
		// �f�t�H���g�R���X�g���N�^
		Token();
		// �R���X�g���N�^
		Token(
			// �g�[�N���ɑΉ������b
			 LEXEME_TYPE lexeme
		);

	public:
		// �g�[�N���ɑΉ������b���擾
		LEXEME_TYPE getLexeme() const
		{
			return m_lexeme;
		}

		// �\�[�X�����񂩂�g�[�N���������邩
		virtual bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		);

	protected:
		// ���ݎQ�ƒ��̈ʒu���猟�����ă\�[�X�R�[�h��lexeme�Ŏn�܂邩
		bool isBeginWithThisLexeme(
			// �X�L���i�̏��
			const Scanner::Info& info,
			// �����Ώۂ̌�b
			LEXEME_TYPE lexeme
		);

	protected:
		// �g�[�N���ɑΉ������b
		 LEXEME_TYPE m_lexeme;
	};
}