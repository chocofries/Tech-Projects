/***********************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand

(c) 2018 Media Design School

File Name   :   AnimPaint
Description :   Painting & Animation Software
Author      :   John (Zheng Yu) Bu
Mail        :   zheng.yu5315@mediadesign.school.nz
********************/

#pragma once
//Library Includes
#include <Windows.h>

class CBackBuffer
{
public:
	CBackBuffer();
	~CBackBuffer();

	bool Initialise(HWND _hWnd, int _iWidth, int _iHeight);

	HDC GetBFDC() const;
	HBITMAP GetBitMap() const;

	int GetHeight() const;
	int GetWidth() const;

	void Clear();
	void Present();

private:
	CBackBuffer(const CBackBuffer&);
	//CBackBuffer* & operator = (const CBackBuffer&);

private:
	HWND m_hWnd;
	HDC m_BFDC;  //Handle to the in-memory DC for holding the backbuffer 
	HBITMAP m_hBFBitmap; //handle to the bitmap that represents the backbuffer
	HBITMAP m_hOldBitmap; //Used in select object to save the old bitmap.
	int m_iWidth;
	int m_iHeight;


};


