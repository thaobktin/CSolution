#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define		NUM		4

/* Khai bao kieu du lieu */
typedef struct {
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
} dateType;

typedef struct {
	char ten[30];
	dateType ngaysinh ;
} person_st;

void PersonInfo(){
	/* Bien toan cuc: danh sach nguoi */
	person_st personList[NUM];
	int mode = 0, breakMode = 0;
	
	do{
		mode = Menu();
		switch (mode){
			case 1: AddPerson(personList);
				break;
			case 2: SortPerson(personList);
				break;
			case 3: FindOldest(personList);
				break;
			case 4: WriteToFile(personList);
				break;
			case 5: ReadFromFile(personList);
				break;
			case 6: breakMode = 1;
				printf("Tam biet!\n");
				break;
			//default: printf("Lua chon sai. Nhap lai\n");
			//	break;
		}
		if (breakMode) break;
	} while(mode);
}

int Menu(){
	int choice;
	
	do{
		printf("-------------------------------------------\n");
		printf("Menu\n");
		printf("1. Nhap thong tin ve 4 nguoi.\n");
		printf("2. Sap xep va hien thi thong tin.\n");
		printf("3. Tim va hien thi nguoi co tuoi cao nhat.\n");
		printf("4. Ghi vao tap tin nhi phan person.dat.\n");
		printf("5. Doc tu tap tin nhi phan da ghi.\n");
		printf("6. Thoat\n\n");
		printf("Lua chon cua ban: ");	scanf("%d", &choice);
	} while (choice < 1 || choice > 6);
	return choice;
}

void AddPerson(person_st personList[]){
	int i, n = 4;
	printf("Nhap du lieu cho tung nguoi\n");
	for (i = 0; i < NUM; i++){
		printf("Nguoi thu %d:\n", i + 1);
		printf("   Ten: ");
		scanf("%s", personList[i].ten);
		printf("   Ngay-Thang-Nam:\n");
		printf("    Ngay: ");
		scanf("%d", &personList[i].ngaysinh.ngay);
		printf("    Thang: ");
		scanf("%d", &personList[i].ngaysinh.thang);
		printf("    Nam: ");
		scanf("%d", &personList[i].ngaysinh.nam);
		//scanf("%d/%d/%d", &personList[i].ngaysinh.ngay, &personList[i].ngaysinh.thang, &personList[i].ngaysinh.nam);
		
		while(!CheckDate(personList[i].ngaysinh.ngay, personList[i].ngaysinh.thang, personList[i].ngaysinh.nam)){
			printf("   Khong hop len, nhap lai Ngay-Thang-Nam:\n");
			printf("    Ngay: ");
			scanf("%d", &personList[i].ngaysinh.ngay);
			printf("    Thang: ");
			scanf("%d", &personList[i].ngaysinh.thang);
			printf("    Nam: ");
			scanf("%d", &personList[i].ngaysinh.nam);
		}
	}

    printf("\n");
}

//implement merge Sort
void SortPerson(person_st personList[]){
	int first, last;
	first = 0;
	last = sizeof(personList) - 1;	//NUM - 1;//sizeof(personList);
	
	MergeSort(personList, first, last);
	PrintListPerson(personList);
}

void FindOldest(person_st personList[]){
	person_st max;
	
	max = personList[0];
	for(int i = 1; i < NUM; i++){
		if (CompareDate(max.ngaysinh, personList[i].ngaysinh) > 0)
			max = personList[i];
	}
	
	printf("Nguoi co tuoi cao nhat:\n");
	printf("%-30s %02d/%02d/%4d\n", max.ten, max.ngaysinh.ngay, max.ngaysinh.thang, max.ngaysinh.nam);
}

void WriteToFile(person_st personList[]){
	FILE *f;
	int n = NUM;
	f = fopen("person.dat", "wt");
	fwrite(&n, sizeof(int), 1, f);
	
	for(int i = 0; i < NUM; i++){
		fwrite(&personList[i], sizeof(person_st), 1, f);
	}
	fclose(f);
	printf("Da ghi vao file person.dat");
	printf("\n");
}

void ReadFromFile(person_st personList[]){
	FILE *f;
	int n = NUM;
	f = fopen("person.dat", "rt");
	fread(&n, sizeof(int), 1, f);
	
	for(int i = 0; i < NUM; i++){
		fread(&personList[i], sizeof(person_st), 1, f);
	}
	
	PrintListPerson(personList);
}

void PrintListPerson(person_st personList[]){
	printf("\n---------- Thong tin tung nguoi -----------\n");
	printf("%3s %-30s %8s\n", "STT", "Ten", "Ngay sinh");
	for (int i = 0; i < NUM; i++) {
       printf("%-3d %-30s %02d/%02d/%4d\n", i + 1, personList[i].ten, personList[i].ngaysinh.ngay, personList[i].ngaysinh.thang, personList[i].ngaysinh.nam);
    }
    printf("\n");
}

int CheckDate(int ngay, int thang, int nam){
	if (nam < 0 || thang < 1 || thang > 12 || ngay < 1 || ngay > 31){
		return 0;
	}
	else {
		switch(thang){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (ngay > 0 && ngay <= 31){
					return 1;
					break;
				}
				else{
					return 0;
					break;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				if (ngay > 0 && ngay <= 30){
					return 1;
					break;
				}
				else{
					return 0;
					break;
				}
			case 2:
				if ((nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0))){
					if (ngay > 0 && ngay <= 29){
						return 1;
						break;
					}
					else{
						return 0;
						break;
					}
				}
				else{
					if (ngay > 0 && ngay <= 28){
						return 1;
						break;
					}
					else{
						return 0;
						break;
					}
				}
				
			default:
				return 0;
				break;
		}
	}
}

void MergeSort(person_st personList[], int first, int last){
	if (first < last)   
   	{   // chia thành hai dãy con      
    	int mid = (first + last)/2;    // chia se diem giua
		// sap xep dãy con trái A[first..mid]      
		MergeSort(personList, first, mid);
		// sap xep dãy con phai A[mid+1..last]
		MergeSort(personList, mid+1, last);
		// Tron hai dãy con      
		Merge(personList, first, mid, last);
	}
}

void Merge(person_st personList[], int first, int mid, int last){
	person_st temp[NUM * 2];    // mang pha
     
	int first1 = first; int last1 = mid;    
	int first2 = mid + 1; int last2 = last; int index = first1;     
	for (; (first1 <= last1) && (first2 <= last2); ++index){  
		if (strcmp(personList[first1].ten, personList[first2].ten) < 0){
			temp[index] = personList[first1];
			++first1;
		}
		else{
			temp[index] = personList[first2];
			++first2;
		}
	}
	
	for (; first1 <= last1; ++first1, ++index)      
		temp[index] = personList[first1]; // sao not dãy con 1
	for (; first2 <= last2; ++first2, ++index)
		temp[index] = personList[first2]; // sao not dãy con 2
	for (index = first; index <= last; ++index)
		personList[index] = temp[index]; // sao tra mang ket qua
}

int CompareDate(dateType dt1, dateType dt2){
	if (dt1.nam < dt2.nam)  return -1;
	else if (dt1.nam > dt2.nam)  return 1;
	
	if (dt1.nam == dt2.nam){
		if (dt1.thang < dt2.thang)  return -1;
		else if (dt1.thang > dt2.thang)  return 1;
		
		if (dt1.thang == dt2.thang){
			if (dt1.ngay < dt2.ngay)  return -1;
			else if (dt1.ngay > dt2.ngay) return 1;
			
			if (dt1.ngay == dt2.ngay)  return 0;
		}
	}
}

void Swap(person_st *a, person_st *b){
	person_st temp = *a;
	*a = *b;
	*b = temp;
}
 	
