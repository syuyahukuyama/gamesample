//===================================================================
//
// 弾の処理　[bullet.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "scene2D.h"

//マクロ定義

class CExplosion : public CScene2D
{
public:
	CExplosion();
	~CExplosion();

	static HRESULT Load(void);
	static void Unload(void);
	static CExplosion *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void SetExplosion(D3DXVECTOR3 pos);								// 爆発位置の設定
	D3DXVECTOR3 GetExplosion(void);									// 爆発位置の取得

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// バッファへのポインタ
	int m_nCounterAnim;							//カウンター
	float m_nPatternAnim;							//パターンNo
};

#endif // !_EXPLOSION_H_
