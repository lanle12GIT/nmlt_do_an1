#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"
#include "HeaderSach.h"
#include "HeaderMuonTraSach.h"
#include "HeaderThongKe.h"

// Biến toàn cục lưu số lượng độc giả hiện tại
int indexDocGia = 0;
int maDocGia[MAX_DOC_GIA];					 // Mã độc giả
char hoTen[MAX_DOC_GIA][MAX_STR];			 // Họ tên độc giả
char cmnd[MAX_DOC_GIA][MAX_STR];			 // Số CMND
char ngayThangNamSinh[MAX_DOC_GIA][MAX_STR]; // Ngày sinh
char gioiTinh[MAX_DOC_GIA][MAX_STR];		 // Giới tính
char email[MAX_DOC_GIA][MAX_STR];			 // Email
char diaChi[MAX_DOC_GIA][MAX_STR];			 // Địa chỉ
char ngayMoThe[MAX_DOC_GIA][MAX_STR];		 // Ngày mở thẻ
char ngayKetThucThe[MAX_DOC_GIA][MAX_STR];	 // Ngày kết thúc thẻ

// Biến toàn cục lưu số lượng sách hiện tại
int indexSach = 0;

// Các mảng lưu trữ thông tin sách
int ISBN[MAX_SACH];					// Mã ISBN
char tenSach[MAX_SACH][MAX_STR];	// Tên sách
char tacGia[MAX_SACH][MAX_STR];		// Tác giả
char nhaXuatBan[MAX_SACH][MAX_STR]; // Nhà xuất bản
int namXuatBan[MAX_SACH];			// Năm xuất bản
char theLoai[MAX_SACH][MAX_STR];	// Thể loại
float giaSach[MAX_SACH];			// Giá sách
int soLuongSach[MAX_SACH];			// Số lượng sách

// Các mảng lưu trữ thông tin mượn trả sách
int indexThongTinMuonTraSach = 0;			  // Số lượng phiếu mượn trả
int maDocGiaMuonSach[MAX_DOC_GIA];			  // Mã độc giả mượn sách
char hoTenMuonSach[MAX_DOC_GIA][MAX_STR];	  // Họ tên độc giả mượn
char tenSachMuon[MAX_DOC_GIA][10][MAX_STR];	  // Tên các sách mượn (tối đa 10 cuốn/độc giả)
char ngayMuonSach[MAX_DOC_GIA][MAX_STR];	  // Ngày mượn sách
char ngayTraSachDuKien[MAX_DOC_GIA][MAX_STR]; // Ngày trả dự kiến
char ngayTraSachThucTe[MAX_DOC_GIA][MAX_STR]; // Ngày trả thực tế
float tienPhat[MAX_DOC_GIA];				  // Tiền phạt nếu có
int soLuongSachMuon[10];					  // Số lượng sách mượn cho từng phiếu
int ISBN_SachMuon[MAX_DOC_GIA][10];			  // ISBN các sách mượn, mỗi độc giả có tối đa 10 cuốn sách
char ghiChu[MAX_DOC_GIA][10][MAX_STR] = {""}; // Ghi chú trạng thái sách đã mượn

// Hàm hiển thị poster giới thiệu chương trình
void hienThiPoster()
{
	printf("*****************************************************\n");
	printf("*                                                   *\n");
	printf("*           HE THONG QUAN LI THU VIEN               *\n");
	printf("*                                                   *\n");
	printf("*        DAI HOC KHOA HOC TU NHIEN_KHOA CNTT        *\n");
	printf("*           Mon hoc: NHAP MON LAP TRINH             *\n");
	printf("*              Sinh vien: LE THI LAN                *\n");
	printf("*                 MSSV:24880226                     *\n");
	printf("*                                                   *\n");
	printf("*****************************************************\n");
	printf("\n\n");
}

// Hàm hiển thị menu chính và xử lý lựa chọn của người dùng
void showMenu()
{
	bool isFinshed = false;
	do
	{ // Hiển thị menu chính
		printf("\n#################################");
		printf("\n=== Menu Quan Li Thu Vien ===\n");
		printf("1. Quan li doc gia\n");
		printf("2. Quan li sach\n");
		printf("3. Lap phieu muon sach\n");
		printf("4. Lap phieu tra sach\n");
		printf("5. Cac thong ke co ban\n");
		printf("6. Thoat\n");
		printf(">>>>> Nhap lua chon cua ban: ");
		char choice[2]; // Kích thước 2 ký tự (1 ký tự + 1 null terminator)
		gets_s(choice, 2);

		switch (choice[0])
		{
		case '1': // Quản lý độc giả
		{
			bool isBreak = false;
			do
			{ // Hiển thị menu con quản lý độc giả
				printf("\n---------------------------------\n");
				printf("------Quan li doc gia.-----\n");
				printf(">>>>> Nhap lua chon (a-g): \n");
				printf("   a. Xem danh sach doc gia trong thu vien\n");
				printf("   b. Them doc gia\n");
				printf("   c. Chinh sua thong tin mot doc gia\n");
				printf("   d. Xoa thong tin mot doc gia\n");
				printf("   e. Tim kiem doc gia theo CMND\n");
				printf("   f. Tim kiem doc gia theo ho ten\n");
				printf("   g. Thoat\n");
				printf(">>>>> Nhap lua chon cua ban: ");
				char subChoice[2];
				gets_s(subChoice, 2);

				switch (subChoice[0])
				{
				case 'a': // Xem danh sách độc giả
					printf("Xem danh sach doc gia trong thu vien.\n");
					hienThiTatCaDocGia(
						indexDocGia, maDocGia, hoTen, cmnd,
						ngayThangNamSinh, gioiTinh, email,
						diaChi, ngayMoThe, ngayKetThucThe);
					break;
				case 'b': // Thêm độc giả mới
					printf("Them doc gia.\n");
					themDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, &indexDocGia);
					break;
				case 'c': // Chỉnh sửa thông tin độc giả
					printf("Chinh sua thong tin mot doc gia.\n");
					chinhSuaDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'd': // Xóa độc giả
					printf("Xoa thong tin mot doc gia.\n");
					xoaDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, &indexDocGia);
					break;
				case 'e': // Tìm kiếm độc giả theo CMND
					printf("Tim kiem doc gia theo CMND.\n");
					timKiemDocGiaTheoCMND(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'f': // Tìm kiếm độc giả theo họ tên
					printf("Tim kiem doc gia theo ho ten.\n");
					timKiemDocGiaTheoHoTen(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'g': // Thoát menu quản lý độc giả
					isBreak = true;
					break;
				default:
					printf("Lua chon khong hop le!");
					break;
				}
			} while (!isBreak);
			break;
		}
		case '2': // Quản lý sách
		{
			bool isBreak = false;
			do
			{
				// Hiển thị menu con quản lý sách
				printf("\n---------------------------------\n");
				printf("------Quan li sach.-----\n");
				printf(">>>>> Nhap lua chon (a-f): \n");
				printf("   a. Xem danh sach cac sach trong thu vien\n");
				printf("   b. Them sach\n");
				printf("   c. Chinh sua thong tin mot quyen sach\n");
				printf("   d. Xoa thong tin sach\n");
				printf("   e. Tim kiem sach theo ISBN\n");
				printf("   f. Tim kiem sach theo ten sach\n");
				printf("   g. Thoat\n");
				printf(">>>>> Nhap lua chon cua ban: ");
				char choice[2]; // Kích thước 2 ký tự (1 ký tự + 1 null terminator)
				gets_s(choice, 2);
				switch (choice[0])
				{
				case 'a':  // Xem danh sách sách
					printf("Xem danh sach cac sach trong thu vien.\n");
					hienThiTatCaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'b': // Thêm sách mới
					printf("Them sach.\n");
					themSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, &indexSach);
					break;
				case 'c':  // Chỉnh sửa thông tin sách
					printf("Chinh sua thong tin mot quyen sach.\n");
					chinhSuaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'd':    // Xóa sách
					printf("Xoa thong tin sach.\n");
					xoaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, &indexSach);
					break;
				case 'e':  // Tìm kiếm sách theo ISBN
					printf("Tim kiem sach theo ISBN.\n");
					timKiemSachTheoISBN(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'f':    // Tìm kiếm sách theo tên sách
					printf("Tim kiem sach theo ten sach.\n");
					timKiemSachTheoTenSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'g':  // Thoát menu quản lý sách
					isBreak = true;
					break;
				default:
					printf("Lua chon khong hop le!\n");
					break;
				}
			} while (!isBreak);
			break;
		}
		case '3':  // Lập phiếu mượn sách
		{
			printf("\n---------------------------------\n");
			printf("Lap phieu muon sach.\n");
			phieuMuonSach(
				maDocGiaMuonSach, maDocGia, hoTen, hoTenMuonSach, tenSachMuon, tenSach,
				ngayMoThe, ngayKetThucThe, ngayMuonSach, ngayTraSachDuKien,
				ngayTraSachThucTe, tienPhat, ISBN_SachMuon, soLuongSachMuon,
				ISBN, soLuongSach, indexDocGia, indexSach, ghiChu, &indexThongTinMuonTraSach);
			break;
		}
		case '4':  // Lập phiếu trả sách
		{
			printf("\n---------------------------------\n");
			printf("Lap phieu tra sach.\n");
			phieuTraSach(
				maDocGiaMuonSach, hoTenMuonSach, ngayMuonSach, ngayTraSachDuKien,
				ngayTraSachThucTe, tienPhat, ISBN_SachMuon, tenSachMuon,
				soLuongSachMuon, ISBN, soLuongSach, giaSach,
				indexSach, ghiChu, &indexThongTinMuonTraSach);
			break;
		}
		case '5':
		{
			 // Thống kê cơ bản
			bool isBreak = false;
			do
			{

				printf("\n---------------------------------\n");
				printf("Ban chon Cac thong ke co ban.\n");
				printf(">>>>> Nhap lua chon (a-f): \n");
				printf("   a. Thong ke so luong sach trong thu vien\n");
				printf("   b. Thong ke so luong sach theo the loai\n");
				printf("   c. Thong ke so luong doc gia\n");
				printf("   d. Thong ke so luong doc gia theo gioi tinh\n");
				printf("   e. Thong ke so sach dang duoc muon\n");
				printf("   f. Thong ke danh sach doc gia bi tre han\n");
				printf("   g. Thoat\n");
				char subChoice[2];
				gets_s(subChoice, 2);
				switch (subChoice[0])
				{
					
				case 'a':   // Thống kê số lượng sách
					printf("Thong ke so luong sach trong thu vien.\n");
					thongKeSoLuongSachTrongThuVien(ISBN, soLuongSach, indexSach);
					break;

				case 'b':  // Thống kê sách theo thể loại
					printf("Thong ke so luong sach theo the loai.\n");
					thongKeSoLuongSachTheoTheLoai(theLoai, soLuongSach, indexSach);
					break;

				case 'c':  // Thống kê số lượng độc giả
					printf("Thong ke so luong doc gia.\n");
					thongKeSoLuongDocGia(indexDocGia);
					break;

				case 'd':   // Thống kê độc giả theo giới tính
					printf("Thong ke so luong doc gia theo gioi tinh.\n");
					thongKeSoLuongDocGiaTheoGioiTinh(gioiTinh, indexDocGia);
					break;

				case 'e':    // Thống kê số sách đang được mượn
					printf("Thong ke so sach dang duoc muon.\n");
					thongKeSoLuongSachDangMuon(
						ISBN_SachMuon, indexThongTinMuonTraSach, soLuongSachMuon,
						indexSach, ISBN, tenSach);
					break;

				case 'f':      // Thống kê độc giả bị trễ hạn
					printf("Thong ke danh sach doc gia bi tre han.\n");
					thongKeDocGiaTreHan(
						maDocGiaMuonSach, hoTenMuonSach,
						ngayTraSachDuKien, indexThongTinMuonTraSach, soLuongSachMuon);
					break;

				case 'g': // Thoát menu thống kê
					isBreak = true;
					break;
				default:
					printf("Lua chon khong hop le!");
					break;
				}
			} while (!isBreak);

			break;
		}
		case '6':  // Thoát chương trình
		{
			printf("\n====================================\n");
			printf("Thoat khoi chuong trinh.\n");
			isFinshed = true;
			break;
		}
		default:
		{
			printf("Lua chon khong hop le! Vui long thu lai.\n");
			break;
		}
			
		}
	} while (!isFinshed);

	printf("Cam on ban da su dung chuong trinh!\n");
	printf("Hen gap lai!\n");
	printf("====================================\n");
	printf("\n\n");
}

// Hàm main: Khởi tạo dữ liệu mẫu và chạy chương trình
int main()
{
	 // Hiển thị poster

	// Khởi tạo dữ liệu mẫu cho độc giả
	hienThiPoster();
	indexDocGia = 5;
	maDocGia[0] = 1001;
	strcpy_s(hoTen[0], "Nguyen Van A");
	strcpy_s(cmnd[0], "123456789");
	strcpy_s(ngayThangNamSinh[0], "01-01-1990");
	strcpy_s(gioiTinh[0], "Nam");
	strcpy_s(email[0], "nguyenvana@gmail.com");
	strcpy_s(diaChi[0], "Ha Noi");
	strcpy_s(ngayMoThe[0], "01-01-2022");
	strcpy_s(ngayKetThucThe[0], "01-01-2026");

	maDocGia[1] = 1002;
	strcpy_s(hoTen[1], "Tran Thi B");
	strcpy_s(cmnd[1], "987654321");
	strcpy_s(ngayThangNamSinh[1], "02-02-1992");
	strcpy_s(gioiTinh[1], "Nu");
	strcpy_s(email[1], "tranthib@gmail.com");
	strcpy_s(diaChi[1], "Hai Phong");
	strcpy_s(ngayMoThe[1], "02-02-2023");
	strcpy_s(ngayKetThucThe[1], "02-02-2027");

	maDocGia[2] = 1003;
	strcpy_s(hoTen[2], "Le Van C");
	strcpy_s(cmnd[2], "456789123");
	strcpy_s(ngayThangNamSinh[2], "03-03-1993");
	strcpy_s(gioiTinh[2], "Nam");
	strcpy_s(email[2], "levanc@gmail.com");
	strcpy_s(diaChi[2], "Da Nang");
	strcpy_s(ngayMoThe[2], "03-03-2022");
	strcpy_s(ngayKetThucThe[2], "03-03-2026");

	maDocGia[3] = 1004;
	strcpy_s(hoTen[3], "Pham Thi D");
	strcpy_s(cmnd[3], "321654987");
	strcpy_s(ngayThangNamSinh[3], "04-04-1994");
	strcpy_s(gioiTinh[3], "Nu");
	strcpy_s(email[3], "phamthid@gmail.com");
	strcpy_s(diaChi[3], "Ho Chi Minh");
	strcpy_s(ngayMoThe[3], "04-04-2023");
	strcpy_s(ngayKetThucThe[3], "04-04-2027");

	maDocGia[4] = 1005;
	strcpy_s(hoTen[4], "Hoang Van E");
	strcpy_s(cmnd[4], "789123456");
	strcpy_s(ngayThangNamSinh[4], "05-05-1995");
	strcpy_s(gioiTinh[4], "Nam");
	strcpy_s(email[4], "hoangvane@gmail.com");
	strcpy_s(diaChi[4], "Can Tho");
	strcpy_s(ngayMoThe[4], "05-05-2024");
	strcpy_s(ngayKetThucThe[4], "05-05-2028");

	 // Khởi tạo dữ liệu mẫu cho sách
	indexSach = 5;
	ISBN[0] = 1111;
	strcpy_s(tenSach[0], "Lap Trinh C++");
	strcpy_s(tacGia[0], "Nguyen Van A");
	strcpy_s(nhaXuatBan[0], "NXB Tre");
	namXuatBan[0] = 2020;
	strcpy_s(theLoai[0], "Lap Trinh");
	giaSach[0] = 150000.0;
	soLuongSach[0] = 10;

	ISBN[1] = 2222;
	strcpy_s(tenSach[1], "Lap Trinh Java");
	strcpy_s(tacGia[1], "Tran Thi B");
	strcpy_s(nhaXuatBan[1], "NXB Giao Duc");
	namXuatBan[1] = 2021;
	strcpy_s(theLoai[1], "Lap Trinh");
	giaSach[1] = 200000.0;
	soLuongSach[1] = 15;

	ISBN[2] = 3333;
	strcpy_s(tenSach[2], "Lap Trinh Python");
	strcpy_s(tacGia[2], "Le Van C");
	strcpy_s(nhaXuatBan[2], "NXB Kim Dong");
	namXuatBan[2] = 2019;
	strcpy_s(theLoai[2], "Lap Trinh");
	giaSach[2] = 180000.0;
	soLuongSach[2] = 8;

	ISBN[3] = 4444;
	strcpy_s(tenSach[3], "Thuat Toan");
	strcpy_s(tacGia[3], "Pham Thi D");
	strcpy_s(nhaXuatBan[3], "NXB Tre");
	namXuatBan[3] = 2018;
	strcpy_s(theLoai[3], "Khoa Hoc");
	giaSach[3] = 250000.0;
	soLuongSach[3] = 5;

	ISBN[4] = 5555;
	strcpy_s(tenSach[4], "Co So Du Lieu");
	strcpy_s(tacGia[4], "Hoang Van E");
	strcpy_s(nhaXuatBan[4], "NXB Giao Duc");
	namXuatBan[4] = 2022;
	strcpy_s(theLoai[4], "Cong Nghe");
	giaSach[4] = 300000.0;
	soLuongSach[4] = 12;

	 // Khởi tạo dữ liệu mẫu cho phiếu mượn trả sách
	indexThongTinMuonTraSach = 3;

	// Thông tin mượn trả cho độc giả ở index 0:
	maDocGiaMuonSach[0] = 1001;
	strcpy_s(hoTenMuonSach[0], "Nguyen Van A");
	strcpy_s(ngayMuonSach[0], "10-04-2025");
	strcpy_s(ngayTraSachDuKien[0], "17-04-2025");
	strcpy_s(ngayTraSachThucTe[0], "00-00-0000");
	tienPhat[0] = 0.0;
	soLuongSachMuon[0] = 2;
	ISBN_SachMuon[0][0] = 1111;
	strcpy_s(tenSachMuon[0][0], MAX_STR, "Lap Trinh C++");
	ISBN_SachMuon[0][1] = 3333;
	strcpy_s(tenSachMuon[0][1], MAX_STR, "Lap Trinh Python");

	// Thông tin mượn trả cho độc giả ở index 1:
	maDocGiaMuonSach[1] = 1002;
	strcpy_s(hoTenMuonSach[1], "Tran Thi B");
	strcpy_s(ngayMuonSach[1], "11-04-2025");
	strcpy_s(ngayTraSachDuKien[1], "18-04-2025");
	strcpy_s(ngayTraSachThucTe[1], "00-00-0000");
	tienPhat[1] = 0.0;
	soLuongSachMuon[1] = 1;
	ISBN_SachMuon[1][0] = 2222;
	strcpy_s(tenSachMuon[1][0], MAX_STR, "Lap Trinh Java");

	// Thông tin mượn trả cho độc giả ở index 2:
	maDocGiaMuonSach[2] = 1003;
	strcpy_s(hoTenMuonSach[2], "Le Van C");
	strcpy_s(ngayMuonSach[2], "12-04-2025");
	strcpy_s(ngayTraSachDuKien[2], "19-04-2025");
	strcpy_s(ngayTraSachThucTe[2], "00-00-0000");
	tienPhat[2] = 0.0;
	soLuongSachMuon[2] = 3;
	ISBN_SachMuon[2][0] = 1111;
	strcpy_s(tenSachMuon[2][0], MAX_STR, "Lap Trinh C++");
	ISBN_SachMuon[2][1] = 4444;
	strcpy_s(tenSachMuon[2][1], MAX_STR, "Thuat Toan");
	ISBN_SachMuon[2][2] = 5555;
	strcpy_s(tenSachMuon[2][2], MAX_STR, "Co So Du Lieu");

	showMenu(); // Chạy menu chính

	return 0;
}