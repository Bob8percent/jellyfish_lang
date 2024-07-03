#include "pch.h"
#include "Scanner.h"
#include "TokenManager.h"
#include "TokenDefine.h"

namespace jf
{
	// �Q�ƈʒu���\�[�X�R�[�h�̍Ō�ɓ��B������
	bool Scanner::Info::isReachSourceEnd(
		// ���ݎQ�ƈʒu����̃I�t�Z�b�g
		size_type offset
	) const
	{
		return source.length() <= (current + offset);
	}

	// �R���X�g���N�^
	Scanner::Scanner(
		// �X�L�����Ώۂ̃\�[�X�R�[�h������
		const std::string& source
	)
		:m_info{ 0, 0, source },
		m_tokens{}
	{
	}

	// �\�[�X��������X�L�������ăg�[�N������擾
	std::vector<Scanner::TokenPointer> Scanner::scanTokens()
	{
		while (!isScanEnd())
		{
			scanToken();
		}

		// EOF��ǉ�
		addEOF();

		return m_tokens;
	}

	// �X�L�������I��������
	bool Scanner::isScanEnd() const
	{
		return m_info.isReachSourceEnd(0);
	}

	// �\�[�X��������X�L��������1�����g�[�N�����擾
	void Scanner::scanToken()
	{
		// �\�[�X�����񂩂�g�[�N�����擾
		auto token = TokenManager::getNextToken(m_info);

		// �擾�����g�[�N����o�^
		m_tokens.push_back(token);
	}

	// EOF��ǉ�
	void Scanner::addEOF()
	{
		// EOF�g�[�N���ւ̃|�C���^���擾
		auto eof = TokenManager::searchToken(END_OF_FILE);

		// EOF��ǉ�
		m_tokens.push_back(eof);
	}
}
