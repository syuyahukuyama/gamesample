//===================================================================
//
// �e�̏����@[bullet.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include "scene2D.h"

//�}�N����`

class CExplosion : public CScene2D
{
public:
	CExplosion();
	~CExplosion();

	static HRESULT Load(void);
	static void Unload(void);
	static CExplosion *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void SetExplosion(D3DXVECTOR3 pos);								// �����ʒu�̐ݒ�
	D3DXVECTOR3 GetExplosion(void);									// �����ʒu�̎擾

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// �o�b�t�@�ւ̃|�C���^
	int m_nCounterAnim;							//�J�E���^�[
	float m_nPatternAnim;							//�p�^�[��No
};

#endif // !_EXPLOSION_H_
