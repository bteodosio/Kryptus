#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct listaEncadeada
{
    int intNumeros;
    struct listaEncadeada *ponteiroId;
};*/

struct registros
{
    int intConteudo;
    struct registros *ponteiroProximo;
};

typedef struct registros elementosLista;

typedef struct {
    int numeroElementos;
    elementosLista *itensLista;

} listaElementos;

void exibirLista(listaElementos *ponteiroLista)
{
    elementosLista *elementoListaTemp = NULL;
    printf("Mostrando a lista:\n"); 
    if(ponteiroLista->numeroElementos != 0)
    {
        elementoListaTemp = ponteiroLista->itensLista;
        do
        {
            printf(" %d", elementoListaTemp->intConteudo);
            elementoListaTemp = elementoListaTemp->ponteiroProximo;
        }
        while(elementoListaTemp);
    }
    else
        printf("Lista vazia.");

    printf("\n");
}

void adicionarItem(listaElementos *ponteiroLista, int numeroAdicional){
    elementosLista *elementoListaTemp = NULL;

    if(ponteiroLista->itensLista == NULL){
        elementoListaTemp = (elementosLista*) malloc(sizeof(elementosLista*));
        elementoListaTemp->intConteudo = numeroAdicional;
        elementoListaTemp->ponteiroProximo = NULL;
        ponteiroLista->itensLista = elementoListaTemp;
    }else{

        elementoListaTemp = ponteiroLista->itensLista;

        while (elementoListaTemp->ponteiroProximo!=NULL)
        {
            elementoListaTemp = elementoListaTemp->ponteiroProximo;
        }

        elementoListaTemp->ponteiroProximo = (elementosLista*) malloc(sizeof(elementosLista*));
        elementoListaTemp->ponteiroProximo->intConteudo = numeroAdicional;
        elementoListaTemp->ponteiroProximo->ponteiroProximo = NULL;
    }

    ponteiroLista->numeroElementos++;
}

void mostrarUltimo(listaElementos *ponteiroLista){
    elementosLista *elementoListaTemp = NULL;
    if(ponteiroLista->numeroElementos != 0)
    {

        elementoListaTemp = ponteiroLista->itensLista;

        while (elementoListaTemp->ponteiroProximo != NULL)
        {
            elementoListaTemp = elementoListaTemp->ponteiroProximo;
        }

        printf(" %d\n", elementoListaTemp->intConteudo);

    }else
    {
        printf("Lista vazia.\n");
    }
    
}

void mostrarPrimeiro(listaElementos *ponteiroLista){
    
    if(ponteiroLista->numeroElementos != 0)
    {
        printf(" %d\n", ponteiroLista->itensLista->intConteudo);
    }else
    {
        printf("Lista vazia.\n");
    }
    
}

void mostrarValorUnico(listaElementos *ponteiroLista,int valor){
    elementosLista *elementoListaTemp = NULL;

    if(ponteiroLista->numeroElementos != 0)
    {

        elementoListaTemp = ponteiroLista->itensLista;

        for(int i=1;i<valor;i++){

            if(elementoListaTemp != NULL){
                elementoListaTemp = elementoListaTemp->ponteiroProximo;
            }else
            {
                break;
            }
        }

        if(elementoListaTemp != NULL){
            printf(" %d\n", elementoListaTemp->intConteudo);
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

void removerValor(listaElementos *ponteiroLista, int valor){
    elementosLista *elementoListaTemp = NULL;

    if(ponteiroLista->numeroElementos != 0){
        
        elementoListaTemp = ponteiroLista->itensLista;

        if(elementoListaTemp->intConteudo == valor){
            printf("Entrei\n");
            ponteiroLista->itensLista = NULL;
            ponteiroLista->numeroElementos--;
            printf("O valor %d foi removido com sucesso!\n",valor);
        }else{
            while (elementoListaTemp->ponteiroProximo != NULL && elementoListaTemp->intConteudo!=valor)
            {
                elementoListaTemp = elementoListaTemp->ponteiroProximo;
            }

            if(elementoListaTemp != NULL){
                elementoListaTemp = NULL;
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
    listaElementos *listaPrincipal = NULL;
    char entrada[1000];
    int numero;
    char * comando;

    listaPrincipal = (listaElementos*) malloc(sizeof(listaElementos*));
    listaPrincipal->numeroElementos = 0;
    listaPrincipal->itensLista = NULL;

    printf("Prompt:> ");
    scanf("%[^\n]s", entrada);
    setbuf(stdin, NULL);
    
    comando = strtok (entrada," ");

    while(strcmp(comando,"exit") != 0){
        
        if(strcmp(comando,"put") == 0){
            adicionarItem(listaPrincipal,atoi(strtok (NULL,"")));
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