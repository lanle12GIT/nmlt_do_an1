﻿#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"

// Hàm tính ngày kết thúc thẻ (cộng thêm 4 năm)
void tinhNgayKetThucThe(const char ngayMoThe[], char ngayKetThucThe[])
{

    int ngay, thang, nam;

    sscanf_s(ngayMoThe, "%d-%d-%d", &ngay, &thang, &nam); // Tách ngày, tháng, năm từ chuỗi
    nam += 4;                                             // Cộng thêm 4 năm

    // Định dạng lại ngày kết thúc thẻ
    sprintf_s(ngayKetThucThe, MAX_STR, "%02d-%02d-%04d", ngay, thang, nam);
}

// Hàm thêm thông tin độc giả mới
void themDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR], char gioiTinh[][MAX_STR],
    char email[][MAX_STR], char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR], char ngayKetThucThe[][MAX_STR],
    int *indexDocGia)
{
     // Kiểm tra số lượng độc giả đã đạt tối đa chưa
    if (*indexDocGia >= MAX_DOC_GIA)
    {
        printf("Khong the them doc gia moi. So luong doc gia da dat toi da.\n");
        return;
    }
     // Gán mã độc giả tự động
    if (*indexDocGia == 0)
    {
        maDocGia[*indexDocGia] = 1001; // Gán mã độc giả đầu tiên là 1001
    }
    else
    {
        maDocGia[*indexDocGia] = maDocGia[*indexDocGia - 1] + 1; // Tăng mã độc giả lên 1 so với độc giả trước đó
    }

     // Nhập thông tin độc giả
    printf("Nhap ho ten (vi du: Le Thi Lan): ");
    gets_s(hoTen[*indexDocGia], MAX_STR);

    printf("Nhap CMND (vi du: 109145286): ");
    gets_s(cmnd[*indexDocGia], MAX_STR);

    printf("Nhap ngay thang nam sinh: ");
    enterDateTime(ngayThangNamSinh[*indexDocGia]);

    printf("Nhap gioi tinh (vi du: Nu): ");
    gets_s(gioiTinh[*indexDocGia], MAX_STR);

    printf("Nhap email (vi du: lanle12@gmail.com): ");
    gets_s(email[*indexDocGia], MAX_STR);

    printf("Nhap dia chi (vi du: Quang Tri): ");
    gets_s(diaChi[*indexDocGia], MAX_STR);

    printf("Nhap ngay mo the (dd/mm/yyyy): ");
    enterDateTime(ngayMoThe[*indexDocGia]);

    // Tính ngày kết thúc thẻ
    tinhNgayKetThucThe(ngayMoThe[*indexDocGia], ngayKetThucThe[*indexDocGia]);
    printf("Ngay ket thuc the (tu dong tinh): %s\n", ngayKetThucThe[*indexDocGia]);

    // In thông tin độc giả vừa thêm
    printf("Doc gia da duoc them thanh cong!\n");
    hienThiDocGiaTheoindexDocGia(*indexDocGia, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
    (*indexDocGia)++; // Cap nhat indexDocGia
}

// Hàm in tiêu đề bảng
void hienThiTieuDe()
{
    printf("+-----+-------+-----------------+------------+------------+------+----------------------+--------------------+------------+------------+\n");
    printf("| %-4s| %-5s | %-15s | %-10s | %-10s | %-4s | %-20s | %-18s | %-10s | %-10s |\n",
           "STT ", "MaDG ", "Ho ten", "CMND", "Ngay sinh", "GT", "Email", "Dia chi", "Ngay mo", "Ngay het");
    printf("+-----+-------+-----------------+------------+------------+------+----------------------+--------------------+------------+------------+\n");
}
// Hàm hiển thị thông tin độc giả theo indexDocGia
void hienThiDocGiaTheoindexDocGia(
    int indexDocGia,
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR])
{
    // In tiêu đề bảng
    hienThiTieuDe();

    // In thông tin độc giả tại vị trí indexDocGia (indexDocGia + 1 hiển thị thứ tự)
    printf("| %-4d| %-5d | %-15s | %-10s | %-10s | %-4s | %-20s | %-18s | %-10s | %-10s |\n",
           indexDocGia + 1,
           maDocGia[indexDocGia],
           hoTen[indexDocGia],
           cmnd[indexDocGia],
           ngayThangNamSinh[indexDocGia],
           gioiTinh[indexDocGia],
           email[indexDocGia],
           diaChi[indexDocGia],
           ngayMoThe[indexDocGia],
           ngayKetThucThe[indexDocGia]);
    printf("+-----+-------+-----------------+------------+------------+------+----------------------+--------------------+------------+------------+\n");
}

// Hàm hiển thị thông tin tất cả các độc giả
void hienThiTatCaDocGia(
    int indexDocGia,
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR])
{
    // In tiêu đề bảng
    hienThiTieuDe();

    // Duyệt và in thông tin từng độc giả
    for (int i = 0; i < indexDocGia; i++)
    {
        printf("| %-4d| %-5d | %-15s | %-10s | %-10s | %-4s | %-20s | %-18s | %-10s | %-10s |\n",
               i + 1,
               maDocGia[i],
               hoTen[i],
               cmnd[i],
               ngayThangNamSinh[i],
               gioiTinh[i],
               email[i],
               diaChi[i],
               ngayMoThe[i],
               ngayKetThucThe[i]);
    }
    printf("+-----+-------+-----------------+------------+------------+------+----------------------+--------------------+------------+------------+\n");
}

//hàm chỉnh sửa thông tin độc giả
void chinhSuaDocGia(
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    int indexDocGia)

{
    int maDocGiaChinhSua;
    printf(">>>>> Nhap ma doc gia muon chinh sua: ");
    scanf_s("%d", &maDocGiaChinhSua);
    while (getchar() != '\n')
        ;

    bool isTonTai = false;
    for (int i = 0; i < indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiaChinhSua)
        {
            isTonTai = true;
            printf("=== Thong tin doc gia muon chinh sua ===\n");
            hienThiDocGiaTheoindexDocGia(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);

            printf("=== Chon thong tin muon thay doi===\n"); // mỗi lần chỉ có thể thay đổi 1 thông tin
            printf("1. Ten doc gia\n");
            printf("2. CMND\n");
            printf("3. Ngay thang nam sinh\n");
            printf("4. Gioi tinh\n");
            printf("5. Email\n");
            printf("6. Dia chi\n");
            printf("7. Ngay mo the\n");
            printf(">>>>> Nhap lua chon cua ban: ");

            int choise;
            scanf_s("%d", &choise);
            bool isBreak = false;
            while (getchar() != '\n')
                ;

            switch (choise)
            {
            case 1:

                printf("Nhap ho ten doc gia: ");
                gets_s(hoTen[i], MAX_STR);
                break;

            case 2:
                printf("Nhap CMND: ");
                gets_s(cmnd[i], MAX_STR);
                break;

            case 3:
                printf("Nhap ngay thang nam sinh: ");
                enterDateTime(ngayThangNamSinh[i]);
                break;

            case 4:
                printf("Nhap gioi tinh:");
                gets_s(gioiTinh[i], MAX_STR);
                break;

            case 5:
                printf("Nhap email: ");
                gets_s(email[i], MAX_STR);
                break;

            case 6:
                printf("Nhap dia chi: ");
                gets_s(diaChi[i], MAX_STR);
                break;

            case 7:
            {
                printf("Nhap ngay mo the (dd/mm/yyyy): ");
                enterDateTime(ngayMoThe[i]);

                // Tính ngày kết thúc thẻ
                tinhNgayKetThucThe(ngayMoThe[i], ngayKetThucThe[i]);
                printf("Ngay ket thuc the (tu dong tinh): %s\n", ngayKetThucThe[i]);
                break;
            }

            default:
                printf("Lua chon cua ban khong hop le");
                break;
            }

            printf("Doc gia da duoc chinh sua thanh cong!\n");
            hienThiDocGiaTheoindexDocGia(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
        }
    }
    if (!isTonTai)
    {
        printf("Khong tim thay doc gia co ma %d\n", maDocGiaChinhSua);
    }
}

// xóa độc giả ra khỏi danh sách
void xoaDocGia(
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    int *indexDocGia)
{
    int maDocGiaXoa;
    printf(">>>>> Nhap ma doc gia muon xoa: ");
    scanf_s("%d", &maDocGiaXoa);
    while (getchar() != '\n')
        ;
    bool isTonTai = false;
    for (int i = 0; i < *indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiaXoa) // xóa theo mã độc giả vì đó là mã duy nhất
        {
            isTonTai = true;
            printf("=== Thong tin doc gia muon xoa ===\n");
            hienThiDocGiaTheoindexDocGia(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            printf("=== Ban co chac chan muon xoa doc gia nay khong? (1: Co, 0: Khong) ===\n");
            int luaChonXoa;
            printf(">>>>> Nhap lua chon: ");
            scanf_s("%d", &luaChonXoa);
            if (luaChonXoa == 0)
            {
                printf("Khong xoa doc gia.\n");
                return;
            }
            else if (luaChonXoa != 1)
            {
                printf("Lua chon khong hop le. Khong xoa doc gia.\n");
                return;
            }
            // Xóa thông tin độc giả bằng cách dịch chuyển các phần tử phía sau lên trước
            for (int j = i; j < *indexDocGia - 1; j++)
            {
                maDocGia[j] = maDocGia[j + 1];
                strcpy_s(hoTen[j], MAX_STR, hoTen[j + 1]);
                strcpy_s(cmnd[j], MAX_STR, cmnd[j + 1]);
                strcpy_s(ngayThangNamSinh[j], MAX_STR, ngayThangNamSinh[j + 1]);
                strcpy_s(gioiTinh[j], MAX_STR, gioiTinh[j + 1]);
                strcpy_s(email[j], MAX_STR, email[j + 1]);
                strcpy_s(diaChi[j], MAX_STR, diaChi[j + 1]);
                strcpy_s(ngayMoThe[j], MAX_STR, ngayMoThe[j + 1]);
                strcpy_s(ngayKetThucThe[j], MAX_STR, ngayKetThucThe[j + 1]);
            }
            (*indexDocGia)--; // Giảm số lượng độc giả đi 1
            printf("Xoa doc gia thanh cong!\n");
            hienThiTatCaDocGia(*indexDocGia, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            break;
        }
    }

    if (!isTonTai)
    {
        printf("Khong tim thay doc gia co ma %d\n", maDocGiaXoa);
    }
}

// hàm tìm kiếm độc giả theo CMND
void timKiemDocGiaTheoCMND(
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    int indexDocGia)
{
    char cmndTimKiem[MAX_STR];
    printf(">>>>> Nhap CMND doc gia muon tim: ");
    gets_s(cmndTimKiem, MAX_STR);

    for (int i = 0; i < indexDocGia; i++)
    {
        if (strcmp(cmnd[i], cmndTimKiem) == 0)
        {
            hienThiDocGiaTheoindexDocGia(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            return;
        }
        else if (i == indexDocGia - 1)
        {
            printf("Khong tim thay doc gia co CMND %s\n", cmndTimKiem);
        }
    }
}
// hàm tìm kiếm độc giả theo họ tên
void timKiemDocGiaTheoHoTen(
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    int indexDocGia)
{
    char hoTenTimKiem[MAX_STR];
    printf(">>>>> Nhap ho ten doc gia muon tim: ");
    gets_s(hoTenTimKiem, MAX_STR);

    for (int i = 0; i < indexDocGia; i++)
    {
        if (strcmp(hoTen[i], hoTenTimKiem) == 0)
        {
            hienThiDocGiaTheoindexDocGia(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            return;
        }
        else if (i == indexDocGia - 1)
        {
            printf("Khong tim thay doc gia co ho ten: %s\n", hoTenTimKiem);
        }
    }
}
