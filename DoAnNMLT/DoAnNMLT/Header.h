#define MAX_STR 100
#define MAX_DOC_GIA 1000
#define _CRT_SECURE_NO_WARNINGS

void themDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR], char gioiTinh[][MAX_STR],
    char email[][MAX_STR], char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR], char ngayKetThucThe[][MAX_STR],
    int *index);
// void hienThiDanhSachDocGia(int maDocGia[], char hoTen[], char cmnd[], char email[], int* index);
void enterDateTime(char timeStr[MAX_STR]);
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
    char ngayKetThucThe[][MAX_STR]);
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
    char ngayKetThucThe[][MAX_STR]);
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
    int index);
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
    int *index);
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
    int index);
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
    int index);