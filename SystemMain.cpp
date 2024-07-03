#include "pch.h"

#include "SystemMain.h"
#include "SystemDebug.h"

#include "Debug.h"
#include "TokenManager.h"

namespace jf
{
	SystemMain::SystemMain()
	{
		// �g�[�N���̓o�^
		TokenManager::registerTokens();
	}
	// �t�@�C����ǂݍ��ݎ��s
	void SystemMain::runFile(
		// �t�@�C���p�X
		const std::string& path
	)
	{
		// �t�@�C�����J��
		std::ifstream ifs{path, std::ios_base::in};
		if (!ifs.is_open())
		{
			JF_SYSTEM_ERROR("Can't open file.");
		}

		// �t�@�C�����̓��e���擾
		std::stringstream ss;
		ss << ifs.rdbuf();
		std::string source = ss.str();
		ifs.close();

		// �r���h�����s
		run(source);

		// �G���[����������ΏI��
		if (debug::getIsHadError())
		{
			return;
		}
	}

	// �v�����v�g���N��
	void SystemMain::runPrompt()
	{
		// �R�}���h�v�����v�g�ɓ��͂��ꂽ�R�[�h��1�s�����s
		std::string line;
		while (1)
		{
			std::cout << "> ";
			if (!std::getline(std::cin, line))
				break;
			run(line);
		}
	}

	// ���s
	void SystemMain::run(
		// �\�[�X�R�[�h������
		const std::string& source
	)
	{
		// �X�L���j���O
		//jf::Scanner scanner(source);
		//std::vector<jf::Token> tokens = scanner.scanTokens();

		// 
		
	}
}


