//===================================================================
//
// �e�̏����@[bullet.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "bullet.h"
#include "manager.h"
#include "scene2D.h"
#include "renderer.h"
#include "enemy.h"
#include "explosion.h"
#include "player.h"
#include "game.h"
#include "fade.h"

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = NULL;
CExplosion *CBullet::m_Explosion = NULL;

CBullet::CBullet()
{
}

//�f�X�g���N�^
CBullet::~CBullet()
{
}

CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove,BULLET nType)
{
	CBullet *pBullet = NULL;
	pBullet = new CBullet;
	pBullet->Init(pos, move, size,Angelmove);
	pBullet->BindTexture(m_pTexture);

	//�ړ��ʂ̑��
	pBullet->m_move = move;

	//�^�C�v�̑��
	pBullet->m_Btype = nType;

	return pBullet;
}

//�e�̏���������
HRESULT CBullet::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove)
{
	CScene2D::Init(pos,size);
	m_size = size;

	SetPosition(pos);

	return S_OK;
}

//�e�̏I������
void CBullet::Uninit(void)
{
	CScene2D::Uninit();
}

//�e�̍X�V����
void CBullet::Update(void)
{
	CScene2D::Update();
	D3DXVECTOR3 pos;
	//�ʒu�̎擾
	pos = GetPosition();

	//���
	pos -= m_move;

	//�G�̗̑�
	m_nLife = 2;

	//�Z�b�g
	SetPosition(pos);

	CScene *pScene = NULL;
	for (int nCnt = 0; nCnt < MAX_OBJ; nCnt++)
	{
		pScene = CScene::GetScene(nCnt);
		if (pScene != NULL)
		{
		CScene::OBJTYPE Obj = pScene->GetObjType();

		if (Obj == OBJTYPE_PLAYER)
		{
			if (m_Btype == BULLET_ENEMY)
			{
				if (collision(pos, D3DXVECTOR2(5, 5), OBJTYPE_PLAYER, &pScene) == true)
				{
					CPlayer *pPlayer = (CPlayer*)pScene;

					if (pPlayer != NULL)
					{
						pPlayer->Uninit();
						CExplosion::Create(pos, D3DXVECTOR2(30, 30));
						CFade::SetFade(CFade::FADE_OUT, CManager::MODE_RESULT);
					}

					return;
				}
			}

			else if (collision(pos, D3DXVECTOR2(15, 15), OBJTYPE_ENEMY, &pScene) == true)
			{
				CEnemy *pEnemy = (CEnemy *)pScene;
				pEnemy->Uninit();
				CExplosion::Create(pos, D3DXVECTOR2(30, 30));
				Uninit();
				return;
			}
		}
		}
	}


	//�e�̉�ʊO����
	if (pos.x - m_size.x < 0)
	{
		Uninit();

		return;
	}
	if (pos.x + m_size.x > SCREEN_WIDTH)
	{
		Uninit();

		return;
	}
	if (pos.y - m_size.y < 0)
	{
		Uninit();

		return;
	}
	if (pos.y + m_size.y > SCREEN_HEIGHT)
	{
		Uninit();

		return;
	}
}

//�e�̕`�揈��
void CBullet::Draw()
{
	CScene2D::Draw();
}

//�e�̃e�N�X�`�����[�h
HRESULT CBullet::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\player000.png", &m_pTexture);

	return S_OK;
}

//�e�̃e�N�X�`���A�����[�h
void CBullet::Unload()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

CBullet * CBullet::BCreate(D3DXVECTOR3 pos ,int nCircle)
{
	//�e�̗���
	D3DXVECTOR3 Angelmove;
	float fAngel;
	fAngel = (float)(nCircle) / 100.0f;
	Angelmove.x = sinf(fAngel) * 4;
	Angelmove.y = cosf(fAngel) * 4;
	CBullet::Create(pos, D3DXVECTOR3(Angelmove.x, Angelmove.y, 0), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f),BULLET_ENEMY);
	return nullptr;
}
