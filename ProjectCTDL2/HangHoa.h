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
    int getGia()
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
};