#pragma once
#include "pch.h"

namespace jf
{
	// jellyfish����̃��C���C���^�[�t�F�[�X
	class SystemMain
	{
	public:
		// �R���X�g���N�^
		SystemMain();

	public:
		// �t�@�C����ǂݍ��ݎ��s
		void runFile(
			// �t�@�C���p�X
			const std::string& path
		);

		// �v�����v�g���N��
		void runPrompt();

	private:
		// ���s
		void run(
			// �\�[�X�R�[�h������
			const std::string& source
		);
	};
}