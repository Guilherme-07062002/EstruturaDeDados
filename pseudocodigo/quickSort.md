# Quick Sort (Pseudocódigo)

```pseudocode
    função quickSort(vetor, left, right)
    inicio
        se left < right então
            pivot <= particionar(vetor, left, right)
            quickSort(vetor, pivot + 1, right)
            quickSort(vetor, left, pivot - 1)
        fim_se

        retorne vetor
    fim

    função particionar(vetor, left, right)
    inicio
        pivot <- right
        i <- (left - 1)
        para j de left ate (right - 1) faça
            se vetor[j] < vetor[pivot] então
                i += 1
                troque(vetor[j], vetor[i])
            fim_se
        fim_para 
        troque(vetor[pivot], vetor[i + 1])

        retorne i + 1;
    fim
```
