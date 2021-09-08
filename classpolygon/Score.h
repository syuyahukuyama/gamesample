//===================================================================
//
// �X�R�A�̏����@[score.h]
// Author: fukuyama syuya
//
//===================================================================
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "scene2D.h"

//�}�N����`
#define MAX_SCORE (8)			//�X�R�A�̌���

class CScore : public CScene2D
{
public:
	CScore();
	~CScore();

	static CScore *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	static HRESULT Load(void);
	static void Unload(void);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);

private:
	static LPDIRECT3DTEXTURE9	m_apTexture[MAX_SCORE];		//�X�R�A�̃e�N�X�`��
	int		m_nCounterSAnim;									//�J�E���^�[
	float	m_nPatternSAnim;									//�p�^�[��No
};

#endif // !_SCORE_H_
