//===================================================================
//
// スコアの処理　[score.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "scene2D.h"

//マクロ定義
#define MAX_SCORE (8)			//スコアの桁数

class CScore : public CScene2D
{
public:
	CScore();
	~CScore();

	static CScore *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static LPDIRECT3DTEXTURE9	m_apTexture[MAX_SCORE];		//スコアのテクスチャ
	int		m_nCounterSAnim;									//カウンター
	float	m_nPatternSAnim;									//パターンNo
};

#endif // !_SCORE_H_
