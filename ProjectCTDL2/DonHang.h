#pragma once
#include <string>
#include <iostream>
#include "Queue.h"
//#include "Queue.cpp"
#include "Graphics.h"
using namespace std;

class DonHang
{
	int _iSTT;
	Queue<string> _MaHang;
	Queue<int> _SoLuong;
	int _iTongTien;
	string _strTenKH;
	string _strDiaChi;
	int _iSoDT;
	string _strNgayDatHang;
	int _iSoMaHang;
public:
	Queue<string> getMaHang() const
	{
		return _MaHang;
	}
	void setMaHang(Queue<string>& maHang)
	{
		_MaHang = maHang;
	}
	Queue<int> getSoLuong() const
	{
		return _SoLuong;
	}
	void setSoLuong(Queue<int>& soLuong)
	{
		_SoLuong = soLuong;
	}
	DonHang() 
	{
		_iSTT = 0;
		_MaHang;
		_SoLuong;
		_iTongTien = 0;
		_strTenKH = "Unknow";
		_strDiaChi = "Unknow";
		_iSoDT = 0;
		_strNgayDatHang = "Unknow";
		_iSoMaHang = 0;
	}
	DonHang(int iSTT, Queue<string> MaHang, Queue<int> SoLuong, int iTongTien, string strTenKH, string strDiaChi, int iSoDT, string strNgayDatHang, int iSoMaHang)
	{
		_iSTT = iSTT;
		_MaHang = MaHang;
		_SoLuong = SoLuong;
		_iTongTien = iTongTien;
		_strTenKH = strTenKH;
		_strDiaChi = strDiaChi;
		_iSoDT = iSoDT;
		_strNgayDatHang = strNgayDatHang;
		_iSoMaHang = iSoMaHang;
	}
	DonHang(const DonHang& d)
	{
		_iSTT = d._iSTT;
		_MaHang = d._MaHang;
		_SoLuong = d._SoLuong;
		_iTongTien = d._iTongTien;
		_strTenKH = d._strTenKH;
		_strDiaChi = d._strDiaChi;
		_iSoDT = d._iSoDT;
		_strNgayDatHang = d._strNgayDatHang;
		_iSoMaHang = d._iSoMaHang;
	}
	~DonHang() {}
	friend istream& operator >> (istream& is, DonHang& d)
	{
		string strMaHang; 
		int iSoLuong;
		is >> d._iSTT;
		is >> d._iSoMaHang;
		for (int i = 0; i < d._iSoMaHang; i++)
		{
			is >> strMaHang;
			is >> iSoLuong;
			d._MaHang.enQueue(strMaHang);
			d._SoLuong.enQueue(iSoLuong);
		}
		is >> d._iTongTien;
		is.ignore();
		getline(is, d._strTenKH);
		getline(is, d._strDiaChi);
		is >> d._iSoDT;
		is.ignore();
		getline(is, d._strNgayDatHang);
		return is;
	}
	friend ostream& operator << (ostream& os, DonHang d)
	{
		os << d._iSTT << endl;
		//In ra ma hang va so luong thay phien nhau den khi 2 queue khong con
		while (!d._MaHang.isEmpty())
		{
			os << d._MaHang.deQueue() << endl;
			os << d._SoLuong.deQueue() << endl;
		}
		os << d._iTongTien << endl;
		os << d._strTenKH << endl;
		os << d._strDiaChi << endl;
		os << d._iSoDT << endl;
		os << d._strNgayDatHang;
		return os;
	}
	/*void printDonHang(int x, int y)
	{
		int iYn = y;
		SetColor(15);
		gotoxy(x + 1, iYn);
		cout << _iSTT;
		gotoxy(x + 12, iYn);
		cout << _strMaHang;
		gotoxy(x + 45, iYn);
		cout << _iSoLuong;
		gotoxy(x + 60, iYn);
		cout << _strMauSac;
		gotoxy(x + 80, iYn);
		cout << _iGiaBan;
		gotoxy(x + 100, iYn);
		cout << _strNgayNhapKho;
		gotoxy(x + 135, iYn);
		cout << _iSoLuong;
		// dien ngan cach
		SetColor(11);
		gotoxy(x, y);
		cout << "|";
		gotoxy(x + 11, iYn);
		cout << "|";
		gotoxy(x + 44, iYn);
		cout << "|";
		gotoxy(x + 59, iYn);
		cout << "|";
		gotoxy(x + 79, iYn);
		cout << "|";
		gotoxy(x + 99, iYn);
		cout << "|";
		gotoxy(x + 134, iYn);
		cout << "|";
		gotoxy(x + 150, iYn);
		cout << "|";
		gotoxy(x, iYn + 1);
		for (int i = x; i <= x + 150; i++)
			cout << char(196);
	}*/
};