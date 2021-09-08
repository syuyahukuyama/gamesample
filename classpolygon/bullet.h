//===================================================================
//
// 弾の処理　[bullet.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _BULLET_H_
#define _BULLET_H_

#include "scene2D.h"

class CExplosion;

class CBullet : public CScene2D
{
public:
	typedef enum
	{
		BULLET_ENEMY = 0,
		BULLET_PLAYER,
		BULLET_MAX,
	}BULLET;
	CBullet();
	~CBullet();
	static CBullet *Create(D3DXVECTOR3 pos,D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove, BULLET nType);
	static HRESULT Load(void);
	static void Unload(void);
	static CBullet *BCreate(D3DXVECTOR3 pos,int nCircle);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	D3DXVECTOR3					m_move;						//弾の移動量
	static LPDIRECT3DTEXTURE9	m_pTexture;					//弾のテクスチャ
	static CExplosion			*m_Explosion;				//爆発の表示
	float						m_fCntGame;					//弾の角度変更
	BULLET						m_Btype;					//弾の主
	D3DXVECTOR2					m_size;						//弾のサイズ
	int							m_nLife;					//体力
};

#endif // !_BULLET_H_
