#include <stdio.h>
#include "HeaderSach.h"

void hienThiTieuDeSach()
{
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
    printf("| %-4s| %-5s | %-32s | %-15s | %-15s | %-4s | %-13s | %-10s | %-8s |\n",
           "STT", "ISBN", "Ten sach", "Tac gia", "NXB", "Nam", "The loai", "Gia", "So luong");
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
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
        printf("| %-4d| %-5d | %-32s | %-15s | %-15s | %-4d | %-13s | %-10.2f | %-8d |\n",
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
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
}

void hienThiSachTheoIndex(int ISBN[], char tenSach[][MAX_STR],
                          char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
                          int namXuatBan[], char theLoai[][MAX_STR],
                          float giaSach[], int soLuongSach[],
                          int indexSach)
{
    printf("| %-4d| %-5d | %-32s | %-15s | %-15s | %-4d | %-13s | %-10.2f | %-8d |\n",
           indexSach + 1,
           ISBN[indexSach],
           tenSach[indexSach],
           tacGia[indexSach],
           nhaXuatBan[indexSach],
           namXuatBan[indexSach],
           theLoai[indexSach],
           giaSach[indexSach],
           soLuongSach[indexSach]);
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
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
            printf(">>>nhap ma ISBN: ");
            int temp;
            scanf_s("%d", &temp);
            bool isTonTai = false;
            for (int i = 0; i < *indexSach; i++)
            {
                if (ISBN[i] == temp)
                {
                    printf("Ma ISBN nay da ton tai, vui long nhap lai\n");
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

        printf(">>>Nhap ten sach: ");
        gets_s(tenSach[*indexSach], MAX_STR);

        printf(">>>Nhap tac gia: ");
        gets_s(tacGia[*indexSach], MAX_STR);

        printf(">>>Nhap nha xuat ban: ");
        gets_s(nhaXuatBan[*indexSach], MAX_STR);

        printf(">>>Nhap nam xuat ban: ");
        scanf_s("%d", &namXuatBan[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(">>>Nhap the loai: ");
        gets_s(theLoai[*indexSach], MAX_STR);

        printf(">>>Nhap gia sach: ");
        scanf_s("%f", &giaSach[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(">>>Nhap so luong sach: ");
        scanf_s("%d", &soLuongSach[*indexSach]);
        while (getchar() != '\n')
            ;

        printf("Them sach thanh cong \n");
        hienThiTieuDeSach();
        hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, *indexSach);
        (*indexSach)++;
    }
}
void chinhSuaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    printf("Nhap ma ISBN cua sach can chinh sua: ");
    int maISBN;
    scanf_s("%d", &maISBN);
    while (getchar() != '\n')
        ;

    bool isFound = false;
    for (int i = 0; i < indexSach; i++)
    {
        if (ISBN[i] == maISBN)
        {
            isFound = true;

            printf("Nhap ten sach moi: ");
            gets_s(tenSach[i], MAX_STR);

            printf("Nhap tac gia moi: ");
            gets_s(tacGia[i], MAX_STR);

            printf("Nhap nha xuat ban moi: ");
            gets_s(nhaXuatBan[i], MAX_STR);

            printf("Nhap nam xuat ban moi: ");
            scanf_s("%d", &namXuatBan[i]);
            while (getchar() != '\n')
                ;

            printf("Nhap the loai moi: ");
            gets_s(theLoai[i], MAX_STR);

            printf("Nhap gia sach moi: ");
            scanf_s("%f", &giaSach[i]);
            while (getchar() != '\n')
                ;

            printf("Nhap so luong sach moi: ");
            scanf_s("%d", &soLuongSach[i]);
            while (getchar() != '\n')
                ;

            printf("Chinh sua sach thanh cong!\n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);
        }
    }
    if (!isFound)
    {
        printf("Khong tim thay sach co ma ISBN %d\n", maISBN);
    }
}
