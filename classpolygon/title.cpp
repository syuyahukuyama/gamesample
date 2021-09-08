//==================================================================
//
// titleの処理[title.cpp]:
// hukuyamasyuuya
//
//=================================================================
#include "title.h"
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "Bg.h"
#include "fade.h"

//静的メンバ変数
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = NULL;

//コンストラクタ
CTitle::CTitle()
{
}

//デストラクタ
CTitle::~CTitle()
{
}

// タイトルのロード
HRESULT CTitle::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//テクスチャの生成
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Bg000.jpg", &m_pTexture);

	return S_OK;
}

void CTitle::Unload(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//クリエイト
CTitle *CTitle::Create(void)
{
	CTitle *pTitle;
	pTitle = new CTitle;
	pTitle->Init();
	pTitle->BindTexture(m_pTexture);

	return pTitle;
}

//初期化処理
HRESULT CTitle::Init(void)
{
	//背景のテクスチャロード
	CBg::Load();

	//背景の生成
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//終了処理
void CTitle::Uninit(void)
{
	//背景のテクスチャアンロード
	CBg::Unload();

	//タイトル画面のアンロード
	//CTitle::Unload();

	Release();
}

//更新処理
void CTitle::Update()
{
	//キーボードの更新
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//モード処理
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		CFade::SetFade(CFade::FADE_OUT,CManager::MODE_GAME);
	}
}

//描画処理
void CTitle::Draw()
{

}