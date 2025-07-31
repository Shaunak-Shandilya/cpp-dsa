//BUBBLE SORT

//INSERTION SORT
/*
time & space complexity = O(n^2)
adaptive
stable
better performance on linked list than on array
*/
void insertionsort(int *arr, int size) {
	//int* arr = (int*)malloc(size * sizeof(int));
	//int* arr = new int[size];
	int i, j, x;

	for (i = 1; i < size; i++) {
		j = i - 1;
		x = arr[i];
		while (j > -1 && arr[j] > x) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1];
	}
}

//SELECTION SORT
/*
time and space complexity O(n^2)
not stable (original order of duplicates is lost), not adaptive
*/

void selectionsort(int *arr, int size) {
	int i,j,k;
	for (i = 0; i < size-1; i++) {
		for (j = k = i; j < size; j++) {
			if (arr[j] < arr[k]) {
				k = j;
			}
			std::swap(arr[i], arr[k]);
		}
	}
}
