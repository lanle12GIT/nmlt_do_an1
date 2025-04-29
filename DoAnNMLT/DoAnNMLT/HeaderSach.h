#define MAX_STR 100                // Độ dài tối đa cho chuỗi ký tự
#define MAX_SACH 1000              // Số lượng sách tối đa trong thư viện
#define _CRT_SECURE_NO_WARNINGS    // Cho phép sử dụng các hàm không an toàn trong C

// Khai báo nguyên mẫu các hàm quản lý sách

// Hàm hiển thị tất cả sách trong thư viện
void hienThiTatCaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach);

// Hàm thêm sách mới vào thư viện
void themSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach);

// Hàm chỉnh sửa thông tin sách
void chinhSuaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach);

// Hàm xóa sách khỏi thư viện
void xoaSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int *indexSach);

// Hàm tìm kiếm sách theo mã ISBN
void timKiemSachTheoISBN(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach);

// Hàm tìm kiếm sách theo tên sách
void timKiemSachTheoTenSach(
    int ISBN[], char tenSach[][MAX_STR],
    char tacGia[][MAX_STR], char nhaXuatBan[][MAX_STR],
    int namXuatBan[], char theLoai[][MAX_STR],
    float giaSach[], int soLuongSach[],
    int indexSach);