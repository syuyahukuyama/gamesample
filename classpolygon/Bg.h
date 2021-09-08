//==================================================================
//
// Bg�̏���[Bg.h]:
// hukuyamasyuuya
//
//==================================================================

#ifndef _BG_H_
#define _BG_H_

class CScene2D;
class CScene;

#include "scene.h"
#include "Bg.h"

// �}�N����`
#define MAX_BG (2)

class CBg : public CScene
{
public:
	typedef enum
	{
		BG_TITLE = 0,		//�^�C�g���̔w�i
		BG_GAME,			//�Q�[���̔w�i
		BG_RESULT,			//���U���g�̔w�i
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

	D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(0, 0, 0); }			// �ʒu�̎擾
	D3DXVECTOR2 GetSize(void) { return D3DXVECTOR2(0, 0); }
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;				// �o�b�t�@�ւ̃|�C���^
	static LPDIRECT3DTEXTURE9 m_apTexture[MAX_BG];	//�w�i�̃e�N�X�`��
	CScene2D *m_apScene2D[MAX_BG];
	float m_fAnim;									//�w�i�̈ړ�
	static TEXBG m_texbg;							//�w�i�̎��
};

#endif // !_BG_H_
