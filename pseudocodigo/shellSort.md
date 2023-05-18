# Shell Sort (Pseudocódigo)

```pseudocode
    função shellSort(vetor)
    inicio
        n <- tamanho vetor
        para intervalo de n/2 enquanto > 1 faça
            para i de intervalo ate n faça
                    para j de i ate n faça
                        se vetor[j] >= intervalo e vetor[j] < vetor[j - intervalo] então
                            troque(vetor[j], vetor[j - intervalo])
                        fim_se 
                    fim_para
            fim_para
            n/=2
        fim_para
    fim
```
