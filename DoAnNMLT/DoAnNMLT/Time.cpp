
#include <stdio.h>
#include <string.h>
#include "HeaderDocGia.h"

 void enterDateTime(char timeStr[MAX_STR]) {
    int ngay, thang, nam;

    while (1) {
        printf("voi format: dd-mm-yyyy. vi du: 29-03-2025\n");
        if (scanf_s("%d-%d-%d", &ngay, &thang, &nam) == 3) {
            while (getchar() != '\n');
        }
        else {
            printf("Dinh dang nhap khong hop le. Vui long nhap lai.\n");
            // Xóa bộ nhớ đệm nhập để chuẩn bị cho lần nhập mới.
            while (getchar() != '\n');
            continue;
        }
        // Kiểm tra tháng hợp lệ
        if (thang < 1 || thang > 12) {
            printf("Thang khong hop le\n");
            continue;
        }

        // Xác định số ngày tối đa của tháng
        int maxNgay;
        if (thang == 2)
            maxNgay = ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) ? 29 : 28;
        else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            maxNgay = 30;
        else
            maxNgay = 31;

        // Kiểm tra ngày hợp lệ
        if (ngay < 1 || ngay > maxNgay) {
            printf("Ngay khong hop le\n");
            continue;
        }

        // Định dạng kết quả dạng "dd-mm-yyyy"
        sprintf_s(timeStr, 100, "%02d-%02d-%04d", ngay, thang, nam);
        break;
    }

   
}
