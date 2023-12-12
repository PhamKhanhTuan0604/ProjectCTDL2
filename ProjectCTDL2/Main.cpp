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
void readHangHoa(Queue<HangHoa>& hangHoa, string& strFn);
int continueOrStop(int iY);
void doCase2(Queue<HangHoa> &hangHoa);
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
	int iChoice = createMainMenu();
	switch (iChoice)
	{
		case 1:
		{
			system("cls");
			gotoxy(75, 3);
			SetColor(51);
			cout << "TAP HOA TU CA" << endl; // In ten shop
			//readHangHoa(hangHoa, strFile);

			int iX = 5, iY = 5;
			printLetterHead(iX, iY, 150, 2, 11); // in muc cac thong tin
			HangHoa temp;
			int iQueueNumber = hangHoa.getSize(), iCount = 0;

			//In thong tin hang hoa
			while ( iCount < iQueueNumber)
			{
				iY += 3;
				temp = hangHoa.deQueue();
				temp.printHangHoa(iX, iY);
				hangHoa.enQueue(temp);
				iCount++;
			}
			//Lua chon tiep tuc hay thoat ra
			gotoxy(50, iY + 5);
			SetColor(10);
			cout << "Moi ban nhap 1 de quay ve menu, 0 de ket thuc chuong trinh: ";
			SetColor(7);
			int iSelect;
			cin >> iSelect;
			if (iSelect == 1)
				Menu();
			else if (iSelect == 0)
				exit(0);

			break;
		}
		case 2:
		{
			//readHangHoa(hangHoa, strFile);
			system("cls");
			doCase2(hangHoa);
		}
		case 3:
		{
			//To do sth
			break;
		}
		case 4:
		{
			//To do sth
			system("cls");
			hangHoa.display();
			break;
		}
		case 5:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Chuong trinh co loi, se thoat";
			break;
		}
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
void readHangHoa(Queue<HangHoa>& hangHoa, string& strFn)
{
	ifstream infile;//
	infile.open(strFn, ios::in);
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
				exit(0);
			}
			hangHoa.enQueue(h);
		}
	}
	else
	{
		cout << "Khong the mo file " << endl;
	}
}
/************************************************
* Decription Lua chon tiep tuc hay dung lai
* parameter toa do y
* return 1 neu tiep tuc, 0 neu dung lai
*************************************************/
int continueOrStop(int iY)
{
	gotoxy(50, iY + 5);
	SetColor(10);
	cout << "Moi ban nhap 1 de quay ve menu, 0 de ket thuc chuong trinh: ";
	SetColor(7);
	int iSelect;
	cin >> iSelect;
	if (iSelect == 1)
		return 1;
	else if (iSelect == 0)
		return 0;
}
/***********************************************
* Decription Thuc hien chuc nang tim kiem
* parameter 1 Queue chua thong tin hang hoa
************************************************/
void doCase2(Queue<HangHoa>& hangHoa)
{
	gotoxy(75, 3);
	SetColor(51);
	cout << "TAP HOA TU CA" << endl; // In ten shop

	/*Tim thong tin hang hoa*/
	//Khai bao cac bien su dung
	Queue<HangHoa> Result;
	string strFind;
	HangHoa temp;
	bool bCheck = false;
	int iX2 = 5, iY2 = 12;
	int iQueueSize = hangHoa.getSize(), iCount = 0;

	//Nhap ten hang hoa can tim
	gotoxy(50, 6);
	SetColor(10);
	cout << "Moi ban nhap ten hang hoa can tim:";
	gotoxy(50, 7);
	cout << "Ten hang hoa: ";
	SetColor(7);
	getline(cin, strFind);
	//cin.ignore();

	//Tim kiem
	for (int i = 0; i < iQueueSize; i++)
	{
		temp = hangHoa.deQueue();
		if (temp.getTenHang() == strFind)
		{
			Result.enQueue(temp);
		}
		hangHoa.enQueue(temp);
	}
	//In ket qua tim kiem
	if (Result.isEmpty())
	{
		SetColor(1);
		gotoxy(50, iY2);
		cout << "Xin loi, chung toi chua co hang hoa ban can.";
	}
	else
	{
		printLetterHead(iX2, iY2, 150, 2, 11);
		iY2 += 3;
		while (!Result.isEmpty())
		{
			temp = Result.deQueue();
			temp.printHangHoa(iX2, iY2);
			iY2 += 3;
		}
	}


	// Quay lai hoac thoat chuong trinh
	int iDo = continueOrStop(iY2);
	if (iDo == 1)
		Menu();
	else if (iDo == 0)
		exit(0);
}