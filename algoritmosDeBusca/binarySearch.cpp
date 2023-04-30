#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> lista, int elemento){
    int left = 0;
    int right = lista.size() -1;
    int mid = 0;

    while(left <= right){
        mid = (left + right) / 2;
        if(lista[mid] == elemento){
            return mid;
        }else if(lista[mid] < elemento){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

return -1;
}

int main(){
    vector<int> lista = {5, 6, 7, 8};
    int elemento = 10;
    int resultado = binarySearch(lista, elemento);

    if(resultado != -1){
        cout << "O valor " << elemento << " foi encontrado na posição " << resultado << endl;
    }else{
        cout << "Valor não encontrado." << endl;
    }

    return 0;
}
