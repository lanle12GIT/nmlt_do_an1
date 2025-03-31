#define MAX_STR 100
#define MAX_SACH 1000
#define _CRT_SECURE_NO_WARNINGS

void hienThiTatCaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach);
void themSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach);