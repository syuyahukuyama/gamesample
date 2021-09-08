//===========================================================
//
// [�|���S���̏���]
// 
//
//===========================================================

#ifndef _SECENE_H_
#define _SECENE_H_

//===========================================================
// �C���N���[�h�t�@�C��
//===========================================================
#include <windows.h>
#include "main.h"

//�}�N����`
#define MAX_OBJ (1000)		//�I�u�W�F�N�g�̍ő吔

//�I�u�W�F�N�g�N���X
class CScene
{
public:
	//�I�u�W�F�N�g�̎��
	typedef enum
	{
		OBJTYPE_NONE = 0,
		OBJTYPE_PLAYER,		//�v���C���[
		OBJTYPE_ENEMY,		//�G
		OBJTYPE_BULLET,		//�e
		OBJTYPE_MAX,
	}OBJTYPE;
	CScene();
	virtual ~CScene();
	static void ReleaseAll(void);
	static void UpdateAll(void);
   	static void DrawAll(void);
	void SetObjType(OBJTYPE obj) { m_ObjType = obj; }
	OBJTYPE GetObjType(void) { return m_ObjType; }
	static CScene *GetScene(int nCntScene) { return m_apScene[nCntScene]; }

	//void BindTexture(LPDIRECT3DTEXTURE9 pTexture);

	virtual D3DXVECTOR3 GetPosition(void) = 0;											// �ʒu�̎擾
	virtual D3DXVECTOR2 GetSize(void) = 0;

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

protected:
	void Release(void);
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// �o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9		m_pTexture;		// �e�N�X�`��
	D3DXVECTOR3				m_pos;			// �|���S���̈ʒu
	static CScene *m_apScene[MAX_OBJ];		// �I�u�W�F�N�g
	OBJTYPE m_ObjType;						// �I�u�W�F�N�g�̎��
	static int m_nNumAll;

	int m_nID;								// �i�[��̔ԍ�
};

#endif