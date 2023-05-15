# Insertion Sort (Pseudocódigo)

```pseudocode
função insertionSort(vetor)
inicio
    n <- tamanho do vetor

    para i de 1 ate n faça
        para j de i ate 1 faça
            se vetor[j] < vetor[j - 1]
                trocar(vetor[j], vetor[j - 1])
            fim_se
        fim_para
    fim_para
fim
```
