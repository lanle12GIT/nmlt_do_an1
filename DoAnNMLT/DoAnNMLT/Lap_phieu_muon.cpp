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
    return (nam - 1) / 4 - (nam - 1) / 100 + (nam - 1) / 400;
}

// Hàm tính số ngày từ 01/01/0001 đến ngày 'ngay', 'thang', 'nam'
int tinhSoNgay(int ngay, int thang, int nam)
{
    // Số ngày trong mỗi tháng (tháng 2 mặc định là 28)
    int soNgayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tính tổng số ngày từ 01/01/0001 đến ngày cho trước
    int soNgay = (nam - 1) * 365 + ngay;

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
bool xetDieuKienNgay(const char ngayBD[], const char ngayKT[])
{
    int ngay1, thang1, nam1;
    int ngay2, thang2, nam2;

    sscanf_s(ngayBD, "%d-%d-%d", &ngay1, &thang1, &nam1); // Tách ngày, tháng, năm từ chuỗi
    sscanf_s(ngayKT, "%d-%d-%d", &ngay2, &thang2, &nam2);

    int soNgayBD = tinhSoNgay(ngay1, thang1, nam1);
    int soNgayKT = tinhSoNgay(ngay2, thang2, nam2);

    if (soNgayBD > soNgayKT)
    {
        return false; // Ngày mượn sách không được lớn hơn ngày kết thúc thẻ
    }
    return true; // Ngày mượn sách hợp lệ
}

void hienThiPhieuMuonTraSach(
    int maDocGiaMuonSach[], char hoTenMuonSach[][MAX_STR],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], char tenSachMuon[][10][MAX_STR],
    char ghiChu[][10][MAX_STR], int soLuongSachMuon[], int indexThongTinMuonTraSach)
{
    printf("\n *********************************************************************************\n");
    printf(" |                                                                               |\n");
    printf(" |                         PHIEU-TRA MUON SACH                                   |\n");
    printf(" |                                                                               |\n");
    printf(" |    Ma doc gia:            %-50d  |\n", maDocGiaMuonSach[indexThongTinMuonTraSach]);
    printf(" |    Ten doc gia:           %-50s  |\n", hoTenMuonSach[indexThongTinMuonTraSach]);
    printf(" |    Ngay muon sach:        %-50s  |\n", ngayMuonSach[indexThongTinMuonTraSach]);
    printf(" |    Ngay tra sach du kien: %-50s  |\n", ngayTraSachDuKien[indexThongTinMuonTraSach]);
    printf(" |    Ngay tra sach thuc te: %-50s  |\n", ngayTraSachThucTe[indexThongTinMuonTraSach]);
    printf(" |    Tien phat neu co:      %-50.2f  |\n", tienPhat[indexThongTinMuonTraSach]);
    printf(" |   --------------------------------------------------------------------------  |\n");
    printf(" |   | %-08s | %-25s |%-30s   |  |\n", "ISBN", "Ten Sach", "Ghi chu"); // ghi tiêu đề cho bảng
    printf(" |   --------------------------------------------------------------------------  |\n");
    // in thông tin sách mượn

    for (int i = 0; i < soLuongSachMuon[indexThongTinMuonTraSach]; i++)
    {
        if (ISBN_SachMuon[indexThongTinMuonTraSach][i] != 0)
        {
            printf(" |   | %-08d | %-25s | %-30s  |  |\n", ISBN_SachMuon[indexThongTinMuonTraSach][i], tenSachMuon[indexThongTinMuonTraSach][i], ghiChu[indexThongTinMuonTraSach][i]); // in tên và mã sách
            printf(" |   --------------------------------------------------------------------------  |\n");
        }
    }

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
    char hoTen[][MAX_STR], char hoTenMuonSach[][MAX_STR],
    char tenSachMuon[][10][MAX_STR], char tenSach[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    int indexDocGia, int indexSach,
    char ghiChu[][10][MAX_STR],
    int *indexThongTinMuonTraSach)
{
    int maDocGiatemp;
    printf(">>>>> Nhap ma doc gia muon sach(vi du: 1001): "); // nhập mã độc giả cần mượn sách
    scanf_s("%d", &maDocGiatemp);

    // kiểm tra mã độc giả có trong danh sách đã mượn sách không
    for (int i = 0; i < *indexThongTinMuonTraSach; i++)
    {
        if (maDocGiatemp == maDocGiaMuonSach[i])
        {
            printf("\n =====> Doc gia ma %d da muon sach, khong the lap phieu muon sach moi\n", maDocGiaMuonSach[i]);
            while (getchar() != '\n')
            ;
            return;
        }
    }

    bool isTonTai = false;
    for (int i = 0; i < indexDocGia; i++)
    {
        if (maDocGia[i] == maDocGiatemp) // độc giả mượn sách phải có trong danh sách độc giả
        {
            isTonTai = true;
            maDocGiaMuonSach[*indexThongTinMuonTraSach] = maDocGiatemp;            // lưu mã độc giả vào danh sách mượn sách
            strcpy_s(hoTenMuonSach[*indexThongTinMuonTraSach], MAX_STR, hoTen[i]); // lưu tên độc giả vào danh sách mượn sách

            while (getchar() != '\n')
                ;

            do
            {
                printf(">>>>> Nhap ngay,thang,nam muon sach "); // nhập ngày mượn sách
                enterDateTime(ngayMuonSach[*indexThongTinMuonTraSach]);

                if (xetDieuKienNgay(ngayMoThe[i], ngayMuonSach[*indexThongTinMuonTraSach]) == false          // ngày mượn sách phải lớn hơn hoặc bằng ngày mở thẻ
                    || xetDieuKienNgay(ngayMuonSach[*indexThongTinMuonTraSach], ngayKetThucThe[i]) == false) // và nhỏ hơn hoặc bằng ngày kết thúc thẻ

                {
                    printf("Thoi gian muon sach khong hop le, vui long kiem tra lai the doc gia cua ban\n");
                }

            } while (xetDieuKienNgay(ngayMoThe[i], ngayMuonSach[*indexThongTinMuonTraSach]) == false || xetDieuKienNgay(ngayMuonSach[*indexThongTinMuonTraSach], ngayKetThucThe[i]) == false);

            // tính ngày trả sách dự kiến
            // ngày trả sách dự kiến = ngày mượn + 7 ngày
            tinhNgayngayTraSachDuKien(ngayMuonSach[*indexThongTinMuonTraSach], ngayTraSachDuKien[*indexThongTinMuonTraSach]);

            // khởi tạo ngày trả sách thực tế và tiền phạt nếu trả trễ
            // ngày trả sách thực tế = 00-00-0000
            // tiền phạt = 0
            strcpy_s(ngayTraSachThucTe[*indexThongTinMuonTraSach], "00-00-0000");
            tienPhat[*indexThongTinMuonTraSach] = 0;

            // nhập số lượng sách mượn
            int soSachMuon;
            do
            {

                printf("\n>>>>> Nhap so sach muon (1-10): ");
                scanf_s("%d", &soSachMuon);
                while (getchar() != '\n')
                    ;
                if (soSachMuon < 1 || soSachMuon > 10) // không được mượn ít hơn 1 hoặc nhiều hơn 10 cuốn sách
                {
                    printf("So sach muon khong hop le, khong the muon it hon 1 hoac lon hon 10 cuon");
                }
            } while (soSachMuon < 1 || soSachMuon > 10);
            soLuongSachMuon[*indexThongTinMuonTraSach] = soSachMuon;

            // nhập mã ISBN của sách
            for (int soSach = 0; soSach < soSachMuon; soSach++)
            {
                int ISBNtemp;
                bool isTonTaiSach = false;
                do
                {
                    printf("\n>>>>> Nhap ma ISBN cua sach %d: ", soSach + 1);
                    scanf_s("%d", &ISBNtemp);
                    while (getchar() != '\n')
                        ;

                    for (int j = 0; j < indexSach; j++)
                    {
                        if (ISBN[j] == ISBNtemp) // kiểm tra mã ISBN có trong thư viện không
                        {
                            isTonTaiSach = true;
                            ISBN_SachMuon[*indexThongTinMuonTraSach][soSach] = ISBNtemp;                   // lưu mã ISBN vào danh sách mượn sách
                            strcpy_s(tenSachMuon[*indexThongTinMuonTraSach][soSach], MAX_STR, tenSach[j]); // lưu tên sách vào danh sách mượn sách
                            soLuongSach[j]--;                                                              // trừ số lượng sách trong thư viện đi 1 cuốn
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
            maDocGiaMuonSach, hoTenMuonSach, ngayMuonSach, ngayTraSachDuKien,
            ngayTraSachThucTe, tienPhat, ISBN_SachMuon, tenSachMuon, ghiChu, soLuongSachMuon,
            *indexThongTinMuonTraSach);

        (*indexThongTinMuonTraSach)++;
    }
}

// hàm xóa độc giả đã trả sách
void xoaDocGiaMuonSach(int maDocGiaMuonSach[], char hoTenMuonSach[][MAX_STR], char tenSachMuon[][10][MAX_STR],
                       char ngayMuonSach[][MAX_STR],
                       char ngayTraSachDuKien[][MAX_STR],
                       char ngayTraSachThucTe[][MAX_STR], float tienPhat[],
                       int ISBN_SachMuon[][10], int soLuongSachMuon[], int *indexThongTinMuonTraSach, int maDocGiaTraSach, bool isTonTai)
{

    if (isTonTai) // đã trả sách rồi thì xóa khỏi danh sách mượn
    {
        for (int i = 0; i < *indexThongTinMuonTraSach; i++)
        {
            if (maDocGiaMuonSach[i] == maDocGiaTraSach) // tìm mã đọc giả muốn trả trong danh sách độc giả mượn sách
            {
                for (int j = i; j < *indexThongTinMuonTraSach - 1; j++) // xóa độc giả đã trả sách bằng cach dịch chuyển các phần tử phía sau lên 1 vị trí
                // và giảm số lượng độc giả đã mượn sách đi 1
                {
                    maDocGiaMuonSach[j] = maDocGiaMuonSach[j + 1];
                    strcpy_s(hoTenMuonSach[j], MAX_STR, hoTenMuonSach[j + 1]);
                    strcpy_s(ngayMuonSach[j], MAX_STR, ngayMuonSach[j + 1]);
                    strcpy_s(ngayTraSachDuKien[j], MAX_STR, ngayTraSachDuKien[j + 1]);
                    strcpy_s(ngayTraSachThucTe[j], MAX_STR, ngayTraSachThucTe[j + 1]);
                    tienPhat[j] = tienPhat[j + 1];
                    soLuongSachMuon[j] = soLuongSachMuon[j + 1];
                    for (int k = 0; k < 10; k++)
                    {
                        ISBN_SachMuon[j][k] = ISBN_SachMuon[j + 1][k];
                        strcpy_s(tenSachMuon[j][k], MAX_STR, tenSachMuon[j + 1][k]);
                    }
                }
                (*indexThongTinMuonTraSach)--;
                break;
            }
        }
    }
}

void phieuTraSach(
    int maDocGiaMuonSach[], char hoTenMuonSach[][MAX_STR],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], char tenSachMuon[][10][MAX_STR],
    int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    float giaSach[], int indexSach, char ghiChu[][10][MAX_STR],
    int *indexThongTinMuonTraSach)
{
    int maDocGiaTraSach;
    bool isTonTai = false;
    int ISBNprintf[1][10] = {0};
    int temp;

    printf(">>>>> Nhap ma doc gia muon tra sach( vi du: 1001): "); // nhập mã độc giả
    scanf_s("%d", &maDocGiaTraSach);
    while (getchar() != '\n')
        ;

    for (int i = 0; i < *indexThongTinMuonTraSach; i++) // tìm mã đọc giả muốn trả trong danh sách độc giả mượn sách
    {
        if (maDocGiaMuonSach[i] == maDocGiaTraSach)
        {
            temp = i; // lưu vị trí độc giả muốn trả sách
            isTonTai = true;
            do
            {
                printf(">>>>> Nhap ngay tra thuc te: "); // nếu có đoc giả thì nhập ngày trả thực tế
                enterDateTime(ngayTraSachThucTe[i]);
                if (xetDieuKienNgay(ngayMuonSach[i], ngayTraSachThucTe[i]) == false) // ngày trả phải sau ngày mượn
                {
                    printf("Thoi gian tra sach khong hop le, vui long kiem tra lai\n");
                }

            } while (xetDieuKienNgay(ngayMuonSach[i], ngayTraSachThucTe[i]) == false);

            int result = tinhSoNgayTraTre(ngayTraSachDuKien[i], ngayTraSachThucTe[i]); // tính ngày trả trễ
            printf("so ngay tra sach tre : %d * 5000", result);
            tienPhat[i] = (float)result * 5000; // trả trễ 5000/ngày

            int soLuongSachTra; // số lượng sách trả
            do
            {
                printf("\n>>>>> Nhap so sach tra( 1-so sach muon): ");
                scanf_s("%d", &soLuongSachTra);
                while (getchar() != '\n')
                    ;
                if (soLuongSachTra < 1 || soLuongSachTra > soLuongSachMuon[i]) // số lượng trả phải từ 1 đến số lượng mượn tại i
                {
                    printf("So sach tra khong hop le, khong the tra it hon 1 hoac lon hon so luong da muon\n");
                }
            } while (soLuongSachTra < 1 || soLuongSachTra > soLuongSachMuon[i]);

            // copy mảng ISBN để in ra
            for (int j = 0; j < soLuongSachMuon[i]; j++)
            {
                ISBNprintf[0][j] = ISBN_SachMuon[i][j];
               
            }

            for (int j = 0; j < soLuongSachTra; j++) // trả theo số lượng sách đã nhâpp
            {
                int ISBNtemp; // mã sách trả thực tế

                printf(">>>>> Nhap ma ISBN cua sach muon tra (vi du: 2222):  ");
                scanf_s("%d", &ISBNtemp);
                while (getchar() != '\n')
                    ;

                bool isTonTaiSach = false;
                for (int k = 0; k < soLuongSachMuon[i]; k++) // kiểm tra mã sách trả có nằm trong danh sách mượn không
                {
                    isTonTaiSach = false;
                    if (ISBN_SachMuon[i][k] == ISBNtemp)
                    {
                        isTonTaiSach = true;
                        ISBN_SachMuon[i][k] = 0;                        // xét bằng 0 là đã trả sách
                        strcpy_s(ghiChu[i][k], MAX_STR, "Da tra sach"); // ghi chú là đã trả sách
                        for (int l = 0; l < indexSach; l++)
                        {
                            if (ISBN[l] == ISBNtemp)
                            {
                                soLuongSach[l]++; // tăng số lượng sách lên 1 trong thư viện
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

            for (int k = 0; k < soLuongSachMuon[i]; k++) // kiểm tra trên danh sách sách đã mượn
            {
                float tienDenSach = 0;
                if (ISBN_SachMuon[i][k] != 0) // vì không trả nên số mã ISBN này khác 0
                {
                    strcpy_s(ghiChu[i][k], MAX_STR, "khong tra sach( den tien)"); // ghi chú là không trả sách
                    for (int l = 0; l < indexSach; l++)
                    {
                        if (ISBN[l] == ISBN_SachMuon[i][k]) // tìm mã sách không trả
                        {
                            printf("====> Ban khong tra sach nay :\n");
                            tienDenSach = giaSach[l] * 2;
                            printf("Ma ISBN: %d, gia = %0.2f , tien den = %0.2f (200%% gia tien)\n", ISBN_SachMuon[i][k], giaSach[l], tienDenSach);
                            tienPhat[i] += tienDenSach;
                            break;
                        }
                    }
                }
            }
            tienPhat[i] > 0 ? printf("So tien bi phat: %0.2f \n", tienPhat[i]) : printf("\n");
        }
    }

    if (isTonTai)
    {
        printf("====> Ma doc gia %d da tra sach thanh cong!!!", maDocGiaTraSach);

        hienThiPhieuMuonTraSach(
            maDocGiaMuonSach, hoTenMuonSach, ngayMuonSach, ngayTraSachDuKien,
            ngayTraSachThucTe, tienPhat, ISBNprintf, tenSachMuon, ghiChu, soLuongSachMuon,
            temp); // in phiếu sách ra
        // xóa độc giả đã trả sách
        xoaDocGiaMuonSach(
            maDocGiaMuonSach, hoTenMuonSach, tenSachMuon, ngayMuonSach,
            ngayTraSachDuKien, ngayTraSachThucTe, tienPhat,
            ISBN_SachMuon, soLuongSachMuon, &(*indexThongTinMuonTraSach),
            maDocGiaTraSach, isTonTai);
    }
    else if (!isTonTai)
    {
        printf("====> Ma doc gia %d nay khong dung,hoac khong muon sach vui long kiem tra lai \n", maDocGiaTraSach);
    }
}