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
    for(int i = 0; i < n; i++){
        for(int c = i; c < n; c++){
            for(int d = c; d > 0; d--){
                if(lista[d - 1] > lista[d]){
                    aux = lista[d - 1];
                    lista[d - 1] = lista[d];
                    lista[d] = aux;
                }
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
