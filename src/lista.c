#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct listaEncadeada
{
    int nNumeros;
    struct listaEncadeada *ponteiroId;
};*/

struct reg
{
    int nNumeros;
    struct reg *ponteiroId;
};

typedef struct reg listaEncadeada;

void exibirLista(listaEncadeada *ponteiroLista)
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

void adicionarItem(listaEncadeada *ponteiroLista, int numeroAdicional){
    listaEncadeada *ponteiroListaTemp = NULL;


    ponteiroListaTemp = (listaEncadeada*) malloc(sizeof(listaEncadeada*));
    ponteiroListaTemp->nNumeros = numeroAdicional;
    ponteiroListaTemp->ponteiroId = NULL;
    while (ponteiroLista->ponteiroId!=NULL)
    {
        ponteiroLista=ponteiroLista->ponteiroId;
    }

    ponteiroLista->ponteiroId = ponteiroListaTemp;
}

void mostrarUltimo(listaEncadeada *ponteiroLista){
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

void mostrarPrimeiro(listaEncadeada *ponteiroLista){
    if(ponteiroLista)
    {
        printf(" %d\n", ponteiroLista->nNumeros);
    }else
    {
        printf("Lista vazia.\n");
    }
    
}

void mostrarValorUnico(listaEncadeada *ponteiroLista,int valor){
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

void listarComandos(){
    printf("get x[numero do registro] - Traz o valor armazenado no numero do registro passado como parametro\n");
    printf("put x[numero adicionar] - Adiciona o valor passado como parametro\n");
    printf("all - Exibe todos os registros\n");
    printf("last - Exibe o ultimo registro\n");
    printf("first - Exibe o primeiro registro\n");
}

void removerValor(listaEncadeada *ponteiroLista, int valor){
    
    if(ponteiroLista){
        printf("Entrei\n");
        if(ponteiroLista->nNumeros == valor){
            printf("Entrei\n");
            
            printf("O valor %d foi removido com sucesso!\n",valor);
        }else{
            while (ponteiroLista!=NULL && ponteiroLista->ponteiroId->nNumeros!=valor)
            {
                ponteiroLista = ponteiroLista->ponteiroId;
            }

            if(ponteiroLista!=NULL){
                ponteiroLista->ponteiroId = ponteiroLista->ponteiroId->ponteiroId;
                printf("O valor %d foi removido com sucesso!\n",valor);
            }else{
                printf("O valor %d nao foi encontrado.\n",valor);
            }
            
        }
        
    }else
    {
        printf("Lista vazia.\n");
    }
    
    
}

int main(void)
{
    listaEncadeada *listaPrincipal = NULL;
    char entrada[1000];
    int numero;
    char * comando;
    printf("Prompt:> ");
    scanf("%[^\n]s", entrada);
    setbuf(stdin, NULL);
    
    comando = strtok (entrada," ");

    while(strcmp(comando,"exit") != 0){
        
        if(strcmp(comando,"put") == 0){
            if(listaPrincipal == NULL){
                listaPrincipal = (listaEncadeada*) malloc(sizeof(listaEncadeada*));
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
        }else if(strcmp(comando,"remove") == 0){
            removerValor(listaPrincipal,atoi(strtok (NULL,"")));
        }else if(strcmp(comando,"help") == 0){
            listarComandos();
        }

        printf("Prompt:> ");
        scanf("%[^\n]s", entrada);
        setbuf(stdin, NULL);
        comando = strtok (entrada," ");
    }
    

    
  
  return 0;
}