#include <stdio.h>
#include <malloc.h>


int findMinValue(int *p, int n) {
    int *min = p;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(min + i) > *(p + j)) {
                *(min + i) = *(p + j);
            }
        }
    }
    return *min;
}

int findMaxValue(int *p, int n) {
    int *max = p;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(max + i) < *(p + j)) {
                *(max + i) = *(p + j);
            }
        }
    }
    return *max;
}


void nhap(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", (p + i));
    }
}

void xuat(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void menu() {
    printf("-----------MENU------------\n");
    printf("1.In ra so lon nhat trong mang. \n");
    printf("2.In ra so nho nhat trong mang. \n");
    printf("3.Ket thuc\n");
    printf("Hay lua chon cac thao tac (1|2|3) \n");
}

int main() {
    int *p, n, choice, max, min;
    printf("Nhap so luong phan tu cua mang: \n");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua mang: \n");
    nhap(p, n);
    printf("Mang sau khi nhap: \n");
    xuat(p, n);
    while (1 == 1) {
        menu();
        printf("Nhap lua chon cua ban: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
                max = findMaxValue(p, n);
                printf("So lon nhat trong mang la: \n");
                printf("%d\n", max);
                break;
            case 2 :
                min = findMinValue(p, n);
                printf("So nho nhat trong mang la: \n");
                printf("%d\n", min);
                break;
            case 3 :
                printf("Tam biet!\n");
                exit(1);
            default:
                printf("Hay nhap lai lua chon cua ban!\n");
        }
    }

}