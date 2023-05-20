#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void printArray(vector<int> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl;
}

vector<int> bubbleSort(vector<int> lista)
{
    int n = lista.size();
    int aux;
    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c < (n - 1); c++)
        {
            if (lista[c] > lista[c + 1])
            {
                aux = lista[c];
                lista[c] = lista[c + 1];
                lista[c + 1] = aux;
            }
        }
    }
    return lista;
}

int main()
{
    // Cria um gerador de números aleatórios usando um valor de semente fixo
    std::mt19937 rng(1234);

    // Cria uma distribuição uniforme no intervalo [0, 99]
    std::uniform_int_distribution<int> dist(0, 99);

    vector<int> lista;

    int tamanho;
    cout << "Tamanho do array: ";
    cin >> tamanho;

    for (int i = 0; i < tamanho; i++)
    {
        int rand_num = dist(rng);
        lista.push_back(rand_num);
    }

    auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    bubbleSort(lista); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Bubble Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    return 0;
}
