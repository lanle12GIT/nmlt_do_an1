#define MAX_STR 100              // Độ dài tối đa cho chuỗi ký tự
#define MAX_SACH 1000            // Số lượng sách tối đa trong thư viện
#define MAX_DOC_GIA 1000         // Số lượng độc giả tối đa
#define _CRT_SECURE_NO_WARNINGS  // Cho phép sử dụng các hàm không an toàn trong C (như gets, scanf...)

// Khai báo nguyên mẫu các hàm thống kê

// Thống kê tổng số lượng sách trong thư viện
void thongKeSoLuongSachTrongThuVien(int ISBN[], int soLuongSach[], int indexSach);

// Thống kê số lượng sách theo từng thể loại
void thongKeSoLuongSachTheoTheLoai(char theLoai[][MAX_STR], int soLuongSach[], int indexSach);

// Thống kê tổng số lượng độc giả
void thongKeSoLuongDocGia(int indexDocGia);

// Thống kê số lượng độc giả theo giới tính
void thongKeSoLuongDocGiaTheoGioiTinh(char gioiTinh[][MAX_STR], int indexDocGia);

// Thống kê số lượng sách đang được mượn
void thongKeSoLuongSachDangMuon(int ISBN_SachMuon[][10], int indexThongTinMuonTraSach,
    int soLuongSachMuon[], int indexSach, int ISBN[], char tenSach[][MAX_STR]);

// Thống kê các độc giả trả sách trễ hạn
void thongKeDocGiaTreHan(int maDocGiaMuuonSach[], char hoTenMuonSach[][MAX_STR],
    char ngayTraSachDuKien[][MAX_STR], int indexThongTinMuonTraSach, int soLuongSachMuon[]);