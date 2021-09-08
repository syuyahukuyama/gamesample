//==================================================================
//
// Bgの処理[Bg.h]:
// hukuyamasyuuya
//
//==================================================================

#ifndef _BG_H_
#define _BG_H_

class CScene2D;
class CScene;

#include "scene.h"
#include "Bg.h"

// マクロ定義
#define MAX_BG (2)

class CBg : public CScene
{
public:
	typedef enum
	{
		BG_TITLE = 0,		//タイトルの背景
		BG_GAME,			//ゲームの背景
		BG_RESULT,			//リザルトの背景
		BG_MAX,
	}TEXBG;
	CBg();
	~CBg();
	static HRESULT Load(void);
	static void Unload(void);
	static CBg *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

	HRESULT Init(void);
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetBgTex(TEXBG texbg);

	D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(0, 0, 0); }			// 位置の取得
	D3DXVECTOR2 GetSize(void) { return D3DXVECTOR2(0, 0); }
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;				// バッファへのポインタ
	static LPDIRECT3DTEXTURE9 m_apTexture[MAX_BG];	//背景のテクスチャ
	CScene2D *m_apScene2D[MAX_BG];
	float m_fAnim;									//背景の移動
	static TEXBG m_texbg;							//背景の種類
};

#endif // !_BG_H_
