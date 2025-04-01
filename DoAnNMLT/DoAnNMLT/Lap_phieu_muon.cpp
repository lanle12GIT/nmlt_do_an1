#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"
#include "HeaderSach.h"
#include "HeaderMuonTraSach.h"

void tinhNgayngayTraSachDuKien(const char ngayMuonSach[], char ngayTraSachDuKien[])
{
    int ngay, thang, nam;
    sscanf_s(ngayMuonSach, "%d-%d-%d", &ngay, &thang, &nam); // Tách ngày, tháng, năm từ chuỗi

    // ngày cộng 7 ngày
    ngay += 7;

    // Kiểm tra số ngày trong tháng và điều chỉnh ngày, tháng, năm
    int soNgayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Kiểm tra năm nhuận
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
        soNgayTrongThang[1] = 29; // Tháng 2 có 29 ngày
    }

    if (ngay> soNgayTrongThang[thang-1])
    {
        ngay= ngay-soNgayTrongThang[thang-1];
        thang++;

    }
    if (thang>12)
    {
        thang=1;
        nam++;
    }

     // Định dạng lại ngày trả sách dự kiến
     sprintf_s(ngayTraSachDuKien, MAX_STR, "%02d-%02d-%04d", ngay, thang, nam);
     printf("Ngay tra sach du kien: %s\n", ngayTraSachDuKien);
}

void phieuMuonSach(
    int maDocGiaMuonSach[], int maDocGia[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    int ISBN_SachMuon[][10], int ISBN[],
    int indexDocGia, int indexSach,
    int *indexThongTinMuonTraSach)
{
    int maDocGiatemp;
    printf("Nhap ma doc gia muon muon sach");
    scanf_s("%d", &maDocGiatemp);

    for (int i = 0; i < indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiatemp)
        {
            maDocGiaMuonSach[*indexThongTinMuonTraSach] = maDocGiatemp;

            enterDateTime(ngayMuonSach[*indexThongTinMuonTraSach]);
        }
    }
}