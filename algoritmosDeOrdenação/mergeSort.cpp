#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
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

    mergeSort(lista, 0, lista.size() - 1); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    std::chrono::duration<double> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término

    cout << "Para um array aleatório de tamanho " << tamanho << ":\n";
    std::cout << "Tempo de execucao do Insertion Sort: " << diff.count() << " segundos\n"; // exibe o tempo de execução

    return 0;
}