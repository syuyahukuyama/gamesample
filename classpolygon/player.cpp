//===================================================================
//
// プレイヤーの処理　[player.cpp]
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

//静的メンバ変数
LPDIRECT3DTEXTURE9 CPlayer::m_pTexture = NULL;

//プレイヤーのコンストラクタ
CPlayer::CPlayer()
{
}

//プレイヤーのデストラクタ
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

//プレイヤーの初期化処理
HRESULT CPlayer::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos,size);

	//オブジェクトの種類
	SetObjType(CScene::OBJTYPE_PLAYER);

	return S_OK;
}

//プレイヤーの終了処理
void CPlayer::Uninit(void)
{
	CScene2D::Uninit();
}

//プレイヤーの更新処理
void CPlayer::Update(void)
{
	CScene2D::Update();
	CScene *pScene = NULL;

	//変数宣言
	D3DXVECTOR3 pos;
	pos = GetPosition();
	m_nCntBullet++;

	D3DXVECTOR3 Angelmove;

	//キーボードの更新
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//サウンドの更新
	CSound *pSound;
	pSound = CManager::GetSound();


	//プレイヤーの更新
	//ポリゴンの上下左右or低速移動
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

	//弾を発射
	if (pInputKeyboard->GetPress(DIK_SPACE) == true)
	{
		if ((m_nCntBullet % 15) == 0)
		{
			CBullet::Create(pos, D3DXVECTOR3(0, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);
			CBullet::Create(pos, D3DXVECTOR3(1, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);
			//CBullet::Create(pos, D3DXVECTOR3(-1, 10, 0), D3DXVECTOR2(7, 7), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f), CBullet::BULLET_PLAYER);

			//音源
			pSound->PlaySound(pSound->SOUND_LABEL_SE_SHOT);
		}
	}

	//プレイヤーの位置
	pos += g_movePlayer;

	//プレイヤーの当たり判定
	if (m_nPosX >= pos.x - 30 / 2 && m_nPosX < pos.x + 30 / 2 &&
		m_nPosY >= pos.y - 30 / 2 && m_nPosY < pos.y + 30 / 2)
	{
		CPlayer::Uninit();
	}

	//移動量の減衰
	g_movePlayer.x += (0.0f - g_movePlayer.x) * 0.20f;
	g_movePlayer.y += (0.0f - g_movePlayer.y) * 0.20f;
	
	//画面制限
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

	//敵との当たり判定
	if (collision(pos, D3DXVECTOR2(5, 5), OBJTYPE_ENEMY, &pScene) == true)
	{
		CExplosion::Create(pos, D3DXVECTOR2(30, 30));
		CFade::SetFade(CFade::FADE_OUT, CManager::MODE_RESULT);
		Uninit();
	}

	SetPosition(pos);
}

//プレイヤーの描画処理
void CPlayer::Draw(void)
{
	CScene2D::Draw();
}

//テクスチャのロード
HRESULT CPlayer::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\player001.png", &m_pTexture);

	return S_OK;
}

// テクスチャのアンロード
void CPlayer::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}