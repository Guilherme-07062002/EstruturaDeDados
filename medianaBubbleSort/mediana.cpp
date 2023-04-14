#include <iostream>

using namespace std;

int main(){
    int tamanho = 6;
    int lista[tamanho] = {5, 4, 3, 2, 1, 6};
    int auxiliar = 0;    
    
    // Ordenar elementos:
    for(int c = 0; c < tamanho; c++){
        for(int i = 0; i < tamanho; i++){
            if(lista[i] > lista[i + 1]){
                auxiliar = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = auxiliar;
            }
        }    
    }
    for(int c = 0; c < tamanho; c++){
        cout << lista[c] << " ";
    }
    cout << endl;
    int mediana = 0;
    // Checando se array tem um número par de elementos
    if(tamanho % 2 == 0){
        // Somando dois elementos que estão no meio e dividindo por dois
        mediana = (lista[(tamanho / 2)] + lista[(tamanho / 2) + 1]) / 2;
    }else{
        // Obtendo elemento que está no meio
        mediana = lista[(tamanho / 2)];
    }
    cout << "A mediana é: " << mediana << endl; 

}
