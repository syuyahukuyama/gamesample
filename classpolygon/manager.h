//===========================================================
//
// [マネージャーの処理]
// 
//
//===========================================================
#ifndef _MANAGER_H_
#define _MANAGER_H_

//前方宣言
class CRenderer;
class CInputKeyboard;
class CPlayer;
class CBullet;
class CEnemy;
class CEnemyS;
class CBg;
class CSound;
class CTitle;
class CGame;
class CResult;

class CManager
{
public:
	typedef enum
	{
		MODE_TITLE = 0,
		MODE_GAME,
		MODE_RESULT,
		MODE_MAX,
	}MODE;

	CManager();
	~CManager();

	HRESULT Init(HINSTANCE hInstance,HWND hWnd, bool bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static void SetMode(MODE mode);
	static MODE GetMode(void);

	static CRenderer *GetRenderer(void);
	static CInputKeyboard *GetInputKey(void);
	static CBullet *GetBullet(void);
	static CSound *GetSound(void);

private:
	static CRenderer *m_pRenderer;
	static CInputKeyboard *m_pInputKeyboard;
	static CBullet *m_pBullet;
	static CEnemy *m_pEnemy;
	static CEnemyS *m_pEnemyS;
	static CBg *m_pBg;
	static CSound *m_pSound;
	static CTitle *m_pTitle;
	static CGame *m_pGame;
	static CResult *m_pResult;
	static MODE m_mode;
};

#endif // !_MANAGER_H_
