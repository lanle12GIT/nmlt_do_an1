#include <stdio.h>
#include "HeaderSach.h"

void hienThiTieuDeSach()
{
    printf("+-----+-------+----------------------+-----------------+-------------------+------+--------------------+------------+\n");
    printf("| %-4s | %-5s | %-20s | %-15s | %-15s | %-4s | %-18s | %-10s | %-10s |\n",
           "STT", "ISBN", "Ten sach", "Tac gia", "NXB", "Nam", "The loai", "Gia", "So luong");
    printf("+-----+-------+----------------------+-----------------+-------------------+------+--------------------+------------+\n");
}

void hienThiTatCaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    hienThiTieuDeSach();
    for (int i = 0; i < indexSach; i++)
    {
        printf("| %-4d | %-5d | %-20s | %-15s | %-15s | %-4d | %-18s | %-10.2f | %-10d |\n",
               i + 1,
               ISBN[i],
               tenSach[i],
               tacGia[i],
               nhaXuatBan[i],
               namXuatBan[i],
               theLoai[i],
               giaSach[i],
               soLuongSach[i]);
        }
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+------------+\n");
}
