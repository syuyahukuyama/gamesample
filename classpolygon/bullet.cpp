//===================================================================
//
// 弾の処理　[bullet.cpp]
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

//静的メンバ変数
LPDIRECT3DTEXTURE9 CBullet::m_pTexture = NULL;
CExplosion *CBullet::m_Explosion = NULL;

CBullet::CBullet()
{
}

//デストラクタ
CBullet::~CBullet()
{
}

CBullet *CBullet::Create(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove,BULLET nType)
{
	CBullet *pBullet = NULL;
	pBullet = new CBullet;
	pBullet->Init(pos, move, size,Angelmove);
	pBullet->BindTexture(m_pTexture);

	//移動量の代入
	pBullet->m_move = move;

	//タイプの代入
	pBullet->m_Btype = nType;

	return pBullet;
}

//弾の初期化処理
HRESULT CBullet::Init(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXVECTOR2 size, D3DXVECTOR3 Angelmove)
{
	CScene2D::Init(pos,size);
	m_size = size;

	SetPosition(pos);

	return S_OK;
}

//弾の終了処理
void CBullet::Uninit(void)
{
	CScene2D::Uninit();
}

//弾の更新処理
void CBullet::Update(void)
{
	CScene2D::Update();
	D3DXVECTOR3 pos;
	//位置の取得
	pos = GetPosition();

	//代入
	pos -= m_move;

	//敵の体力
	m_nLife = 2;

	//セット
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


	//弾の画面外処理
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

//弾の描画処理
void CBullet::Draw()
{
	CScene2D::Draw();
}

//弾のテクスチャロード
HRESULT CBullet::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\player000.png", &m_pTexture);

	return S_OK;
}

//弾のテクスチャアンロード
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
	//弾の乱射
	D3DXVECTOR3 Angelmove;
	float fAngel;
	fAngel = (float)(nCircle) / 100.0f;
	Angelmove.x = sinf(fAngel) * 4;
	Angelmove.y = cosf(fAngel) * 4;
	CBullet::Create(pos, D3DXVECTOR3(Angelmove.x, Angelmove.y, 0), D3DXVECTOR2(15, 15), D3DXVECTOR3(Angelmove.x, Angelmove.y, 0.0f),BULLET_ENEMY);
	return nullptr;
}
