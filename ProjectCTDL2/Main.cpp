﻿#include "Queue.h"
#include "Queue.cpp"
#include "Graphics.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include "HangHoa.h"
#include <fstream>
using namespace std;

void Menu();
int createMainMenu();
void readHangHoa(Queue<HangHoa> hangHoa, string fn);

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
	readHangHoa(hangHoa, "HangHoa.txt");
	int iChose = createMainMenu();
	if (iChose == 1)
	{
		//to do sth
		system("cls");
		readHangHoa(hangHoa, "HangHoa.txt");
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
* @Decription Doc du lieu tu file
*******************************************/
void readHangHoa(Queue<HangHoa> hangHoa, string fn)
{
	ifstream infile;
	infile.open("fn", ios::in);
	if (infile.is_open())
		cout << "Khong the mo duoc file";
	else
	{
		HangHoa h;
		int iNumber;
		infile >> iNumber;
		string strMaHang;
		string strTenHang;
		string strNoiSanXuat;
		string strMauSac;
		int iGiaBan;
		string strNgayNhapKho;
		int iSoLuong;
		for (int i = 0; i < iNumber; i++)
		{
			infile >> strMaHang;
			infile.ignore();
			getline(infile, strTenHang);
			getline(infile, strNoiSanXuat);
			getline(infile, strMauSac);
			infile >> iGiaBan;
			infile.ignore();
			getline(infile, strNgayNhapKho);
			infile >> iSoLuong;
			h = HangHoa(strMaHang, strTenHang, strNoiSanXuat, strMauSac, iGiaBan, strNgayNhapKho, iSoLuong);
			hangHoa.enQueue(h);
		}
		infile.close();
	}
	hangHoa.display();
}