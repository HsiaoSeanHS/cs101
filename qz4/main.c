#include <stdio.h>
#include <stdlib.h>

void swap(int* n, int* m) {
	int temp = *n;
	*n = *m;
	*m = temp;
}

void swapArray(int sourse[], int dest[], int size) {
	for(int i = 0; i < size; i++) {
		int temp = sourse[i];
		sourse[i] = dest[i];
		dest[i] = temp;
	}
}

void printArray(int array[], int size) {
	for(int i = 0; i < size; i++) {
		if(i == size - 1) {
			printf("%d]\n", array[i]);
		} else {
			printf("%d, ", array[i]);
		}
	}
}

char* copy_string(char* s) {
	int size = 0;
	while(s[size++]);
	char* cp_str = (char*)calloc(size, sizeof(char));
	for(int i = 0; i < size - 1; i++) {
		cp_str[i] = s[i];
	}
	cp_str[size] = '\0';
	return cp_str;
}

int main(void) {
	printf("No.1 -------------------\n");
	int n, m;
	n = 1;
	m = 2;
	swap(&n, &m);
	printf("after swap, n = %d, m = %d\n", n, m);

	printf("No.2 -------------------\n");
	int size = 10;
	int sourse[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	swapArray(sourse, dest,size);
	printf("after swap array, sourse array = [");
	printArray(sourse, size);
	printf("after swap array, dest array = [");
	printArray(dest, size);

	printf("No.3 -------------------\n");
	char str[] = "IU!IU!IU!IU!";
	char* cp_str = copy_string(str);
	printf("copy string = %s\n", cp_str);
	free(cp_str);
	return 0;
}
