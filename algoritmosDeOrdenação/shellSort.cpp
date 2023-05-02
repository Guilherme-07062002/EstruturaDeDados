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

// Comentários baseando-se no array [5 ,4 ,3 ,2, 1] 
void shellSort(vector<int> lista){
    // Tamanho do array = 5
    int tamanho = lista.size();
    // Loop que realiza a divisão consecutiva do intervalo por 2
    // A váriavel é inicializada com o valor 2 pois a parte inteira de tamanho( que é 5) / 2 = 2
    for(int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2){
        // Loop que inicia-se apartir do intervalo (2) até o ultimo indice do array (4)
        for(int i = intervalo; i < tamanho; i++){
            // Valor atual na primeira execução lista[i], sendo i = intervalo então
            // valor_atual = 3
            int valor_atual = lista[i];
            // Este loop realiza a comparação consecutiva do valor atual com o elemento que está a um intervalo de distância.
            // j inicia no indice do elemento atual que no caso possui valor 3, portanto j = 2
            // Ele checa se j é maior ou igual que o intervalo para que seja possivel realizar a comparação
            // Em seguida checa também se o elemento que está 2 indíces atrás é maior que o valor atual
            // Se sim o bloco de código que está contido no for é executado
            // E será realizada a troca, o elemento atual irá para o local do elemento a um intervalo de distância dele.
            for(int j = i; j >= intervalo && lista[j - intervalo] > valor_atual; j-=intervalo){
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