//===========================================================
//
// [ポリゴンの処理]
// 
//
//===========================================================

#ifndef _SECENE_H_
#define _SECENE_H_

//===========================================================
// インクルードファイル
//===========================================================
#include <windows.h>
#include "main.h"

//マクロ定義
#define MAX_OBJ (1000)		//オブジェクトの最大数

//オブジェクトクラス
class CScene
{
public:
	//オブジェクトの種類
	typedef enum
	{
		OBJTYPE_NONE = 0,
		OBJTYPE_PLAYER,		//プレイヤー
		OBJTYPE_ENEMY,		//敵
		OBJTYPE_BULLET,		//弾
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

	virtual D3DXVECTOR3 GetPosition(void) = 0;											// 位置の取得
	virtual D3DXVECTOR2 GetSize(void) = 0;

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

protected:
	void Release(void);
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// バッファへのポインタ
	LPDIRECT3DTEXTURE9		m_pTexture;		// テクスチャ
	D3DXVECTOR3				m_pos;			// ポリゴンの位置
	static CScene *m_apScene[MAX_OBJ];		// オブジェクト
	OBJTYPE m_ObjType;						// オブジェクトの種類
	static int m_nNumAll;

	int m_nID;								// 格納先の番号
};

#endif