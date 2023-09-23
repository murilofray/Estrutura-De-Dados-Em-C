#include <stdio.h>
#define TAM 100

typedef struct sLista
{
    int info[TAM];
    int n;
} LISTA;

int menu()
{
    int opcao;
    printf("\nEscolha a operacao desejada");
    printf("\n1 - Inserir um elemento em uma posicao especifica");
    printf("\n2 - Inserir um elemento no inicio");
    printf("\n3 - Inserir um elemento no fim");
    printf("\n4 - Remover um elemento de uma posicao especifica;");
    printf("\n5 - Remover um elemento no inicio");
    printf("\n6 - Remover um elemento no dfim");
    printf("\n7 - Acessar um elemento de uma posicao especifica;");
    printf("\n8 - Procurar um elemento derteminado;");
    printf("\n9 - Exibir os elementos da lista;");
    printf("\n0 - Encerrar Sistema.\n");
    do
    {
        scanf("%d", &opcao);
        if(opcao < 0 || opcao > 9)
            printf("Opcao invalida");
    } while (opcao < 0 || opcao > 9);
    return opcao;
}

int ler_inteiro()
{
    int numero;
    do
    {
        scanf("%d", &numero);
        if (numero < 0)
            printf("Valor invalido, apenas informe numeros inteiros e positivos.\ninforme novamente o valor: ");
    } while (numero < 0);
    return numero;
}

int validar_posicao(LISTA *l, int aux)
{
    int posicao;
    do
    {
        printf("\ninforme a posicao de um elemento: ");
        posicao = ler_inteiro();
        if (posicao < 0 || posicao > (*l).n + aux)
            printf("Posicao fora dos limites da lista.\n");
    } while (posicao < 0 || posicao > (*l).n + aux);
    return posicao;
}

void inicializar(LISTA *l)
{
    (*l).n = -1;
}

int cheia(LISTA *l)
{
    if ((*l).n + 1 == TAM)
        return 1;
    return 0;
}

int vazia(LISTA *l)
{
    if ((*l).n == -1)
        return 1;
    return 0;
}

void inserir_posicao(LISTA *l)
{
    int posicao, elemento,i;
    if (cheia(l))
    {
        printf("Lista cheia.\n");
    }
    else
    {
        posicao = validar_posicao(l, 1);
        printf("\ninforme o elemento que deseja inserir na lista: ");
        elemento = ler_inteiro();
        for (i = (*l).n + 1; i > posicao; i--)
        {
            (*l).info[i] = (*l).info[i - 1];
        }
        (*l).info[posicao] = elemento;
        (*l).n++;
    }
}

int remover_posicao(LISTA *l)
{
    int posicao,aux;
    if (vazia(l))
    {
        printf("Lista vazia.\n");
        return -1;
    }
    posicao = validar_posicao(l, 0);
    aux = l->info[posicao];
    for (int i = posicao; i < (*l).n; i++)
    {
        (*l).info[i] = (*l).info[i + 1];
    }
    (*l).n--;
    printf("Elemento %d Removido com sucesso.\n", aux);
    return aux;
}

void inserir_inicio(LISTA *l)
{
    int valor;
    if (cheia(l))
    {
        printf("Lista cheia.\n");
        return;
    }
    valor = ler_inteiro();
    for (int i = l->n + 1; i > 0; i--)
    {
        l->info[i] = l->info[i - 1];
    }
    l->info[0] = valor;
    l->n++;
    printf("Elemento Inserido com sucesso.\n");
}

void inserir_fim(LISTA *l)
{
    int valor;
    if (cheia(l))
    {
        printf("Lista cheia.\n");
        return;
    }
    valor = ler_inteiro();
    l->info[l->n + 1] = valor;
    l->n++;
    printf("Elemento Inserido com sucesso.\n");
}

int remover_inicio(LISTA *l)
{
    int aux;
    if (vazia(l))
    {
        printf("Lista Vazia.\n");
        return -1;
    }
    aux = l->info[0];
    for (int i = 0; i < l->n; i++)
    {
        l->info[i] = l->info[i + 1];
    }
    l->n--;
    printf("Elemento %d Removido com sucesso.\n", aux);
    return aux;
}

int remover_fim(LISTA *l)
{
    int aux;
    if (vazia(l))
    {
        printf("Lista vazia.\n");
        return -1;
    }
    aux = l->info[l->n];
    l->n--;
    printf("Elemento %d Removido com sucesso.\n", aux);
    return aux;
}

void buscar_posicao(LISTA *l)
{
    int posicao;
    if (!vazia(l))
    {
        printf("Lista vazia.\n");
        return;
    }
    posicao = validar_posicao(l, 0);
    printf("O elemento da lista na posicao #%d: %d.\n", posicao, (*l).info[posicao]);
}

void buscar_elemento(LISTA *l)
{
    int elemento, achou = 0;
    if (vazia(l))
    {
        printf("Lista vazia.\n");
        return;
    }
    printf("informe o elemento a ser procurado na lista: ");
    elemento = ler_inteiro();
    for (int i = 0; i < (*l).n; i++)
    {
        if ((*l).info[i] == elemento)
        {
            printf("\nPosicao %d", i);
            achou = 1;
        }
    }
    if (!achou)
        printf("\nElemento nao encontrado na lista.");

}

void exibir(LISTA *l)
{
    if (vazia(l))
    {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i <= (*l).n; i++)
        printf("|%d|", i, (*l).info[i]);
    printf("\n");
}

void main()
{
    int opcao;
    LISTA l;
    inicializar(&l);
    do
    {
        opcao = menu();
        switch (opcao)
        {
            case 1:
                inserir_posicao(&l);
                break;
            case 2:
                inserir_inicio(&l);
                break;
            case 3:
                inserir_fim(&l);
                break;
            case 4:
                remover_posicao(&l);
                break;
            case 5:
                remover_inicio(&l);
                break;
            case 6:
                remover_fim(&l);
                break;
            case 7:
                buscar_posicao(&l);
                break;
            case 8:
                buscar_elemento(&l);
                break;
            case 9:
                exibir(&l);
                break;
            case 0:
                printf("\n\nBye...");
                break;
        }
    } while (opcao != 0);

}