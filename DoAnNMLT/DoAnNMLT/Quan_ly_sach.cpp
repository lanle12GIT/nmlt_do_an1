#include <stdio.h>
#include "HeaderSach.h"

void hienThiTieuDeSach()
{
    printf("+-----+-------+----------------------+-----------------+-------------------+------+--------------------+------------+-----------+\n");
    printf("| %-4s| %-5s | %-20s | %-15s | %-15s | %-4s | %-18s | %-10s | %-10s |\n",
           "STT", "ISBN", "Ten sach", "Tac gia", "NXB", "Nam", "The loai", "Gia", "So luong");
    printf("+-----+-------+----------------------+-----------------+-------------------+------+--------------------+------------+-----------+\n");
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
        printf("| %-4d| %-5d | %-20s | %-15s | %-15s | %-4d | %-18s | %-10.2f | %-10d |\n",
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
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+---------------+-----+\n");
}

void hienThiSachTheoIndex(int ISBN[], char tenSach[][MAX_STR],
                          char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
                          int namXuatBan[], char theLoai[][MAX_STR],
                          float giaSach[], int soLuongSach[],
                          int indexSach)
{
    printf("| %-4d| %-5d | %-20s | %-15s | %-15s | %-4d | %-15s | %-8.2f | %-4d |\n",
           indexSach + 1,
           ISBN[indexSach],
           tenSach[indexSach],
           tacGia[indexSach],
           nhaXuatBan[indexSach],
           namXuatBan[indexSach],
           theLoai[indexSach],
           giaSach[indexSach],
           soLuongSach[indexSach]);
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+---------------+\n");
}

void themSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach)
{
    if (*indexSach >= MAX_SACH)
    {
        printf("Khong the them sach moi. So luong sach da dat toi da.\n");
        return;
    }
    else
    {
        while (1)
        {
            printf("nhap ma ISBN ");
            int temp;
            scanf_s("%d", &temp);
            bool isTonTai = false;
            for (int i = 0; i < *indexSach; i++)
            {
                if (ISBN[i] == temp)
                {
                    printf("ma ISBN nay da ton tai, vui long nhap lai\n");
                    isTonTai = true;
                }
            }
            if (!isTonTai)
            {
                ISBN[*indexSach] = temp;
                break;
            }
        }
        while (getchar() != '\n')
            ;

        printf("Nhap ten sach: ");
        gets_s(tenSach[*indexSach], MAX_STR);

        printf(" Nhap tac gia: ");
        gets_s(tacGia[*indexSach], MAX_STR);

        printf(" Nhap nha xuat ban: ");
        gets_s(nhaXuatBan[*indexSach], MAX_STR);

        printf(" Nhap nam xuat ban: ");
        scanf_s("%d", &namXuatBan[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(" Nhap the loai: ");
        gets_s(theLoai[*indexSach], MAX_STR);

        printf(" Nhap gia sach: ");
        scanf_s("%f", &giaSach[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(" Nhap so luong sach: ");
        scanf_s("%d", &soLuongSach[*indexSach]);
        while (getchar() != '\n')
            ;

        
        printf("them sach thanh cong \n");
        hienThiTieuDeSach();
        hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, *indexSach);
        (*indexSach)++;

    }
}

