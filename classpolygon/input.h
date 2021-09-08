//===================================================================
//
// �E�C���h�E�̏����@[input.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//=================================================================================================
//�C���v�b�g�̃N���X
//=================================================================================================
class CInput
{
public:
	CInput();
	virtual ~CInput();

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);			//����������
	virtual void Uninit(void);										//�I������
	virtual void Update(void) = 0;									//�X�V����

protected:
	LPDIRECTINPUTDEVICE8 m_pDevice;
	static LPDIRECTINPUT8 m_pInput;
	
};

class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);			//�L�[�{�[�h�̏���������
	void Uninit(void);										//�I������
	void Update(void);										//�X�V����
	bool GetPress(int nKey);								//�L�[�{�[�h�v���X
	bool GetTrigger(int nKey);								//�L�[�{�[�h�g���K�[
private:
	BYTE m_aKeyState[256];
	BYTE m_aKeyStateTrigger[256];																			//�L�[�{�[�h���
	BYTE m_aKeyStateRelese[256];																			//�����[�X���
	BYTE m_aKeyStateRepeat[256];																			//�L�[���s�[�g���
	int m_aCountRepeat[256];																				//�L�[���s�[�g�J�E���^�[
};


#endif
