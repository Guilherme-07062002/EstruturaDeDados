# Selection Sort (Pseudocódigo)

```pseudocode
função selectionSort(vetor)
inicio
    n <- tamanho do vetor

    para i de 0 ate n faça
        menor <- i
        para j de i ate n faça
            se vetor[j] < vetor[menor]
                trocar(vetor[menor], vetor[j])
            fim_se
        fim_para
    fim_para

fim
```
