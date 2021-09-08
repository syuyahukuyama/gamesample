//========================================================
//
// [�|���S��2D�̏���]
//
//
//========================================================
#ifndef _SCENESECOND_H_
#define _SCENESECOND_H_

class CSceneSecond
{
public:
	CSceneSecond();
	~CSceneSecond();
	static CSceneSecond *Create(D3DXVECTOR3 pos, D3DXVECTOR2 size);

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR2 size);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetBg(float fAnim);
	void SetTex(float fTexture);
	void SetScore(float fScore);

	void SetPosition(D3DXVECTOR3 pos);		// �ʒu�̐ݒ�
	D3DXVECTOR3 GetPosition(void);			// �ʒu�̎擾
	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);
	void SetColor(D3DXCOLOR col);
	//void SetSize(float fsizeX, float fsizeY);

	D3DXVECTOR2 GetSize(void) { return m_size; }
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// �o�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9		m_pTexture;		// �e�N�X�`��
	D3DXVECTOR3				m_pos;			// �|���S���̈ʒu
	D3DXVECTOR2				m_size;			// �|���S���̃T�C�Y
	float					m_fLength;		//�Ίp���̒���
	float					m_fAngle;		//
};

#endif
