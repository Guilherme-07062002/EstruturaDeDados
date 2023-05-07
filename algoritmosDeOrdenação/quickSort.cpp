#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void printArray(vector<int> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << " ";
    }
    cout << endl;
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(vector<int> &v, int low, int high){
	/*
		Parameters:
		v = input array to be ordered
		low = left index
		high = right index
	*/
	int pivot = v[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (v[j] < pivot) {
			i++;
			swap(&v[i], &v[j]);
		}
	}
	swap(&v[i + 1], &v[high]);
	return (i + 1);
}


vector<int> quickSort(vector<int> &v, int low, int high){
	if (low < high) { 
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
	}
	return v;
    
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

    lista = quickSort(lista, 0, lista.size()); // executa o algoritmo que queremos medir o tempo

    auto end = std::chrono::high_resolution_clock::now(); // marca o tempo de término

   	std::chrono::duration<double, std::milli> diff = end - start; // calcula a diferença entre o tempo de início e o tempo de término em milissegundos

    cout << "\nPara um array aleatório de tamanho " << tamanho << endl;
    cout << "Tempo de execucao do Quick Sort: \n" << diff.count() / 1000 << " segundos \n" << fmod(diff.count(), 1000) << " milissegundos\n"; // exibe o tempo de execução em segundos e milissegundos

    return 0;
}