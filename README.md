# ExpressionTree

**Árvores de expressões aritméticas - Trabalho final de estrutura de dados 2**

### UNIVERSIDADE FEDERAL DO PARANÁ
*SETOR DE EDUCAÇÃO PROFISSIONAL E TECNOLÓGICA*

*TECNOLOGIA EM ANÁLISE E DESENVOLVIMENTO DE SISTEMAS*

*ESTRUTURA DE DADOS II*

*PROF. ME. ANDREIA DE JESUS*


**Postagem do Trabalho no Moodle – até às 23h59 do dia 29/06/2020 (segunda);
Valor do trabalho 100; 
peso na média da disciplina 20%.**

**Etapa 1: Árvores de expressões aritméticas (50 pontos):**

*Vamos considerar um certo conjunto de operadores binários, por exemplo + (soma), -(subtração), * (multiplicação), / (divisão) e ^ (exponenciação). Estes operadores são
chamados **binários** porque operam sobre dois números (os operandos) para produzir um terceiro número (o resultado). Por exemplo, na subtração A - B, A e B são os operandos
do operador subtração. A é o operando esquerdo e B é o operando direito. Uma tal operação pode ser representada pela árvore abaixo. Note que neste caso é
importantíssimo distinguir entre o **filho direito** e o **filho esquerdo**, pois em geral A – B e B – A são diferentes!*

![arv1](https://user-images.githubusercontent.com/59929856/87487047-093ea480-c613-11ea-9ef9-80eb8ad2464e.jpg)

*Qualquer expressão aritmética com os cinco operadores binários acima pode ser representada por uma árvore estritamente binária em que os nós internos são operadores
e os nós terminais são os operandos (isto é, os números e as variáveis). A figura abaixo mostra alguns exemplos.*

![arv2](https://user-images.githubusercontent.com/59929856/87487051-0c399500-c613-11ea-9ff6-a2e41ced9cb4.jpg)

 **O operador de menor prioridade aparece na raiz. Operandos sempre aparecem como folhas, operadores nunca.** 

*As expressões aritméticas acima conduziram a árvores estritamente binárias porque usamos somente operadores binários. Em expressões aritméticas, no entanto, podem
surgir também operadores unários, isto é, operadores que atuam sobre um único número. Um exemplo de um tal operador é o sinal de menos unário, que aparece quando
queremos expressar um número negativo, como -3 ou o oposto de uma variável, como -x. Outro exemplo são as funções de uma variável, como o logaritmo log(x), a raiz
quadrada sqrt(x), etc que podem ser visto como um operador unário (a função) atuando sobre o operando x (o argumento da função). Abaixo são ilustradas árvores binárias,
mas não estritamente binárias, que surgem quando incluímos estes operadores:*

![arv3](https://user-images.githubusercontent.com/59929856/87487063-0f348580-c613-11ea-91b7-9b8e3379a432.jpg)

*As expressões aritméticas podem ser representadas de 3 formas:*

• *Préfixa (+AB): o operador precede os dois operandos. (Esta notação também é
chamada de Polonesa)*

• *Posfixa (AB+): o operador é introduzido depois dos dois operandos. (Esta
notação também é chamada de Polonesa Reversa)*

• *Infixa (A+B): o operador aparece entre os dois operandos.*

**Observação: A notação polonesa reversa (posfixa) é muito útil, principalmente para as máquinas, pois exibe os operadores na ordem de execução das operações.** 

*Dada a aplicação de árvores acima, implementar um programa com as seguintes funções e regra:*

1. **(1.5 pontos)** *Função que gera uma árvore binária a partir de uma expressão aritmética em notação infixa. Você pode criar um algoritmo que a partir da
expressão infixa monta a árvore ou **antes** de montar a árvore, transforma a expressão infixa em posfixa.*

2. **(2.0 pontos)** *Função que avalia a árvore de expressão aritmética (calcula a expressão).*

3. **(1.5 pontos)**  

**Regra do programa 1:**
*O usuário deve entrar com quantas expressões desejar, porém não deve ser informada a quantidade de expressões a
serem entradas no sistema. Após a entrada de todas as expressões que o usuário desejar informar, o programa deverá apresentar a árvore gerada para cada
expressão e o resultado de cada expressão de entrada.*

**Regra do Programa 2:** 
*As expressões poderão conter: 

  -Operadores binário (+, -, *, /);
  
  -Unários (- (valornegativo), exponenciação, raiz quadrada);
  
  -Parênteses alteram a precedência dos operadores; operandos de valores inteiros.*

 ***Etapa 2: Demonstração da execução do programa (50 pontos):***

 1. *Gravar um vídeo com a execução do programa. As expressões de entrada serão disponibilizadas na* **Semana 6.** 

 2. *Gravar um vídeo explicando as funções que foram implementadas pela equipe.*

 **Observação: para a gravação dos vídeos pode ser utilizado a ferramentas Camtasia ou outra ferramenta de escolha da equipe.** 



