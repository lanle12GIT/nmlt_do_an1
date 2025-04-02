#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"
#include "HeaderSach.h"
#include "HeaderMuonTraSach.h"
#include "HeaderThongKe.h"

//Thống kê số lượng sách trong thư viện
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

void thongKeSoLuongSachTheoTheLoai(char theLoai[][MAX_STR],int soLuongSach[], int indexSach ){
    
    for (int i = 0; i < indexSach; i++)
    {
        
    }
    
}
