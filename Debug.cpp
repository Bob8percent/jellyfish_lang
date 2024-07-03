#include "pch.h"
#include "Debug.h"

namespace jf::debug
{
	namespace
	{
		// �G���[���N������
		bool isHadError = false;
	}

	// �R���p�C�����̃G���[����
	void compile_error(
		// �G���[���N�����\�[�X�t�@�C��
		const std::string& file,
		// �G���[���N�����s
		unsigned line,
		// �G���[���b�Z�[�W
		const std::string& message
	)
	{
		log("COMPILE ERROR", file, line, message);
		setIsHadError(true);
	}

	// ���O����
	void log(
		// ���O�̃^�C�v
		const std::string& type,
		// ���O���o�͂���t�@�C��
		const std::string& file,
		// ���O���o�͂���s
		unsigned line,
		// �o�̓��b�Z�[�W
		const std::string& message
	)
	{
		// ���O�o��
		std::printf("[%s] %s l%d, %s\n",
			type.c_str(), file.c_str(), line, message.c_str());
	}

	// �G���[��Ԃ��Z�b�g
	void setIsHadError(
		bool isError
	)
	{
		// TODO: ���b�N����
		isHadError = isError;
	}

	// �G���[��Ԃ��擾
	bool getIsHadError()
	{
		// TODO: ���b�N����
		return isHadError;
	}
}
