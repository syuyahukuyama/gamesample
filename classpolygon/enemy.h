//========================================================
//
// [�G�l�~�[�̏���]:
//
//
//========================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "scene2D.h"

//�}�N����`
#define MAX_TEX (3)

class CEnemy : public CScene2D
{
public:
	//�G�̎��
	typedef enum
	{
		ENEMYTYPE_ALPHA = 0,
		ENEMYTYPE_BETA,
		ENEMYTYPE_BOSS,
		ENEMYTYPE_MAX,
	}ENEMYTYPE;

	CEnemy();
	~CEnemy();

	static HRESULT Load(void);
	static void Unload(void);
	static CEnemy *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move,ENEMYTYPE type);

	static void SetEneType(ENEMYTYPE type);
	static ENEMYTYPE GetEneType(void);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move,ENEMYTYPE type);
	void Uninit(void);
	void Update(void);
	void Draw(void);
private:
	D3DXVECTOR3					g_moveEnemy;				//�G�̈ړ���
	static LPDIRECT3DTEXTURE9	m_apTexture[MAX_TEX];		//�G�̃e�N�X�`��
	int							m_nCounter;					//�G�̒e�̃J�E���^�[
	int							m_nMoveCnt;
	float						m_fCntGame;					//�e�̊p�x�ύX
	D3DXVECTOR3					m_move;
	static ENEMYTYPE			m_EnemyType;				//�G�̃^�C�v
};

#endif