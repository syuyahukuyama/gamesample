//=============================================================================
//
// サウンド処理 [sound.h]
// Author : 
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//=============================================================================
// サウンドのクラス
//=============================================================================
class CSound
{
public:
	CSound();
	~CSound();

	// サウンドファイル
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
		SOUND_LABEL_SE_SHOT,		// 弾発射音
		SOUND_LABEL_SE_HIT,			// ヒット音
		SOUND_LABEL_SE_EXPLOSION,	// 爆発音
		SOUND_LABEL_MAX,
	} SOUND_LABEL;

	HRESULT InitSound(HWND hWnd);
	void UninitSound(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);
private:
	// パラメータ構造体定義
	typedef struct
	{
		char *pFilename;	// ファイル名
		int nCntLoop;		// ループカウント
	} SOUNDPARAM;

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// ソースボイス
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// オーディオデータ
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
		{ "data/SE/shot000.wav", 0 },		// 弾発射音
		{ "data/SE/hit000.wav", 0 },		// ヒット音
		{ "data/SE/explosion000.wav", 0 },	// 爆発音
	};
};

#endif

