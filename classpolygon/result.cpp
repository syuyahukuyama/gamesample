//==================================================================
//
// resultの処理[result.cpp]:
// hukuyamasyuuya
//
//=================================================================
#include "main.h"
#include "result.h"
#include "title.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "fade.h"
#include "Bg.h"

//静的メンバ変数
LPDIRECT3DTEXTURE9 CResult::m_pTexture = NULL;

//コンストラクタ
CResult::CResult()
{
}

//デストラクタ
CResult::~CResult()
{
}

//クリエイト
CResult *CResult::Create(void)
{
	CResult *pResult;
	pResult = new CResult;
	pResult->Init();

	return pResult;
}

//初期化処理
HRESULT CResult::Init()
{
	//リザルト画面のロード
	//CResult::Load();

	//背景のテクスチャロード
	CBg::Load();

	//背景の生成
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//終了処理
void CResult::Uninit()
{
	//リザルト画面のアンロード
	//CResult::Unload();

	Release();
}

//更新処理
void CResult::Update()
{
	//キーボードの更新
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//モード処理
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		CFade::SetFade(CFade::FADE_OUT, CManager::MODE_TITLE);
	}
}

//描画処理
void CResult::Draw()
{
}

void CResult::Unload()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}