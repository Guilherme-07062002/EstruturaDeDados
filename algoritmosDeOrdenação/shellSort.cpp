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

void shellSort(vector<int> lista){
    int tamanho = lista.size();
    for(int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2){
        for(int i = intervalo; i < tamanho; i++){
            int valor_atual = lista[i];
            for(int j = i; j >= intervalo && lista[j - intervalo] > valor_atual; j-= intervalo){
                lista[j] = lista[j - intervalo];
                lista[j - intervalo] = valor_atual;
            }
        }
    }
    printArray(lista);
}

int main(){
    vector<int> lista = {5, 4, 3, 2, 1};
    printArray(lista);
    shellSort(lista);

    return 0;
}