TUTORIAL COMPLETO – Framework de Testes Unity (C/C++)

\## 1) Objetivo do tutorial



Ao seguir este tutorial, o leitor será capaz de:



Baixar e instalar o Unity



Baixar o código de produção (função a ser testada)



Organizar o projeto com estrutura de diretórios



Escrever testes unitários



Rodar o Unity



Gerar relatório de testes



Analisar o output final



O resultado será um MÍNIMO projeto funcional contendo:



código de produção



testes



Makefile



relatórios



executável de testes



\## 2) Download do Unity



O Unity é distribuído oficialmente no GitHub do projeto ThrowTheSwitch.



Link oficial:



https://github.com/ThrowTheSwitch/Unity



Como baixar:

git clone https://github.com/ThrowTheSwitch/Unity.git





Isso criará um diretório com:



Unity/

&nbsp;├─ src/

&nbsp;└─ extras/





Os arquivos necessários são:



src/unity.c



src/unity.h



\## 3) Instalação do Unity



O Unity não exige instalação.

Basta copiar os dois arquivos para seu projeto.



Crie a seguinte estrutura:



Atividade/

&nbsp;├── src/              (código de produção)

&nbsp;├── test/             (código de teste)

&nbsp;├── unity/            (Unity framework)

&nbsp;├── build/            (arquivos compilados)

&nbsp;└── Makefile





Copie os arquivos do Unity:



cp Unity/src/unity.\* Atividade/unity/



\## 4) Baixar código de produção



Para este tutorial, usaremos um código simples: uma função de soma.



Link para baixar o código de produção:



https://github.com/andreirocha7/Unity-test/tree/main/Documents/Programa%C3%A7%C3%A3o/Automa%C3%A7%C3%A3o/Atividade





Copie o arquivo:



src/atividade.h



int soma(int a, int b);





src/atividade.c



\#include "atividade.h"



int soma(int a, int b) {

&nbsp;   return a + b;

}



\## 5) Escrever o teste com Unity



Crie:



test/test\_atividade.c



\#include "unity.h"

\#include "atividade.h"



void setUp(void) {}

void tearDown(void) {}



void test\_soma(void) {

&nbsp;   TEST\_ASSERT\_EQUAL(4, soma(2, 2));

}



int main(void)

{

&nbsp;   UNITY\_BEGIN();

&nbsp;   RUN\_TEST(test\_soma);

&nbsp;   return UNITY\_END();

}



\## 6) Criar o Makefile (para automatizar tudo)



Makefile



CC = gcc

CFLAGS = -Iunity -Isrc



SRC = src/atividade.c

TEST = test/test\_atividade.c

UNITY = unity/unity.c



all: test\_run



test\_run: $(SRC) $(TEST) $(UNITY)

&nbsp;	$(CC) $(CFLAGS) -o build/tests $(SRC) $(TEST) $(UNITY)

&nbsp;	./build/tests



clean:

&nbsp;	rm -rf build/tests



\## 7) Rodar os testes



No diretório do projeto:



make





Ou diretamente:



gcc -Iunity -Isrc -o build/tests src/atividade.c test/test\_atividade.c unity/unity.c

./build/tests



\## 8) Output esperado



O Unity exibirá algo assim:



-----------------------

TEST(test\_atividade.c)

-----------------------

test\_soma\_valores\_positivos: PASS

test\_soma\_valores\_negativos: PASS



-----------------------

2 Tests 0 Failures 0 Ignored

OK



\## 9) Gerar relatório



O Unity não gera HTML nativamente, mas você pode redirecionar para arquivo:



./build/tests > build/relatorio.txt





O arquivo relatorio.txt conterá:



test\_soma\_valores\_positivos: PASS

test\_soma\_valores\_negativos: PASS

2 Tests 0 Failures





Esse relatório pode ser anexado ao trabalho.

