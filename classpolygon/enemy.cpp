//========================================================
//
// [�G�l�~�[�̏���]:
//
//
//========================================================

#include "enemy.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "bullet.h"

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CEnemy::m_apTexture[MAX_TEX] = {};
CEnemy::ENEMYTYPE CEnemy::m_EnemyType = CEnemy::ENEMYTYPE_ALPHA;
int g_nData;

//�f�X�g���N�^
CEnemy::CEnemy()
{
}

//�f�X�g���N�^
CEnemy::~CEnemy()
{
}

//�G�̃e�N�X�`�����[�h
HRESULT CEnemy::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	switch (m_EnemyType)
	{
	case ENEMYTYPE_ALPHA:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\robo001.png", &m_apTexture[0]);
		break;
	case ENEMYTYPE_BETA:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\robo000.png", &m_apTexture[1]);
		break;
	case ENEMYTYPE_BOSS:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\boss003.png", &m_apTexture[2]);
		break;
	}

	return S_OK;
}

//�G�̃e�N�X�`���A�����[�h
void CEnemy::Unload(void)
{
	for (int nCnt = 0; nCnt < MAX_TEX; nCnt++)
	{
		if (m_apTexture[nCnt] != NULL)
		{
			m_apTexture[nCnt]->Release();
			m_apTexture[nCnt] = NULL;
		}
	}
}

//�G�̐���
CEnemy *CEnemy::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move, ENEMYTYPE type)
{
	for (int nCnt = 0; nCnt < MAX_TEX; nCnt++)
	{
		CEnemy *pEnemy;
		pEnemy = new CEnemy;
		pEnemy->Init(pos, size, move,type);
		pEnemy->BindTexture(m_apTexture[nCnt]);
		return pEnemy;
	}
	return S_OK;
}

void CEnemy::SetEneType(ENEMYTYPE type)
{
	m_EnemyType = type;
}

CEnemy::ENEMYTYPE CEnemy::GetEneType(void)
{
	return m_EnemyType;
}

//�G�̏���������
HRESULT CEnemy::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move, ENEMYTYPE type)
{
	CScene2D::Init(pos,size);

	m_move = move;

	//�I�u�W�F�N�g�̎��
	SetObjType(CScene::OBJTYPE_ENEMY);

	return S_OK;
}

//�G�̏I������
void CEnemy::Uninit(void)
{
	CScene2D::Uninit();
}

//�G�̍X�V����
void CEnemy::Update(void)
{
	CScene2D::Update();
	
	//�ϐ��錾
	D3DXVECTOR3 pos;
	pos = GetPosition();
	m_nCounter++;
	m_nMoveCnt++;
	//D3DXVECTOR3 Angelmove;

	//�e�̗���
	D3DXVECTOR3 Angelmove;
	float fAngel;
	fAngel = (float)(m_fCntGame) / 100.0f;
	Angelmove.x = sinf(fAngel) * 5;
	Angelmove.y = cosf(fAngel) * 5;

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

	//�G����e�̔���
	if (m_nCounter % 100 == 0)
	{
		for (int nCnt = 0; nCnt < 20; nCnt++)
		{
			//CBullet::Create(pos, D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_ENEMY);
			//CBullet::Create(pos, D3DXVECTOR3(sinf(D3DX_PI *  1.0f * ((float)nCnt / ((float)10))) * 3, cosf(D3DX_PI * 1.0f * ((float)nCnt / (float)10)) * 3, 0), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_ENEMY);
		}
	}

	if (m_nCounter % 70 == 0)
	{
		CBullet::BCreate(pos, 314);
		CBullet::BCreate(pos, -157);
		CBullet::BCreate(pos, 157);
		CBullet::BCreate(pos, 78);
		CBullet::BCreate(pos, -78);
		CBullet::BCreate(pos, 235);
		CBullet::BCreate(pos, -235);
		CBullet::BCreate(pos, 0);
	}

	SetPosition(pos);
}

//�G�̕`�揈��
void CEnemy::Draw(void)
{
	CScene2D::Draw();
}