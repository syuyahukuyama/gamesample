//==================================================================
//
//
//
//
//==================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "scene2D.h"
#include "main.h"

//マクロ定義
#define PSIZE_X (30)				//中心から端までのXの距離
#define PSIZE_Y (35)				//中心から端までのYの距離

class CPlayer : public CScene2D
{
public:
	CPlayer();
	~CPlayer();
	static CPlayer *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void); 
	void Update(void);
	void Draw(void);
private:
	D3DXVECTOR3					g_movePlayer;		//プレイヤーの移動量
	static LPDIRECT3DTEXTURE9	m_pTexture;			//プレイヤーのテクスチャ
	int							m_nPosX;			//プレイヤーの当たり判定(X軸)
	int							m_nPosY;			//プレイヤーの当たり判定(Y軸)
	int							m_nCntBullet;		//弾のカウント
};


#endif // !_PLAYER_H_


