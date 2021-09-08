//===========================================================
//
// [gameの処理]
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

//静的メンバ変数
CPlayer *CGame::m_pPlayer = NULL;

//コンストラクタ
CGame::CGame()
{
}

//デストラクタ
CGame::~CGame()
{
}

//初期化処理
HRESULT CGame::Init(void)
{
	//プレイヤーのテクスチャロード
	CPlayer::Load();

	//弾のテクスチャロード
	CBullet::Load();

	// 敵のテクスチャロード
	CEnemy::Load();
	CEnemyS::Load();

	//背景のテクスチャロード
	CBg::Load();

	//爆発のテクスチャロード
	CExplosion::Load();

	//スコアのテクスチャロード
	CScore::Load();

	//背景の生成
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	//プレイヤーの生成
	m_pPlayer = CPlayer::Create(D3DXVECTOR3(640, 900, 0), D3DXVECTOR2(PSIZE_X, PSIZE_Y));

	//敵の生成
	CEnemy::Create(D3DXVECTOR3(500, -200, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(2, -2, 0),CEnemy::ENEMYTYPE_ALPHA);
	CEnemy::Create(D3DXVECTOR3(780, -200, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(-2, -2, 0),CEnemy::ENEMYTYPE_BETA);

	//CEnemyS::Create(D3DXVECTOR3(640, 300, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(1, 0, 0));

	//スコアの生成
	CScore::Create(D3DXVECTOR3(900, 50, 0), D3DXVECTOR2(30, 30));

	

	return S_OK;
}

//終了処理
void CGame::Uninit()
{
	//背景のテクスチャアンロード
	CBg::Unload();

	//プレイヤーのテクスチャアンロード
	CPlayer::Unload();

	//弾のテクスチャアンロード
	CBullet::Unload();

	// 敵のテクスチャアンロード
	CEnemy::Unload();
	CEnemyS::Unload();

	//爆発のテクスチャアンロード
	CExplosion::Unload();

	//スコアのテクスチャアンロード
	CScore::Unload();

	Release();
}

//更新処理
void CGame::Update()
{
	m_nPornCnt++;

	//キーボードの更新
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//敵の生成
	if ((m_nPornCnt % 500) == 0)
	{
		CEnemyS::Create(D3DXVECTOR3(600, 400, 0), D3DXVECTOR2(60, 60), D3DXVECTOR3(1, 0, 0));
	}
}

//描画処理
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