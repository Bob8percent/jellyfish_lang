#pragma once

namespace jf
{
	class Token;
	class Scanner
	{
	public:
		using size_type = std::size_t;
		using TokenPointer = std::shared_ptr<Token>;

		// ���݂̏��������\����
		struct Info
		{
			// �\�[�X������̌��ݎQ�ƒ��̃C���f�b�N�X
			size_type current;
			// �\�[�X������̌��݂̍s
			size_type line;
			// �\�[�X������
			const std::string source;

			// �Q�ƈʒu���\�[�X�R�[�h�̍Ō�ɓ��B������
			bool isReachSourceEnd(
				// ���ݎQ�ƈʒu����̃I�t�Z�b�g
				size_type offset
			) const;
		};

	public:
		// �R���X�g���N�^
		Scanner(
			// �X�L�����Ώۂ̃\�[�X�R�[�h������
			const std::string& source
		);

		// �\�[�X��������X�L�������ăg�[�N������擾
		std::vector<TokenPointer> scanTokens();

	private:
		// �X�L�������I��������
		bool isScanEnd() const;

		// �\�[�X��������X�L��������1�����g�[�N�����擾
		void scanToken();

		// EOF��ǉ�
		void addEOF();

	private:
		// ���݂̏󋵂��������
		Info m_info;
		// �X�L�������Ď擾�����g�[�N����
		std::vector<TokenPointer> m_tokens;
	};
}