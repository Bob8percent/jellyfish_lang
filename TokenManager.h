#pragma once
#include "TokenDefine.h"
#include "Scanner.h"

namespace jf
{
	class Token;

	// Token��o�^�Ǘ����邾����static�N���X
	class TokenManager
	{
	public:
		using size_type = std::size_t;
		using TokenPointer = std::shared_ptr<Token>;

	public:
		// �R���p�C���������g�[�N�������ׂēo�^����
		static void registerTokens();

		// ��b�ɑΉ�����g�[�N����T��
		static TokenPointer searchToken(
			// ��b
			LEXEME_TYPE lexeme
		);

		// �\�[�X�����񂩂玟�̃g�[�N�����擾����
		static TokenPointer getNextToken(
			// �X�L���i�̏��
			Scanner::Info& info
		);

	private:
		// �g�[�N����o�^����
		static void registerToken(TokenPointer token);

	private:
		// �o�^�g�[�N��
		inline static std::vector<TokenPointer> registeredTokens{};
	};
}
