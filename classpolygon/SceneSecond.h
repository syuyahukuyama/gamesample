//========================================================
//
// [ポリゴン2Dの処理]
//
//
//========================================================
#ifndef _SCENESECOND_H_
#define _SCENESECOND_H_

class CSceneSecond
{
public:
	CSceneSecond();
	~CSceneSecond();
	static CSceneSecond *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

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
	void SetColor(D3DXCOLOR col);
	//void SetSize(float fsizeX, float fsizeY);

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
