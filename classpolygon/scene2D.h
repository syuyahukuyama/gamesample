//========================================================
//
// [�|���S��2D�̏���]
//
//
//========================================================
#ifndef _SCENE2D_H_
#define _SCENE2D_H_

#include "scene.h"

//�}�N����`
#define TEXTURE_X (8)
#define TEXTURE_Y (1)

#define MAX_SCORE_X (10)		//�X�R�A��X��
#define MAX_SCORE_Y (1)			//�X�R�A��Y��

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

	void SetPosition(D3DXVECTOR3 pos);		// �ʒu�̐ݒ�
	D3DXVECTOR3 GetPosition(void);			// �ʒu�̎擾
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
	void SetSize(float fsizeX, float fsizeY);

	bool collision(D3DXVECTOR3 pos, D3DXVECTOR2 size, OBJTYPE obj,CScene **pColscene);
	D3DXVECTOR2 GetSize(void) { return m_size; }
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// �o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9		m_pTexture;		// �e�N�X�`��
	D3DXVECTOR3				m_pos;			// �|���S���̈ʒu
	D3DXVECTOR2				m_size;			// �|���S���̃T�C�Y
	float					m_fLength;		//�Ίp���̒���
	float					m_fAngle;		//
};

#endif