#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"
#include "HeaderSach.h"
#include "HeaderMuonTraSach.h"
#include "HeaderThongKe.h"

// Thống kê tổng số lượng sách trong thư viện
void thongKeSoLuongSachTrongThuVien(int ISBN[], int soLuongSach[], int indexSach)
{
    int tongSachTrongThuVien = 0;
    printf("\n+-----------------+--------------------+\n");
    printf("| %-16s| %-18s |\n", "ISBN", "So luong");
    printf("+-----------------+--------------------+\n");
    for (int i = 0; i < indexSach; i++)
    {
        tongSachTrongThuVien += soLuongSach[i];

        printf("| %-16d| %-18d |\n", ISBN[i], soLuongSach[i]);
    }
    printf("+-----------------+--------------------+\n");
    printf("| %-16s| %-18d |\n",
           "Tong sach", tongSachTrongThuVien);
    printf("+-----------------+--------------------+\n");
}

//  Thống kê số lượng sách theo các thể loại trong thư viện
void thongKeSoLuongSachTheoTheLoai(char theLoai[][MAX_STR], int soLuongSach[], int indexSach)
{

    int daThongKe[1000] = {0}; // Mảng đánh dấu các thể loại đã được thống kê
    printf("\n+-------------------------+--------------------+\n");
    printf("| %-23s | %-18s |\n", "The loai", "So luong");
    printf("+-------------------------+--------------------+\n");
    for (int i = 0; i < indexSach; i++)
    {
        if (daThongKe[i] == 0) // chưa được đếm
        {
            int tongSoLuong = 0;

            // tính tổng cho thể loại này
            for (int j = 0; j < indexSach; j++)
            {
                if (_stricmp(theLoai[i], theLoai[j]) == 0)
                {
                    tongSoLuong += soLuongSach[j];
                    daThongKe[j] = 1; // Đánh dấu thể loại đã được thống kê
                }
            }
            // In ra kết quả cho thể loại này
            printf("| %-23s | %-18d |\n", theLoai[i], tongSoLuong);
        }
    }
    printf("+-------------------------+--------------------+\n");
}

// Thống kê tổng số lượng độc giả trong thư viện
void thongKeSoLuongDocGia(int indexDocGia)
{
    printf(" Tong so luong doc gia trong thu vien %d", indexDocGia);
}

// Thống kê số lượng độc giả theo giới tính
void thongKeSoLuongDocGiaTheoGioiTinh(char gioiTinh[][MAX_STR], int indexDocGia)
{
    int daThongKe[1000] = {0}; // Mảng đánh dấu các thể loại đã được thống kê
    printf("\n+-------------------------+--------------------+\n");
    printf("| %-23s | %-18s |\n", "Gioi tinh", "So luong");
    printf("+-------------------------+--------------------+\n");
    for (int i = 0; i < indexDocGia; i++)
    {
        if (daThongKe[i] == 0) // chưa được đếm
        {
            int tongSoLuong = 0;

            // tính tổng cho thể loại này
            for (int j = 0; j < indexDocGia; j++)
            {
                if (_stricmp(gioiTinh[i], gioiTinh[j]) == 0)
                {
                    tongSoLuong ++;
                    daThongKe[j] = 1; // Đánh dấu thể loại đã được thống kê
                }
            }
            // In ra kết quả cho thể loại này
            printf("| %-23s | %-18d |\n", gioiTinh[i], tongSoLuong);
        }
    }
    printf("+-------------------------+--------------------+\n");
}

// Thống kê số lượng sách đang được mượn
void thongKeSoLuongSachMuon(){
    
}

