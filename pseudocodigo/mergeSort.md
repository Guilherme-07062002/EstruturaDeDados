# Merge Sort (Pseudocódigo)

```pseudocode
    função mergeSort(vetor)
        inicio
            se tamanho do vetor > 1 então
                meio <- tamanho do vetor / 2
                vetor_esquerda <- vetor[0 até meio - 1]
                vetor_direita <- vetor[meio até fim]
                
                mergeSort(vetor_esquerda)
                mergeSort(vetor_direita)
                merge(vetor_esquerda, vetor_direita, vetor)
            fim_se
        fim

    função merge(vetor_esquerda, vetor_direita, vetor)
        inicio
            i <- j <- k <- 0
            
            enquanto i < tamanho do vetor_esquerda e j < tamanho do vetor_direita faça
                se vetor_esquerda[i] < vetor_direita[j] então
                    vetor[k] <- vetor_esquerda[i]
                    i <- i + 1
                senão
                    vetor[k] <- vetor_direita[j]
                    j <- j + 1
                fim_se
                k <- k + 1
                
            enquanto i < tamanho do vetor_esquerda faça
                vetor[k] <- vetor_esquerda[i]
                i <- i + 1
                k <- k + 1
            
            enquanto j < tamanho do vetor_direita faça
                vetor[k] <- vetor_direita[j]
                j <- j + 1
                k <- k + 1
        fim
```
