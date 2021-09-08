//===================================================================
//
// インプットの処理　[input.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "input.h"

//===========================================================================================================
//グローバル変数
//===========================================================================================================
LPDIRECTINPUT8 CInput::m_pInput = NULL;

//コンストラクタ
CInput::CInput()
{

}

//デストラクタ
CInput::~CInput()
{

}

//初期化処理
HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	/*HRESULT hr = S_FALSE;
	if (m_pInput = NULL)
	{
		hr = DirectInput8Create();
	}
	return hr;*/

	//DirectInputオブジェクトの生成
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}
	return S_OK;
}

//終了処理
void CInput::Uninit()
{
	if (m_pDevice != NULL)
	{
		//アクセス権の破棄
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
//初期化処理
//===========================================================================================================
HRESULT CInputKeyboard::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::Init(hInstance, hWnd);

	//入力デバイスの設定
	if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
	{
		return E_FAIL;
	}

	//データフォーマットの設定
	if (FAILED(m_pDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//協調モードの設定
	if (FAILED(m_pDevice->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//アクセス権の取得
	m_pDevice->Acquire();
	return S_OK;
}

//=================================================================================================
//終了処理
//=================================================================================================
void CInputKeyboard::Uninit(void)
{
	CInput::Uninit();

	if (m_pDevice != NULL)
	{
		//アクセス権の破棄
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
//更新処理
//=================================================================================================
void CInputKeyboard::Update(void)
{
	BYTE aKeyState[256];

	//デバイスからデータを取得
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
		//アクセス権の取得
		m_pDevice->Acquire();
	}
}

//=================================================================================================
//キーボード情報の取得
//=================================================================================================
bool CInputKeyboard::GetPress(int nKey)
{
	return(m_aKeyState[nKey] & 0x80) ? true	:	false;
}

//キーボードトリガー
bool CInputKeyboard::GetTrigger(int nKey)
{
	return(m_aKeyStateTrigger[nKey] & 0x80) ? true	:	false;
}