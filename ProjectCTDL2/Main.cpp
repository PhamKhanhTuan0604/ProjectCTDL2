#include "Queue.h"
#include "Queue.cpp"
#include "Graphics.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include "HangHoa.h"
#include <fstream>
#include <cstdlib>
using namespace std;

void Menu();
int createMainMenu();
void readHangHoa(Queue<HangHoa>& hangHoa, string& fn);
int main()
{
	Menu();
	return 0;
}
/********************************************
* @Decription Menu de chay chuong trinh
*********************************************/
void Menu()
{
	Queue<HangHoa> hangHoa;
	string strFile = "HangHoa.txt";
	readHangHoa(hangHoa, strFile);
	int iChose = createMainMenu();
	if (iChose == 1)
	{
		system("cls");
		gotoxy(75, 3);
		SetColor(51);
		cout << "TAP HOA TU CA" << endl; // In ten shop

		int iX = 5, iY = 5;
		printLetterHead(5, 5, 150, 2, 11); // in muc cac thong tin
		HangHoa temp;
		//In thong tin hang hoa
		while (!hangHoa.isEmpty())
		{
			iY += 3;
			temp = hangHoa.deQueue();
			temp.printHangHoa(iX, iY);
		}
		//Lua chon tiep tuc hay thoat ra
		gotoxy(50, iY + 5);
		SetColor(10);
		cout << "Moi ban nhap 1 de quay ve menu, 0 de ket thuc chuong trinh.";
		gotoxy(50, iY + 6);
		cout << "Lua chon cua ban: ";
		SetColor(7);
		int iSelect;
		cin >> iSelect;
		if (iSelect == 1)
			Menu();
		else if (iSelect == 0)
			exit(0);
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
		system("cls");
		exit(0);
	}
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
/******************************************
* @Decription Doc du lieu tu file vao queue (Hang Hoa)
*******************************************/
void readHangHoa(Queue<HangHoa>& hangHoa, string& fn)
{
	ifstream infile(fn);
	if (infile.is_open())
	{
		HangHoa h;
		while (infile >> h)
		{
			string iCheck = h.getMaHang();
			if (iCheck.length() != 4) // kiem tra ma hang co 4 ki tu hay khong
			{
				cout << "Ma hang lon hon 4 ki tu"; 
				break;
			}
			hangHoa.enQueue(h);
		}
	}
	else
	{
		cout << "Khong the mo file " << endl;
	}
}