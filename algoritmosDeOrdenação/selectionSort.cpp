#include <iostream>
#include <vector>
#include <random>
#include <chrono>


using namespace std;

void printArray(vector<int> &lista){
    int n = lista.size();
    for(int i = 0; i < n; i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

vector<int> selectionSort(vector<int> lista){
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
    return lista;
}

int main(){
      // Cria um gerador de números aleatórios usando um valor de semente fixo
    std::mt19937 rng(1234);

    // Cria uma distribuição uniforme no intervalo [0, 99]
    std::uniform_int_distribution<int> dist(0, 99);

    vector<int> lista;

    for(int i = 0; i < 10; i++){
        int rand_num = dist(rng);
        lista.push_back(rand_num);
    }
    printArray(lista);

    auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    lista = selectionSort(lista); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    std::chrono::duration<double , std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término
    printArray(lista);

    std::cout << "Tempo de execucao do Selection Sort: " << diff.count() << " milissegundos\n"; // exibe o tempo de execução

    return 0;
}
