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

void selectionSort(vector<int> &lista){
    cout << "Selection Sort: ";
    int n = lista.size();
    int aux = 0;

    for(int i = 0; i < n; i++){
        int menor = lista[i];
        for(int c = i; c < n; c++){
            if(lista[c] < menor){
                aux = lista[i];
                lista[i] = lista[c];
                lista[c] = aux;
            }        
        }
    }
    printArray(lista);

}

int main(){
    vector<int> lista = {1, 2, 3, 4, 5, 6, 7};
    printArray(lista);
    selectionSort(lista);

    return 0;
}
