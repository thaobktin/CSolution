#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char masv[20]; 
    char hoten[20];
} sinhvien;

void WriteFile(char *filename)
{
    FILE *fp;
    int n, i;
    sinhvien sv;
    printf("So luong sinh vien can nhap:");
    scanf("%d", &n);
    fflush(stdin);
    if((fp=fopen(filename,"ab"))!=NULL)
    {
        for(i=1;i<=n;i++)
        {
            printf("Sinh vien thu %i\n",i);
            printf("   -MSSV: "); gets(sv.masv);
            printf("   -Ho Ten: "); gets(sv.hoten);
            fwrite(&sv,sizeof(sv),1,fp);
            fflush(stdin);
        }
    }
    fclose(fp);
    printf("\nBam phim bat ky de tiep tuc!!!");
    getch();
}

void ReadFile(char *FileName) 
{ 
     FILE *f; 
     sinhvien sv; 
     f=fopen(FileName,"rb"); 
      printf("    MSSV  |  Ho va ten\n"); 
     fread(&sv,sizeof(sv),1,f); 
     while (!feof(f)) 
     { 
        printf("  %s  |  %s\n",sv.masv,sv.hoten); 
       fread(&sv,sizeof(sv),1,f); 
     } 
     fclose(f);
     printf("\nBam phim bat ky de tiep tuc!!!");
     getch(); 
} 

void docfile(char x[30], unsigned long &dodai) 
{ 
    char ch;       // Bien dem ki tu 
    FILE *fp; 
    fp=fopen(x,"r"); 
    if(fp==NULL) 
        ("Khong The Mo Tap Tin "); 
    else 
    { 
        while((ch=getc(fp))!=EOF)   //neu gap ki tu cuoi file thi ket thuc 
        { 
            putc(ch,stdout);   //doc tung ki tu roi xuat ra man hinh 
            dodai++;
        } 
    } 
    fclose(fp); 
    printf("\n\nDo dai cua File la %lu ",dodai); 
} 
 
void Search(char *FileName) 
{ 
     char MSSV[20]; 
     FILE *f; 
     int Found=0; 
     sinhvien sv; 
     
     fflush(stdin); 
      printf("Ma so sinh vien can tim: ");gets(MSSV); 
     f=fopen(FileName,"rb"); 
      while (!feof(f) && Found==0) 
     { 
       fread(&sv,sizeof(sv),1,f); 
        if (strcmp(sv.masv,MSSV)==0) Found=1; 
     } 
     fclose(f); 
      if (Found == 1) 
       printf("Tim thay SV co ma %s. Ho ten la: %s",sv.masv,sv.hoten); 
      else 
       printf("Tim khong thay sinh vien co ma %s",MSSV);
      printf("\nBam phim bat ky de tiep tuc!!!");
     getch(); 
} 
 
int main() 
{ 
     int c; 
     for (;;) 
     {
        printf("\n-----------------------------\n");
        printf("1. Nhap DSSV\n"); 
        printf("2. In DSSV\n"); 
        printf("3. Tim kiem\n"); 
        printf("4. Thoat\n"); 
        printf("Ban chon 1, 2, 3, 4: "); scanf("%d",&c); 
       switch(c)
       {
           case 1: WriteFile("SinhVien.dat"); break;
           case 2: ReadFile("SinhVien.dat"); break;
           case 3: Search("SinhVien.dat"); break;
           case 4: exit(0); break;
           default: printf("Ban chon khong dung\n"); break;
       }
     }
     getch();
     return 0;
}
