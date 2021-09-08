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

// �ÓI�����o�ϐ�
CScene *CScene::m_apScene[MAX_OBJ];
int CScene::m_nNumAll = 0;

// �R���X�g���N�^
CScene::CScene()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] == NULL)
		{
			m_apScene[nCntScene] = this;
			//�����̔ԍ���ݒ�
			m_nID = nCntScene;
			m_nNumAll++;
			break;
		}
	}
}

// �f�X�g���N�^
CScene::~CScene()
{

}

//�����[�X�I�[��
void CScene::ReleaseAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//�I������
			m_apScene[nCntScene]->Uninit();
		}
	}
}

// �I�u�W�F�N�g�X�V����
void CScene::UpdateAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//�X�V����
			m_apScene[nCntScene]->Update();
		}
	}
}

// �`�揈��
void CScene::DrawAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//�`�揈��
			m_apScene[nCntScene]->Draw();
		}
	}
}

void CScene::Release()
{
	if (m_apScene[m_nID] != NULL)
	{
		//�C���X�^���X�̔j��
		int nID = m_nID;
		delete m_apScene[nID];
		m_apScene[nID] = NULL;
		m_nNumAll--;
	}
}