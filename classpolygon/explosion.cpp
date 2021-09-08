//===================================================================
//
// �e�̏����@[bullet.cpp]
// Author: fukuyama syuya
//
//===================================================================
#include "explosion.h"
#include "manager.h"
#include "renderer.h"

// �ÓI�����o�ϐ�
LPDIRECT3DTEXTURE9 CExplosion::m_pTexture = NULL;

CExplosion::CExplosion()
{
}

// �f�X�g���N�^
CExplosion::~CExplosion()
{
}

// �N���G�C�g
CExplosion *CExplosion::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CExplosion *pExplosion = NULL;
	pExplosion = new CExplosion;
	pExplosion->Init(pos,size);
	pExplosion->BindTexture(m_pTexture);

	return pExplosion;
}

// �����̃Z�b�g
void CExplosion::SetExplosion(D3DXVECTOR3 pos)
{

}

D3DXVECTOR3 CExplosion::GetExplosion(void)
{
	return D3DXVECTOR3();
}

// �����̏���������
HRESULT CExplosion::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D::Init(pos,size);

	return S_OK;
}

// �����̏I������
void CExplosion::Uninit(void)
{
	CScene2D::Uninit();
}

//�����̍X�V����
void CExplosion::Update(void)
{
	CScene2D::Update();

	// �J�E���^�[�̍X�V
	m_nCounterAnim++;


	//�e�N�X�`���̐؂�ւ����x
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

// �����̕`�揈��
void CExplosion::Draw(void)
{
	CScene2D::Draw();
}

//�����̃e�N�X�`�����[�h
HRESULT CExplosion::Load(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̐���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\explosion000.png", &m_pTexture);

	return S_OK;
}

//�����̃e�N�X�`���A�����[�h
void CExplosion::Unload()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}