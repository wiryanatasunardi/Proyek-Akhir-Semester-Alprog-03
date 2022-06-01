#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "fungsi.h"

int main(){
	system("color f0");
	int i;
	int banyakMahasiswa;
	int is_Valid = 0;
	float average, jumlah, nilai;
	double quartile_1, quartile_2, quartile_3;
	int opsi, jenisStat, jenisSort, binary, checker = 0;
	char bufferAverage[5], bufferQuartile1[5], bufferQuartile2[5], bufferQuartile3[5];
	DATA *data;
	NodePtr root = NULL;
	
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selamat Datang di Program Database Mahasiswa \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	while(1){
		printf("\n\t\t\t\tMasukkan angka untuk memilih menu: \n");
		printf("\n\t\t\t\t1. Input Nilai ");
		printf("\n\t\t\t\t2. Delete Linked List ");
		printf("\n\t\t\t\t3. Statistik Kelas ");
		printf("\n\t\t\t\t4. Panduan ");
		printf("\n\t\t\t\t5. Antrian Vaksin");
		printf("\n\t\t\t\t6. Keluar");
		printf("\n\t\t\t\tPilihan Anda >\t ");
		scanf("%d", &opsi);
		
		switch(opsi){
			case(1):
				system("cls");
				printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Selamat Datang di Program Database Mahasiswa \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
				// Error handling input banyak mahasiswa
				printf("\n\t\t\t\tJumlah Mahasiswa :  ");
				while(is_Valid == 0){
					if(scanf("%d", &banyakMahasiswa) == 1){
						if(banyakMahasiswa > 0) {
							break;
						} else {
							printf("\n\t\t\t\tBesar angka minimal 1!\n");
						}
					} else {
						printf("\n\t\t\t\tTidak boleh memasukkan input selain angka!\n");
					}
					scanf("%*[^\n]");
					printf("\n\t\t\t\tJumlah Mahasiswa :  ");
				}
	
				data = (DATA*) calloc(banyakMahasiswa, sizeof(DATA));
				
				for(i = 0; i < banyakMahasiswa; i++){
					printf("\n\t\t\t\tNama lengkap mahasiswa ke-%d :  ", i + 1);
					takeInput(data[i].nama);
		
					while(is_Valid == 0) {
						printf("\n\t\t\t\tNPM mahasiswa ke-%d :  ", i + 1);
						takeInput(data[i].npm);
						if(strlen(data[i].npm) != 10) {
							printf("\t\t\t\tNPM harus 10 digit!\n");
						} else {
							break;
						}
					}
		
					printf("\n\t\t\t\tNilai mahasiswa ke-%d :  ", i + 1);
					while(is_Valid == 0){
						if(scanf("%f", &data[i].nilai) == 1){
							if(data[i].nilai >= 0) {
								break;
							} else {
								printf("\n\t\t\t\tNilai tidak boleh negatif!\n");
							}
						} else {
							printf("\n\t\t\t\tTidak boleh memasukkan input selain angka!\n");
						}
						scanf("%*[^\n]");
						printf("\n\t\t\t\tNilai mahasiswa ke-%d :  ", i + 1);
					}
					printf("\n\t\t\t\t============================================================\n");
					
					head = push(head, data[i]);
				}
				
				system("cls");
				printf("\n\t\t\t\tData yang telah diinput\n");
				tabel_data(data, banyakMahasiswa);
				
				printf("\n\t\t\t\tData yang telah diinput(linkedlist)\n");
				tabel_data_linkedlist(head, iteratorPtr);
				
				checker = 1;
				
				delay();
				break;				
			
			case(2):
				if(checker == 0){
					printf("\n\t\t\t\tUser belum memasukkan nilai!\n\n");
					break;
				} else{
					system("cls");
					tabel_data_linkedlist(head, iteratorPtr);
					int input = 1;
					char deleteNama[50];
				
				
					while(input == 1){
						system("cls");
				
						tabel_data_linkedlist(head, iteratorPtr);
						printf("\n\t\t\t\tTuliskan nama mahasiswa yang datanya ingin dihapus: ");
						takeInput(deleteNama);
					
						head = deleteNode(head, deleteNama);
						
						printf("\n\n");
						tabel_data_linkedlist(head, iteratorPtr);	
						
						if(head != NULL){									
							printf("\n\t\t\t\tApakah anda ingin menghapus data lagi?\n\t\t\t\t1. Ya\n\t\t\t\t2. Tidak\n\t\t\t\tPilihan anda: ");				
							scanf("%d", &input);
						} else {
							printf("\n\t\t\t\tAnda akan diarahkan ke menu utama dalam 3 detik");
							sleep(3);
							break;
						}
					}
				}
				
					
			case(3):
				if(checker == 0){
					printf("\n\t\t\t\tUser belum memasukkan nilai!\n\n");
					break;
				}
				else if(checker == 1){
					system("cls");
									
					printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Statistik Kelas \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
					printf("\n\t\t\t\tMasukkan angka untuk memilih menu Statistik: \n");
					printf("\n\t\t\t\t1. Rata-Rata Kelas");
					printf("\n\t\t\t\t2. Kuartil Kelas");
					printf("\n\t\t\t\t3. Modus Kelas"); 
					printf("\n\t\t\t\t4. Pengurutan Nilai Mahasiswa");
					printf("\n\t\t\t\t5. Searching Nilai Mahasiswa");
					printf("\n\t\t\t\t6. Binary Tree");
					printf("\n\t\t\t\tPilihan Anda >\t");
					scanf("%d", &jenisStat);
				
					switch(jenisStat){
						case(1):
							system("cls");
							jumlah = sum(data, banyakMahasiswa);
							average = mean(jumlah, banyakMahasiswa);
							sprintf(bufferAverage, "%.2f", average);
							
							printf("\n\t\t\t\t\t");
							printGaris('=', 40);
							printf("\t\t\t\t\t| %-20s | %-2s%-6s |\n", "Rata-rata nilai Mahasiswa", "", bufferAverage);
							printf("\t\t\t\t\t");
							printGaris('=', 40);
							printf("\n\t\t\t\t\t\tTabel Data Nilai");
							tabel_data(data, banyakMahasiswa);
							break;
						
						case(2):
							system("cls");
							ascending_sort(data, banyakMahasiswa);
							quartile_1 = quartile(data, 0, banyakMahasiswa/2 - 1);
							quartile_2 = quartile(data, 0, banyakMahasiswa - 1);
							quartile_3 = quartile(data, banyakMahasiswa/2, banyakMahasiswa/2 - 1);
							sprintf(bufferQuartile1, "%.2f", quartile_1);
							sprintf(bufferQuartile2, "%.2f", quartile_2);
							sprintf(bufferQuartile3, "%.2f", quartile_3);
							
							printf("\n\t\t\t\t\t");
							printGaris('=', 35);
							printf("\t\t\t\t\t| %-20s | %-2s%-6s |\n", "Kuartil Bawah (Q1)", "", bufferQuartile1);
							printf("\t\t\t\t\t");
							printGaris('-', 35);
							printf("\t\t\t\t\t| %-20s | %-2s%-6s |\n", "Median (Q2)", "", bufferQuartile2);
							printf("\t\t\t\t\t");
							printGaris('-', 35);
							printf("\t\t\t\t\t| %-20s | %-2s%-6s |\n", "Kuartil Atas (Q3)", "", bufferQuartile3);
							printf("\t\t\t\t\t");
							printGaris('=', 35);
							
							printf("\n\t\t\t\t\t\tTabel Data Nilai");
							tabel_data(data, banyakMahasiswa);
							printf("\n");
				
							break;
						
						case(3):
							mode(data, banyakMahasiswa);
							break;
						
						case(4):
							system("cls");
							printf("\n\t\t\t\tMasukkan angka untuk memilih menu Pengurutan: \n");
							printf("\n\t\t\t\t1. Ascending ");
							printf("\n\t\t\t\t2. Descending\n");
							printf("\n\t\t\t\tPilihan >\t");
							scanf("%d", &jenisSort);
							if(jenisSort == 1){
								ascending_sort(data, banyakMahasiswa);
								tabel_data(data, banyakMahasiswa);
							}
							else if(jenisSort == 2){
								descending_sort(data, banyakMahasiswa);
								tabel_data(data, banyakMahasiswa);
							}
						else
							printf("\n\t\t\t\tAngka yang anda pilih tidak ada di opsi: \n");
						break;
						
						case(5):
							system("cls");
							printf("\n\t\t\t\tMasukkan nilai mahasiswa yang ingin dilakukan searching >\t");
							scanf("%f", &nilai);
							ascending_sort(data, banyakMahasiswa);
							tabel_data(data, banyakMahasiswa);
							binary_search(data, banyakMahasiswa, nilai);
							break;
							
						case(6):
							system("cls");
							printf("\n\t\t\t\tMasukkan Angka Untuk Memilih Menu Binary Tree");
							printf("\n\t\t\t\t1. Postorder");
							printf("\n\t\t\t\t2. Inorder");
							printf("\n\t\t\t\t3. Preorder");
							printf("\n\t\t\t\tPilihan Anda >\t");
							scanf("%d", &binary);
							for(i = 0; i < banyakMahasiswa; i++){
								newNode(&root, data[i]);
							}
							switch(binary){
								case(1):
									system("cls");
									printf("\n\t\t\t\tPostoder Transversal : \n");
									printPostorder(root);
									break;
								case(2):
									system("cls");
									printf("\n\t\t\t\tInoder Transversal : \n");
									printInorder(root);
								case(3):
									system("cls");
									printf("\n\t\t\t\tPreoder Transversal : \n");
									printPreorder(root);
							}
							
						default://jika dipilih user diluar 4 opsi
							printf("\n\t\t\t\tMasukkan opsi angka yang tersedia\n");
    						Sleep(2000);
    						system("cls");
							break;
					}
				break;
				}
		
			case(4):
				system("cls");
				panduan();
				system("pause");
				system("cls");
				break;
				
			case(5):
				if(checker == 0){
					printf("\n\t\t\t\tUser belum memasukkan nilai!\n\n");
					break;
				}
				else if(checker == 1){
					system("cls");
					printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Antrian Vaksin COVID-19 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
					tabel_vaksin(data, banyakMahasiswa);
					break;
				}
			case(6):
				system("cls");
            	printf("\n\t\t\t\tTerima Kasih telah menggunakan program ini.\n");
            	delay();
            	delay();
            	exit(0);
            	
            default://jika dipilih user diluar 4 opsi
				printf("\n\t\t\t\tMasukkan opsi angka yang tersedia\n");
    			delay();
    			system("cls");
				break;
		}
	}
	return 0;		
}
