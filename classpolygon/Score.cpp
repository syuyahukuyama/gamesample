//===================================================================
//
// スコアの処理　[score.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "Score.h"
#include "main.h"
#include "manager.h"
#include "renderer.h"

//静的メンバ変数
LPDIRECT3DTEXTURE9 CScore::m_apTexture[MAX_SCORE] = {};

//コンストラクタ
CScore::CScore()
{
}

//デストラクタ
CScore::~CScore()
{
}

//クリエイト
CScore *CScore::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScore *pScore;
	pScore = new CScore;
	pScore->Init(pos, size);
	pScore->BindTexture(m_apTexture[0]);

	return pScore;
}

//テクスチャロード
HRESULT CScore::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\number000.png", &m_apTexture[0]);

	return S_OK;
}

//テクスチャのアンロード
void CScore::Unload(void)
{
	if (m_apTexture[0] != NULL)
	{
		m_apTexture[0]->Release();
		m_apTexture[0] = NULL;
	}
}

//初期化処理
HRESULT CScore::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos, size);

	return S_OK;
}

//終了処理
void CScore::Uninit(void)
{
	CScene2D::Uninit();
}

//更新処理
void CScore::Update(void)
{
	CScene2D::Update();

	SetScore(m_nPatternSAnim);
}

//描画処理
void CScore::Draw(void)
{
	CScene2D::Draw();
}