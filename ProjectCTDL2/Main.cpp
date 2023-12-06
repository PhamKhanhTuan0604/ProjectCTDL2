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
	int iChose = createMainMenu();
	if (iChose == 1)
	{
		//to do sth
		system("cls");
		cout << 1 << endl;
	}
	else if (iChose == 2)
	{
		//to do sth
		system("cls");
		cout << 2 << endl;
	}
	else if (iChose == 3)
	{
		//to do sth
		system("cls");
		cout << 3 << endl;
	}
	else if (iChose == 4)
	{
		//to do sth
		system("cls");
		cout << 4 << endl;
	}
	else if (iChose == 5)
	{
		//to do sth
		system("cls");
		exit(0);
	}
	return 0;
}
/***********************************************
* @Description Ham tao menu cac chuc nang
* @attention Neu chon exit thi thoat chuong trinh
************************************************/
int createMainMenu()
{
	int iSelect = 1;
	system("cls");
	string strChucNang[5] = {"Hien thi thong tin hang hoa","Tim kiem thong tin hang hoa" ,"Dat hang" , "Quan li" , "Thoat" };
	ShowCur(0);
	gotoxy(75, 3);
	SetColor(51);
	cout << "TAP HOA TU CA" << endl; // In tieu de

	int iX = 63, iY = 7; // lay toa do x = 63, y = 7 trong man hinh console.
	int iXp = iX, iYp = iY; // toa do thay doi mau chu
	int iXcu = iXp, iYcu = iYp;
	bool bCheck = true, bStop = true;
	while (bStop)
	{
		char cIn;
		if (bCheck == true)
		{
			gotoxy(iXcu, iYcu);
			drawMenu(iX, iY, strChucNang);
			changeContentColor(iXp, iYp, strChucNang[iSelect - 1]);
			iXcu = iXp; iYcu = iYp;

			changeContentColor(iXcu, iYcu, strChucNang[iSelect - 1]);
			bCheck = false;
		}

		if (_kbhit())
		{
			//cIn = getchar();
			cIn = _getch();
			if (cIn == -32)
			{
				bCheck = true;
				cIn = _getch();
				if (cIn == 72) // mui ten len
				{
					if (iSelect == 1)
					{
						iSelect = 5;
						iYp = iY + 8;
					}
					else
					{
						iSelect -= 1;
						iYp -= 2;
					}
				}
				else if (cIn == 80) // mui ten xuong
				{
					if (iSelect == 5)
					{
						iSelect = 1;
						iYp = iY;
					}
					else
					{
						iSelect += 1;
						iYp += 2;
					}
				}
				else if (cIn == '\r')
				{
					//return iSelect;
					bStop = false;
					break;
				}
			}
			else
			{
				bStop = false;
			}
		}
		
	}
	return iSelect;
}
