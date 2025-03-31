#include <stdio.h>
#include <string.h>
#include "Header.h"

// Hàm tính ngày kết thúc thẻ (cộng thêm 4 năm)
void tinhNgayKetThucThe(const char ngayMoThe[], char ngayKetThucThe[])
{

    int ngay, thang, nam;

    sscanf_s(ngayMoThe, "%d-%d-%d", &ngay, &thang, &nam); // Tách ngày, tháng, năm từ chuỗi
    nam += 4;                                             // Cộng thêm 4 năm

    // Định dạng lại ngày kết thúc thẻ
    sprintf_s(ngayKetThucThe, MAX_STR, "%02d-%02d-%04d", ngay, thang, nam);
}

// Ham them doc gia
void themDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR], char gioiTinh[][MAX_STR],
    char email[][MAX_STR], char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR], char ngayKetThucThe[][MAX_STR],
    int *index)
{
    if (*index >= MAX_DOC_GIA)
    {
        printf("Khong the them doc gia moi. So luong doc gia da dat toi da.\n");
        return;
    }
    if (*index == 0){
        maDocGia[*index] = 1001; // Gán mã độc giả đầu tiên là 1001
    }
    else
    {
        maDocGia[*index] = maDocGia[*index - 1] + 1; // Tăng mã độc giả lên 1 so với độc giả trước đó
    }

    printf("Nhap ho ten: ");
    gets_s(hoTen[*index], MAX_STR);

    printf("Nhap CMND: ");
    gets_s(cmnd[*index], MAX_STR);

    printf("Nhap ngay thang nam sinh: ");
    enterDateTime(ngayThangNamSinh[*index]);

    printf("Nhap gioi tinh: ");
    gets_s(gioiTinh[*index], MAX_STR);

    printf("Nhap email: ");
    gets_s(email[*index], MAX_STR);

    printf("Nhap dia chi: ");
    gets_s(diaChi[*index], MAX_STR);

    printf("Nhap ngay mo the (dd/mm/yyyy): ");
    enterDateTime(ngayMoThe[*index]);

    // Tính ngày kết thúc thẻ
    tinhNgayKetThucThe(ngayMoThe[*index], ngayKetThucThe[*index]);
    printf("Ngay ket thuc the (tu dong tinh): %s\n", ngayKetThucThe[*index]);

    printf("Doc gia da duoc them thanh cong!\n");
    hienThiDocGiaTheoIndex(*index, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
    (*index)++; // Cap nhat index
}


// Hàm in tiêu đề bảng
void hienThiTieuDe()
{
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+------------+------------+\n");
    printf("| %-4s| %-5s | %-15s | %-10s | %-10s | %-4s | %-18s | %-18s | %-10s | %-10s |\n",
           "STT ", "MaDG ", "Ho ten", "CMND", "Ngay sinh", "GT", "Email", "Dia chi", "Ngay mo", "Ngay het");
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+------------+------------+\n");
}
// Hàm hiển thị thông tin độc giả theo index
void hienThiDocGiaTheoIndex(
    int index,
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

    // In thông tin độc giả tại vị trí index (index + 1 hiển thị thứ tự)
    printf("| %-4d| %-5d | %-15s | %-10s | %-10s | %-4s | %-18s | %-18s | %-10s | %-10s |\n",
           index + 1,
           maDocGia[index],
           hoTen[index],
           cmnd[index],
           ngayThangNamSinh[index],
           gioiTinh[index],
           email[index],
           diaChi[index],
           ngayMoThe[index],
           ngayKetThucThe[index]);
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+------------+------------+\n");
}

// Hàm hiển thị thông tin tất cả các độc giả
void hienThiTatCaDocGia(
    int index,
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
    for (int i = 0; i < index; i++)
    {
        printf("| %-4d| %-5d | %-15s | %-10s | %-10s | %-4s | %-18s | %-18s | %-10s | %-10s |\n",
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
    printf("+-----+-------+-----------------+------------+------------+------+--------------------+--------------------+------------+------------+\n");
}

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
    int index)

{
    int maDocGiaChinhSua;
    printf(">>>>> Nhap ma doc gia muon chinh sua: ");
    scanf_s("%d", &maDocGiaChinhSua);

    for (int i = 0; i < index; i++)
    {
        if (maDocGia[i] == maDocGiaChinhSua)
        {
            hienThiDocGiaTheoIndex(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);

            printf("=== Chon thong tin muon thay doi===\n");
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

                printf("Nhap ho ten doc gia : ");
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
                printf("Nhap gioi tinh: ");
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
            hienThiDocGiaTheoIndex(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
        }
    }
}
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
    int *index)
{
    int maDocGiaXoa;
    printf(">>>>> Nhap ma doc gia muon xoa: ");
    scanf_s("%d", &maDocGiaXoa);

    for (int i = 0; i < *index; i++)
    {
        if (maDocGia[i] == maDocGiaXoa)
        {   printf("=== Thong tin doc gia muon xoa ===\n");
            hienThiDocGiaTheoIndex(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
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
            for (int j = i; j < *index - 1; j++)
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
            (*index)--; // Giảm số lượng độc giả đi 1
            printf("Xoa doc gia thanh cong!\n");
            break;
        }
        else if (i == *index - 1)
        {
            printf("Khong tim thay doc gia co ma %d\n", maDocGiaXoa);
        }
    }
    hienThiTatCaDocGia(*index, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
}
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
    int index)
{
    char cmndTimKiem[MAX_STR];
    printf(">>>>>Nhap CMND doc gia muon tim: ");
    gets_s(cmndTimKiem, MAX_STR);

    for (int i = 0; i < index; i++)
    {
        if (strcmp(cmnd[i], cmndTimKiem) == 0)
        {
            hienThiDocGiaTheoIndex(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            return;
        }
        else if (i == index - 1)
        {
            printf("Khong tim thay doc gia co CMND %s\n", cmndTimKiem);
        }
    }
}
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
    int index)
{
    char hoTenTimKiem[MAX_STR];
    printf(">>>>>Nhap ho ten doc gia muon tim: ");
    gets_s(hoTenTimKiem, MAX_STR);

    for (int i = 0; i < index; i++)
    {
        if (strcmp(hoTen[i], hoTenTimKiem) == 0)
        {
            hienThiDocGiaTheoIndex(i, maDocGia, hoTen, cmnd, ngayThangNamSinh, gioiTinh, email, diaChi, ngayMoThe, ngayKetThucThe);
            return;
        }
        else if (i == index - 1)
        {
            printf("Khong tim thay doc gia co ho ten: %s\n", hoTenTimKiem);
        }
    }
}
