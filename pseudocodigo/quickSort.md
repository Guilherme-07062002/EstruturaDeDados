# Quick Sort (Pseudocódigo)

```pseudocode
    função quickSort(vetor, esquerda, direita)
    inicio
        se esquerda < direita então
            pivot <- particionar(vetor, esquerda, direita)
            quickSort(vetor, esquerda, pivot - 1)
            quickSort(vetor, pivot + 1, direita)
        fim_se
    fim

    função particionar(vetor, esquerda, direita)
    inicio
        pivot <- vetor[direita]
        i <- esquerda - 1

        para j de esquerda ate direita - 1 faça
            se vetor[j] < pivot
                i <- i + 1
                trocar(vetor[i], vetor[j])
            fim_se
        fim_para

        trocar(vetor[i], vetor[direita])
        retornar i + 1
    fim
```
