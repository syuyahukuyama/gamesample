//==================================================================
//
// title�̏���[title.cpp]:
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

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = NULL;

//�R���X�g���N�^
CTitle::CTitle()
{
}

//�f�X�g���N�^
CTitle::~CTitle()
{
}

// �^�C�g���̃��[�h
HRESULT CTitle::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
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

//�N���G�C�g
CTitle *CTitle::Create(void)
{
	CTitle *pTitle;
	pTitle = new CTitle;
	pTitle->Init();
	pTitle->BindTexture(m_pTexture);

	return pTitle;
}

//����������
HRESULT CTitle::Init(void)
{
	//�w�i�̃e�N�X�`�����[�h
	CBg::Load();

	//�w�i�̐���
	CBg::Create(D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT));

	return S_OK;
}

//�I������
void CTitle::Uninit(void)
{
	//�w�i�̃e�N�X�`���A�����[�h
	CBg::Unload();

	//�^�C�g����ʂ̃A�����[�h
	//CTitle::Unload();

	Release();
}

//�X�V����
void CTitle::Update()
{
	//�L�[�{�[�h�̍X�V
	CInputKeyboard *pInputKeyboard;
	pInputKeyboard = CManager::GetInputKey();

	//���[�h����
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{
		CFade::SetFade(CFade::FADE_OUT,CManager::MODE_GAME);
	}
}

//�`�揈��
void CTitle::Draw()
{

}