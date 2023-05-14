#include <iostream>
#include <chrono>

using namespace std;

int main(){
    // Armazena tempo do início da execução
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Olá mundo" << endl;

    // Armazena tempo do fim da execução
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a diferença de tempo entre início e fim e converte em segundos.
    std::chrono::duration<double , std::milli> diff = end - start;

    // Exibe no terminal
    std::cout << "Tempo de execução: " << diff.count() << " milissegundos\n";
    
    return 0;
}
