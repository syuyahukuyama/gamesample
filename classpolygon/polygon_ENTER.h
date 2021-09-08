//===================================================================
//
// スコアの処理　[score.h]
// Author: fukuyama syuya
//
//===================================================================

#ifndef _ENTER_H_
#define _ENTER_H_

#include "main.h"
#include "polygon_ENTER.h"
#include "SceneSecond.h"

//ポリゴンクラス
class CEnter : public CSceneSecond
{
public:
	CEnter();
	~CEnter();

	static CEnter *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	static HRESULT Load(void);
	static void Unload(void);
	
};

#endif // !_ENTER_H_

