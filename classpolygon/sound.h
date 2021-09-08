//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : 
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//=============================================================================
// �T�E���h�̃N���X
//=============================================================================
class CSound
{
public:
	CSound();
	~CSound();

	// �T�E���h�t�@�C��
	typedef enum
	{
		SOUND_LABEL_BGM000 = 0,		// BGM0
		SOUND_LABEL_BGM001,			// BGM1
		SOUND_LABEL_BGM002,			// BGM2
		SOUND_LABEL_BGM003,			// BGM3
		SOUND_LABEL_BGM004,			// BGM4
		SOUND_LABEL_BGM005,			// BGM5
		SOUND_LABEL_BGM006,			// BGM6
		SOUND_LABEL_BGM007,			// BGM7
		SOUND_LABEL_BGM008,			// BGM8
		SOUND_LABEL_SE_SHOT,		// �e���ˉ�
		SOUND_LABEL_SE_HIT,			// �q�b�g��
		SOUND_LABEL_SE_EXPLOSION,	// ������
		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);
private:
	// �p�����[�^�\���̒�`
	typedef struct
	{
		char *pFilename;	// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g
	} SOUNDPARAM;

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};

	SOUNDPARAM m_aParam[SOUND_LABEL_MAX] =
	{
		{"data/BGM/bgm000.wav", -1},		// BGM0
		{ "data/BGM/bgm001.wav", -1 },		// BGM1
		{ "data/BGM/bgm002.wav", -1 },		// BGM2
		{ "data/BGM/bgm003.wav", -1 },		// BGM3
		{ "data/BGM/bgm004.wav", -1 },		// BGM4
		{ "data/BGM/bgm005.wav", -1 },		// BGM5
		{ "data/BGM/bgm006 coll.wav", -1 },	// BGM6
		{ "data/BGM/bgm007.wav", -1 },		// BGM7
		{ "data/BGM/bgm008.wav", -1 },		// BGM8
		{ "data/SE/shot000.wav", 0 },		// �e���ˉ�
		{ "data/SE/hit000.wav", 0 },		// �q�b�g��
		{ "data/SE/explosion000.wav", 0 },	// ������
	};
};

#endif

