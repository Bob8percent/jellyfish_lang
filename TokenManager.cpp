#include "pch.h"
#include "SystemDebug.h"

#include "Debug.h"
#include "TokenManager.h"
#include "Tokens.h"
#include "Scanner.h"

namespace jf
{
	// �R���p�C���������g�[�N�������ׂēo�^����
	void TokenManager::registerTokens()
	{
		// �L���g�[�N���̓o�^
		registerToken(std::make_shared<LeftParen>());
		registerToken(std::make_shared<RightParen>());
		registerToken(std::make_shared<LeftBrace>());
		registerToken(std::make_shared<RightBrace>());
		registerToken(std::make_shared<Comma>());
		registerToken(std::make_shared<Dot>());
		registerToken(std::make_shared<Semicoron>());
		registerToken(std::make_shared<Plus>());
		registerToken(std::make_shared<Minus>());
		registerToken(std::make_shared<Slash>());
		registerToken(std::make_shared<Star>());
		registerToken(std::make_shared<Bang>());
		registerToken(std::make_shared<BangEqual>());
		registerToken(std::make_shared<Equal>());
		registerToken(std::make_shared<EqualEqual>());
		registerToken(std::make_shared<Greater>());
		registerToken(std::make_shared<GreaterEqual>());
		registerToken(std::make_shared<Less>());
		registerToken(std::make_shared<LessEqual>());
		registerToken(std::make_shared<Comment>());
		registerToken(std::make_shared<CReturn>());
		registerToken(std::make_shared<Newline>());
		registerToken(std::make_shared<Tab>());

	}

	// ��b�ɑΉ�����g�[�N����T��
	TokenManager::TokenPointer TokenManager::searchToken(
		// ��b
		LEXEME_TYPE lexeme
	)
	{
		for (auto token : registeredTokens)
		{
			if (isSameLexeme(token->getLexeme(), lexeme))
			{
				return token;
			}
		}

		// �Ή������b���Ȃ��ꍇ�̓G���[
		JF_SYSTEM_ERROR("Invalid Lexeme!");

		return nullptr;
	}

	// �\�[�X�����񂩂玟�̃g�[�N�����擾����
	TokenManager::TokenPointer TokenManager::getNextToken(
		// �X�L���i�̏��
		Scanner::Info& info
	)
	{
		for (auto token : registeredTokens)
		{
			if (token->isFindToken(info))
			{
				return token;
			}
		}

		// ����������Ȃ��ꍇ�͐i�߂�

		// �Ή������b���Ȃ��ꍇ�̓G���[
		// TODO: file�o��
		JF_COMPILE_ERROR("TODO: source file path", info.line, std::string("Invalid Token!"));

		return nullptr;
	}

	// �g�[�N����o�^����
	void TokenManager::registerToken(TokenPointer token)
	{
		registeredTokens.push_back(token);
	}
}
