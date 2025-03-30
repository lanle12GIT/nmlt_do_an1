#include <stdio.h>
#include <string.h>
#include "Header.h"

#define MAX_DOC_GIA 1000
int index = 0;
// Các mảng lưu trữ thông tin độc giả
int maDocGia[MAX_DOC_GIA];
char hoTen[MAX_DOC_GIA][100];
char cmnd[MAX_DOC_GIA][20];
char ngayThangNamSinh[MAX_DOC_GIA][30];
char gioiTinh[MAX_DOC_GIA][30];
char email[MAX_DOC_GIA][50];
char diaChi[MAX_DOC_GIA][50];
char ngayMoThe[MAX_DOC_GIA][30];
char ngayKetThucThe[MAX_DOC_GIA][50];
void hienThiPoster() {
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

//Hàm hiển thị menu
void showMenu() {

	printf("=== Menu Quan Li Thu Vien ===\n");
	printf("1. Quan li doc gia\n");
	printf("2. Quan li sach\n");
	printf("3. Lap phieu muon sach\n");
	printf("4. Lap phieu tra sach\n");
	printf("5. Cac thong ke co ban\n");
	printf("Nhap lua chon cua ban: ");
	char choice[1];
	gets_s(choice);

	switch (choice[0]) {
	case '1': {
		printf("Ban chon Quan li doc gia.\n");
		printf("Nhap lua chon (a-f): \n");
		printf("   a. Xem danh sach doc gia trong thu vien\n");
		printf("   b. Them doc gia\n");
		printf("   c. Chinh sua thong tin mot doc gia\n");
		printf("   d. Xoa thong tin mot doc gia\n");
		printf("   e. Tim kiem doc gia theo CMND\n");
		printf("   f. Tim kiem sach theo ho ten\n");
		char subChoice[1];
		gets_s( subChoice);
		
		switch (subChoice[0]) {
		/*case 'a':
			printf( "Xem danh sach doc gia trong thu vien.\n" );
			hienThiDanhSachDocGia(maDocGia, hoTen, cmnd, email, index);
			break;*/
		case 'b':
			printf( "Them doc gia.\n" );
			themDocGia(maDocGia, hoTen, cmnd, email, &index);
			break;
		/*case 'c':
			printf( "Chinh sua thong tin mot doc gia." );
			updateReader(maDocGia, hoTen, cmnd, email, &index);
			break;
		case 'd':
			printf( "Xoa thong tin mot doc gia." );
			deleteReader(maDocGia, hoTen, cmnd, email, &index);
			break;
		case 'e':
			printf( "Tim kiem doc gia theo CMND." );
			findReaderBycmnd(maDocGia, hoTen, cmnd, email, &index);
			break;
		case 'f':
			printf( "Tim kiem docgia theo ho ten." );
			findReaderByName(maDocGia, hoTen, cmnd, email, &index);
			break;*/
		default:
			printf( "Lua chon khong hop le!" );
			break;
		}
		break;

	
		break;
	}
	case '2': {
		printf("Ban chon Quan li sach.\n");
		printf("Nhap lua chon (a-f): \n");
		printf("   a. Xem danh sach cac sach trong thu vien\n");
		printf("   b. Them sach\n");
		printf("   c. Chinh sua thong tin mot quyen sach\n");
		printf("   d. Xoa thong tin sach\n");
		printf("   e. Tim kiem sach theo ISBN\n");
		printf("   f. Tim kiem sach theo ten sach\n");
		/*char subChoice;
		cin >> subChoice;
		switch (subChoice) {
		case 'a':
			printf( "Xem danh sach cac sach trong thu vien." );
			viewBooks(arrBooks, m);
			break;
		case 'b':
			printf( "Them sach." );
			addBook(arrBooks, m);
			break;
		case 'c':
			printf( "Chinh sua thong tin mot quyen sach." );
			updateBook(arrBooks, m);
			break;
		case 'd':
			printf( "Xoa thong tin sach." );
			deleteBook(arrBooks, m);
			break;
		case 'e':
			printf( "Tim kiem sach theo ISBN." );
			findBookByISBN(arrBooks, m);
			break;
		case 'f':
			printf( "Tim kiem sach theo ten sach." );
			findBookByName(arrBooks, m);
			break;
		default:
			printf( "Lua chon khong hop le!" );
			break;
		}
		break;*/
		break;
	}
	case '3': {
		printf("Lap phieu muon sach.");

		/*{
			phieumuon[numberOfPhieumuon] = MuonSach(arrReaders, n, arrBooks, m);
			numberOfPhieumuon++;
		}

		{
			phieumuon[numberOfPhieumuon] = MuonSach(arrReaders, n, arrBooks, m);
			numberOfPhieumuon++;
		}

		for (int i = 0; i < numberOfPhieumuon; i++)
		{
			printf( phieumuon[i].madocgia );
		}
		break;*/
		break;
	}
	case '4': {
		printf("Lap phieu tra sach.");
		//		int maDocGia;long ISBN[] = { 1,2,4 };
		//		TraSach(phieumuon, numberOfPhieumuon, maDocGia, ISBN, numOfIsbn, arrBooks, m);
		//		break;
		break;
	}
	case '5': {
		//		printf( "Ban chon Cac thong ke co ban." );
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
	default: {
		printf("Lua chon khong hop le! Vui long thu lai.");
		break;
	}
		   //}*/




	}

}

int main()
{
	/*hienThiPoster();
	showMenu();*/
	/*

char *result = Time();
	printf("Ngay thang nam: %s\n", result);*/
	return 0;
}