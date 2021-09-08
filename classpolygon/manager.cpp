//=============================================================================
//
// �}�l�[�W���[���� [manager.cpp]
// Author : 
//
//=============================================================================

#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "scene2D.h"
#include "input.h"
#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include "Bg.h"
#include "explosion.h"
#include "input.h"
#include "sound.h"
#include "game.h"
#include "result.h"
#include "title.h"
#include "fade.h"

//�ÓI�����o�ϐ�
CRenderer *CManager::m_pRenderer = NULL;
CInputKeyboard *CManager::m_pInputKeyboard = NULL;
//CPlayer *CManager::m_pPlayer = NULL;
CBullet *CManager::m_pBullet = NULL;
CEnemy *CManager::m_pEnemy = NULL;
CEnemyS *CManager::m_pEnemyS = NULL;
CBg *CManager::m_pBg = NULL;
CSound *CManager::m_pSound = NULL;
CTitle *CManager::m_pTitle = NULL;
CGame *CManager::m_pGame = NULL;
CResult *CManager::m_pResult = NULL;
CManager::MODE CManager::m_mode = CManager::MODE_TITLE;

//�}�l�[�W���[�̃R���X�g���N�^
CManager::CManager()
{

}

//�}�l�[�W���[�̃f�X�g���N�^
CManager::~CManager()
{

}

//�}�l�[�W���[�̏���������
HRESULT CManager::Init(HINSTANCE hInstance,HWND hWnd, bool bWindow)
{
	int nCount = 0;

	//�����_���[����
	m_pRenderer = new CRenderer;
	m_pRenderer->Init(hWnd, bWindow);

	//�L�[�{�[�h����
	m_pInputKeyboard = new CInputKeyboard;
	m_pInputKeyboard->Init(hInstance, hWnd);

	//�T�E���h�̐���
	m_pSound = new CSound;
	m_pSound->InitSound(hWnd);

	//�t�F�[�h����
	CFade::Init();

	//�L�[�{�[�h�̍X�V
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//���[�h����
	SetMode(MODE_TITLE);

	return S_OK;
}

//�}�l�[�W���[�̏I������
void CManager::Uninit(void)
{
	CScene::ReleaseAll();
	//�����_���[�j��
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	//�L�[�{�[�h�̔j��
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	//�t�F�[�h�̔j��
	CFade::Uninit();

	//�^�C�g���̃A�����[�h
	CTitle::Unload();

	//���U���g�̃A�����[�h
	CResult::Unload();

}

//�}�l�[�W���[�̍X�V����
void CManager::Update()
{
	//�L�[�{�[�h�̍X�V
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Update();
	}

	//�����_���[�̍X�V
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Update();
	}

	//�t�F�[�h�̍X�V
	CFade::Update();
}

//�}�l�[�W���[�̕`�揈��
void CManager::Draw()
{
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Draw();
	}
}

CRenderer *CManager::GetRenderer(void)
{
	return m_pRenderer;
}

CInputKeyboard *CManager::GetInputKey(void)
{
	return m_pInputKeyboard;
}

//�e�̎擾
CBullet *CManager::GetBullet(void)
{
	return m_pBullet;
}

//�T�E���h�̎擾
CSound *CManager::GetSound(void)
{
	return m_pSound;
}

//���[�h�̐ݒ�
void CManager::SetMode(MODE mode)
{
	switch (m_mode)
	{
	case MODE_TITLE:
		if (m_pTitle != NULL)
		{
			m_pTitle->Uninit();
			m_pTitle = NULL;
		}
		break;

	case MODE_GAME:
		if (m_pGame != NULL)
		{
			m_pGame->Uninit();
			m_pGame = NULL;
		}
		break;

	case MODE_RESULT:
		if (m_pResult != NULL)
		{
			m_pResult->Uninit();
			m_pResult = NULL;
		}
		break;
	}
	CScene::ReleaseAll();

	m_mode = mode;

	switch (m_mode)
	{
	case MODE_TITLE:
		if (m_pTitle == NULL)
		{
			m_pTitle = CTitle::Create();
		}
		break;

	case MODE_GAME:
		if (m_pGame == NULL)
		{
			CGame::Create();
			m_pGame = CGame::Create();
		}
		break;

	case MODE_RESULT:
		if (m_pResult == NULL)
		{
			CResult::Create();
			m_pResult = CResult::Create();
		}
		break;
	}
}

CManager::MODE CManager::GetMode(void)
{
	return m_mode;
}