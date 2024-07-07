#include "pch.h"
#include "SystemDebug.h"

namespace jf::sys_debug
{
	namespace
	{
		// �G���[���N������
		bool isHadError = false;
	}

	// �V�X�e�����ُ�I��������
	void error(
		// �G���[���N�����t�@�C��
		const std::string& file,
		// �G���[���N�����s
		std::size_t line,
		// �G���[���b�Z�[�W
		const std::string& message
	)
	{
		log("ERROR", file, line, message);
		std::abort();
	}

	// ���O����
	void log(
		// ���O�̃^�C�v
		const std::string& type,
		// ���O���o�͂���t�@�C��
		const std::string& file,
		// ���O���o�͂���s
		std::size_t line,
		// �o�̓��b�Z�[�W
		const std::string& message
	)
	{
		// ���O�o��
		std::printf("!%s! %s l%zu, %s\n",
			type.c_str(), file.c_str(), line, message.c_str());
	}
}
