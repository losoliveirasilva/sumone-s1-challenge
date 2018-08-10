# Desafio SumOne
Projeto realizado para o processo seletivo da SumOne. Requisitos podem ser encontrados [aqui](https://github.com/sumoners/s1-programming-challenges/tree/master/v2). Um documento sobre a arquitetura e as escolhas feitas por mim pode ser encontrado na raiz do projeto.

## Instalação
Este projeto foi escrito em C++, e compilado utilizando o g++ (GCC) 8.2.0. Para compilá-lo, utilize o seguinte comando:
```
$ make
```

## Uso
Para realizar a ordenação:
```
./sortbooks
```

### Lista de livros
Os livros devem estar no arquivo `livros.txt`, descritos da seguinte maneira:
```
Titulo
Autor
Ano de edição
```

O projeto já contém a lista de livros disponibilizada no desafio.
A lista de livros ordenados de acordo com as regras estará no arquivo `livrosordenados.txt` após a conclusão do programa.

## Arquivo de configuração
Para adicionar regras de ordenação, utiliza-se o arquivo `.orderrc`. Há três opções de regras de ordenação:
- Ano de edição: `edicao`
- Autor: `autor`
- Título: `titulo`

Sendo que todas elas podem ser configuradas como `ascendente` ou `descendente`.

O exemplo de configuração abaixo configura Edição descendente, Autor descendente, Título ascendente:
```
edicao=descendente
autor=descendente
titulo=ascendente
```
