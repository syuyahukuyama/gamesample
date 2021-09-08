//========================================================
//
// [ポリゴンの処理]
//
//
//========================================================

#include <windows.h>

#include "renderer.h"
#include "main.h"
#include "scene.h"
#include "SceneSecond.h"
#include "manager.h"
#include "input.h"
#include "bullet.h"
#include "explosion.h"

//マクロ定義
#define PLAY_ANIM (1.0f / TEXTURE_X)
#define SCORE_ANIM (1,0f / MAX_SCORE_X)

// コンストラクタ
CSceneSecond::CSceneSecond()
{

}

// デストラクタ
CSceneSecond::~CSceneSecond()
{

}

// ポリゴンの初期化処理
HRESULT CSceneSecond::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	//変数宣言
	VERTEX_2D *pVtx;
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//頂点バッファの生成
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL)))
	{
		return E_FAIL;
	}

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点情報を設定
	m_pos = pos;
	m_size = size;
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//rhmの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//頂点情報の設定
	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

// ポリゴンの終了処理
void CSceneSecond::Uninit()
{
	//頂点バッファの開放
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//オブジェクトの破棄
	//Release();
}

// ポリゴンの更新処理
void CSceneSecond::Update()
{
	VERTEX_2D *pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の更新
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

// ポリゴンの描画処理
void CSceneSecond::Draw()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_pTexture);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

CSceneSecond *CSceneSecond::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CSceneSecond* pSceneSecond;
	pSceneSecond = new CSceneSecond;
	if (pSceneSecond != NULL)
	{
		pSceneSecond->Init(pos, size);
	}
	return pSceneSecond;
}

//位置情報の取得
D3DXVECTOR3 CSceneSecond::GetPosition(void)
{
	return m_pos;
}

void CSceneSecond::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

void CSceneSecond::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

void CSceneSecond::SetColor(D3DXCOLOR col)
{
	//変数宣言
	VERTEX_2D *pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点カラーの設定
	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//ポリゴンのサイズの設定
//void CSceneSecond::SetSize(float fsizeX, float fsizeY)
//{
//	//対角線の設定
//	m_fLength = sqrtf(fsizeX * fsizeX + fsizeY * fsizeY);
//	m_fAngle = atan2f(fsizeX, fsizeY);
//}

void CSceneSecond::SetBg(float fAnim)
{
	//変数宣言
	VERTEX_2D *pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャの頂点座標
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f + fAnim);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f + fAnim);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f + fAnim);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f + fAnim);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//爆発のテクスチャ座標の更新
void CSceneSecond::SetTex(float fTexture)
{
	//変数宣言
	VERTEX_2D *pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャの頂点座標
	pVtx[0].tex = D3DXVECTOR2(PLAY_ANIM * fTexture, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fTexture, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(PLAY_ANIM * fTexture, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fTexture, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//スコアのテクスチャ座標
void CSceneSecond::SetScore(float fScore)
{
	//変数宣言
	VERTEX_2D *pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャの頂点座標
	pVtx[0].tex = D3DXVECTOR2(PLAY_ANIM * fScore, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fScore, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(PLAY_ANIM * fScore, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fScore, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}