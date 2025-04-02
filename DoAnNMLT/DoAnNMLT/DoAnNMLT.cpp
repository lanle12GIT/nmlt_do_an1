#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"
#include "HeaderSach.h"
#include "HeaderMuonTraSach.h"

int indexDocGia = 0;
// Các mảng lưu trữ thông tin độc giả
int maDocGia[MAX_DOC_GIA];
char hoTen[MAX_DOC_GIA][MAX_STR];
char cmnd[MAX_DOC_GIA][MAX_STR];
char ngayThangNamSinh[MAX_DOC_GIA][MAX_STR];
char gioiTinh[MAX_DOC_GIA][MAX_STR];
char email[MAX_DOC_GIA][MAX_STR];
char diaChi[MAX_DOC_GIA][MAX_STR];
char ngayMoThe[MAX_DOC_GIA][MAX_STR];
char ngayKetThucThe[MAX_DOC_GIA][MAX_STR];

int indexSach = 0;
// Các mảng lưu trữ thông tin sách
int ISBN[MAX_SACH];
char tenSach[MAX_SACH][MAX_STR];
char tacGia[MAX_SACH][MAX_STR];
char nhaXuatBan[MAX_SACH][MAX_STR];
int namXuatBan[MAX_SACH];
char theLoai[MAX_SACH][MAX_STR];
float giaSach[MAX_SACH];
int soLuongSach[MAX_SACH];

// Các mảng lưu trữ thông tin mượn trả sách
int indexThongTinMuonTraSach = 0;
int maDocGiaMuonSach[MAX_DOC_GIA];
char ngayMuonSach[MAX_DOC_GIA][MAX_STR];
char ngayTraSachDuKien[MAX_DOC_GIA][MAX_STR];
char ngayTraSachThucTe[MAX_DOC_GIA][MAX_STR];
float tienPhat[MAX_DOC_GIA];
int soLuongSachMuon[10];
int ISBN_SachMuon[MAX_DOC_GIA][10]; // mỗi đọc giả được mượn tối đa 10 cuốn khác nhau.

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

// Hàm hiển thị menu
void showMenu()
{
	bool isFinshed = false;
	do
	{   printf("\n--------------------------------\n");
		printf("\n=== Menu Quan Li Thu Vien ===\n");
		printf("1. Quan li doc gia\n");
		printf("2. Quan li sach\n");
		printf("3. Lap phieu muon sach\n");
		printf("4. Lap phieu tra sach\n");
		printf("5. Cac thong ke co ban\n");
		printf("6. Thoat\n");
		printf(">>>>>Nhap lua chon cua ban: ");
		char choice[2]; // Kích thước 10 ký tự (9 ký tự + 1 null terminator)
		gets_s(choice, 2);

		switch (choice[0])
		{
		case '1':
		{
			bool isBreak = false;
			do
			{
				printf("\n---------------------------------\n");
				printf("------Quan li doc gia.-----\n");
				printf(">>>>>Nhap lua chon (a-g): \n");
				printf("   a. Xem danh sach doc gia trong thu vien\n");
				printf("   b. Them doc gia\n");
				printf("   c. Chinh sua thong tin mot doc gia\n");
				printf("   d. Xoa thong tin mot doc gia\n");
				printf("   e. Tim kiem doc gia theo CMND\n");
				printf("   f. Tim kiem doc gia theo ho ten\n");
				printf("   g. Thoat\n");
				printf(">>>>>Nhap lua chon cua ban: ");
				char subChoice[2];
				gets_s(subChoice, 2);

				switch (subChoice[0])
				{
				case 'a':
					printf("Xem danh sach doc gia trong thu vien.\n");
					hienThiTatCaDocGia(
						indexDocGia, maDocGia, hoTen, cmnd,
						ngayThangNamSinh, gioiTinh, email,
						diaChi, ngayMoThe, ngayKetThucThe);
					break;
				case 'b':
					printf("Them doc gia.\n");
					themDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, &indexDocGia);
					break;
				case 'c':
					printf("Chinh sua thong tin mot doc gia.\n");
					chinhSuaDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'd':
					printf("Xoa thong tin mot doc gia.\n");
					xoaDocGia(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, &indexDocGia);
					break;
				case 'e':
					printf("Tim kiem doc gia theo CMND.\n");
					timKiemDocGiaTheoCMND(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'f':
					printf("Tim kiem doc gia theo ho ten.\n");
					timKiemDocGiaTheoHoTen(
						maDocGia, hoTen, cmnd, ngayThangNamSinh,
						gioiTinh, email, diaChi, ngayMoThe,
						ngayKetThucThe, indexDocGia);
					break;
				case 'g':
					isBreak = true;
					break;
				default:
					printf("Lua chon khong hop le!");
					break;
				}
			} while (!isBreak);
			break;
		}
		case '2':
		{
			bool isBreak = false;
			do
			{

				printf("\n---------------------------------\n");
				printf("------Quan li sach.-----\n");
				printf(">>>>>Nhap lua chon (a-f): \n");
				printf("   a. Xem danh sach cac sach trong thu vien\n");
				printf("   b. Them sach\n");
				printf("   c. Chinh sua thong tin mot quyen sach\n");
				printf("   d. Xoa thong tin sach\n");
				printf("   e. Tim kiem sach theo ISBN\n");
				printf("   f. Tim kiem sach theo ten sach\n");
				printf("   g. Thoat\n");
				printf(">>>>>Nhap lua chon cua ban: ");
				char choice[2]; // Kích thước 2 ký tự (1 ký tự + 1 null terminator)
				gets_s(choice, 2);
				switch (choice[0])
				{
				case 'a':
					printf("Xem danh sach cac sach trong thu vien.\n");
					hienThiTatCaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'b':
					printf("Them sach.\n");
					themSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, &indexSach);
					break;
				case 'c':
					printf("Chinh sua thong tin mot quyen sach.\n");
					chinhSuaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'd':
					printf("Xoa thong tin sach.\n");
					xoaSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, &indexSach);
					break;
				case 'e':
					printf("Tim kiem sach theo ISBN.\n");
					timKiemSachTheoISBN(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'f':
					printf("Tim kiem sach theo ten sach.\n");
					timKiemSachTheoTenSach(
						ISBN, tenSach, tacGia, nhaXuatBan, namXuatBan,
						theLoai, giaSach, soLuongSach, indexSach);
					break;
				case 'g':
					isBreak = true;
					break;
				default:
					printf("Lua chon khong hop le!\n");
					break;
				}
			} while (!isBreak);
			break;
		}
		case '3':
		{
			printf("\n---------------------------------\n");
			printf("Lap phieu muon sach.\n");
			phieuMuonSach(
				maDocGiaMuonSach, maDocGia, ngayMuonSach, ngayTraSachDuKien,
				ngayTraSachThucTe, tienPhat, ISBN_SachMuon, soLuongSachMuon,
				ISBN, soLuongSach, indexDocGia, indexSach, &indexThongTinMuonTraSach);
			break;
		}
		case '4':
		{
			printf("\n---------------------------------\n");
			printf("Lap phieu tra sach.\n");
			phieuTraSach(
				maDocGiaMuonSach, ngayMuonSach, ngayTraSachDuKien,
				ngayTraSachThucTe, tienPhat, ISBN_SachMuon,
				soLuongSachMuon, ISBN, soLuongSach, giaSach,
				indexSach, &indexThongTinMuonTraSach);
			break;
		}
		case '5':
		{
			//		printf( "Ban chon Cac thong ke co ban.\n" );
			//		printf( "Nhap lua chon (a-f): ";
			//		printf( "   a. Thong ke so luong sach trong thu vien" );
			//		printf( "   b. Thong ke so luong sach theo the loai" );
			//		printf( "   c. Thong ke so luong doc gia" );
			//		printf( "   d. Thong ke so luong doc gia theo gioi tinh" );
			//		printf( "   e. Thong ke so sach dang duoc muon" );
			//		printf( "   f. Thong ke danh sach doc gia bi tre han" );
			//		char subChoice;
			//		cin >> subChoice;
			//		switch (subChoice) {
			//		case 'a':
			//			printf( "Thong ke so luong sach trong thu vien." );
			//			numberOfBooks(arrBooks, m);
			//			break;
			//		case 'b':
			//			printf( "Thong ke so luong sach theo the loai." );
			//			numberOfBooksByCategory(arrBooks, m);
			//			break;
			//		case 'c':
			//			printf( "Thong ke so luong doc gia." );
			//			numberOfReaders(arrInfReaders, n);
			//			break;
			//		case 'd':
			//			printf( "Thong ke so luong doc gia theo gioi tinh." );
			//			numberofReadersBySex(arrInfReaders, n);
			//			break;
			//		case 'e':
			//			printf( "Thong ke so sach dang duoc muon." );
			//			NumberOfBooksBeingBorrowed(phieumuon, numberOfPhieumuon);
			//			break;
			//		case 'f':
			//			printf( "Thong ke danh sach doc gia bi tre han." );
			//			OverdueReadersList(phieumuon, numberOfPhieumuon);
			//			break;
			//		default:
			//			printf( "Lua chon khong hop le!" );
			//			break;
			//		}
			//		break;
			break;
		}
		case '6':
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
			//}*/
		}
	} while (!isFinshed);

	printf("Cam on ban da su dung chuong trinh!\n");
	printf("Hen gap lai!\n");
	printf("====================================\n");
	printf("\n\n");
}

int main()
{
	hienThiPoster();
	indexDocGia = 5;
	maDocGia[0] = 1001;
	strcpy_s(hoTen[0], "Nguyen Van A");
	strcpy_s(cmnd[0], "123456789");
	strcpy_s(ngayThangNamSinh[0], "01-01-1990");
	strcpy_s(gioiTinh[0], "Nam");
	strcpy_s(email[0], "nguyenvana@gmail.com");
	strcpy_s(diaChi[0], "Ha Noi");
	strcpy_s(ngayMoThe[0], "01-01-2020");
	strcpy_s(ngayKetThucThe[0], "01-01-2024");

	maDocGia[1] = 1002;
	strcpy_s(hoTen[1], "Tran Thi B");
	strcpy_s(cmnd[1], "987654321");
	strcpy_s(ngayThangNamSinh[1], "02-02-1992");
	strcpy_s(gioiTinh[1], "Nu");
	strcpy_s(email[1], "tranthib@gmail.com");
	strcpy_s(diaChi[1], "Hai Phong");
	strcpy_s(ngayMoThe[1], "02-02-2021");
	strcpy_s(ngayKetThucThe[1], "02-02-2025");

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

	showMenu();
	// tinhNgayngayTraSachDuKien("30-11-2024", ngayTraSachDuKien[0]);

	return 0;
}