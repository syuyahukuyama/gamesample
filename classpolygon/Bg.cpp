//==================================================================
//
// Bg‚Ìˆ—[Bg.cpp]:
// hukuyamasyuuya
//
//=================================================================

#include "Bg.h"
#include "manager.h"
#include "renderer.h"
#include "scene2D.h"

//Ã“Iƒƒ“ƒo•Ï”
LPDIRECT3DTEXTURE9 CBg::m_apTexture[MAX_BG] = {};
CBg::TEXBG CBg::m_texbg = BG_TITLE;

// ”wŒiƒ[ƒh
HRESULT CBg::Load(void)
{
	CManager::MODE mode = CManager::GetMode();

	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();
	switch (CManager::GetMode())
	{
	case CManager::MODE_TITLE:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Bg001.png", &m_apTexture[0]);
		break;

	case CManager::MODE_GAME:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Bg000.jpg", &m_apTexture[0]);
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\fig1j.png", &m_apTexture[1]);
		break;

	case CManager::MODE_RESULT:
		D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\Bg000.jpg", &m_apTexture[0]);
		break;
	}
	return S_OK;
}

// ”wŒiƒAƒ“ƒ[ƒh
void CBg::Unload(void)
{
	if (m_apTexture[0] != NULL)
	{
		m_apTexture[0]->Release();
		m_apTexture[0] = NULL;
	}
}

CBg *CBg::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CBg *pBg;
	pBg = new CBg;
	pBg->Init(pos,size);
	return pBg;
}

HRESULT CBg::Init(void)
{
	return E_NOTIMPL;
}

// ”wŒi‚ÌƒRƒ“ƒXƒgƒ‰ƒNƒ^
CBg::CBg()
{
	//”wŒi‚Ì”•ª‰ñ‚·
	for (int nBg = 0; nBg < MAX_BG; nBg++)
	{
		m_apScene2D[nBg] = NULL;
	}
}

// ”wŒi‚ÌƒfƒXƒgƒ‰ƒNƒ^
CBg::~CBg()
{
}

//”wŒi‚Ì‰Šú‰»ˆ—
HRESULT CBg::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	switch (CManager::GetMode())
	{
	case CManager::MODE_TITLE:
		m_apScene2D[0] = new CScene2D;
		m_apScene2D[0]->Init(pos, size);
		m_apScene2D[0]->BindTexture(m_apTexture[0]);
		break;
	case CManager::MODE_GAME:
		for (int nBg = 0; nBg < MAX_BG; nBg++)
		{
			m_apScene2D[nBg] = new CScene2D;
			m_apScene2D[nBg]->Init(pos, size);
			m_apScene2D[nBg]->BindTexture(m_apTexture[nBg]);
		}
		break;

	case CManager::MODE_RESULT:
		m_apScene2D[0] = new CScene2D;
		m_apScene2D[0]->Init(pos, size);
		m_apScene2D[0]->BindTexture(m_apTexture[0]);
		break;
	}
	return S_OK;
}

//”wŒi‚ÌI—¹ˆ—
void CBg::Uninit(void)
{
	for (int nBg = 0; nBg < MAX_BG; nBg++)
	{
		if (m_apScene2D[nBg] != NULL)
		{
			m_apScene2D[nBg]->Uninit();
			m_apScene2D[nBg] = NULL;
		}
	}

	Release();
}

// ”wŒi‚ÌXVˆ—
void CBg::Update(void)
{
	for (int nBg = 0; nBg < 2; nBg++)
	{
		if (m_apScene2D[nBg] != NULL)
		{
			m_fAnim -= 0.0005f;

			//§ŒÀ
			m_apScene2D[nBg]->SetBg(m_fAnim *(nBg + 1));
		}
	}
}

// ”wŒi‚Ì•`‰æˆ—
void CBg::Draw(void)
{
}

void CBg::SetBgTex(TEXBG texbg)
{
	m_texbg = texbg;
}
