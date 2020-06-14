#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct employee_st
{
    char name[30];
    char province[30];
    int year;
};
void Nhap(employee_st *&nv, int *n);
void Xuat(employee_st *nv, int n);
void sapXep(employee_st *nv, int n);
void thongKe(employee_st *nv, int n);
void timKiem(employee_st *nv, int n);
void XuatFile(employee_st *nv, int n);
void mainmenu(int chon, int n, employee_st *nv);
int main()
{
    int n;
    int chon;
    employee_st *nv;
    mainmenu(chon, n, nv);
    return 0;
}
void mainmenu(int chon, int n, employee_st *nv)
{
    do
    {
        printf("\n\t---------------------------------------MENU----------------------------------------------");
        printf("\n\t---------------------------------------o0o-----------------------------------------------");
        printf("\n\t|1. Nhap du lieu cua tung nhan vien.                                                    |");
        printf("\n\t|2. Sap xep, thong ke va hien thi thong tin chi tiet cua tung nhan vien theo tinh(Z->A).|");
        printf("\n\t|3. Tim nhan vien theo tinh.                                                            |");
        printf("\n\t|4. Ghi thong tin nhan vien.                                                            |");
        printf("\n\t|5. Thoat.                                                                              |");
        printf("\n\t-----------------------------------------------------------------------------------------");
        printf("\n\tBan vui long chon mot trong cac chuc nang tren [1 - 5]: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            Nhap(nv, &n);
            Xuat(nv, n);
            break;
        case 2:
            sapXep(nv, n);
            thongKe(nv, n);
            break;
        case 3:
            timKiem(nv, n);
            break;
        case 4:
            XuatFile(nv, n);
            break;
        case 5:
            break;
        default:
            printf("\n\tKhong co mot trong cac chuc nang tren: ");
        }
    } while (chon != 5);
}

// Nhap thong tin nhan vien
void Nhap(employee_st *&nv, int *n)
{
    printf("\tNhap so luong nhan vien:  ");
    scanf("%d", n);
    nv = (employee_st *)malloc(*n * sizeof(employee_st));
    for (int i = 0; i < *n; i++)
    {
        printf("\n\tNhap so luong nhan vien thu:  %d", i + 1);
        printf("\n\tNhap ho va ten nhan vien:  ");
        fflush(stdin);
        gets((nv + i)->name);
        printf("\tNhap ten tinh cua nhan vien:  ");
        fflush(stdin);
        gets((nv + i)->province);
        printf("\tNhap nam sinh cua nhan vien:  ");
        scanf("%d", &(nv + i)->year);
    }
}

//Hien thi thong tin nhan vien da duoc nhap va ghi lai
void Xuat(employee_st *nv, int n)
{
    printf("\n\tDanh sach nhan vien: ");
    for (int i = 0; i < n; i++)
    {
        printf("\n\tNhan vien thu:  %d", i + 1);
        printf("\n\tHo va ten nhan vien:  %s", (nv + i)->name);
        printf("\n\tTen tinh cua nhan vien:  %s", (nv + i)->province);
        printf("\n\tNam sinh cua nhan vien:  %d\n", (nv + i)->year);
    }
}

//Sap xep nhan vien theo tinh
void sapXep(employee_st *nv, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp((nv + i)->province, (nv + j)->province) == 0)
            {
                employee_st v;
                strcpy(v.name, (nv + i)->name);
                strcpy(v.province, (nv + i)->province);
                v.year = (nv + i)->year;
                strcpy((nv + i)->name, (nv + j)->name);
                strcpy((nv + i)->province, (nv + j)->province);
                (nv + i)->year = (nv + j)->year;
                strcpy((nv + j)->name, v.name);
                strcpy((nv + j)->province, v.province);
                (nv + j)->year = v.year;
            }
        }
    }
    printf("\n\n\tDanh sach nhan vien da sap xep\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\tNhan vien thu:  %d", i + 1);
        printf("\n\tHo ten:  %s", (nv + i)->name);
        printf("\n\tTen tinh:  %s", (nv + i)->province);
        printf("\n\tNam sinh:  %d\n", (nv + i)->year);
    }
}

//Thong ke nhan vien theo tinh
void thongKe(employee_st *nv, int n)
{
    printf("\n\t**Thong ke nhan vien: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int soluong = 0;
            if ((nv + i)->province == (nv + j)->province)
            {
                if (i <= j)
                    soluong++;
                else
                    break;
            }
            if (soluong != 0)
                printf("\n\tTinh %s co %d nhan vien.\n", (nv + i)->province, soluong);
        }
    }
}

//Tim kiem nhan vien theo tinh
void timKiem(employee_st *nv, int n)
{
    char province1[30];
    printf("\n\n\tNhap ten tinh can tim:  ");
    fflush(stdin);
    gets(province1);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (stricmp(province1, (nv + i)->province) == 0)
        {
            dem++;
            printf("\n\t%d. Nhan vien can tim theo tinh %s. ", dem, province1);
            printf("\n\tHo va ten nhan vien:  %s", (nv + i)->name);
            printf("\n\tTen tinh cua nhan vien:  %s", (nv + i)->province);
            printf("\n\tNam sinh cua nhan vien:  %d", (nv + i)->year);
        }
    }
    if (dem == 0)
        printf("\n\tKhong co nhan vien thuoc tinh nay:  %s\n", province1);
}

// Ghi nhan vien vao file employee.txt
void XuatFile(employee_st *nv, int n)
{
    FILE *file;
    if ((file = fopen("employee.txt", "wb")) == NULL)
    {
        printf("\n\tKhong the ghi duoc!");
    }
    else
    {
        fprintf(file, "\n\tThong tin nhan vien: ");
        for (int i = 0; i < n; i++)
        {
            fprintf(file, "\n\tHo va ten nhan vien:  %s", (nv + i)->name);
            fprintf(file, "\n\tTen tinh cua nhan vien:  %s", (nv + i)->province);
            fprintf(file, "\n\tNam sinh cua nhan vien:  %d\n", (nv + i)->year);
        }
    }
    fclose(file);
}
 
