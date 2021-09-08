//===================================================================
//
// 弾の処理　[bullet.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "explosion.h"
#include "manager.h"
#include "renderer.h"

// 静的メンバ変数
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture = NULL;

CExplosion::CExplosion()
{
}

// デストラクタ
CExplosion::~CExplosion()
{
}

// クリエイト
CExplosion *CExplosion::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CExplosion *pExplosion = NULL;
	pExplosion = new CExplosion;
	pExplosion->Init(pos,size);
	pExplosion->BindTexture(m_pTexture);

	return pExplosion;
}

// 爆発のセット
void CExplosion::SetExplosion(D3DXVECTOR3 pos)
{

}

D3DXVECTOR3 CExplosion::GetExplosion(void)
{
	return D3DXVECTOR3();
}

// 爆発の初期化処理
HRESULT CExplosion::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos,size);

	return S_OK;
}

// 爆発の終了処理
void CExplosion::Uninit(void)
{
	CScene2D::Uninit();
}

//爆発の更新処理
void CExplosion::Update(void)
{
	CScene2D::Update();

	// カウンターの更新
	m_nCounterAnim++;


	//テクスチャの切り替え速度
	if ((m_nCounterAnim % 8) == 0)
	{
		m_nPatternAnim++;
	}

	SetTex(m_nPatternAnim);

	if (m_nPatternAnim >= 7)
	{
		Uninit();
	}
}

// 爆発の描画処理
void CExplosion::Draw(void)
{
	CScene2D::Draw();
}

//爆発のテクスチャロード
HRESULT CExplosion::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\explosion000.png", &m_pTexture);

	return S_OK;
}

//爆発のテクスチャアンロード
void CExplosion::Unload()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}