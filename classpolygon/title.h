//==================================================================
//
// title�̏���[title.h]:
// hukuyamasyuuya
//
//=================================================================
#ifndef _TITLE_H_
#define _TITLE_H_

#include "scene.h"
#include "scene2D.h"

//�^�C�g���̃N���X
class CTitle : public CScene2D
{
public:
	CTitle();
	~CTitle();
	static HRESULT Load(void);
	static void Unload(void);
	static CTitle *Create(void);

	virtual D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(); }
	virtual D3DXVECTOR2 GetSize(void) { return D3DXVECTOR2(); }

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	static LPDIRECT3DTEXTURE9	m_pTexture;		//�^�C�g���̃e�N�X�`��
	CScene2D *m_pScene2D;
};

#endif // !_TITLE_H_