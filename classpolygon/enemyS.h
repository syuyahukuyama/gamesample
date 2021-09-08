//========================================================
//
// [エネミーの処理]:
//
//
//========================================================
#ifndef _ENEMYS_H_
#define _ENEMYS_H_

#include "scene2D.h"

class CEnemyS : public CScene2D
{
public:
	CEnemyS();
	~CEnemyS();

	static HRESULT Load(void);
	static void Unload(void);
	static CEnemyS *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	D3DXVECTOR3					g_moveEnemy;				//敵の移動量
	static LPDIRECT3DTEXTURE9	m_apTexture;				//敵のテクスチャ
	int							m_nCounter;					//敵の弾のカウンター
	int							m_nMoveCnt;
	float						m_fCntGame;					//弾の角度変更
	D3DXVECTOR3					m_move;
	//static ENEMYTYPE			m_EnemyType;				//敵のタイプ
};

#endif