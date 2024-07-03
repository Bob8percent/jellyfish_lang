#pragma once

// �\�[�X�R�[�h�̃G���[����
namespace jf::debug
{
// �R���p�C�����̃G���[�����̃C���^�[�t�F�[�X
#define JF_COMPILE_ERROR(file, line, message) jf::debug::compile_error(file, line, message)

	// �R���p�C�����̃G���[������
	void compile_error(
		// �G���[���N�����\�[�X�t�@�C��
		const std::string& file,
		// �G���[���N�����s
		unsigned line,
		// �G���[���b�Z�[�W
		const std::string& message
	);

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
	);

	// �G���[��Ԃ��Z�b�g
	void setIsHadError(
		bool isError
	);
	// �G���[��Ԃ��擾
	bool getIsHadError();
}

