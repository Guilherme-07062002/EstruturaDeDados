### Estrutura de Dados
<p>Repositório com códigos e anotações relacionadas a disciplina de Estrutura de Dados 3° Período.</p>

#### Compilar código
```
$  g++ <nome-do-arquivo.cpp> -o <nome-para-o-executável>
```
#### Executar
```
$  ./<nome-do-executável>
```

### Algoritmos presentes até então neste repositório
#### Ordenação
<ol>
  <li><b>Bubble Sort</b></li>
  <p>Realiza-se a comparação do elemento atual com o seu sucessor, realizando a troca caso o antecessor seja maior que o que vem em seguida.</p>
  <li><b>Selection Sort</b></li>
  <p>Busca-se o menor elemento do conjunto, inserindo-o no início da lista, esse processo é feito (n - 1) vezes, sendo n o comprimento do array</p>
  <li><b>Insertion Sort</b></li>
  <p>De certa forma semelhante o bubble sort, a diferença é que ele realiza comparações consecutivas, checando se o valor atual é menor que cada elemento
  anterior a ele na lista.</p>
  <li><b>Shell Sort</b></li>
  <p>Primeiramente é obtido o 'gap', que consiste em (n / 2), aonde n é o tamanho do array, em seguida é realizado a comparação entre o elemento atual e o elemento que está a um gap de distância do mesmo, depois que essa checagem é feita em toda a lista, reinicia-se novamente o processo dividindo novamente o valor de gap por 2 dessa forma gap = ((n / 2) / 2) ou (n / 4), esse processo é repetido quantas vezes for necessário até que em determinado momento gap seja 1, e a lista for ordenada.</p>
</ol>

#### Busca
<ol>
  <li><b>Linear Search</b></li>
  <p>Algoritmo primitivos de busca, percorre cada elemento da lista e retorna o indíce que armazena o valor desejado.</p>
  <li><b>Binary Search</b></li>
  <p>"Dividir para conquistar" Divide a lista pela metade, checando se o valor está na metade da esquerda ou da direita, dessa forma economizando muitos
  passos em relação a busca linear.</p>
</ol>
