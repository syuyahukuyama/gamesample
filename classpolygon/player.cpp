//===================================================================
//
// �v���C���[�̏����@[player.cpp]
// Author: fukuyama syuya
//
//===================================================================

#include "player.h"
#include "input.h"
#include "manager.h"
#include "bullet.h"
#include "renderer.h"
#include "enemy.h"
#include "sound.h"
#include "explosion.h"
#include "fade.h"

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;

//�v���C���[�̃R���X�g���N�^
CPlayer::CPlayer()
{
}

//�v���C���[�̃f�X�g���N�^
CPlayer::~CPlayer()
{
}

//
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CPlayer *player = NULL;
	player = new CPlayer;
	player->Init(pos,size);
	player->BindTexture(m_pTexture);

	return player;
}

//�v���C���[�̏���������
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos,size);

	//�I�u�W�F�N�g�̎��
	SetObjType(CScene::OBJTYPE_PLAYER);

	return S_OK;
}

//�v���C���[�̏I������
void CPlayer::Uninit(void)
{
	CScene2D::Uninit();
}

//�v���C���[�̍X�V����
void CPlayer::Update(void)
{
	CScene2D::Update();
	CScene *pScene = NULL;

	//�ϐ��錾
	D3DXVECTOR3 pos;
	pos = GetPosition();
	m_nCntBullet++;

	D3DXVECTOR3 Angelmove;

	//�L�[�{�[�h�̍X�V
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//�T�E���h�̍X�V
	CSound *pSound;
	pSound = CManager::GetSound();


	//�v���C���[�̍X�V
	//�|���S���̏㉺���Eor�ᑬ�ړ�
	if (pInputKeyboard->GetPress(DIK_UP) == true)
	{
		if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
		{
			g_movePlayer.x += sinf(D3DX_PI) / 2;
			g_movePlayer.y += cosf(D3DX_PI) / 2;
		}
		else
		{
			g_movePlayer.x += sinf(D3DX_PI) * 3;
			g_movePlayer.y += cosf(D3DX_PI) * 3;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_DOWN) == true)
	{
		if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
		{
			g_movePlayer.x -= sinf(-D3DX_PI) / 2;
			g_movePlayer.y -= cosf(-D3DX_PI) / 2;
		}
		else
		{
			g_movePlayer.x -= sinf(-D3DX_PI) * 3;
			g_movePlayer.y -= cosf(-D3DX_PI) * 3;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_LEFT) == true)
	{
		if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
		{
			g_movePlayer.x += sinf(D3DX_PI / -2) / 2;
			g_movePlayer.y += cosf(D3DX_PI / -2) / 2;
		}
		else
		{
			g_movePlayer.x += sinf(D3DX_PI / -2) * 3;
			g_movePlayer.y += cosf(D3DX_PI / -2) * 3;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_RIGHT) == true)
	{
		if (pInputKeyboard->GetPress(DIK_LSHIFT) == true)
		{
			g_movePlayer.x += sinf(D3DX_PI / 2) / 2;
			g_movePlayer.y += cosf(D3DX_PI / 2) / 2;
		}
		else
		{
			g_movePlayer.x += sinf(D3DX_PI / 2) * 3;
			g_movePlayer.y += cosf(D3DX_PI / 2) * 3;
		}
	}

	//�e�𔭎�
	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
	{
		if ((m_nCntBullet % 15) == 0)
		{
			CBullet::Create(pos, D3DXVECTOR3(0, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);
			CBullet::Create(pos, D3DXVECTOR3(1, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);
			//CBullet::Create(pos, D3DXVECTOR3(-1, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);

			//����
			pSound->PlaySound(pSound->SOUND_LABEL_SE_SHOT);
		}
	}

	//�v���C���[�̈ʒu
	pos += g_movePlayer;

	//�v���C���[�̓����蔻��
	if (m_nPosX >= pos.x - 30 / 2 && m_nPosX < pos.x + 30 / 2 &&
		m_nPosY >= pos.y - 30 / 2 && m_nPosY < pos.y + 30 / 2)
	{
		CPlayer::Uninit();
	}

	//�ړ��ʂ̌���
	g_movePlayer.x += (0.0f - g_movePlayer.x) * 0.20f;
	g_movePlayer.y += (0.0f - g_movePlayer.y) * 0.20f;
	
	//��ʐ���
	if (pos.x - PSIZE_X < 0)
	{
		pos.x = PSIZE_X;
	}
	if (pos.x + PSIZE_X > SCREEN_WIDTH)
	{
		pos.x = SCREEN_WIDTH - PSIZE_X;
	}
	if (pos.y - PSIZE_Y < 0)
	{
		pos.y = PSIZE_Y;
	}
	if (pos.y + PSIZE_Y > SCREEN_HEIGHT)
	{
		pos.y = SCREEN_HEIGHT - PSIZE_Y;
	}

	//�G�Ƃ̓����蔻��
	if (collision(pos, D3DXVECTOR2(5, 5), OBJTYPE_ENEMY, &pScene) == true)
	{
		CExplosion::Create(pos, D3DXVECTOR2(30, 30));
		CFade::SetFade(CFade::FADE_OUT, CManager::MODE_RESULT);
		Uninit();
	}

	SetPosition(pos);
}

//�v���C���[�̕`�揈��
void CPlayer::Draw(void)
{
	CScene2D::Draw();
}

//�e�N�X�`���̃��[�h
HRESULT CPlayer::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\player001.png", &m_pTexture);

	return S_OK;
}

// �e�N�X�`���̃A�����[�h
void CPlayer::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}