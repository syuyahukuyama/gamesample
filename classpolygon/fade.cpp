//
//
//
//
//

#include "fade.h"
#include "main.h"
#include "manager.h"
#include "SceneSecond.h"

//静的メンバ変数
CSceneSecond *CFade::m_pSceneSecond = NULL;
CFade::FADE CFade::m_fade = FADE_IN;
D3DXCOLOR CFade::m_colorFade = D3DXCOLOR(0,0,0,1.0);
CManager::MODE CFade::m_modeNext;

CFade::CFade()
{
}

CFade::~CFade()
{
}

CFade *CFade::Create(void)
{
	CFade *pFade;
	pFade = new CFade;
	pFade->Init();
	return pFade;
}

void CFade::SetFade(FADE fade, CManager::MODE modenext)
{
	m_fade = fade;
	m_modeNext = modenext;
}

//初期化処理
HRESULT CFade::Init(void)
{
	if (m_pSceneSecond == NULL)
	{
		m_pSceneSecond = CSceneSecond::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));
	}
	return S_OK;
}

//終了処理
void CFade::Uninit(void)
{
	if (m_pSceneSecond != NULL)
	{
		m_pSceneSecond->Uninit();
		m_pSceneSecond = NULL;
	}
}

//更新処理
void CFade::Update(void)
{
	if (m_fade == FADE_IN)
	{
		m_colorFade.a -= 0.05f;
		if (m_colorFade.a <= 0.0f)
		{
			m_fade = FADE_NONE;
		}
	}
	else if (m_fade == FADE_OUT)
	{
		m_colorFade.a += 0.05f;
		if (m_colorFade.a >= 1.0f)
		{
			m_fade = FADE_IN;
			CManager::SetMode(m_modeNext);
		}
	}
	m_pSceneSecond->SetColor(m_colorFade);
}

//描画処理
void CFade::Draw(void)
{
	if (m_pSceneSecond != NULL)
	{
		m_pSceneSecond->Draw();
	}
}