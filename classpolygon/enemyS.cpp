//========================================================
//
// [エネミーの処理]:
//
//
//========================================================

#include "enemyS.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "bullet.h"

//静的メンバ変数
LPDIRECT3DTEXTURE9 CEnemyS::m_apTexture = NULL;

//デストラクタ
CEnemyS::CEnemyS()
{
}

//デストラクタ
CEnemyS::~CEnemyS()
{
}

//敵のテクスチャロード
HRESULT CEnemyS::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\robo000.png", &m_apTexture);

	return S_OK;
}

//敵のテクスチャアンロード
void CEnemyS::Unload(void)
{
	if (m_apTexture != NULL)
	{
		m_apTexture->Release();
		m_apTexture = NULL;
	}
}

//敵の生成
CEnemyS *CEnemyS::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move)
{
	CEnemyS *pEnemyS;
	pEnemyS = new CEnemyS;
	pEnemyS->Init(pos, size, move);
	pEnemyS->BindTexture(m_apTexture);
	return pEnemyS;

	return S_OK;
}

//敵の初期化処理
HRESULT CEnemyS::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size, D3DXVECTOR3 move)
{
	CScene2D::Init(pos, size);

	m_move = move;

	//オブジェクトの種類
	SetObjType(CScene::OBJTYPE_ENEMY);

	return S_OK;
}

//敵の終了処理
void CEnemyS::Uninit(void)
{
	CScene2D::Uninit();
}

//敵の更新処理
void CEnemyS::Update(void)
{
	CScene2D::Update();

	//変数宣言
	D3DXVECTOR3 pos;
	pos = GetPosition();
	m_nCounter++;
	m_nMoveCnt++;
	//D3DXVECTOR3 Angelmove;

	//敵の位置
	pos -= m_move;

	//敵の移動
	if (pos.x + 30 / 2.0f >= SCREEN_WIDTH)
	{
		m_move.x *= -1;
	}
	if (pos.x - 30 / 2.0f <= 0)
	{
		m_move.x *= -1;
	}

	//弾の角度変更
	m_fCntGame += 3.0f;

	//敵の移動量減衰
	//g_moveEnemy.x += (0.0f - g_moveEnemy.x) * 0.02f;
	g_moveEnemy.y -= (0.0f + g_moveEnemy.y) * 0.01f;

	//弾の乱射
	D3DXVECTOR3 Angelmove;
	float fAngel;
	fAngel = (float)(m_fCntGame) / 100.0f;
	Angelmove.x = sinf(fAngel) * 5;
	Angelmove.y = cosf(fAngel) * 5;

	//敵から弾の発射
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

//敵の描画処理
void CEnemyS::Draw(void)
{
	CScene2D::Draw();
}