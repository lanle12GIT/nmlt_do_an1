#define MAX_STR 100

// void tinhNgayngayTraSachDuKien(const char ngayMuonSach[], char ngayTraSachDuKien[]);
void phieuMuonSach(
    int maDocGiaMuonSach[], int maDocGia[],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int ISBN[], int soLuongSach[],
    int indexDocGia, int indexSach,
    int *indexThongTinMuonTraSach);