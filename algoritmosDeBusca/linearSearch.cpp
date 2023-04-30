#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int> &lista, int elemento){
    for(int i = 0; i < lista.size(); i++){
        if(elemento == lista[i]){         
            return i;
        }        
    } 
    return -1;
    
}
int main(){
    vector<int> lista = {1, 2, 3, 4, 5};
    int elemento = 3;
    int resultado = linearSearch(lista, elemento);

    if(resultado != -1){
        cout << "O valor "<< elemento << " foi encontrado na posição " <<  resultado << " do array." << endl;
    }else{
        cout << "Valor não encontrado." << endl;    
    }

    return 0;
}
