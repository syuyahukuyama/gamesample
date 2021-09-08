//========================================================
//
// [�G�l�~�[�̏���]:
//
//
//========================================================

#include "enemyS.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "bullet.h"

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CEnemyS::m_apTexture = NULL;

//�f�X�g���N�^
CEnemyS::CEnemyS()
{
}

//�f�X�g���N�^
CEnemyS::~CEnemyS()
{
}

//�G�̃e�N�X�`�����[�h
HRESULT CEnemyS::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\robo000.png", &m_apTexture);

	return S_OK;
}

//�G�̃e�N�X�`���A�����[�h
void CEnemyS::Unload(void)
{
	if (m_apTexture != NULL)
	{
		m_apTexture->Release();
		m_apTexture = NULL;
	}
}

//�G�̐���
CEnemyS *CEnemyS::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move)
{
	CEnemyS *pEnemyS;
	pEnemyS = new CEnemyS;
	pEnemyS->Init(pos, size, move);
	pEnemyS->BindTexture(m_apTexture);
	return pEnemyS;

	return S_OK;
}

//�G�̏���������
HRESULT CEnemyS::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move)
{
	CScene2D::Init(pos, size);

	m_move = move;

	//�I�u�W�F�N�g�̎��
	SetObjType(CScene::OBJTYPE_ENEMY);

	return S_OK;
}

//�G�̏I������
void CEnemyS::Uninit(void)
{
	CScene2D::Uninit();
}

//�G�̍X�V����
void CEnemyS::Update(void)
{
	CScene2D::Update();

	//�ϐ��錾
	D3DXVECTOR3 pos;
	pos = GetPosition();
	m_nCounter++;
	m_nMoveCnt++;
	//D3DXVECTOR3 Angelmove;

	//�G�̈ʒu
	pos -= m_move;

	//�G�̈ړ�
	if (pos.x + 30 / 2.0f >= SCREEN_WIDTH)
	{
		m_move.x *= -1;
	}
	if (pos.x - 30 / 2.0f <= 0)
	{
		m_move.x *= -1;
	}

	//�e�̊p�x�ύX
	m_fCntGame += 3.0f;

	//�G�̈ړ��ʌ���
	//g_moveEnemy.x += (0.0f - g_moveEnemy.x) * 0.02f;
	g_moveEnemy.y -= (0.0f + g_moveEnemy.y) * 0.01f;

	//�e�̗���
	D3DXVECTOR3 Angelmove;
	float fAngel;
	fAngel = (float)(m_fCntGame) / 100.0f;
	Angelmove.x = sinf(fAngel) * 5;
	Angelmove.y = cosf(fAngel) * 5;

	//�G����e�̔���
	if (m_nCounter % 100 == 0)
	{
		for (int nCnt = 0; nCnt < 20; nCnt++)
		{
			//CBullet::Create(pos, D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_ENEMY);
			CBullet::Create(pos, D3DXVECTOR3(sinf(D3DX_PI *  1.0f * ((float)nCnt / ((float)10))) * 1, cosf(D3DX_PI * 1.0f * ((float)nCnt / (float)10)) * 1, 0), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_ENEMY);
		}
	}

	if (m_nCounter % 70 == 0)
	{
		/*CBullet::BCreate(pos, 314);
		CBullet::BCreate(pos, -157);
		CBullet::BCreate(pos, 157);
		CBullet::BCreate(pos, 78);
		CBullet::BCreate(pos, -78);
		CBullet::BCreate(pos, 235);
		CBullet::BCreate(pos, -235);
		CBullet::BCreate(pos, 0);*/
	}

	SetPosition(pos);
}

//�G�̕`�揈��
void CEnemyS::Draw(void)
{
	CScene2D::Draw();
}