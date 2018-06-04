// https://www.hackerearth.com/practice/algorithms/searching/binary-search/tutorial/

#include <stdio.h>

void bubble_sort(int array[], int array_length) {
    int temp;
    
    for (int i=0; i < array_length-1; i++) {
        for (int j=0; j < array_length-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int binary_search(int array[], int array_length, int key) {
    int low = 0;
    int high = array_length - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key < array[mid]) {
            high = mid-1;
        } else if (key > array[mid]) {
            low = mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(){
	int array_length, query_count, key, array[100000];
	
	scanf("%d", &array_length);
    
	for (int i=0; i<array_length; i++) {
	    scanf("%d", &array[i]);
	}
	
	bubble_sort(array, array_length);
	
	scanf("%d", &query_count);
	
	for (int i=0; i<query_count; i++) {
	    scanf("%d", &key);
	    printf("%d\n", binary_search(array, array_length, key) + 1); // array is 1 indexed
	}
}
