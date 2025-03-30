#include <stdio.h>
#include <string.h>
#include "Header.h"
#define MAX_STR 100
#define MAX_DOC_GIA 1000

// Ham them doc gia
void themDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR], char gioiTinh[][MAX_STR],
    char email[][MAX_STR], char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR], char ngayKetThucThe[][MAX_STR],
    int *index)
{
    if (*index >= MAX_DOC_GIA) {
        printf("Khong the them doc gia moi. So luong doc gia da dat toi da.\n");
        return;
    }

    printf("Nhap ma doc gia: ");
    scanf_s("%d", &maDocGia[*index]);
    fflush(stdin);

    printf("Nhap ho ten: ");
    gets_s(hoTen[*index], MAX_STR);

    printf("Nhap CMND: ");
    gets_s(cmnd[*index], MAX_STR);

    printf("Nhap ngay thang nam sinh (dd/mm/yyyy): ");
    gets_s(ngayThangNamSinh[*index], MAX_STR);

    printf("Nhap gioi tinh: ");
    gets_s(gioiTinh[*index], MAX_STR);

    printf("Nhap email: ");
    gets_s(email[*index], MAX_STR);

    printf("Nhap dia chi: ");
    gets_s(diaChi[*index], MAX_STR);

    printf("Nhap ngay mo the (dd/mm/yyyy): ");
    gets_s(ngayMoThe[*index], MAX_STR);

    printf("Nhap ngay ket thuc the (dd/mm/yyyy): ");
    gets_s(ngayKetThucThe[*index], MAX_STR);

    printf("Doc gia da duoc them thanh cong!\n");
    (*index)++; // Cap nhat index
}

// Ham hien thi danh sach doc gia
void hienThiDanhSachDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR], 
    char email[][MAX_STR], int index)
{
    printf("Danh sach doc gia:\n");
    for (int i = 0; i < index; i++) {
        printf("Ma doc gia: %d, Ho ten: %s, CMND: %s, Email: %s\n", 
               maDocGia[i], hoTen[i], cmnd[i], email[i]);
    }
}

// Ham hien thi danh sach doc gia
void hienThiDanhSachDocGia(int maDocGia[], char hoTen[], char cmnd[], char email[], int index)
{
    printf("Danh sach doc gia:\n");
    for (int i = 0; i <= index; i++)
    {
        printf("Ma doc gia: %d, Ho ten: %c, CMND: %c, Email: %c\n", maDocGia[i], hoTen[i], cmnd[i], email[i]);
    }
}