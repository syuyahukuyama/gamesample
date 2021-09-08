//==================================================================
//
// result�̏���[result.cpp]:
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

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CResult::m_pTexture = NULL;

//�R���X�g���N�^
CResult::CResult()
{
}

//�f�X�g���N�^
CResult::~CResult()
{
}

//�N���G�C�g
CResult *CResult::Create(void)
{
	CResult *pResult;
	pResult = new CResult;
	pResult->Init();

	return pResult;
}

//����������
HRESULT CResult::Init()
{
	//���U���g��ʂ̃��[�h
	//CResult::Load();

	//�w�i�̃e�N�X�`�����[�h
	CBg::Load();

	//�w�i�̐���
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//�I������
void CResult::Uninit()
{
	//���U���g��ʂ̃A�����[�h
	//CResult::Unload();

	Release();
}

//�X�V����
void CResult::Update()
{
	//�L�[�{�[�h�̍X�V
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//���[�h����
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		CFade::SetFade(CFade::FADE_OUT, CManager::MODE_TITLE);
	}
}

//�`�揈��
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