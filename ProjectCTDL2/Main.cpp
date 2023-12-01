#include "Queue.h"
#include "Queue.cpp"
#include "Graphics.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;

int createMainMenu();

int main()
{
	createMainMenu();
	
	return 0;
}
/***********************************************
@ Description Ham tao menu cac chuc nang
@ attention Neu chon exit thi thoat chuong trinh
************************************************/
int createMainMenu()
{
	int iSelect = 0;
	system("cls");

	ShowCursor(0);
	gotoxy(75, 1);
	SetColor(51);
	cout << "TAP HOA TU CA" << endl; // In tieu de

	int iCounter = 2;
	char cKey;
	int iX = 63, iY = 4; // lay toa do x = 50, y = 4 trong man hinh console.

	

	// Tao giao dien menu
	box(iX, iY + 0, 35, 2, 33, 7, "Hien thi thong tin hang hoa");
	box(iX, iY + 2, 35, 2, 33, 7, "Tim kiem thong tin hang hoa");
	box(iX, iY + 4, 35, 2, 33, 7, "Dat hang");
	box(iX, iY + 6, 35, 2, 33, 7, "Quan li");
	box(iX, iY + 8, 35, 2, 33, 7, "Thoat");
	// fix goc cua may cai canh
	for (int i = 1; i <= 4; i++)
	{
		gotoxy(iX , iY + (i * 2));
		SetColor(33);
		cout << char(195);
		gotoxy(iX + 35, iY + (i * 2));
		cout << char(180);
	}

	/*int iY = 4;
	int iXNow = iX, iYNow = iY;
	bool bCheck = true;
	while (true)
	{

	}*/
	_getch();
	return iSelect;
}