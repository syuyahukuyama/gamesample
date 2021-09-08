//===================================================================
//
// �t�F�[�h�̏����@[fade.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _FADE_H_
#define _FADE_H_

#include "main.h"
#include "manager.h"

class CSceneSecond;

//�t�F�[�h�̃N���X
class CFade
{
public:
	typedef enum
	{
		FADE_NONE = 0,		//�������Ă��Ȃ�
		FADE_IN,			//�t�F�[�h�C��
		FADE_OUT,			//�t�F�[�h�A�E�g
		FADE_MAX,
	}FADE;
	CFade();
	~CFade();

	static CFade *Create(void);
	static void SetFade(FADE fade,CManager::MODE modenext);
	//static 

	static HRESULT Init(void);
	static void Uninit(void);
	static void Update(void);
	static void Draw(void);

private:
	static FADE m_fade;							//
	static CSceneSecond *m_pSceneSecond;			//
	static CManager::MODE m_modeNext;			//���̃��[�h(���)
	static D3DXCOLOR m_colorFade;				//�t�F�[�h�F
};


#endif
