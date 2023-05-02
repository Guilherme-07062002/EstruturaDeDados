#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> lista){
    int n = lista.size();
    int aux;
    for(int i = 0; i < n; i++){
        for(int c = 0; c < (n - 1); c++){
            if(lista[c] > lista[c + 1]){
                aux = lista[c];
                lista[c] = lista[c + 1];
                lista[c + 1] = aux;
            }
        }
    }
    printArray(lista);
}

int main(){
    vector<int> lista = {5, 4, 3, 2, 1};
    printArray(lista);
    bubbleSort(lista);    

    return 0;
}
