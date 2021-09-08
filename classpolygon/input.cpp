//===================================================================
//
// �C���v�b�g�̏����@[input.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "input.h"

//===========================================================================================================
//�O���[�o���ϐ�
//===========================================================================================================
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//�R���X�g���N�^
CInput::CInput()
{

}

//�f�X�g���N�^
CInput::~CInput()
{

}

//����������
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	/*HRESULT hr = S_FALSE;
	if (m_pInput = NULL)
	{
		hr = DirectInput8Create();
	}
	return hr;*/

	//DirectInput�I�u�W�F�N�g�̐���
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	return S_OK;
}

//�I������
void CInput::Uninit()
{
	if (m_pDevice != NULL)
	{
		//�A�N�Z�X���̔j��
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
		if (m_pInput != NULL)
		{
			m_pInput->Release();
			m_pInput = NULL;
		}
	}
}

CInputKeyboard::CInputKeyboard()
{
}

CInputKeyboard::~CInputKeyboard()
{
}

//===========================================================================================================
//����������
//===========================================================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//���̓f�o�C�X�̐ݒ�
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//�f�[�^�t�H�[�}�b�g�̐ݒ�
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������[�h�̐ݒ�
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�A�N�Z�X���̎擾
	m_pDevice->Acquire();
	return S_OK;
}

//=================================================================================================
//�I������
//=================================================================================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();

	if (m_pDevice != NULL)
	{
		//�A�N�Z�X���̔j��
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
		if (m_pInput != NULL)
		{
			m_pInput->Release();
			m_pInput = NULL;
		}
	}
}

//=================================================================================================
//�X�V����
//=================================================================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[256];

	//�f�o�C�X����f�[�^���擾
  	if (SUCCEEDED(m_pDevice->GetDeviceState(sizeof(aKeyState), &aKeyState[0])))
	{
		for (int nKey = 0; nKey < 256; nKey++)
		{
			m_aKeyStateTrigger[nKey] = (~m_aKeyState[nKey])&aKeyState[nKey];
			m_aKeyState[nKey] = aKeyState[nKey];
		}
	}
	else
	{
		//�A�N�Z�X���̎擾
		m_pDevice->Acquire();
	}
}

//=================================================================================================
//�L�[�{�[�h���̎擾
//=================================================================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return(m_aKeyState[nKey] & 0x80) ? true	:	false;
}

//�L�[�{�[�h�g���K�[
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) ? true	:	false;
}