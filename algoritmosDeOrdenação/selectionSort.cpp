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

void selectionSort(vector<int> lista){
    int n = lista.size();
    int aux;
    for(int menor = 0; menor < n; menor++){
        for(int c = menor; c < n; c++){
            if(lista[c] < lista[menor]){
                aux = lista[menor];
                lista[menor] = lista[c];
                lista[c] = aux;
            }
        }
    }
    printArray(lista);
}

int main(){
    vector<int> lista = {5, 4, 3, 2, 1};
    printArray(lista);
    selectionSort(lista);

    return 0;
}
