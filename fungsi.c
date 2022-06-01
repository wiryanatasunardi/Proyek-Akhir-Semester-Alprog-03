#include <stdio.h>
#include <time.h>
#include <string.h>
#include "fungsi.h"

typedef struct {
	char nama[50];
	float nilai;
	char npm[15];
} DATA;

struct node {
	char nama[50];
	float nilai;
	char npm[15];
	int urutan;
	struct node * next;
	struct node * left;
	struct node * right;
};

struct node *head = NULL;
struct node * iteratorPtr;
typedef struct node Node;
typedef Node *NodePtr;

void newNode(NodePtr *nodePtr, DATA data)
{
	if(*nodePtr == NULL){
		*nodePtr = malloc(sizeof(struct node));
		if(*nodePtr != NULL){
			strcpy((*nodePtr)->nama, data.nama);
			strcpy((*nodePtr)->npm, data.npm);
    		(*nodePtr)->nilai = data.nilai;
    		(*nodePtr)->left = NULL;
    		(*nodePtr)->right = NULL;
		}
		else{
			printf( "%.2f tidak dimasukkan. tidak tersedia memori.\n", data.nilai );
		}
	}
	
	else{
		if(data.nilai < (*nodePtr)->nilai){
			newNode(&((*nodePtr)->left), data);
		}
		else if(data.nilai > (*nodePtr)->nilai){
			newNode(&((*nodePtr)->right), data);
		}
		else{
			printf("dup");
		}
	}
}

struct node* push(struct node* head, DATA data) {
	// Membuat node baru
    struct node *next_node = malloc(sizeof(struct node));
	
	strcpy(next_node->nama, data.nama);
	strcpy(next_node->npm, data.npm);
    next_node->nilai = data.nilai;
    next_node->next = NULL;

    struct node *curr = head;
    if (curr == NULL) {
        head = next_node;
    } else {
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = next_node;
    }
    return head;
}
 
struct node* deleteNode(struct node *head, char nama[50]) {

    struct node *temp = head;
    struct node *prev;
    
    if (temp != NULL && (strcmp(temp->nama, nama) == 0))  {
        head = temp->next;
        free(temp);
        return head;
    }
    
    while (temp != NULL && (strcmp(temp->nama, nama) < 0)) {
        prev = temp;
        temp = temp->next;

    }

	if((strcmp(prev->nama, nama)< 0)) {
		printf("\n\t\t\t\t[ERROR] Nama yang anda masukkan tidak ada dalam list\n");	
		return head;
	}
    if (temp == NULL){
    	printf("bbbb");
    	return NULL;
	}
	printf("cccc");
    prev->next = temp->next;    
    free(temp);
    
    return head;

}

void takeInput(char ch[50]) {
    fflush(stdin);
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

void printGaris(char symbol, int banyakGaris) {
	int i;
	
	for(i = 0; i < banyakGaris; i++) {
		printf("%c", symbol);
	}
	printf("\n");
}

void tabel_data(DATA *data, int num){
	int i;
	char bufferNilai[5];
	
	printf("\n\t\t\t");
	printGaris('=', 80);
	printf("\t\t\t| %-3s| %-35s| %-12s| %-21s|\n", "No","            Nama", "    NPM", "       Nilai");
	printf("\t\t\t");
	printGaris('-', 80);
	for(i = 0; i < num; i++){
		sprintf (bufferNilai, "%.2f", data[i].nilai);
		printf("\t\t\t| %-3d| %-35s| %-12s| %-7s%-14s|\n", i+1 ,data[i].nama, data[i].npm, "", bufferNilai);
	}
	printf("\t\t\t");
	printGaris('=', 80);
	printf("\n");
}

void tabel_data_linkedlist(struct node *head, struct node *iteratorPtr){
	char bufferNilai[5];
	
	if(head != NULL){
		printf("\n\t\t\t");
		printGaris('=', 80);
		printf("\t\t\t| %-7s| %-31s| %-12s| %-21s|\n", "Alamat","            Nama", "    NPM", "       Nilai");
		printf("\t\t\t");
		printGaris('-', 80);
		
		iteratorPtr = head;
		
		while(iteratorPtr != NULL){
			sprintf (bufferNilai, "%.2f", iteratorPtr->nilai);
			printf("\t\t\t| %-7x| %-31s| %-12s| %-7s%-14s|\n", iteratorPtr,iteratorPtr->nama, iteratorPtr->npm, "", bufferNilai);
			iteratorPtr = iteratorPtr->next;
		}
		printf("\t\t\t");
		printGaris('=', 80);
		printf("\n");
		} else{
			printf("\t\t\t");
			printGaris('=', 80);
			printf("\t\t\t| %-32s %-44s|\n", " ", "List Kosong");
			printf("\t\t\t");
			printGaris('=', 80);
			printf("\n");
		}	
	

}

void tabel_vaksin(DATA *data, int num){
	int i;

	printf("\n\t\t\t");
	printGaris('=', 80);
	printf("\t\t\t| %-3s| %-35s| %-12s| %-16s|\n", "No","            Nama", "    NPM", "	Vaksin");
	printf("\t\t\t");
	printGaris('-', 80);
	for(i = 0; i < num; i++){
		printf("\t\t\t| %-3d| %-35s| %-12s|%-16s|\n", i+1 ,data[i].nama, data[i].npm, "	Pfizer");
	}
	printf("\t\t\t");
	printGaris('=', 80);
	printf("\n");
}

void ascending_sort(DATA *data, int num){
	int k, count;
	DATA temp;
	for(count = 1; count < num; count++){
		for(k = 0; k < num - 1; k++){
			if(data[k].nilai>data[k+1].nilai){
				temp = data[k];
				data[k] = data[k+1];
				data[k+1] = temp;
			}
		}
	}
}

void descending_sort(DATA *data, int num){
	int i, j; 
	DATA temp;
	for(i=0; i < num; ++i){
		for(j = i + 1; j < num; ++j){
			if(data[i].nilai < data[j].nilai){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}

void delay(){
	int milli_seconds = 1000 * 1; // Mengkonversi Waktu Menjadi milli_sekon
    clock_t start_time = clock(); // Menyimpan Waktu Ketika Dimulai
    while (clock() < start_time + milli_seconds); // Melakukan Loop Hingga Waktu Tujuan Belum Tercapai
}

void mode(DATA *data, int num){
	int i, j, mode, count, max = 0;
	for(i=0; i < num-1; i++){
		count = 0;
		for(j = i + 1; j < num; j++){
			if(data[i].nilai == data[j].nilai){
				count++;
			}
		}
		if(count > max && count != 0){
			max = count;
			mode = data[i].nilai;
		}
	}
	if(max==0){
		printf("\n\t\t\t\tTidak ada modus dalam data ini\n\n");
	}
	else{
		printf("\n\t\t\t\tModus dari data mahasiswa adalah %d\n\n", mode);
	}
}

float sum(DATA *data, int num){ 
	if(num <= 0){
		return 0;
	}
	return data[num-1].nilai + sum(data, num-1);
}

double quartile(DATA *data, int start, int end){
	double med;
	int len = end-start + 1;
	if(len%2==0){
		med = ( (data[start + len/2 -1].nilai + data[start+len/2].nilai) / 2.0);
	}
	else{
		med = (data[start+len/2].nilai/ 1.0);
	}
	return med;
}

float mean(float sum, int num){
	float avg;
	avg = sum/num;
	
	return avg;
}

void panduan(){
	printf("Terdapat 4 menu yang tersedia dari program ini, yaitu:\n");
	printf("1. Input Data\n2. Statistik Kelas\n3. Panduan\n4. Keluar\n");
	printf("Pilih 1 untuk menginput nilai mahasiswa\n");
	printf("Pilih 2 untuk melihat statistik kelas\n");
	printf("Pilih 4 untuk melihat antrian vaksin COVID-19\n\n");
}

void binary_search(DATA *data, int num, float number){
	int first, last, middle;
	first = 0;
	last = num-1;
	middle = (first + last)/2;
	
	while (first <= last) {
    	if (data[middle].nilai < number){
      		first = middle + 1;
      	}
    	else if (data[middle].nilai == number) {
      		printf("\n\n\t\t\t\tMahasiswa dengan nilai %.2f terdapat pada database dengan nama mahasiswa %s ", number, data[middle].nama);
      		break;
    	}
    	else{
      		last = middle - 1;
		}
    	middle = (first + last)/2;
  	}
  	if (first > last){
    	printf("\n\n\t\t\t\tMahasiswa dengan nilai %.2f, tidak terdapat pada database", number);
	}
}

void printPostorder(struct node* root)
{
    if (root != NULL){
    	printPostorder(root->left);
    	printPostorder(root->right);
    	printf("%.3f ", root->nilai);
	}
}

void printPreorder(struct node* root)
{
    if (root != NULL){
    	printf("%.3f ", root->nilai);
    	printPreorder(root->left);
    	printPreorder(root->right);
	}
}

void printInorder(struct node* root)
{
    if (root != NULL){
    	printInorder(root->left);
    	printf("%.3f ", root->nilai);
    	printInorder(root->right);
	}
}
