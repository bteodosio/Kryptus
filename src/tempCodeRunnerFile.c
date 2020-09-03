#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaEncadeada
{
    int nNumeros;
    struct listaEncadeada *ponteiroId;
};


void exibirLista(struct listaEncadeada *ponteiroLista)
{
    printf("Mostrando a lista:\n"); 
    if(ponteiroLista)
    {
        do
        {
            printf(" %d", ponteiroLista->nNumeros);
            ponteiroLista=ponteiroLista->ponteiroId;
        }
        while(ponteiroLista);
    }
    else
        printf("Lista vazia.");

    printf("\n");
}

void adicionarItem(struct listaEncadeada *ponteiroLista, int numeroAdicional){
    struct listaEncadeada *ponteiroListaTemp = NULL;


    ponteiroListaTemp = (struct listaEncadeada*) malloc(sizeof(struct listaEncadeada*));
    ponteiroListaTemp->nNumeros = numeroAdicional;
    ponteiroListaTemp->ponteiroId = NULL;
    while (ponteiroLista->ponteiroId!=NULL)
    {
        ponteiroLista=ponteiroLista->ponteiroId;
    }

    ponteiroLista->ponteiroId = ponteiroListaTemp;
}

void mostrarUltimo(struct listaEncadeada *ponteiroLista){
    if(ponteiroLista)
    {
        while (ponteiroLista->ponteiroId!=NULL)
        {
            ponteiroLista=ponteiroLista->ponteiroId;
        }
        printf(" %d\n", ponteiroLista->nNumeros);
    }else
    {
        printf("Lista vazia.\n");
    }
    
}

void mostrarPrimeiro(struct listaEncadeada *ponteiroLista){
    if(ponteiroLista)
    {
        printf(" %d\n", ponteiroLista->nNumeros);
    }else
    {
        printf("Lista vazia.\n");
    }
    
}

void mostrarValorUnico(struct listaEncadeada *ponteiroLista,int valor){
    int i;
    if(ponteiroLista)
    {
        for(i=1;i<valor;i++){

            if(ponteiroLista!=NULL){
                ponteiroLista=ponteiroLista->ponteiroId;
            }else
            {
                break;
            }
        }

        if(ponteiroLista!=NULL){
            printf(" %d\n", ponteiroLista->nNumeros);
        }else
            printf("Valor nao encontrado.\n");
    }else
    {
        printf("Lista vazia.\n");
    }
    
}

int main(void)
{
    struct listaEncadeada *listaPrincipal = NULL;
    char entrada[100];
    int numero;
    char * comando;
    printf("Prompt:> ");
    scanf("%[^\n]s", entrada);
    setbuf(stdin, NULL);
    
    comando = strtok (entrada," ");

    while(strcmp(comando,"exit") != 0){
        
        if(strcmp(comando,"put") == 0){
            if(listaPrincipal == NULL){
                listaPrincipal = (struct listaEncadeada*) malloc(sizeof(struct listaEncadeada*));
                listaPrincipal->nNumeros = atoi(strtok (NULL,""));
                listaPrincipal->ponteiroId = NULL;
            }else{
                adicionarItem(listaPrincipal,atoi(strtok (NULL,"")));
            }
            
        }else if(strcmp(comando,"last") == 0){
            mostrarUltimo(listaPrincipal);
        }else if(strcmp(comando,"first") == 0){
            mostrarPrimeiro(listaPrincipal);
        }else if(strcmp(comando,"all") == 0){
            exibirLista(listaPrincipal);
        }else if(strcmp(comando,"get") == 0){
            mostrarValorUnico(listaPrincipal,atoi(strtok (NULL,"")));
        }

        printf("Prompt:> ");
        scanf("%[^\n]s", entrada);
        setbuf(stdin, NULL);
        comando = strtok (entrada," ");
    }
    

    
  
  return 0;
}