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
	string strChucNang[5] = {"Hien thi thong tin hang hoa","Tim kiem thong tin hang hoa" ,"Dat hang" , "Quan li" , "Thoat" };
	ShowCur(0);
	gotoxy(75, 3);
	SetColor(51);
	cout << "TAP HOA TU CA" << endl; // In tieu de

	int iX = 63, iY = 7; // lay toa do x = 50, y = 4 trong man hinh console.

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
	//In ra menu ban dau, chua thao tac
	changeContentColor(iX , iY , strChucNang[0]);
	
	/*int iXp = iX, iYp = iY; // toa do chu to mau
	int iXcu = iXp, int iYcu = iYp;
	bool bFlag = true;
	while (true)
	{
		if (bFlag)
		{
			//xoa
			gotoxy(iXcu, iYcu);
			changeContentColor(iX, iY, strChucNang[0]);
			iXcu = iXp; iYcu = iYp;

			changeContentColor(iX, iY, strChucNang[0]);
			bool Flag = false;
		}
		// Dieu khien - di chuyen
		if (_kbhit())
		{
			char cDo = _getch();
			if (cDo == -32)
			{
				bFlag = true; // da bam
				cDo = _getch();
				if (cDo == 72) // Mui ten len
				{
					if (iYp != iY)
						iYp -= 2;
					else
						iYp = iY;

				}
				else if (cDo == 80) // Mui ten xuong
				{
					iYp += 2;
				}
			}
		}

	}*/
	_getch();
	return iSelect;
}
// chua xong menu