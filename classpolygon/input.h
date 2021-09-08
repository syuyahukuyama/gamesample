//===================================================================
//
// ウインドウの処理　[input.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//=================================================================================================
//インプットのクラス
//=================================================================================================
class CInput
{
public:
	CInput();
	virtual ~CInput();

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);			//初期化処理
	virtual void Uninit(void);										//終了処理
	virtual void Update(void) = 0;									//更新処理

protected:
	LPDIRECTINPUTDEVICE8 m_pDevice;
	static LPDIRECTINPUT8 m_pInput;
	
};

class CInputKeyboard : public CInput
{
public:
	CInputKeyboard();
	~CInputKeyboard();
	
	HRESULT Init(HINSTANCE hInstance, HWND hWnd);			//キーボードの初期化処理
	void Uninit(void);										//終了処理
	void Update(void);										//更新処理
	bool GetPress(int nKey);								//キーボードプレス
	bool GetTrigger(int nKey);								//キーボードトリガー
private:
	BYTE m_aKeyState[256];
	BYTE m_aKeyStateTrigger[256];																			//キーボード情報
	BYTE m_aKeyStateRelese[256];																			//リリース情報
	BYTE m_aKeyStateRepeat[256];																			//キーリピート情報
	int m_aCountRepeat[256];																				//キーリピートカウンター
};


#endif
