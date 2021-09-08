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

//�}�N����`
#define PSIZE_X (30)				//���S����[�܂ł�X�̋���
#define PSIZE_Y (35)				//���S����[�܂ł�Y�̋���

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
	D3DXVECTOR3					g_movePlayer;		//�v���C���[�̈ړ���
	static LPDIRECT3DTEXTURE9	m_pTexture;			//�v���C���[�̃e�N�X�`��
	int							m_nPosX;			//�v���C���[�̓����蔻��(X��)
	int							m_nPosY;			//�v���C���[�̓����蔻��(Y��)
	int							m_nCntBullet;		//�e�̃J�E���g
};


#endif // !_PLAYER_H_


