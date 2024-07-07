#pragma once

namespace jf::sys_debug
{

// �V�X�e���̃G���[�����̃C���^�[�t�F�[�X
#define JF_SYSTEM_ERROR(message) jf::sys_debug::error(__FILE__, __LINE__, message)

	// �V�X�e�����ُ�I��������
	void error(
		// �G���[���N�����t�@�C��
		const std::string& file,
		// �G���[���N�����s
		std::size_t line,
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
		std::size_t line,
		// �o�̓��b�Z�[�W
		const std::string& message
	);
}

