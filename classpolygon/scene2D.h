//========================================================
//
// [ポリゴン2Dの処理]
//
//
//========================================================
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

#include "scene.h"

//マクロ定義
#define TEXTURE_X (8)
#define TEXTURE_Y (1)

#define MAX_SCORE_X (10)		//スコアのX軸
#define MAX_SCORE_Y (1)			//スコアのY軸

class CScene2D : public CScene
{
public:
	CScene2D();
	~CScene2D();
	static CScene2D *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

	HRESULT Init(void);
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetBg(float fAnim);
	void SetTex(float fTexture);
	void SetScore(float fScore);

	void SetPosition(D3DXVECTOR3 pos);		// 位置の設定
	D3DXVECTOR3 GetPosition(void);			// 位置の取得
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
	void SetSize(float fsizeX, float fsizeY);

	bool collision(D3DXVECTOR3 pos, D3DXVECTOR2 size, OBJTYPE obj,CScene **pColscene);
	D3DXVECTOR2 GetSize(void) { return m_size; }
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// バッファへのポインタ
	LPDIRECT3DTEXTURE9		m_pTexture;		// テクスチャ
	D3DXVECTOR3				m_pos;			// ポリゴンの位置
	D3DXVECTOR2				m_size;			// ポリゴンのサイズ
	float					m_fLength;		//対角線の長さ
	float					m_fAngle;		//
};

#endif