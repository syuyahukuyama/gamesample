//===========================================================
//
// [gameの処理]
// 
//
//===========================================================

#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"
#include "scene.h"

class CBg;
class CPlayer;

class CGame :public CScene
{
public:
	CGame();
	~CGame();
	static CGame *Create(void);

	virtual D3DXVECTOR3 GetPosition(void) { return D3DXVECTOR3(); }
	virtual D3DXVECTOR2 GetSize(void) { return D3DXVECTOR2(); }

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CPlayer *GetPlayer(void);

private:
	static CBg *GetBg;
	static CPlayer *m_pPlayer;
	int			m_nPornCnt;					//敵の生成カウンター
};

#endif // !_GAME_H_
