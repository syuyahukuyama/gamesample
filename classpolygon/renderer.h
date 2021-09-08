//===========================================================
//
// [レンダリングの処理]
// 
//
//===========================================================

#ifndef _RENDERER_H_
#define _RENDERER_H_ 

//===========================================================
// インクルードファイル
//===========================================================
#include <windows.h>
#include "main.h"

//レンダラーのクラス
class CRenderer
{
public:
	CRenderer();
	~CRenderer();
	HRESULT Init(HWND hWnd, bool bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	LPDIRECT3DDEVICE9 GetDevice(void) { return m_pD3DDevice; }
private:
	void DrawFPS(void);

	LPDIRECT3D9				m_pD3D;			// Direct3Dオブジェクト
	LPDIRECT3DDEVICE9		m_pD3DDevice;	// Deviceオブジェクト(描画に必要)
	VERTEX_2D				m_aVertex[4];	// 頂点情報を格納する
	LPD3DXFONT				m_pFont;		// フォントへのポインタ
};

#endif