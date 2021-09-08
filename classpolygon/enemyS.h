//========================================================
//
// [�G�l�~�[�̏���]:
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
	D3DXVECTOR3					g_moveEnemy;				//�G�̈ړ���
	static LPDIRECT3DTEXTURE9	m_apTexture;				//�G�̃e�N�X�`��
	int							m_nCounter;					//�G�̒e�̃J�E���^�[
	int							m_nMoveCnt;
	float						m_fCntGame;					//�e�̊p�x�ύX
	D3DXVECTOR3					m_move;
	//static ENEMYTYPE			m_EnemyType;				//�G�̃^�C�v
};

#endif