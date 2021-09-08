//========================================================
//
// [�|���S���̏���]
//
//
//========================================================

#include <windows.h>

#include "renderer.h"
#include "main.h"
#include "scene.h"
#include "scene2D.h"
#include "manager.h"
#include "input.h"
#include "bullet.h"
#include "explosion.h"

//�}�N����`
#define PLAY_ANIM (1.0f / TEXTURE_X)
#define SCORE_ANIM (1,0f / MAX_SCORE_X)

// �R���X�g���N�^
CScene2D::CScene2D()
{

}

// �f�X�g���N�^
CScene2D::~CScene2D()
{

}

HRESULT CScene2D::Init(void)
{
	return E_NOTIMPL;
}

// �|���S���̏���������
HRESULT CScene2D::Init(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	//�ϐ��錾
	VERTEX_2D *pVtx;
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	if (FAILED(pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_2D, D3DPOOL_MANAGED, &m_pVtxBuff, NULL)))
	{
		return E_FAIL;
	}

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_����ݒ�
	m_pos = pos;
	m_size = size;
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//rhm�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//���_���̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0, 0.0);
	pVtx[1].tex = D3DXVECTOR2(1.0, 0.0);
	pVtx[2].tex = D3DXVECTOR2(0.0, 1.0);
	pVtx[3].tex = D3DXVECTOR2(1.0, 1.0);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

// �|���S���̏I������
void CScene2D::Uninit()
{
	//���_�o�b�t�@�̊J��
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}

	//�I�u�W�F�N�g�̔j��
	Release();
}

// �|���S���̍X�V����
void CScene2D::Update()
{
	VERTEX_2D *pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̍X�V
	pVtx[0].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y - m_size.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x - m_size.x, m_pos.y + m_size.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + m_size.x, m_pos.y + m_size.y, 0.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

// �|���S���̕`�揈��
void CScene2D::Draw()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}

CScene2D *CScene2D::Create(D3DXVECTOR3 pos, D3DXVECTOR2 size)
{
	CScene2D* pScene2D;
	pScene2D = new CScene2D;
	if (pScene2D != NULL)
	{
		pScene2D->Init(pos,size);
	}
	return pScene2D;
}

//�ʒu���̎擾
D3DXVECTOR3 CScene2D::GetPosition(void)
{
	return m_pos;
}

void CScene2D::SetPosition(D3DXVECTOR3 pos)
{
	m_pos = pos;
}

void CScene2D::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
	m_pTexture = pTexture;
}

//�|���S���̃T�C�Y�̐ݒ�
void CScene2D::SetSize(float fsizeX, float fsizeY)
{
	//�Ίp���̐ݒ�
	m_fLength = sqrtf(fsizeX * fsizeX + fsizeY * fsizeY);
	m_fAngle = atan2f(fsizeX, fsizeY);
}

void CScene2D::SetBg(float fAnim)
{
	//�ϐ��錾
	VERTEX_2D *pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`���̒��_���W
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f + fAnim);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f + fAnim);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f + fAnim);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f + fAnim);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//�����̃e�N�X�`�����W�̍X�V
void CScene2D::SetTex(float fTexture)
{
	//�ϐ��錾
	VERTEX_2D *pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`���̒��_���W
	pVtx[0].tex = D3DXVECTOR2(PLAY_ANIM * fTexture,0.0f);
	pVtx[1].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fTexture, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(PLAY_ANIM * fTexture, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fTexture, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//�X�R�A�̃e�N�X�`�����W
void CScene2D::SetScore(float fScore)
{
	//�ϐ��錾
	VERTEX_2D *pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�e�N�X�`���̒��_���W
	pVtx[0].tex = D3DXVECTOR2(PLAY_ANIM * fScore, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fScore, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(PLAY_ANIM * fScore, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(PLAY_ANIM + PLAY_ANIM * fScore, 1.0f);

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

bool CScene2D::collision(D3DXVECTOR3 pos, D3DXVECTOR2 size, OBJTYPE obj, CScene **pColscene)
{
	bool Col = false;
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		CScene *pScene;
		pScene = CScene::GetScene(nCntScene);

		if (pScene != NULL)
		{
			CScene::OBJTYPE objtype;
			objtype = pScene->GetObjType();
			if (objtype == obj)
			{
				D3DXVECTOR3 objpos = pScene->GetPosition();
				D3DXVECTOR2 objsize = pScene->GetSize();

				if (objpos.x - objsize.x / 2 <= pos.x + size.x && objpos.x + objsize.x / 2 > pos.x - size.x &&
					objpos.y - objsize.y / 2 <= pos.y + size.y && objpos.y + objsize.y / 2 > pos.y - size.y)
				{
					Col = true;

					*pColscene = pScene;
				}
			}
		}
	}
	return Col;
}