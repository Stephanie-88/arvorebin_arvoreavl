# arvorebin_arvoreavl
 Trabalho de 2VA estrutura de dados II
 
Faça um programa que leia um arquivo texto (no formato .txt) e imprima, em ordem alfabética, as palavras e a suas frequências no texto. A leitura do arquivo deverá desprezar espaços em branco e sinais de pontuação, que serão considerados separadores de palavras. O texto deverá estar em minúsculo.

A pesquisa e inserção das palavras do texto deverão ser implementadas com as estruturas de:

1. Árvore Binária de Pesquisa sem balanceamento e

2. Árvore Binária de Pesquisa com balanceamento (Árvore AVL).

Coloque contadores no seu programa para determinar o número de comparações de chaves e o número de registros de cada palavra necessárias para montar a tabela de frequências em cada uma das estruturas acima. Conte apenas o número de comparações para montar a estrutura (operações de inserir e pesquisar). Você não deve considerar as operações na fase de impressão ordenada.

Entrada

A entrada de dados será um arquivo de texto contendo um texto qualquer. O arquivo texto deverá usar a codificação UTF-8. Seu algoritmo receberá o nome do arquivo texto a ser lido como parâmetro e também o tipo da estrutura (1 ou 2) a ser utilizada para impressão das frequências.

Saída

Deverá ser impresso na tela um resumo completo da execução para todas as duas estruturas implementadas. Deve ser impresso a quantidade de comparação em cada uma das estruturas. Em seguida, as frequências de cada palavra devem ser impressas. Para esta impressão, deverá ser utilizada a estrutura indicada pelo parâmetro passado na linha de comando.
