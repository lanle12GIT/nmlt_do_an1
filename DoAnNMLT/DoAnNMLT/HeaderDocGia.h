#define MAX_STR 100                // Độ dài tối đa cho chuỗi ký tự
#define MAX_DOC_GIA 1000           // Số lượng độc giả tối đa
#define _CRT_SECURE_NO_WARNINGS    // Cho phép sử dụng các hàm không an toàn trong C

// Khai báo nguyên mẫu các hàm quản lý độc giả

// Hàm thêm độc giả mới vào danh sách
void themDocGia(
    int maDocGia[], char hoTen[][MAX_STR], char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR], char gioiTinh[][MAX_STR],
    char email[][MAX_STR], char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR], char ngayKetThucThe[][MAX_STR],
    int *indexDocGia);

// Hàm nhập ngày/tháng/năm dưới dạng chuỗi
void enterDateTime(char timeStr[MAX_STR]);

// Hàm hiển thị thông tin độc giả theo chỉ số
void hienThiDocGiaTheoindexDocGia(
    int indexDocGia,
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR]);

// Hàm hiển thị tất cả độc giả
void hienThiTatCaDocGia(
    int indexDocGia,
    int maDocGia[],
    char hoTen[][MAX_STR],
    char cmnd[][MAX_STR],
    char ngayThangNamSinh[][MAX_STR],
    char gioiTinh[][MAX_STR],
    char email[][MAX_STR],
    char diaChi[][MAX_STR],
    char ngayMoThe[][MAX_STR],
    char ngayKetThucThe[][MAX_STR]);

// Hàm chỉnh sửa thông tin độc giả
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
    int indexDocGia);

// Hàm xóa độc giả khỏi danh sách
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
    int *indexDocGia);

// Hàm tìm kiếm độc giả theo CMND
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
    int indexDocGia);

// Hàm tìm kiếm độc giả theo họ tên
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
    int indexDocGia);