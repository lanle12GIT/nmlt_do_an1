#define MAX_STR 100

// void tinhNgayngayTraSachDuKien(const char ngayMuonSach[], char ngayTraSachDuKien[]);
void phieuMuonSach(
    int maDocGiaMuonSach[], int maDocGia[],
    char hoTen[][MAX_STR], char hoTenMuonSach[][MAX_STR],
    char tenSachMuon[][10][MAX_STR], char tenSach[][MAX_STR], char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    int indexDocGia, int indexSach,char ghiChu[][10][MAX_STR],
    int *indexThongTinMuonTraSach);

void phieuTraSach(
    int maDocGiaMuonSach[], char hoTenMuonSach[][MAX_STR],
    char ngayMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR],
    char ngayTraSachThucTe[][MAX_STR],
    float tienPhat[],
    int ISBN_SachMuon[][10], char tenSachMuon[][10][MAX_STR],
    int soLuongSachMuon[],
    int ISBN[], int soLuongSach[],
    float giaSach[], int indexSach,char ghiChu[][10][MAX_STR],
    int *indexThongTinMuonTraSach);