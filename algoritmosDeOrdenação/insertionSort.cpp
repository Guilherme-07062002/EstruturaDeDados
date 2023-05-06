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

vector<int> insertionSort(vector<int> lista){
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
    return lista;
}

int main(){
     // Cria um gerador de números aleatórios usando um valor de semente fixo
    std::mt19937 rng(1234);

    // Cria uma distribuição uniforme no intervalo [0, 99]
    std::uniform_int_distribution<int> dist(0, 99);

    vector<int> lista;

    int tamanho;
    cout << "Tamanho do array: ";
    cin >> tamanho;

    for(int i = 0; i < tamanho; i++){
        int rand_num = dist(rng);
        lista.push_back(rand_num);
    }

    auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    insertionSort(lista); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    std::chrono::duration<double> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término

    cout << "Para um array aleatório de tamanho " << tamanho << ":\n";
    std::cout << "Tempo de execucao do Insertion Sort: " << diff.count() << " segundos\n"; // exibe o tempo de execução

    return 0;
}
