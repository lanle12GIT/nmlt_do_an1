#include <stdio.h>
#include "HeaderSach.h"
#include <string.h>

// Hàm hiển thị tiêu đề bảng sách
void hienThiTieuDeSach()
{
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
    printf("| %-4s| %-5s | %-32s | %-15s | %-15s | %-4s | %-13s | %-10s | %-8s |\n",
           "STT", "ISBN", "Ten sach", "Tac gia", "NXB", "Nam", "The loai", "Gia", "So luong");
    printf("+-----+-------+----------------------------------+-----------------+-----------------+------+---------------+------------+----------+\n");
}

// Hàm hiển thị thông tin sách 
void hienThiTatCaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    hienThiTieuDeSach(); // In tiêu đề bảng
    for (int i = 0; i < indexSach; i++)
    {
          // In thông tin từng cuốn sách
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
// Hàm hiển thị thông tin sách theo index
// Hàm này được gọi khi thêm sách mới hoặc chỉnh sửa thông tin sách
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

// Hàm thêm sách mới vào thư viện
void themSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach)
{
     // Kiểm tra số lượng sách đã đạt tối đa chưa
    if (*indexSach >= MAX_SACH)
    {
        printf("Khong the them sach moi. So luong sach da dat toi da.\n");
        return;
    }
    else
    {   // Nhập mã ISBN và kiểm tra trùng lặp
        while (1)
        {
            printf(">>>>> Nhap ma ISBN: ");
            int temp;
            scanf_s("%d", &temp);
            bool isTonTai = false;
            for (int i = 0; i < *indexSach; i++)
            {
                if (ISBN[i] == temp)
                {
                    printf("Ma ISBN nay da ton tai, vui long nhap lai\n"); // mỗi sách phải có 1 mã ISBN duy nhất
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

        // Nhập các thông tin khác của sách
        printf(">>>>> Nhap ten sach (vi du: Mua he 17): ");
        gets_s(tenSach[*indexSach], MAX_STR);

        printf(">>>>> Nhap tac gia (vi du: Nguyen Nhat Anh): ");
        gets_s(tacGia[*indexSach], MAX_STR);

        printf(">>>>> Nhap nha xuat ban (vi du: NXB Nhi Dong): ");
        gets_s(nhaXuatBan[*indexSach], MAX_STR);

        printf(">>>>> Nhap nam xuat ban (vi du: 2019): ");
        scanf_s("%d", &namXuatBan[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(">>>>> Nhap the loai (vi du:Truyen ngan): ");
        gets_s(theLoai[*indexSach], MAX_STR);

        printf(">>>>> Nhap gia sach: ");
        scanf_s("%f", &giaSach[*indexSach]);
        while (getchar() != '\n')
            ;

        printf(">>>>> Nhap so luong sach (vi du:150000): ");
        scanf_s("%d", &soLuongSach[*indexSach]);
        while (getchar() != '\n')
            ;

            // Thông báo và hiển thị sách vừa thêm
        printf("Them sach thanh cong \n");
        hienThiTieuDeSach();
        hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, *indexSach);
        (*indexSach)++;
    }
}
// Hàm chỉnh sửa thông tin sách
void chinhSuaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    printf(">>>>> Nhap ma ISBN cua sach can chinh sua: ");
    int maISBN;
    scanf_s("%d", &maISBN);
    while (getchar() != '\n')
        ;
    bool isTonTai = false;
    for (int i = 0; i < indexSach; i++)
    {
        if (ISBN[i] == maISBN)
        {
            isTonTai = true;
            printf("Thong tin sach muon chinh sua \n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);

              // Hiển thị menu lựa chọn trường cần chỉnh sửa
            printf("=== Chon thong tin muon thay doi===\n");
            printf("1. Ten sach\n");
            printf("2. Tac gia\n");
            printf("3. Nha xuat ban\n");
            printf("4. Nam xuat ban\n");
            printf("5. The loai\n");
            printf("6. Gia sach\n");
            printf("7. So luong sach\n");

            printf(">>>>> Nhap lua chon cua ban: ");
            int luaChon;
            scanf_s("%d", &luaChon);
            while (getchar() != '\n')
                ;
            switch (luaChon)
            {
            case 1:
                printf(">>>>> Nhap ten sach moi: ");
                gets_s(tenSach[i], MAX_STR);
                break;
            case 2:
                printf(">>>>> Nhap tac gia moi: ");
                gets_s(tacGia[i], MAX_STR);
                break;
            case 3:
                printf(">>>>> Nhap nha xuat ban moi: ");
                gets_s(nhaXuatBan[i], MAX_STR);
                break;
            case 4:
                printf(">>>>> Nhap nam xuat ban moi: ");
                scanf_s("%d", &namXuatBan[i]);
                while (getchar() != '\n')
                    ;
                break;
            case 5:
                printf(">>>>> Nhap the loai moi: ");
                gets_s(theLoai[i], MAX_STR);
                break;
            case 6:
                printf(">>>>> Nhap gia sach moi: ");
                scanf_s("%f", &giaSach[i]);
                while (getchar() != '\n')
                    ;
                break;
            case 7:
                printf(">>>>> Nhap so luong sach moi: ");
                scanf_s("%d", &soLuongSach[i]);
                while (getchar() != '\n')
                    ;
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
            }

            printf("Chinh sua sach thanh cong!\n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);
        }
    }
    if (!isTonTai)
    {
        printf("Khong tim thay sach co ma ISBN %d\n", maISBN);
    }
}
// Hàm xóa sách khỏi danh sách
void xoaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach)
{
    printf(">>>>> Nhap ma sach can xoa: ");
    int maISBN;
    scanf_s("%d", &maISBN);
    while (getchar() != '\n')
        ;
    bool isTonTai = false;
    for (int i = 0; i < *indexSach; i++)
    {
        if (ISBN[i] == maISBN)
        {
            isTonTai = true;
            printf("Thong tin sach muon xoa \n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);

            printf("Ban co chac chan muon xoa sach nay khong? (1: Co, 0: Khong): ");
            int luaChonXoa;
            scanf_s("%d", &luaChonXoa);
            while (getchar() != '\n')
                ;
            if (luaChonXoa == 1)
            {
                // Xóa thông tin sách bằng cách dịch chuyển các phần tử phía sau lên trước
                for (int j = i; j < *indexSach - 1; j++)
                {
                    ISBN[j] = ISBN[j + 1];
                    strcpy_s(tenSach[j], tenSach[j + 1]);
                    strcpy_s(tacGia[j], tacGia[j + 1]);
                    strcpy_s(nhaXuatBan[j], nhaXuatBan[j + 1]);
                    namXuatBan[j] = namXuatBan[j + 1];
                    strcpy_s(theLoai[j], theLoai[j + 1]);
                    giaSach[j] = giaSach[j + 1];
                    soLuongSach[j] = soLuongSach[j + 1];
                }
                (*indexSach)--;
                printf("Xoa sach thanh cong!\n");
                hienThiTieuDeSach();
                hienThiTatCaSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, *indexSach);
            }
            else if (luaChonXoa == 0)
            {
                printf("Khong xoa sach.\n");
                hienThiTatCaSach(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, *indexSach);
                return;
            }
            else if (luaChonXoa != 1)
            {
                printf("Lua chon khong hop le. Khong xoa sach.\n");
                return;
            }
        }
    }
    if (!isTonTai)
    {
        printf("Khong tim thay sach co ma ISBN %d\n", maISBN);
    }
}
// Hàm tìm kiếm sách theo ISBN
void timKiemSachTheoISBN(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    printf(">>>>> Nhap ma ISBN sach muon tim: ");
    int maISBN;
    scanf_s("%d", &maISBN);
    while (getchar() != '\n')
        ;
    bool isTonTai = false;
    for (int i = 0; i < indexSach; i++)
    {
        if (ISBN[i] == maISBN)
        {
            isTonTai = true;
            printf("Thong tin sach muon tim \n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);
        }
        
    }
    if (!isTonTai)
    {
        printf("Khong tim thay sach co ma ISBN %d\n", maISBN);
    }
}
// Hàm tìm kiếm sách theo tên sách
void timKiemSachTheoTenSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach)
{
    char tenSachTimKiem[MAX_STR];
    printf(">>>>> Nhap ten sach muon tim: ");
    gets_s(tenSachTimKiem, MAX_STR);
    bool isTonTai = false;
    for (int i = 0; i < indexSach; i++)
    {
        if (strcmp(tenSach[i], tenSachTimKiem) == 0)
        {
            isTonTai = true;
            printf("Thong tin sach muon tim \n");
            hienThiTieuDeSach();
            hienThiSachTheoIndex(ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan, theLoai, giaSach, soLuongSach, i);
        }
        
    }
    if (!isTonTai)
    {
        printf("Khong tim thay sach co ten %s\n", tenSachTimKiem);
    }
}