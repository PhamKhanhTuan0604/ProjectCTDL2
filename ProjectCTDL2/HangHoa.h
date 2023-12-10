#pragma once
#include <iostream>
#include <string>
#include "Graphics.h"
using namespace std;

class HangHoa
{
    string _strMaHang;
    string _strTenHang;
    string _strNoiSanXuat;
    string _strMauSac;
    int _iGiaBan;
    string _strNgayNhapKho;
    int _iSoLuong;
public:
    string getMaHang()
    {
        return _strMaHang;
    }
    int getGiaBan()
    {
        return _iGiaBan;
    }
    int getSoLuong()
    {
        return _iSoLuong;
    }
    void setSoLuong(int iSoLuong)
    {
        _iSoLuong = iSoLuong;
    }
    string getTenHang()
    {
        return _strTenHang;
    }
    string getNoiSanXuat()
    {
        return _strNoiSanXuat;
    }
    string getMauSac()
    {
        return _strMauSac;
    }
    string getNgayNhapKho()
    {
        return _strNgayNhapKho;
    }
    HangHoa(string strMaHang = "MMMM", string strTenHang = "Unknow", string strNoiSanXuat = "Unknow", string strMauSac = "Unknow", int iGiaBan = 0, string strNgayNhapKho = "Unknow", int iSoLuong = 0)
    {
        _strMaHang = strMaHang;
        _strTenHang = strTenHang;
        _strNoiSanXuat = strNoiSanXuat;
        _strMauSac = strMauSac;
        _iGiaBan = iGiaBan;
        _strNgayNhapKho = strNgayNhapKho;
        _iSoLuong = iSoLuong;
    }
    HangHoa(const HangHoa& h)
    {
        _strMaHang = h._strMaHang;
        _strTenHang = h._strTenHang;
        _strNoiSanXuat = h._strNoiSanXuat;
        _strMauSac = h._strMauSac;
        _iGiaBan = h._iGiaBan;
        _strNgayNhapKho = h._strNgayNhapKho;
        _iSoLuong = h._iSoLuong;
    }
    ~HangHoa() {}
    friend istream& operator >> (istream& is, HangHoa& h)
    {
        is >> h._strMaHang;
        is.ignore();
        getline(is, h._strTenHang);
        getline(is, h._strNoiSanXuat);
        getline(is, h._strMauSac);
        is >> h._iGiaBan;
        is.ignore();
        getline(is, h._strNgayNhapKho);
        is >> h._iSoLuong;
        return is;
    }
    friend ostream& operator << (ostream& os, HangHoa h)
    {
        os << h._strMaHang << endl;
        os << h._strTenHang << endl;
        os << h._strNoiSanXuat << endl;
        os << h._strMauSac << endl;
        os << h._iGiaBan << endl;
        os << h._strNgayNhapKho << endl;
        os << h._iSoLuong << endl;
        return os;
    }
    void printHangHoa(int x, int y)
    {
        int yn = y;
        SetColor(15);
        gotoxy(x + 1, yn);
        cout << _strMaHang;
        gotoxy(x + 12, yn);
        cout << _strTenHang;
        gotoxy(x + 45, yn);
        cout << _strNoiSanXuat;
        gotoxy(x + 60, yn);
        cout << _strMauSac;
        gotoxy(x + 80, yn);
        cout << _iGiaBan;
        gotoxy(x + 100, yn);
        cout << _strNgayNhapKho;
        gotoxy(x + 135, yn);
        cout << _iSoLuong;
        // dien ngan cach
        SetColor(11);
        gotoxy(x, y);
        cout << "|";
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
        gotoxy(x + 150, yn);
        cout << "|";
        gotoxy(x, yn + 1);
        for (int i = x; i <= x + 150; i++)
            cout << char(196);
    }
};