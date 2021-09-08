//==================================================================
//
// resultの処理[result.h]:
// hukuyamasyuuya
//
//=================================================================
#ifndef _RESULT_H_
#define _RESULT_H_

#include "scene.h"
#include "scene2D.h"

//タイトルのクラス
class CResult : public CScene2D
{
public:
	CResult();
	~CResult();
	static HRESULT Load(void);
	static void Unload(void);
	static CResult *Create(void);

	virtual D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(); }
	virtual D3DXVECTOR2 GetSize(void) { return D3DXVECTOR2(); }

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	static LPDIRECT3DTEXTURE9	m_pTexture;		//リザルトのテクスチャ
	CScene2D *m_pScene2D;
};

#endif // !_TITLE_H_
