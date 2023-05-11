#include <stdio.h>
#include <stdlib.h>

typedef struct sDEQUE{
    int info;
    struct sDEQUE *back, *next;
}DEQUE;

void inicializar(DEQUE **inicio, DEQUE **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

int vazia(DEQUE *inicio)
{
    if(inicio == NULL)
        return 1;
    return 0;
}

DEQUE* getNode(){
    return (DEQUE*)malloc(sizeof(DEQUE));
}

void freeNode(DEQUE *d)
{
    free(d);
}

void inserirFim(DEQUE **inicio, DEQUE **fim, int elemento)
{
    DEQUE *q;
    q = getNode();
    if(q != NULL)
    {
        q->info = elemento;
        q->next = NULL;
        q->back = *fim;
        if(vazia(*inicio))
            *inicio = q;
        else
            (*fim)->next = q;
        *fim = q;
        return;
    }
    printf("ERRO DE ALOCACAO\n");

}

void inserirInicio(DEQUE **inicio, DEQUE **fim, int elemento)
{
    DEQUE *q;
    q = getNode();
    if(q != NULL)
    {
        q->info = elemento;
        q->back = NULL;
        q->next = *inicio;
        if(vazia(*inicio))
            *fim = q;
        else
            (*inicio)->back = q;
        *inicio = q;
        return;
    }
    printf("ERRO DE ALOCACAO\n");

}

int removerInicio(DEQUE **inicio, DEQUE **fim)
{
    int elemento;
    DEQUE *aux;
    if(!vazia(*inicio))
    {
        elemento = (*inicio)->info;
        aux = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;
        else
            (*inicio)->back = NULL;
        freeNode(aux);
        return elemento;
    }
    printf("DEQUE VAZIA\n");
    return -1;
}

int removerFim(DEQUE **inicio, DEQUE **fim)
{
    int elemento;
    DEQUE *aux;
    if(!vazia(*inicio))
    {
        elemento = (*fim)->info;
        aux = *fim;
        *fim = (*fim)->back;
        if(*fim == NULL)
            *inicio = NULL;
        else
            (*fim)->next = NULL;
        freeNode(aux);
        return elemento;
    }
    printf("DEQUE VAZIA\n");
    return -1;
}


void exibir(DEQUE **inicio, DEQUE **fim)
{
    if(!vazia(*inicio))
    {
        while(!vazia(*inicio))
            printf("|%d|", removerInicio(inicio,fim));
        printf("\n");
        return;
    }
    printf("DEQUE VAZIA\n");
}

void exibirInversa(DEQUE **inicio, DEQUE **fim)
{
    if(!vazia(*inicio))
    {
        while(!vazia(*inicio))
            printf("|%d|", removerFim(inicio,fim));
        printf("\n");
        return;
    }
    printf("DEQUE VAZIA\n");
}

void menu() {
    printf("|======================================|\n");
    printf("|            Menu Principal            |\n");
    printf("|======================================|\n");
    printf("|1. Inserir elemento no final          |\n");
    printf("|2. Inserir elemento no inicio         |\n");
    printf("|3. Remover elemento do inicio         |\n");
    printf("|4. Remover elemento do final          |\n");
    printf("|5. Exibir a deque                     |\n");
    printf("|6. Exibir a deque inversa             |\n");
    printf("|0. Sair                               |\n");
    printf("|======================================|\n");
    printf("Digite sua opcao: ");
}

void main()
{
    DEQUE *inicio, *fim;
    int opcao, elemento;
    inicializar(&inicio,&fim);
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido no final: ");
                scanf("%d", &elemento);
                inserirFim(&inicio, &fim, elemento);
                printf("\n");
                break;
            case 2:
                printf("Digite o elemento a ser inserido no inicio: ");
                scanf("%d", &elemento);
                inserirInicio(&inicio, &fim, elemento);
                printf("\n");
                break;
            case 3:
                elemento = removerInicio(&inicio, &fim);
                if (elemento != -1) {
                    printf("Elemento removido do inicio: %d\n\n", elemento);
                }
                break;
            case 4:
                elemento = removerFim(&inicio, &fim);
                if (elemento != -1) {
                    printf("Elemento removido do final: %d\n\n", elemento);
                }
                break;
            case 5:
                printf("Exibindo o deque:\n");
                exibir(&inicio, &fim);
                printf("\n");
                break;
            case 6:
                printf("Exibindo a deque inversa:\n");
                exibirInversa(&inicio, &fim);
                printf("\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Digite uma opcao valida.\n\n");
                break;
        }
        system("pause");
        system("cls");
    } while (opcao != 0);

}
