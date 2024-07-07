#pragma once
#include "pch.h"
#include "TokenBase.h"

namespace jf
{
	// (
	class LeftParen :public Token
	{
	public:
		// �R���X�g���N�^
		LeftParen();
	};
	// )
	class RightParen :public Token
	{
	public:
		// �R���X�g���N�^
		RightParen();
	};
	// {
	class LeftBrace :public Token
	{
	public:
		// �R���X�g���N�^
		LeftBrace();
	};
	// }
	class RightBrace :public Token
	{
	public:
		// �R���X�g���N�^
		RightBrace();
	};
	// ,
	class Comma :public Token
	{
	public:
		// �R���X�g���N�^
		Comma();
	};
	// .
	class Dot :public Token
	{
	public:
		// �R���X�g���N�^
		Dot();
	};
	// ;
	class Semicoron :public Token
	{
	public:
		// �R���X�g���N�^
		Semicoron();
	};
	// +
	class Plus :public Token
	{
	public:
		// �R���X�g���N�^
		Plus();
	};
	// -
	class Minus :public Token
	{
	public:
		// �R���X�g���N�^
		Minus();
	};
	// /
	class Slash :public Token
	{
	public:
		// �R���X�g���N�^
		Slash();

		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// *
	class Star :public Token
	{
	public:
		// �R���X�g���N�^
		Star();
	};
	// !
	class Bang :public Token
	{
	public:
		// �R���X�g���N�^
		Bang();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// !=
	class BangEqual :public Token
	{
	public:
		// �R���X�g���N�^
		BangEqual();
	};
	// =
	class Equal :public Token
	{
	public:
		// �R���X�g���N�^
		Equal();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// ==
	class EqualEqual :public Token
	{
	public:
		// �R���X�g���N�^
		EqualEqual();
	};
	// >
	class Greater :public Token
	{
	public:
		// �R���X�g���N�^
		Greater();		
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// >=
	class GreaterEqual :public Token
	{
	public:
		// �R���X�g���N�^
		GreaterEqual();
	};
	// <
	class Less :public Token
	{
	public:
		// �R���X�g���N�^
		Less();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// <=
	class LessEqual :public Token
	{
	public:
		// �R���X�g���N�^
		LessEqual();
	};
	// //
	class Comment :public Token
	{
	public:
		// �R���X�g���N�^
		Comment();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// \r
	class CReturn :public Token
	{
	public:
		// �R���X�g���N�^
		CReturn();
	};
	// \n
	class Newline :public Token
	{
	public:
		// �R���X�g���N�^
		Newline();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// \t
	class Tab :public Token
	{
	public:
		// �R���X�g���N�^
		Tab();
	};
	// \"
	class String :public Token
	{
	public:
		// �R���X�g���N�^
		String();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;

	private:
		// "�ň͂܂�镶����
		std::string m_value;
	};
	// ���l (TODO: ���������_�̂ݑΉ��B�����I�ɂق��̐��l�^���Ή��������B)
	class Number :public Token
	{
	public:
		// �R���X�g���N�^
		Number();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;

	private:
		// "�ň͂܂�镶����
		float m_value;
	};
	// ���ʎq
	class Identifier :public Token
	{
	public:
		// �R���X�g���N�^
		Identifier();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;

	public:
		// �\�[�X�����񂩂�P��𔲂��o�����q��֐�Func�𖞂��������肷��
		template <class Func>
		static bool extractAndJudge(
			// ����֐�
			Func&& func,
			// �X�L���i�̏��
			Scanner::Info& info,
			// �����o�����P����o�͂���o�b�t�@
			std::string* name = nullptr
		);
		// �\�[�X�����񂩂环�ʎq�𔲂��o��
		// �߂�l�F���ʎq�̍Ō�̕����̎��̃C���f�b�N�X
		static Scanner::size_type extractIdentifier(
			// �X�L���i���
			const Scanner::Info& info
		);
		// ch��_���A���t�@�x�b�g�ł��邩
		// �߂�l�F�ł���(true), �łȂ�(false)
		static bool isAlphaOrUnderbar(
			// �����Ώۂ̕���
			char ch
		);

	private:
		// ���ʎq��
		std::string m_name;
	};
	
	// or
	class Or :public Token
	{
	public:
		// �R���X�g���N�^
		Or();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// and
	class And :public Token
	{
	public:
		// �R���X�g���N�^
		And();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// false
	class False :public Token
	{
	public:
		// �R���X�g���N�^
		False();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// true
	class True :public Token
	{
	public:
		// �R���X�g���N�^
		True();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// if
	class If :public Token
	{
	public:
		// �R���X�g���N�^
		If();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// else
	class Else :public Token
	{
	public:
		// �R���X�g���N�^
		Else();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// for
	class For :public Token
	{
	public:
		// �R���X�g���N�^
		For();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// while
	class While :public Token
	{
	public:
		// �R���X�g���N�^
		While();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// Func
	class Func :public Token
	{
	public:
		// �R���X�g���N�^
		Func();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// return
	class Return :public Token
	{
	public:
		// �R���X�g���N�^
		Return();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// class
	class Class :public Token
	{
	public:
		// �R���X�g���N�^
		Class();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// super
	class Super :public Token
	{
	public:
		// �R���X�g���N�^
		Super();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// this
	class This :public Token
	{
	public:
		// �R���X�g���N�^
		This();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// var
	class Var :public Token
	{
	public:
		// �R���X�g���N�^
		Var();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// nil
	class Nil :public Token
	{
	public:
		// �R���X�g���N�^
		Nil();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
	// print
	class Print :public Token
	{
	public:
		// �R���X�g���N�^
		Print();
		// �\�[�X�����񂩂�g�[�N���������邩
		bool isFindToken(
			// �X�L���i�̏��
			Scanner::Info& info
		) override;
	};
}

