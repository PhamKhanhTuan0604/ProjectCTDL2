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

// H�m x�a m�n h�nh.
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

// H�m l?y Key t? b�n ph�m
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n ph�m Esc */

// H�m t? vi?t
void ToMau(char* a, int color) // x, y l� t?a ?? con tr? c?n nh?y ??n ?? vi?t, a l� chu?i c?n truy?n v�o, color l� m�u truy?n v�o.
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
/*******************************************
* @Decription Ve menu ban dau
* @parameter x, y, width, hight , t color, b color, noi dung
*******************************************/
void drawMenu(int x, int y, string nd[])
{
	int iX = x, iY = y;
	// Tao giao dien menu ban dau
	box(iX, iY + 0, 35, 2, 33, 7, nd[0]);
	box(iX, iY + 2, 35, 2, 33, 7, nd[1]);
	box(iX, iY + 4, 35, 2, 33, 7, nd[2]);
	box(iX, iY + 6, 35, 2, 33, 7, nd[3]);
	box(iX, iY + 8, 35, 2, 33, 7, nd[4]);
	// fix goc cua may cai canh
	for (int i = 1; i <= 4; i++)
	{
		gotoxy(iX, iY + (i * 2));
		SetColor(33);
		cout << char(195);
		gotoxy(iX + 35, iY + (i * 2));
		cout << char(180);
	}
}
/*************************************************
* Decription Ve khung tieu de hang hoa
* parameter toa do x, y, width, height, mau chu, moi dung
**************************************************/
void printLetterHead(int x, int y, int w, int h, int t_color)
{
	SetColor(t_color);
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
		cout << '|';
		gotoxy(x + w, iy);
		cout << '|';
	}
	int yn = y + 1;
	SetColor(220);
	gotoxy(x + 1, yn);
	cout << "Ma hang";
	gotoxy(x + 12, yn);
	cout << "Ten hang";
	gotoxy(x + 45, yn);
	cout << "Noi san xuat";
	gotoxy(x + 60, yn);
	cout << "Mau sac";
	gotoxy(x + 80, yn);
	cout << "Gia ban";
	gotoxy(x + 100, yn);
	cout << "Ngay nhap kho";
	gotoxy(x + 135, yn);
	cout << "So luong";
	// dien ngan cach
	SetColor(t_color);
	gotoxy(x + 11, yn);
	cout << "|";
	gotoxy(x + 44, yn);
	cout << "|";
	gotoxy(x + 59, yn);
	cout << "|";
	gotoxy(x + 79, yn);
	cout << "|";
	gotoxy(x + 99, yn);
	cout << "|";
	gotoxy(x + 134, yn);
	cout << "|";
}

/**********************************************
* @Decription In ra tieu de don hang
* parameter toa do x, y, dai, cao, mau chu
**********************************************/
void printHeadCustomer(int x, int y, int w, int h, int t_color)
{
	SetColor(t_color);
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
		cout << '|';
		gotoxy(x + w, iy);
		cout << '|';
	}
	int iYn = y+1;
	SetColor(220);
	gotoxy(x + 1, iYn);
	cout << "STT";
	gotoxy(x + 6, iYn);
	cout << "Ma hang";
	gotoxy(x + 15, iYn);
	cout << "So luong";
	gotoxy(x + 24, iYn);
	cout << "Tong tien";
	gotoxy(x + 38, iYn);
	cout << "Ten khach hang";
	gotoxy(x + 70, iYn);
	cout << "Dia chi";
	gotoxy(x + 120, iYn);
	cout << "So dien thoai";
	gotoxy(x + 135, iYn);
	cout << "Ngay dat hang";
	//In vach ngan
	SetColor(t_color);
	gotoxy(x + 5, iYn);
	cout << "|";
	gotoxy(x + 14, iYn);
	cout << "|";
	gotoxy(x + 23, iYn);
	cout << "|";
	gotoxy(x + 37, iYn);
	cout << "|";
	gotoxy(x + 69, iYn);
	cout << "|";
	gotoxy(x + 119, iYn);
	cout << "|";
	gotoxy(x + 134, iYn);
	cout << "|";
}