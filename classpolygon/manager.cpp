//=============================================================================
//
// マネージャー処理 [manager.cpp]
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

//静的メンバ変数
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

//マネージャーのコンストラクタ
CManager::CManager()
{

}

//マネージャーのデストラクタ
CManager::~CManager()
{

}

//マネージャーの初期化処理
HRESULT CManager::Init(HINSTANCE hInstance,HWND hWnd, bool bWindow)
{
	int nCount = 0;

	//レンダラー処理
	m_pRenderer = new CRenderer;
	m_pRenderer->Init(hWnd, bWindow);

	//キーボード生成
	m_pInputKeyboard = new CInputKeyboard;
	m_pInputKeyboard->Init(hInstance, hWnd);

	//サウンドの生成
	m_pSound = new CSound;
	m_pSound->InitSound(hWnd);

	//フェード処理
	CFade::Init();

	//キーボードの更新
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//モード処理
	SetMode(MODE_TITLE);

	return S_OK;
}

//マネージャーの終了処理
void CManager::Uninit(void)
{
	CScene::ReleaseAll();
	//レンダラー破棄
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	//キーボードの破棄
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	//フェードの破棄
	CFade::Uninit();

	//タイトルのアンロード
	CTitle::Unload();

	//リザルトのアンロード
	CResult::Unload();

}

//マネージャーの更新処理
void CManager::Update()
{
	//キーボードの更新
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Update();
	}

	//レンダラーの更新
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Update();
	}

	//フェードの更新
	CFade::Update();
}

//マネージャーの描画処理
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

//弾の取得
CBullet *CManager::GetBullet(void)
{
	return m_pBullet;
}

//サウンドの取得
CSound *CManager::GetSound(void)
{
	return m_pSound;
}

//モードの設定
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