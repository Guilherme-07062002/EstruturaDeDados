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

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Algoritmos

void bubbleSort(vector<int> lista)
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

void selectionSort(vector<int> lista)
{
    int n = lista.size();
    int aux;
    for (int menor = 0; menor < n; menor++)
    {
        for (int c = menor; c < n; c++)
        {
            if (lista[c] < lista[menor])
            {
                aux = lista[menor];
                lista[menor] = lista[c];
                lista[c] = aux;
            }
        }
    }
}

void insertionSort(vector<int> &lista)
{
    int n = lista.size();
    int aux;
    for (int i = 1; i < n; i++)
    {
        aux = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > aux)
        {
            lista[j + 1] = lista[j];
            j--;
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

vector<int> shellSort(vector<int> lista)
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

    //-------------------------------------------------------------------
    
    auto start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    bubbleSort(lista); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Bubble Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    //-------------------------------------------------------------------

    start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    selectionSort(lista); // executa o algoritmo que queremos medir o tempo

    end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Selection Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    //-------------------------------------------------------------------

    start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    insertionSort(lista); // executa o algoritmo que queremos medir o tempo

    end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Insertion Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    //-------------------------------------------------------------------

    start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    lista = shellSort(lista); // executa o algoritmo que queremos medir o tempo

    end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Shell Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    //-------------------------------------------------------------------

    start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    lista = quickSort(lista, 0, lista.size()); // executa o algoritmo que queremos medir o tempo

    end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Quick Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    //-------------------------------------------------------------------

    start = std::chrono::high_resolution_clock::now(); // marca o tempo de início

    mergeSort(lista, 0, lista.size() - 1); // executa o algoritmo que queremos medir o tempo

    end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

    diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Merge Sort: \n"
         << diff.count() / 1000 << " segundos \n"
         << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    return 0;
}