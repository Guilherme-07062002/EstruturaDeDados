#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

void printArray(vector<int> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Algoritmos

void bubbleSort(vector<int> &lista)
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
}

void selectionSort(vector<int> &lista)
{
    int n = lista.size();
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (lista[j] < lista[menor])
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            swap(lista[i], lista[menor]);
        }
    }
}
void insertionSort(vector<int> &lista)
{
    int n = lista.size();
    for (int i = 1; i < n; ++i)
    {
        int aux = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > aux)
        {
            lista[j + 1] = lista[j];
            --j;
        }
        lista[j + 1] = aux;
    }
}

// Quick Sort

int partition(vector<int> &v, int low, int high)
{
    /*
        Parameters:
        v = input array to be ordered
        low = left index
        high = right index
    */
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

vector<int> quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
    return v;
}

vector<int> shellSort(vector<int> &lista)
{

    int tamanho = lista.size();

    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2)
    {
        for (int i = intervalo; i < tamanho; i++)
        {
            int valor_atual = lista[i];
            for (int j = i; j >= intervalo && lista[j - intervalo] > valor_atual; j -= intervalo)
            {
                lista[j] = lista[j - intervalo];
                lista[j - intervalo] = valor_atual;
            }
        }
    }
    return lista;
}

void merge(vector<int> &arr, int l, int m, int r)
{
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

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    // Gerador de números aleatórios usando um valor de semente fixo
    std::mt19937 rng(1234);

    // Cria uma distribuição uniforme no intervalo de 0 a 1000
    std::uniform_int_distribution<int> dist(0, 1000);

    // Vetor de tamanhos dos arrays
    vector<int> tamanhos = {100, 1000, 10000, 100000};
    vector<vector<int>> vetores;         // Vetor de vetores
    vector<vector<int>> vetoresOriginal; // Cópia do vetor de vetores

    for (const auto &tamanho : tamanhos)
    {
        vector<int> lista(tamanho);

        // Preenchendo vetor com números aleatórios
        for (int i = 0; i < tamanho; i++)
        {
            int rand_num = dist(rng);
            lista[i] = rand_num;
        }

        vetores.push_back(lista); // Adiciona uma cópia do vetor `lista` ao vetor `vetores`
    }
    vetoresOriginal = vetores;

    // Vetor de algoritmos de ordenação
    vector<string> algoritmos = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Shell Sort", "Quick Sort", "Merge Sort"};

    // Grava os dados de tempo de execução em um arquivo CSV
    ofstream arquivo("tempos_execucao.csv");
    arquivo << "Algoritmo,Tamanho do Array,Tempo de Execucao (ms)\n";

    int c = 0;

    //-------------------------------------------------------------------
    for (const auto &algoritmo : algoritmos)
    {
        c = 0; // Reinicializa o valor de `c` para cada algoritmo

        for (const auto &tamanho : tamanhos)
        {

            vetores[c] = vetoresOriginal[c];

            cout << "-----------------------------------------------" << endl;
            cout << "Tamanho do array: " << tamanho << endl;

            if (algoritmo == "Bubble Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                bubbleSort(vetores[c]); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Bubble Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }
            else if (algoritmo == "Selection Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                selectionSort(vetores[c]); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Selection Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }

            else if (algoritmo == "Insertion Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                insertionSort(vetores[c]); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Insertion Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }

            else if (algoritmo == "Shell Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                shellSort(vetores[c]); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Shell Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }

            else if (algoritmo == "Quick Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                quickSort(vetores[c], 0, vetores[c].size() - 1); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Quick Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }

            else if (algoritmo == "Merge Sort")
            {

                //-------------------------------------------------------------------

                auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

                mergeSort(vetores[c], 0, vetores[c].size() - 1); // executa o algoritmo que queremos medir o tempo

                auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

                std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

                cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
                cout << "Tempo de execucao do Merge Sort: \n"
                     << diff.count() / 1000 << " segundos \n"
                     << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

                arquivo << algoritmo << "," << tamanho << "," << fmod(diff.count(), 1000) << "\n"; // grava os dados no arquivo
            }
            c++;
        }
    }
    arquivo.close();

    return 0;
}