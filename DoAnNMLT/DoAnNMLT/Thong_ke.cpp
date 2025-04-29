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
                    tongSoLuong++;
                    daThongKe[j] = 1; // Đánh dấu thể loại đã được thống kê
                }
            }
            // In ra kết quả cho thể loại này
            printf("| %-23s | %-18d |\n", gioiTinh[i], tongSoLuong);
        }
    }
    printf("+-------------------------+--------------------+\n");
}

// Thống kê số lượng sách đang được mượn trong thư viện

void thongKeSoLuongSachDangMuon(
    int ISBN_SachMuon[][10],
    int indexThongTinMuonTraSach,
    int soLuongSachMuon[],
    int indexSach,
    int ISBN[],
    char tenSach[][MAX_STR])
{
    // Mảng đếm số lượng sách mượn của từng cuốn trong thư viện
    int demSach[1000]; // Khởi tạo mảng đếm với kích thước bằng số lượng sách trong thư viện
    for (int i = 0; i < indexSach; i++) {
        demSach[i] = 0;
    }

    // Duyệt qua từng phiếu mượn sách để tính số lượng mượn cho từng cuốn
    for (int i = 0; i < indexThongTinMuonTraSach; i++) {
        int soSachMuon = soLuongSachMuon[i];
        for (int j = 0; j < soLuongSachMuon[i]; j++) {
            int ISBNtemp = ISBN_SachMuon[i][j];
            // Tìm kiếm mã ISBN tương ứng trong danh sách thư viện
            for (int k = 0; k < indexSach; k++) {
                if (ISBN[k] == ISBNtemp) {
                    demSach[k]++;
                    break;
                }
            }
        }
    }

    // Tính tổng số sách đang được mượn
    int totalBorrowed = 0;

    // In tiêu đề bảng thống kê
    printf("Thong ke sach dang duoc muon:\n");
    printf("-----------------------------------------------------------------\n");
    printf("| %-10s | %-30s | %-15s |\n", "ISBN", "Ten Sach", "So luong muon");
    printf("-----------------------------------------------------------------\n");

    // Duyệt qua danh sách thư viện để in các sách có số lượng mượn > 0
    for (int i = 0; i < indexSach; i++) {
        if (demSach[i] > 0) {
            printf("| %-10d | %-30s | %-15d |\n", ISBN[i], tenSach[i], demSach[i]);
            totalBorrowed += demSach[i];
        }
    }
    printf("-----------------------------------------------------------------\n");
    printf("Tong so sach dang duoc muon: %d\n", totalBorrowed);
}


// Thống kê danh sách độc giả bị trễ hạn
void thongKeDocGiaTreHan(int maDocGiaMuuonSach[], char hoTenMuonSach[][MAX_STR],
                         char ngayTraSachDuKien[][MAX_STR], int indexThongTinMuonTraSach, int soLuongSachMuon[])
{
    char ngayHienTai[MAX_STR];
    printf(">>>>> Nhap ngay hien tai ");
    enterDateTime(ngayHienTai); // nhập ngày hiện tại để so sánh với ngày trả sách thực tế

    int tong = 0;

    printf("\n ----------------------------------------------------------------------------\n");
    printf(" | %-05s | %-23s | %-15s | %-15s | ", "Ma doc gia", "Doc gia tre han", "So sach muon", "so ngay tre han");
    printf("\n ----------------------------------------------------------------------------\n");

    for (int i = 0; i < indexThongTinMuonTraSach; i++)
    {
        if (xetDieuKienNgay(ngayTraSachDuKien[i], ngayHienTai)) // nếu ngày hiện tại lớn hơn ngày trả sách dự kiến của độc giả thì bị trễ hạn
        {
            int result = tinhSoNgayTraTre(ngayTraSachDuKien[i], ngayHienTai); // tính số ngày trễ hạn
            tong ++;
            printf(" | %-05d      | %-23s | %-15d | %-15d |", maDocGiaMuuonSach[i], hoTenMuonSach[i], soLuongSachMuon[i], result);
            printf("\n ----------------------------------------------------------------------------\n");
        }
    }

    printf(" %s  %d \n", "Tong doc gia tre han: ", tong);
    
}
    
