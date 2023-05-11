#include <stdio.h>
#include <stdlib.h>

typedef struct sFila{
    int info;
    struct sFila *next;
}FILA;

void inicializar(FILA **inicio, FILA **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

int vazia(FILA *inicio)
{
    if(inicio == NULL)
        return 1;
    return 0;
}

FILA* getNode(){
    return (FILA*)malloc(sizeof(FILA));
}

void freeNode(FILA *f)
{
    free(f);
}

void enfilheirar(FILA **inicio, FILA **fim, int elemento)
{
    FILA *q;
    q = getNode();
    if(q != NULL)
    {
        q->info = elemento;
        q->next = NULL;
        if(vazia(*inicio))
            *inicio = q;
        else
            (*fim)->next = q;
        *fim = q;
        return;
    }
    printf("ERRO DE ALOCACAO\n");
}

int desenfilheirar(FILA **inicio, FILA **fim)
{
    int elemento;
    FILA *aux;
    if(!vazia(*inicio))
    {
        elemento = (*inicio)->info;
        aux = *inicio;
        *inicio = (*inicio)->next;
         if (*inicio == NULL)
            *fim = NULL;
        freeNode(aux);
        return elemento;
    }
    printf("Fila Vazia\n");
    return -1;
}

void exibir(FILA **inicio, FILA **fim)
{
    if(!vazia(*inicio))
    {
        while(!vazia(*inicio))
            printf("|%d|", desenfilheirar(inicio,fim));
        printf("\n");
        return;
    }
    printf("Vazia\n");
}

void menu()
{
    printf("|======================================|\n");
    printf("|            Menu Principal            |\n");
    printf("|======================================|\n");
    printf("|1. Enfileirar elemento                |\n");
    printf("|2. Desenfileirar elemento             |\n");
    printf("|3. Exibir fila                        |\n");
    printf("|0. Sair                               |\n");
    printf("|======================================|\n");
    printf("Digite sua opcao: ");
}

void main()
{
    FILA *inicio, *fim;
    int elemento, opcao;
    inicializar(&inicio,&fim);
    do{
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o elemento a ser enfileirado: ");
                scanf("%d", &elemento);
                enfilheirar(&inicio, &fim, elemento);
                break;
            case 2:
                elemento = desenfilheirar(&inicio, &fim);
                if(elemento != -1){
                    printf("Elemento %d desenfileirado com sucesso.\n", elemento);
                }
                break;
            case 3:
                printf("Fila: ");
                exibir(&inicio, &fim);
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
        system("pause");
        system("cls");
    }while(opcao != 0);
}
