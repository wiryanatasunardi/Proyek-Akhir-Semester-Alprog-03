#ifndef fungsi
#define fungsi
#include "fungsi.c"

// num merupakan jumlah mahasiswa
void takeInput(char []);
void printGaris(char, int);
void tabel_data(DATA *data, int num);
void tabel_vaksin(DATA *data, int num);
void ascending_sort(DATA *data, int num);
void descending_sort(DATA *data, int num);
void delay();
void panduan();
void mode(DATA *data, int num);
void binary_search(DATA *data, int num, float number);
void newNode(NodePtr *nodePtr, DATA data);
void printPostorder(struct node* root);
void printInorder(struct node* root);
void printPreorder(struct node* root);
float sum(DATA *data, int num);
float mean(float sum, int num);
double quartile(DATA *data, int start, int end);

#endif
