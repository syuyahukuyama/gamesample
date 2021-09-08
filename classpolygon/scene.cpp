//========================================================
//
// [ポリゴンの処理]
//
//
//========================================================

#include <windows.h>

#include "renderer.h"
#include "main.h"
#include "scene.h"

// 静的メンバ変数
CScene *CScene::m_apScene[MAX_OBJ];
int CScene::m_nNumAll = 0;

// コンストラクタ
CScene::CScene()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] == NULL)
		{
			m_apScene[nCntScene] = this;
			//自分の番号を設定
			m_nID = nCntScene;
			m_nNumAll++;
			break;
		}
	}
}

// デストラクタ
CScene::~CScene()
{

}

//リリースオール
void CScene::ReleaseAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//終了処理
			m_apScene[nCntScene]->Uninit();
		}
	}
}

// オブジェクト更新処理
void CScene::UpdateAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//更新処理
			m_apScene[nCntScene]->Update();
		}
	}
}

// 描画処理
void CScene::DrawAll()
{
	for (int nCntScene = 0; nCntScene < MAX_OBJ; nCntScene++)
	{
		if (m_apScene[nCntScene] != NULL)
		{
			//描画処理
			m_apScene[nCntScene]->Draw();
		}
	}
}

void CScene::Release()
{
	if (m_apScene[m_nID] != NULL)
	{
		//インスタンスの破棄
		int nID = m_nID;
		delete m_apScene[nID];
		m_apScene[nID] = NULL;
		m_nNumAll--;
	}
}