#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

/***************************************************
@ Description Ham thay doi kich co khung cmd
@ parameter Gia tri truyen vao chieu rong, chieu cao
***************************************************/
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

/**************************************************************
@ Description To mau cho chu
@ parameter Gia tri mau
@ return Mau tuong ung voi gia tri nay
**************************************************************/
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

/**************************************************
@ Description Dich chuyen con tro toi toa do x, y
@ parameter Toa do x, y muon chuyen den
***************************************************/
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
/********************************************
@ Description Xoa man hinh
********************************************/
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm l?y Key t? bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */

// Hàm t? vi?t
void ToMau(char* a, int color) // x, y là t?a ?? con tr? c?n nh?y ??n ?? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	textcolor(color);
	cout << a;
	textcolor(7);
}
/***********************************************
@ Description Ve 1 chiec hop chu nhat
@ parameter toa do x, y, chieu dai, chieu cao, mau chu, mau nen, chuoi can in
***********************************************/
void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoxy(ix, iy); cout << " ";
		}
	}
	//SetColor(7);
	gotoxy(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	//SetColor(t_color);//update
	if (h <= 1 || w <= 1)return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}
	gotoxy(x, y); cout << char(218);
	gotoxy(x + w, y); cout << char(191);
	gotoxy(x, y + h); cout << char(192);
	gotoxy(x + w, y + h); cout << char(217);

}

/*********************************************
@ Discription Dat mau cho chu
*********************************************/
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
/***********************************************
@ Decription Thay doi mau noi dung trong khung.
@ parameter Toa do x, y, noi dung.
***********************************************/
void changeContentColor(int x, int y, string nd)
{
	SetColor(2);
	gotoxy(x + 1, y + 1);
	cout << nd;
}
/*************************************************
* @Decription An con tro man hinh console
* @parameter Trang thai con tro, 0 la an, 1 la hien
*************************************************/
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
