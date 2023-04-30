#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &lista){
    int n = lista.size();
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> lista){
    cout << "Insertion Sort: ";
    int n = lista.size();
    int aux = 0;
    for(int i = 0; i < (n - 1); i++){
        while(i >= 0 && lista[i + 1] < lista[i]){
            aux = lista[i];
            lista[i] = lista[i + 1];
            lista[i + 1] = aux;
            i--;
        }
    }
    printArray(lista);
}

int main(){
    vector<int> lista = {5, 4, 3, 2, 1};
    printArray(lista);
    insertionSort(lista);

    return 0;
}
