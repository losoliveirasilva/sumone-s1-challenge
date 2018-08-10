# Desafio SumOne
Projeto realizado para o processo seletivo da SumOne. Requisitos podem ser encontrados [aqui](https://github.com/sumoners/s1-programming-challenges/tree/master/v2).

## Instalação
Este projeto foi escrito em C++, e compilado utilizando o g++ (GCC) 8.2.0. Para compilá-lo, utilize o seguinte comando:
```
$ make
```

## Uso
```
./sortbooks
```

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
