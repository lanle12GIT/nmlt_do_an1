#define MAX_STR 100
#define MAX_SACH 1000
#define MAX_DOC_GIA 1000
#define _CRT_SECURE_NO_WARNINGS

void thongKeSoLuongSachTrongThuVien(int ISBN[], int soLuongSach[], int indexSach);
void thongKeSoLuongSachTheoTheLoai(char theLoai[][MAX_STR], int soLuongSach[], int indexSach);
void thongKeSoLuongDocGia(int indexDocGia);
void thongKeSoLuongDocGiaTheoGioiTinh(char gioiTinh[][MAX_STR], int indexDocGia);
void thongKeSoLuongSachDangMuon( int ISBN_SachMuon[][10],int indexThongTinMuonTraSach,
    int soLuongSachMuon[],int indexSach,int ISBN[],char tenSach[][MAX_STR]);
void thongKeDocGiaTreHan(int maDocGiaMuuonSach[], char hoTenMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR], int indexThongTinMuonTraSach, int soLuongSachMuon[]);