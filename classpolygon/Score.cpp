//===================================================================
//
// �X�R�A�̏����@[score.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "Score.h"
#include "main.h"
#include "manager.h"
#include "renderer.h"

//�ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CScore::m_apTexture[MAX_SCORE] = {};

//�R���X�g���N�^
CScore::CScore()
{
}

//�f�X�g���N�^
CScore::~CScore()
{
}

//�N���G�C�g
CScore *CScore::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScore *pScore;
	pScore = new CScore;
	pScore->Init(pos, size);
	pScore->BindTexture(m_apTexture[0]);

	return pScore;
}

//�e�N�X�`�����[�h
HRESULT CScore::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\number000.png", &m_apTexture[0]);

	return S_OK;
}

//�e�N�X�`���̃A�����[�h
void CScore::Unload(void)
{
	if (m_apTexture[0] != NULL)
	{
		m_apTexture[0]->Release();
		m_apTexture[0] = NULL;
	}
}

//����������
HRESULT CScore::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos, size);

	return S_OK;
}

//�I������
void CScore::Uninit(void)
{
	CScene2D::Uninit();
}

//�X�V����
void CScore::Update(void)
{
	CScene2D::Update();

	SetScore(m_nPatternSAnim);
}

//�`�揈��
void CScore::Draw(void)
{
	CScene2D::Draw();
}