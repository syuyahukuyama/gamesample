//===========================================================
//
// [game�̏���]
// 
//
//===========================================================

#include "game.h"
#include "Bg.h"
#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "main.h"
#include "player.h"
#include "manager.h"
#include "input.h"
#include "Score.h"
#include "enemyS.h"
#include "fade.h"

//�ÓI�����o�ϐ�
CPlayer *CGame::m_pPlayer = NULL;

//�R���X�g���N�^
CGame::CGame()
{
}

//�f�X�g���N�^
CGame::~CGame()
{
}

//����������
HRESULT CGame::Init(void)
{
	//�v���C���[�̃e�N�X�`�����[�h
	CPlayer::Load();

	//�e�̃e�N�X�`�����[�h
	CBullet::Load();

	// �G�̃e�N�X�`�����[�h
	CEnemy::Load();
	CEnemyS::Load();

	//�w�i�̃e�N�X�`�����[�h
	CBg::Load();

	//�����̃e�N�X�`�����[�h
	CExplosion::Load();

	//�X�R�A�̃e�N�X�`�����[�h
	CScore::Load();

	//�w�i�̐���
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//�v���C���[�̐���
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(640, 900, 0), D3DXVECTOR2(PSIZE_X, PSIZE_Y));

	//�G�̐���
	CEnemy::Create(D3DXVECTOR3(500, -200, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(2, -2, 0),CEnemy::ENEMYTYPE_ALPHA);
	CEnemy::Create(D3DXVECTOR3(780, -200, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(-2, -2, 0),CEnemy::ENEMYTYPE_BETA);

	//CEnemyS::Create(D3DXVECTOR3(640, 300, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(1, 0, 0));

	//�X�R�A�̐���
	CScore::Create(D3DXVECTOR3(900, 50, 0), D3DXVECTOR2(30, 30));

	

	return S_OK;
}

//�I������
void CGame::Uninit()
{
	//�w�i�̃e�N�X�`���A�����[�h
	CBg::Unload();

	//�v���C���[�̃e�N�X�`���A�����[�h
	CPlayer::Unload();

	//�e�̃e�N�X�`���A�����[�h
	CBullet::Unload();

	// �G�̃e�N�X�`���A�����[�h
	CEnemy::Unload();
	CEnemyS::Unload();

	//�����̃e�N�X�`���A�����[�h
	CExplosion::Unload();

	//�X�R�A�̃e�N�X�`���A�����[�h
	CScore::Unload();

	Release();
}

//�X�V����
void CGame::Update()
{
	m_nPornCnt++;

	//�L�[�{�[�h�̍X�V
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//�G�̐���
	if ((m_nPornCnt % 500) == 0)
	{
		CEnemyS::Create(D3DXVECTOR3(600, 400, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(1, 0, 0));
	}
}

//�`�揈��
void CGame::Draw()
{
}

CGame *CGame::Create(void)
{
	CGame *pGame;
	pGame = new CGame;
	pGame->Init();

	return pGame;
}

CPlayer * CGame::GetPlayer(void)
{
	return m_pPlayer;
}