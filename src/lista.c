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

const int ordernarCrescente = 1;
const int ordernarDecrescente = 0;


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
        
        if(ponteiroLista->itensLista->intConteudo == valor){
            
            ponteiroLista->itensLista = ponteiroLista->itensLista->ponteiroProximo;
            ponteiroLista->numeroElementos--;
            printf("O valor %d foi removido com sucesso!\n",valor);

        }else{

            elementoListaTemp = ponteiroLista->itensLista;

            while (ponteiroLista->itensLista->ponteiroProximo != NULL && ponteiroLista->itensLista->ponteiroProximo->intConteudo != valor)
            {
                ponteiroLista->itensLista = ponteiroLista->itensLista->ponteiroProximo;
            }

            if(ponteiroLista->itensLista->ponteiroProximo != NULL && ponteiroLista->itensLista->ponteiroProximo->intConteudo == valor){

                ponteiroLista->itensLista->ponteiroProximo = ponteiroLista->itensLista->ponteiroProximo->ponteiroProximo;
                ponteiroLista->numeroElementos--;
                printf("O valor %d foi removido com sucesso!\n",valor);

            }else{
                printf("O valor %d nao foi encontrado.\n",valor);
            }

            ponteiroLista->itensLista = elementoListaTemp;

        }
    }else
    {
        printf("Lista vazia.\n");
    }
    
    
}

void ordernarLista(listaElementos *ponteiroLista, int tipoOrdenacao){
    if(ponteiroLista->numeroElementos != 0){
        
        elementosLista *elementoListaTemp;
        elementosLista *elementoListaAnterior = NULL;
        elementosLista *elementoListaComparador = ponteiroLista->itensLista;
        elementosLista *elementoAuxiliaTroca;
        int ocorreuAlteracao = 0;

        while (elementoListaComparador != NULL)
        {
            elementoListaTemp = elementoListaComparador;

            while (elementoListaTemp != NULL && elementoListaTemp->ponteiroProximo != NULL)
            {

                if( (elementoListaComparador->intConteudo > elementoListaTemp->ponteiroProximo->intConteudo && tipoOrdenacao == ordernarCrescente) || (elementoListaComparador->intConteudo < elementoListaTemp->ponteiroProximo->intConteudo && tipoOrdenacao == ordernarDecrescente) ){
                    
                    elementoAuxiliaTroca = elementoListaTemp->ponteiroProximo;
                    
                    elementoListaTemp->ponteiroProximo = elementoAuxiliaTroca->ponteiroProximo;
                    
                    elementoAuxiliaTroca->ponteiroProximo = elementoListaComparador;

                    if (elementoListaComparador == ponteiroLista->itensLista)
                    {
                       ponteiroLista->itensLista = elementoAuxiliaTroca;
                    }
                    
                    elementoListaComparador = elementoAuxiliaTroca;

                    if(elementoListaAnterior != NULL){
                        elementoListaAnterior->ponteiroProximo = elementoAuxiliaTroca;
                    }
                    
                    exibirLista(ponteiroLista);

                    ocorreuAlteracao = 1;
                }

                elementoListaTemp = elementoListaTemp->ponteiroProximo;
            }

            if(ocorreuAlteracao == 1){
                break;
            }

            elementoListaAnterior = elementoListaComparador;
            elementoListaComparador = elementoListaComparador->ponteiroProximo;
        
        }
        
        
        if(ocorreuAlteracao == 1){
            ordernarLista(ponteiroLista,tipoOrdenacao);
        }

    }else{
        printf("Lista vazia.\n");
    }
}

int main(void)
{
    listaElementos *listaPrincipal = NULL;
    char entrada[1000];
    char * opcaoComando;
    char * comando;

    listaPrincipal = (listaElementos*) malloc(sizeof(listaElementos*));
    listaPrincipal->numeroElementos = 0;
    listaPrincipal->itensLista = NULL;

    while(strcmp(comando,"exit") != 0){

        printf("Prompt:> ");
        scanf("%[^\n]s", entrada);
        setbuf(stdin, NULL);
        
        comando = strtok (entrada," ");
        opcaoComando = strtok (NULL,"");
        
        if(strcmp(comando,"put") == 0){
            adicionarItem(listaPrincipal,atoi(opcaoComando));
        }else if(strcmp(comando,"last") == 0){
            mostrarUltimo(listaPrincipal);
        }else if(strcmp(comando,"first") == 0){
            mostrarPrimeiro(listaPrincipal);
        }else if(strcmp(comando,"all") == 0){
            exibirLista(listaPrincipal);
        }else if(strcmp(comando,"get") == 0){
            mostrarValorUnico(listaPrincipal,atoi(opcaoComando));
        }else if(strcmp(comando,"remove") == 0){
            removerValor(listaPrincipal,atoi(opcaoComando));
        }else if(strcmp(comando,"sort") == 0){
            if(strcmp(opcaoComando,"asc") == 0){
                ordernarLista(listaPrincipal,ordernarCrescente);
            }else{
                ordernarLista(listaPrincipal,ordernarDecrescente);
            }
        }else if(strcmp(comando,"help") == 0){
            listarComandos();
        }
    }
    
  return 0;
}