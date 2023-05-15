# Shell Sort (Pseudocódigo)

```pseudocode
    função shellSort(vetor)
    inicio
        n <- tamanho do vetor

        para intervalo de n / 2 enquanto intervalo > 0 faça
            para i de intervalo ate n faça
                valor_atual <- vetor[i]

                para j de i enquanto j >= intervalo e lista[j - intervalo] >= valor_atual
                    trocar(lista[j], lista[j - intervalo])
                fim_para
            fim_para
        fim_para
    fim
```
