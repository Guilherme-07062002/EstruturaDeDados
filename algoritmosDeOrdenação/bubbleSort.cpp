#include <iostream>
#include <vector>

using namespace std;

void printLista(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

vector<int> binarySearch(vector<int> lista){
    int auxiliar = 0;
    int n = lista.size();
    for(int i = 0; i < n - 1; i++){
        for(int c = 0; c < n - i - 1; c++){
            if(lista[c] > lista[c + 1]){
                auxiliar = lista[c + 1];
                lista[c + 1] = lista[c];
                lista[c] = auxiliar;
            }        
        }
    }

    return lista;
}

int main(){
    vector<int> lista = {5, 4, 3, 2, 1};
    printLista(binarySearch(lista));    

    return 0;
}
