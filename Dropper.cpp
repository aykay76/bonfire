#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

DWORD GetFileCount(LPTSTR lpszDirectory);
void DeleteDirectory(LPTSTR lpszDirectory);

BOOL CDropper::OnDrop( CWnd* pWnd, COleDataObject* pDataObject, DROPEFFECT dropEffect, CPoint point )
{
	CBonfireDlg *pDlg = (CBonfireDlg *)pWnd;
	STGMEDIUM stgMedium;
	char szFilename[MAX_PATH];
	UINT uCount;
	char szMessage[256];
	DWORD dwAttributes;
	DWORD dwTotalFiles = 0;

	pWnd->SetForegroundWindow();

	pDataObject->GetData(CF_HDROP, &stgMedium);

	uCount = DragQueryFile((HDROP)stgMedium.hGlobal, -1, szFilename, MAX_PATH);

	for (UINT uLoop = 0; uLoop < uCount; uLoop++) {
		DragQueryFile((HDROP)stgMedium.hGlobal, uLoop, szFilename, MAX_PATH);
		
		dwAttributes = GetFileAttributes(szFilename);
		if (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			dwTotalFiles += GetFileCount(szFilename);
		} else {
			//DeleteFile(szFilename);
			dwTotalFiles ++;
		}
	}

	pDlg->m_wndFire.m_nSize += 15;

	sprintf(szMessage, "Are you sure you want to delete these %ld files.", dwTotalFiles);
	if (pWnd->MessageBox(szMessage, "Confirm", MB_YESNO | MB_ICONQUESTION) == IDYES) {
		for (UINT uLoop = 0; uLoop < uCount; uLoop++) {
			DragQueryFile((HDROP)stgMedium.hGlobal, uLoop, szFilename, MAX_PATH);
			
			dwAttributes = GetFileAttributes(szFilename);
			if (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				DeleteDirectory(szFilename);
				RemoveDirectory(szFilename);
			} else {
				DeleteFile(szFilename);
			}
		}
	}

	pDlg->m_wndFire.m_nSize -= 15;

	return TRUE;
}

DROPEFFECT CDropper::OnDragEnter( CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point )
{
	TRACE("On Drag Enter\n");

	return DROPEFFECT_COPY;
}

DROPEFFECT CDropper::OnDragOver( CWnd* pWnd, COleDataObject* pDataObject, DWORD dwKeyState, CPoint point )
{
	return DROPEFFECT_COPY;
}

void CDropper::OnDragLeave( CWnd* pWnd )
{
	TRACE("OnDragLeave\n");
}

DWORD GetFileCount(LPTSTR lpszDirectory)
{
	WIN32_FIND_DATA w32fd;
	char szPattern[MAX_PATH];
	HANDLE hFindFile;
	DWORD dwAttributes;
	char szNewFile[MAX_PATH];
	DWORD dwCount = 0;

	sprintf(szPattern, "%s\\*.*", lpszDirectory);

	hFindFile = FindFirstFile(szPattern, &w32fd);
	if (hFindFile == INVALID_HANDLE_VALUE) {
		return 0;
	}

	// iterate
	do {
		if (!strcmp(w32fd.cFileName, ".") || !strcmp(w32fd.cFileName, "..")) continue;

		sprintf(szNewFile, "%s\\%s", lpszDirectory, w32fd.cFileName);

		dwAttributes = GetFileAttributes(szNewFile);

		if (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			dwCount += GetFileCount(szNewFile);
		} else {
			dwCount++;
		}
	} while (FindNextFile(hFindFile, &w32fd));

	FindClose(hFindFile);

	return dwCount;
}

void DeleteDirectory(LPTSTR lpszDirectory)
{
	WIN32_FIND_DATA w32fd;
	char szPattern[MAX_PATH];
	HANDLE hFindFile;
	DWORD dwAttributes;
	char szNewFile[MAX_PATH];

	sprintf(szPattern, "%s\\*.*", lpszDirectory);

	hFindFile = FindFirstFile(szPattern, &w32fd);
	if (hFindFile == INVALID_HANDLE_VALUE) {
		return;
	}

	// iterate
	do {
		if (!strcmp(w32fd.cFileName, ".") || !strcmp(w32fd.cFileName, "..")) continue;

		sprintf(szNewFile, "%s\\%s", lpszDirectory, w32fd.cFileName);

		dwAttributes = GetFileAttributes(szNewFile);

		if (dwAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			DeleteDirectory(szNewFile);
			RemoveDirectory(szNewFile);
		} else {
			DeleteFile(szNewFile);
		}
	} while (FindNextFile(hFindFile, &w32fd));

	FindClose(hFindFile);
}