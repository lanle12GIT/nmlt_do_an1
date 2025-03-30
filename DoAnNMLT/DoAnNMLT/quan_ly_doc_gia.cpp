#include <stdio.h>
#include <string.h>



// Hàm thêm độc giả
void themDocGia( int maDocGia[], char hoTen[][], char cmnd[][], char email[][], int& index) {
    printf("nhap ma doc gia: ");
    scanf_s( "%d", &maDocGia[index]);
    printf("\n nhap ho ten "); 
    gets_s( hoTen[index]);
    printf("\n nhap CMND: ");
    gets_s( cmnd[index]);
    printf("\n nhap email: ");
    gets_s( email[index]);
   // *index++;
}

// Hàm hiển thị danh sách độc giả
void hienThiDanhSachDocGia(int maDocGia[], char hoTen[], char cmnd[], char email[], int index) {
    printf("Danh sách độc giả:\n");
    for (int i = 0; i <= index; i++) {
        printf("Mã độc giả: %d, Họ tên: %c, CMND: %c, Email: %c\n", maDocGia[i], hoTen[i], cmnd[i], email[i]);
    }
}

