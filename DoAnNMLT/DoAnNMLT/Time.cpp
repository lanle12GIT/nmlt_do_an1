//char Time() {
//	int ngay;
//	int thang;
//	int nam;
//	char time[20];
//	do {
//		printf("nhap ngay,thang,nam");
//		scanf_s("%d", &ngay);
//		scanf_s("%d", &thang);
//		scanf_s("%d", &nam);
//		if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
//			if (ngay < 1 || ngay >31) {
//				printf("ngay khong hop le");
//			}
//
//		}
//		else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
//		{
//			if (ngay < 1 || ngay >30) {
//				printf("ngay khong hop le");
//			}
//		}
//		else if (thang == 2)
//		{
//			if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
//				if (ngay < 1 || ngay >29) {
//					printf("ngay khong hop le");
//				}
//			}
//			else
//			{
//				if (ngay < 1 || ngay >28) {
//					printf("ngay khong hop le");
//				}
//			}
//			
//		}
//
//
//	}
//
//
//	while (1>0);
//
//	return time;}
#include <stdio.h>
#include <string.h>
char* Time() {
    char timeStr[30];  // Mảng chứa chuỗi kết quả: "dd-mm-yyyy"
    int ngay, thang, nam;

    while (1) {
        printf("Nhap ngay, thang, nam: ");
        scanf_s("%d %d %d", &ngay, &thang, &nam);

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
        sprintf_s(timeStr, sizeof(timeStr), "%02d-%02d-%04d", ngay, thang, nam);
        break;
    }

    return timeStr;
}
