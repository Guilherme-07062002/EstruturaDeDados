#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(vector<int> &v, int low, int high){
	/*
		Parameters:
		v = input array to be ordered
		low = left index
		high = right index
	*/
	int pivot = v[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i + 1], &v[high]);
	return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
	if (low < high) { 
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
    
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    quickSort(arr, 0, n-1);
    printArray(arr);

    return 0;
}