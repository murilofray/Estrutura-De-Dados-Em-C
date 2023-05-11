# Repositório de Estruturas de Dados em C

Este repositório contém uma coleção de códigos de estruturas de dados implementados em C.

## Comandos exclusivos do Windows

Alguns comandos utilizados nos códigos são exclusivos do Windows, como `system("pause")` e `system("cls")`. Caso esteja executando o código em um sistema operacional Linux, você pode utilizar as seguintes alternativas, respectivamente:

- `system("read -p \"Pressione ENTER para continuar...\"");`
- `system("clear")`

Além disso, o comando `fflush(stdin)` utilizado para limpar o buffer de entrada no Windows, pode ser substituído pelo comando `__fpurge(stdin)` em sistemas operacionais baseados em Linux.

Sinta-se à vontade para contribuir com novas implementações e correções nos códigos existentes.
