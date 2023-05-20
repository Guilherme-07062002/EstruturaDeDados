# Estrutura de Dados

Repositório contendo os códigos relacionadas a disciplina de Estrutura de Dados do 3° período de TSI.

## Executando

Foi criado para este repositório um shell script para automatizar o processo de execução e compilação de código, execute o seguinte comando:

```bash
./cmd
```

Será exibido no terminal um menu, conforme a imagem abaixo:

![texto](./imgs-readme/print1.png)

Depois apenas insira o número do algoritmo que deseje executar.

## Geração de tabelas

Neste código foi implementado um mecanismo que por meio da biblioteca **fstream** do C++, permite que os tempos de execução retornados, sejam persistidos em um arquivo .csv, este pode ser baixado e utilizado em alguma outra aplicação como o Excel para a análise dos dados. No entanto, caso o usuário deseje, no arquivo jupyter notebook localizado na pasta raiz deste projeto, existe um script em python que constroi os graficos com os dados retornados pela aplicação, por meio do arquivo .csv gerado. 

## Execução manual

Mas caso deseje fazer esse processo manualmente:


```bash
g++ <arquivo.cpp> -o <nome-executavel>
```

```bash
./<nome-do-executável>
```

## Algoritmos contidos neste repositório

### Ordenação

  1. Bubble Sort

  2. Selection Sort

  3. Insertion Sort

  4. Shell Sort

  5. Quick Sort

  6. Merge Sort

### Busca

  1. Linear Search
  
  1. Binary Search

