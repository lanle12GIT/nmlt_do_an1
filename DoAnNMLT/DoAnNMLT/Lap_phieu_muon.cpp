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
    int soNgayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
    {
        soNgayTrongThang[1] = 29; // Tháng 2 có 29 ngày
    }

    if (ngay > soNgayTrongThang[thang - 1])
    {
        ngay = ngay - soNgayTrongThang[thang - 1];
        thang++;
    }
    if (thang > 12)
    {
        thang = 1;
        nam++;
    }

    // Định dạng lại ngày trả sách dự kiến
    sprintf_s(ngayTraSachDuKien, MAX_STR, "%02d-%02d-%04d", ngay, thang, nam);
    printf("Ngay tra sach du kien(sau 7 ngay muon): %s\n", ngayTraSachDuKien);
}

void hienThiPhieuMuonTraSach(
    int maDocGiaMuonSach[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int indexThongTinMuonTraSach)
{
    printf("\n*******************************************************\n");
    printf("\n    PHIEU-TRA MUON SACH:\n");
    printf("\n");
    printf(" Ma doc gia muon sach: %d\n", maDocGiaMuonSach[indexThongTinMuonTraSach]);
    printf(" Ngay muon sach: %s\n", ngayMuonSach[indexThongTinMuonTraSach]);
    printf(" Ngay tra sach du kien: %s\n", ngayTraSachDuKien[indexThongTinMuonTraSach]);
    printf(" Ngay tra sach thuc te: %s\n", ngayTraSachThucTe[indexThongTinMuonTraSach]);
    printf(" Tien phat neu co: %.2f\n", tienPhat[indexThongTinMuonTraSach]);
    printf(" Ma ISBN sach muon:\n");
    for (int i = 0; i < 10; i++)
    {
        if (ISBN_SachMuon[indexThongTinMuonTraSach][i] != 0)
        {
            printf(" %d  ", ISBN_SachMuon[indexThongTinMuonTraSach][i]);
        }
    }
    printf("\n");
    printf("\n");
    printf("\n");

    printf("                  vui long mang theo phieu khi tra sach\n");
    printf("\n");
    printf("*******************************************************\n");
}

void phieuMuonSach(
    int maDocGiaMuonSach[], int maDocGia[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int ISBN[], int soLuongSach[],
    int indexDocGia, int indexSach,
    int *indexThongTinMuonTraSach)
{
    int maDocGiatemp;
    printf(">>>Nhap ma doc gia muon muon sach:");
    scanf_s("%d", &maDocGiatemp);
    bool isTonTai = false;
    for (int i = 0; i < indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiatemp)
        {
            isTonTai = true;
            maDocGiaMuonSach[*indexThongTinMuonTraSach] = maDocGiatemp;

            printf(">>>Nhap ngay muon sach (dd-mm-yyyy): ");
            while (getchar() != '\n')
                ;
            enterDateTime(ngayMuonSach[*indexThongTinMuonTraSach]);

            tinhNgayngayTraSachDuKien(ngayMuonSach[*indexThongTinMuonTraSach], ngayTraSachDuKien[*indexThongTinMuonTraSach]);

            strcpy_s(ngayTraSachThucTe[*indexThongTinMuonTraSach], "00-00-0000");
            tienPhat[*indexThongTinMuonTraSach] = 0;
            int soLuongSachMuon;
            do
            {

                printf("\n>>>Nhap so sach muon muon:\n");
                scanf_s("%d", &soLuongSachMuon);
                if (soLuongSachMuon < 1 || soLuongSachMuon > 10)
                {
                    printf("So sach muon khong hop le, khong the muon it hon 1 hoac lon hon 10 cuon");
                }
            } while (soLuongSachMuon < 1 || soLuongSachMuon > 10);

            for (int soSach = 0; soSach < soLuongSachMuon; soSach++)
            {
                int ISBNtemp ;
                bool isTonTaiSach = false;
                do
                {
                    printf("\n>>>Nhap ma ISBN cua sach %d:", soSach + 1);
                    scanf_s("%d", &ISBNtemp);

                    for (int j = 0; j < indexSach; j++)
                    {
                        if (ISBN[j] == ISBNtemp)
                        {
                            isTonTaiSach = true;
                            ISBN_SachMuon[*indexThongTinMuonTraSach][soSach] = ISBNtemp;
                            soLuongSach[*indexThongTinMuonTraSach]--;
                        }
                    }
                    if (!isTonTaiSach)
                    {
                        printf("Ma ISBN %d nay khong dung, vui long kiem tra lai \n", ISBNtemp);
                    }
                } while (!isTonTaiSach);
            }
        }
    }
    if (!isTonTai)
    {
        printf("Khong tim thay doc gia co ma %d\n", maDocGiatemp);
    }
    else
    {
        printf("\nLap phieu muon sach thanh cong!\n");

        hienThiPhieuMuonTraSach(
            maDocGiaMuonSach, ngayMuonSach, ngayTraSachDuKien,
            ngayTraSachThucTe, tienPhat, ISBN_SachMuon,
            *indexThongTinMuonTraSach);

        (*indexThongTinMuonTraSach)++;
    }
}

