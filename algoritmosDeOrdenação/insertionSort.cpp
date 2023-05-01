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
    int n = lista.size();
    int aux;
    for(int i = 1; i < n; i++){
        for(int c = i; c > 0; c--){
            if(lista[c] < lista[c - 1]){
                aux = lista[c];
                lista[c] = lista[c - 1];
                lista[c - 1] = aux;
            }
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
