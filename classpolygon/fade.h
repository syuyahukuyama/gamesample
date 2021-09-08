//===================================================================
//
// フェードの処理　[fade.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _FADE_H_
#define _FADE_H_

#include "main.h"
#include "manager.h"

class CSceneSecond;

//フェードのクラス
class CFade
{
public:
	typedef enum
	{
		FADE_NONE = 0,		//何もしていない
		FADE_IN,			//フェードイン
		FADE_OUT,			//フェードアウト
		FADE_MAX,
	}FADE;
	CFade();
	~CFade();

	static CFade *Create(void);
	static void SetFade(FADE fade,CManager::MODE modenext);
	//static 

	static HRESULT Init(void);
	static void Uninit(void);
	static void Update(void);
	static void Draw(void);

private:
	static FADE m_fade;							//
	static CSceneSecond *m_pSceneSecond;			//
	static CManager::MODE m_modeNext;			//次のモード(画面)
	static D3DXCOLOR m_colorFade;				//フェード色
};


#endif
