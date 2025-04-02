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

int tinhSoNamNhuan(int nam)
{
    return nam / 4 - nam / 100 + nam / 400;
}

// Hàm tính số ngày từ 01/01/0001 đến ngày 'ngay', 'thang', 'nam'
int tinhSoNgay(int ngay, int thang, int nam)
{
    // Số ngày trong mỗi tháng (tháng 2 mặc định là 28)
    int soNgayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tính tổng số ngày từ 01/01/0001 đến ngày cho trước
    int soNgay = nam * 365 + ngay;

    // Thêm số ngày cho các tháng trước tháng hiện tại
    for (int i = 0; i < thang - 1; i++)
    {
        soNgay += soNgayTrongThang[i];
    }

    // Thêm số ngày cho năm nhuận
    soNgay += tinhSoNamNhuan(nam); // Tính số năm nhuận và cộng vào tổng số ngày

    // Kiểm tra năm nhuận và điều chỉnh số ngày cho tháng 2 nếu cần
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
    {
        if (thang > 2)
        {
            soNgay += 1; // Thêm 1 ngày cho tháng 2 trong năm nhuận
        }
    }

    return soNgay;
}

int tinhSoNgayTraTre(const char ngayTraSachDuKien[], const char ngayTraSachThucTe[])
{
    int ngayDK, thangDK, namDK;
    int ngayTT, thangTT, namTT;

    sscanf_s(ngayTraSachDuKien, "%d-%d-%d", &ngayDK, &thangDK, &namDK); // Tách ngày, tháng, năm từ chuỗi
    sscanf_s(ngayTraSachThucTe, "%d-%d-%d", &ngayTT, &thangTT, &namTT);

    int soNgayDK = tinhSoNgay(ngayDK, thangDK, namDK);
    int soNgayTT = tinhSoNgay(ngayTT, thangTT, namTT);

    int ngayTre = soNgayTT - soNgayDK;
    if (ngayTre < 0)
    {
        ngayTre = 0;
    }
    return ngayTre;
}

void hienThiPhieuMuonTraSach(
    int maDocGiaMuonSach[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int soLuongSachMuon[], int indexThongTinMuonTraSach)
{
    printf("\n *********************************************************************************\n");
    printf(" |                                                                               |\n");
    printf(" |                         PHIEU-TRA MUON SACH                                   |\n");
    printf(" |                                                                               |\n");
    printf(" |    Ma doc gia muon sach: %-50d   |\n", maDocGiaMuonSach[indexThongTinMuonTraSach]);
    printf(" |    Ngay muon sach:       %-50s   |\n", ngayMuonSach[indexThongTinMuonTraSach]);
    printf(" |    Ngay tra sach du kien:%-50s   |\n", ngayTraSachDuKien[indexThongTinMuonTraSach]);
    printf(" |    Ngay tra sach thuc te:%-50s   |\n", ngayTraSachThucTe[indexThongTinMuonTraSach]);
    printf(" |    Tien phat neu co:     %-50.2f   |\n", tienPhat[indexThongTinMuonTraSach]);
    printf(" |    Ma ISBN sach muon:                                                         |\n");
    printf(" |");

    for (int i = 0; i < soLuongSachMuon[indexThongTinMuonTraSach]; i++)
    {
        if (ISBN_SachMuon[indexThongTinMuonTraSach][i] != 0)
        {
            if (i == 5)
            {
                printf("    |");
                printf("\n |");
            }

            printf("     %-10d", ISBN_SachMuon[indexThongTinMuonTraSach][i]);
        }
    }
    if (soLuongSachMuon[indexThongTinMuonTraSach] % 5 == 0)
        printf("    |\n");
    if (soLuongSachMuon[indexThongTinMuonTraSach] % 5 == 1)
        printf("                                                                |\n");
    if (soLuongSachMuon[indexThongTinMuonTraSach] % 5 == 2)
        printf("                                                 |\n");
    if (soLuongSachMuon[indexThongTinMuonTraSach] % 5 == 3)
        printf("                                  |\n");
    if (soLuongSachMuon[indexThongTinMuonTraSach] % 5 == 4)
        printf("                   |\n");

    printf(" |                                                                               |\n");
    printf(" |                                                                               |\n");
    printf(" |                                                                               |\n");
    printf(" |                        *Vui long mang theo phieu khi tra sach                 |\n");
    printf(" |                        *Tra sach tre hon ngay du kien se bi phat 5000/ngay    |\n");
    printf(" |                        *Lam mat sach se den 200%% gia sach                     |\n");
    printf(" |                                                                               |\n");
    printf(" *********************************************************************************\n");
}

void phieuMuonSach(
    int maDocGiaMuonSach[], int maDocGia[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    int indexDocGia, int indexSach,
    int *indexThongTinMuonTraSach)
{
    int maDocGiatemp;
    printf(">>>>> Nhap ma doc gia muon muon sach: ");
    scanf_s("%d", &maDocGiatemp);

    bool isTonTai = false;
    for (int i = 0; i < indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiatemp)
        {
            isTonTai = true;
            maDocGiaMuonSach[*indexThongTinMuonTraSach] = maDocGiatemp;

            printf(">>>>> Nhap ngay muon sach (dd-mm-yyyy): ");
            while (getchar() != '\n')
                ;
            enterDateTime(ngayMuonSach[*indexThongTinMuonTraSach]);

            tinhNgayngayTraSachDuKien(ngayMuonSach[*indexThongTinMuonTraSach], ngayTraSachDuKien[*indexThongTinMuonTraSach]);

            strcpy_s(ngayTraSachThucTe[*indexThongTinMuonTraSach], "00-00-0000");
            tienPhat[*indexThongTinMuonTraSach] = 0;
            int soSachMuon;
            do
            {

                printf("\n>>>>> Nhaphap so sach muon muon:\n");
                scanf_s("%d", &soSachMuon);
                while (getchar() != '\n')
                    ;
                if (soSachMuon < 1 || soSachMuon > 10)
                {
                    printf("So sach muon khong hop le, khong the muon it hon 1 hoac lon hon 10 cuon");
                }
            } while (soSachMuon < 1 || soSachMuon > 10);
            soLuongSachMuon[*indexThongTinMuonTraSach] = soSachMuon;

            for (int soSach = 0; soSach < soSachMuon; soSach++)
            {
                int ISBNtemp;
                bool isTonTaiSach = false;
                do
                {
                    printf("\n>>>>> Nhaphap ma ISBN cua sach %d: ", soSach + 1);
                    scanf_s("%d", &ISBNtemp);
                    while (getchar() != '\n')
                        ;

                    for (int j = 0; j < indexSach; j++)
                    {
                        if (ISBN[j] == ISBNtemp)
                        {
                            isTonTaiSach = true;
                            ISBN_SachMuon[*indexThongTinMuonTraSach][soSach] = ISBNtemp;
                            soLuongSach[j]--;
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
        while (getchar() != '\n')
            ;
        printf("Khong tim thay doc gia co ma %d\n", maDocGiatemp);
    }
    else
    {
        printf("\nLap phieu muon sach thanh cong!\n");

        hienThiPhieuMuonTraSach(
            maDocGiaMuonSach, ngayMuonSach, ngayTraSachDuKien,
            ngayTraSachThucTe, tienPhat, ISBN_SachMuon, soLuongSachMuon,
            *indexThongTinMuonTraSach);

        (*indexThongTinMuonTraSach)++;
    }
}

void phieuTraSach(
    int maDocGiaMuonSach[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10],
    int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    float giaSach[], int indexSach,
    int *indexThongTinMuonTraSach)
{
    int maDocGiaTraSach;
    bool isTonTai = false;
    do
    {
        printf(">>>>> Nhap ma doc gia muon tra sach: ");
        scanf_s("%d", &maDocGiaTraSach);
        while (getchar() != '\n')
            ;

        for (int i = 0; i < *indexThongTinMuonTraSach; i++)
        {
            if (maDocGiaMuonSach[i] == maDocGiaTraSach)
            {
                isTonTai = true;
                printf(">>>>> Nhap ngay tra thuc te: ");
                enterDateTime(ngayTraSachThucTe[i]);
                int result = tinhSoNgayTraTre(ngayTraSachDuKien[i], ngayTraSachThucTe[i]);
                printf(" so ngay tra sach tre : %d * 5000", result);
                tienPhat[i] = (float)result * 5000;

                int soLuongSachTra;
                do
                {
                    printf("\n>>>>> Nhaphap so sach tra:\n");
                    scanf_s("%d", &soLuongSachTra);
                    while (getchar() != '\n')
                        ;
                    if (soLuongSachTra < 1 || soLuongSachTra > soLuongSachMuon[i])
                    {
                        printf("So sach tra khong hop le, khong the tra it hon 1 hoac lon hon so luong da muon\n");
                    }
                } while (soLuongSachTra < 1 || soLuongSachTra > soLuongSachMuon[i]);

                for (int j = 0; j < soLuongSachTra; j++) // muon 5 cuon sach
                {
                    int ISBNtemp;

                    printf(">>>>> Nhap ma ISBN cua sach muon tra: ");
                    scanf_s("%d", &ISBNtemp);
                    while (getchar() != '\n')
                        ;

                    bool isTonTaiSach = false;
                    for (int k = 0; k < soLuongSachMuon[i]; k++)
                    {
                        isTonTaiSach = false;
                        if (ISBN_SachMuon[i][k] == ISBNtemp)
                        {
                            isTonTaiSach = true;
                            ISBN_SachMuon[i][k] = 0;
                            for (int l = 0; l < indexSach; l++)
                            {
                                if (ISBN[l] == ISBNtemp)
                                {
                                    soLuongSach[l]++;
                                    break;
                                }
                            }
                            printf("---------------------------------\n");
                            printf("Sach voi ma ISBN: %d da duoc tra thanh cong.\n", ISBNtemp);
                            break;
                        }
                    }
                    if (!isTonTaiSach)
                    {
                        printf("Ma ISBN %d khong dung hoac khong co trong danh sach sach da muon. Vui long kiem tra lai.\n", ISBNtemp);
                        j--; // Yêu cầu nhập lại mã ISBN cho sách này
                    }
                }

                // Kiểm tra nếu vẫn còn sách chưa trả

                for (int k = 0; k < soLuongSachMuon[i]; k++)
                {
                    float tienDenSach = 0;
                    if (ISBN_SachMuon[i][k] != 0)
                    {

                        for (int l = 0; l < indexSach; l++)
                        {
                            if (ISBN[l] == ISBN_SachMuon[i][k])
                            {
                                printf("\t ====> Ban khong tra/ lam mat sach nay se bi phat 200% gia tien\n");
                                tienDenSach = giaSach[l] * 2;
                                printf("\t Ma ISBN cua sach bi mat: %d, gia sach = %0.2f , tien den sach = %0.2f \n", ISBN_SachMuon[i][k], giaSach[l], tienDenSach);
                                tienPhat[i] += tienDenSach;
                                break;
                            }
                        }
                    }
                }
            }
            tienPhat[i] > 0 ? printf("So tien bi phat: %0.2f \n", tienPhat[i]) : printf("\n");
        }

        printf("====> Ma doc gia %d da tra sach thanh cong!!!", maDocGiaTraSach);
        if (!isTonTai)
            printf("====> Ma doc gia %d nay khong dung, vui long kiem tra lai \n", maDocGiaTraSach);
    } while (!isTonTai);
}