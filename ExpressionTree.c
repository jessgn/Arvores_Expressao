/*

					 MJ Dupla Dinâmica
					 
	Alunos: Jéssica Gustavo do Nascimento - GRR20185004
			Marcos Antonio Petry Kerchner - GRR20184576

*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include <ctype.h>

#define OPERAND 1
#define UN_OP   2
#define BIN_OP  3
#define EXP_OP  4
#define IS_SEP  5

#define SEP '_'

#define MAX 50


typedef struct infix_pilha
{
    int info[MAX];
    int topo;
}infix_pilha;

int infix_precedence(char);
void infix_init(infix_pilha *);
int infix_vazia(infix_pilha *);
int infix_full(infix_pilha *);
int infix_pop(infix_pilha *);
void infix_push(infix_pilha *,int);
int infix_top(infix_pilha *);   //value of the topo element
void infix_postfix(char infix[],char postfix[]);

struct tree
{
    int num;
    char info;
    struct tree *esq,*dir;
};

typedef struct nodoFila {
    char exp[MAX];
    struct nodoFila *prox;
}Fila;

void infix_postfix(char infix[],char postfix[])
{
    infix_pilha s;
    char x,token, nextToken;
    int i,jStart=0, jEnd=0;    //i-index para infix,j-index para postfix
    infix_init(&s);
 
    for(i=0; infix[i]!='\0'; i++) {
        //printf("loop i=%d\n", i);
        token=infix[i];
       
        if (isdigit(token) || isalpha(token)) {
           // printf("infix_postfix: A\n");
            postfix[jStart++]=token;
            if (infix[i+1] != '\0') {
                nextToken = infix[i+1];
                if (!(isdigit(nextToken) || isalpha(nextToken))) {
                    postfix[jStart++]= SEP;
                }
            }
        } else if(token=='(') {
          //  printf("infix_postfix: B\n");
            infix_push(&s,'(');
        } else if(token==')') {
           // printf("infix_postfix: C\n");
            while((x=infix_pop(&s)) != '(')
                  postfix[jStart++]=x;
        } else {
          //  printf("infix_postfix: D\n");
            while(infix_precedence(token) <= infix_precedence(infix_top(&s)) && !infix_vazia(&s))
            {
                x=infix_pop(&s);
             //   printf("poping stuff: %a\n", x);
                postfix[jStart++]=x;
            }
            infix_push(&s,token);
        }
        //printf("infix=%s\n", infix);
        //printf("postfix=%s\n", postfix);
    }
 
    while(!infix_vazia(&s))
    {
        x=infix_pop(&s);
        postfix[jStart++]=x;
    }
 
    postfix[jStart]='\0';
}
 
int infix_precedence(char x)
{
    if(x=='(')
        return(0);
    if(x=='+'||x=='-')
        return(1);
    if(x=='*'||x=='/')
        return(2);
 
    return(3);
}
 
void infix_init(infix_pilha *s)
{
    s->topo=-1;
}
 
int infix_vazia(infix_pilha *s)
{
    if(s->topo==-1)
        return(1);
 
    return(0);
}

int infix_full(infix_pilha *s)
{
    if(s->topo==MAX-1)
        return(1);
 
    return(0);
}
 
void infix_push(infix_pilha *s,int x)
{
    s->topo=s->topo+1;
    s->info[s->topo]=x;
}
 
int infix_pop(infix_pilha *s)
{
    int x;
    x=s->info[s->topo];
    s->topo=s->topo-1;
    return(x);
}
 
int infix_top(infix_pilha *p)
{
    return (p->info[p->topo]);
}
int topo=-1;

struct tree *pilha[MAX];
struct tree *node;

void push(struct tree* node)
{
    pilha[++topo]=node;
}

struct tree * pop()
{ 
    return(pilha[topo--]);
}

struct tree * Cria_Nodo_Tree() {
    struct tree *p;    
    p = (struct tree*) malloc(sizeof(struct tree));
    if (!p) {
        printf("Problema de alocação");
        exit(0);
    }
    return p;
}

Fila * Cria_Nodo_Fila() {
    Fila *p;
    p = (Fila *)malloc(sizeof(Fila));
    if (!p) {
        printf("Problema de alocação");
        exit(0);
    }
    return p;
}

void insere_no_fila(Fila **fila, char exp[MAX]) {
    Fila *novo = NULL;
    Fila *aux = NULL;

    novo = Cria_Nodo_Fila();
    strcpy(novo->exp, exp);
    //printf("insere_no_file: %s\n", exp);
    novo->prox = NULL;

    if (*fila == NULL) { //primeiro e último
        *fila = novo;
    }
    else {
        aux = *fila;

        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void free_lista(Fila *fila) {
    Fila *aux1;

    while (fila != NULL) {
        aux1 = fila;
        fila = fila->prox;
        free(aux1);
    }
}

void free_arvore(struct tree *raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL)
        free_arvore(raiz->esq);
    if (raiz->dir != NULL)
        free_arvore(raiz->dir);
    free(raiz);
}

/* Operadores unarios, binarios ou operandos */ 
int verifica( char ch)
{ 
	if(ch=='$')
		return EXP_OP;
    if (ch=='#')
        return UN_OP;   
    if (ch=='+'||ch=='/'||ch=='*'||ch=='-')
        return BIN_OP;
    if (ch == SEP)
        return IS_SEP;
    return OPERAND;
}

/* Calculando o valor da expressão posfixa recursivamente */
int calcular(struct tree *node)
{
    int ch;
    
   // printf("calcular: node->num: %d\n", node->num);
    //printf("calcular: node->info: %c\n", node->info);
    ch = verifica(node->info);
    if (node->info == SEP) {
       // printf("calcular: got num: %d\n", node->num);
        return node->num;
    }
    else if (ch==UN_OP) {
    	 if (node->info== '#' && node->dir > 0 ){
            return (int)sqrt(calcular(node->dir)); 
	} else {
		printf("Impossivel calcular raiz de numero negativo");
	}
}
    else if(node->info=='$'){
             return pow(calcular(node->esq),calcular(node->dir));
    }
    else if(node->info=='-'){
    		if ((node->esq) && (node->dir) != NULL){
				return (calcular(node->esq)) - (calcular(node->dir));
        }
			if ( (node->esq) != NULL  && (node->dir) == NULL){
				return (calcular(node->esq) * (-1));
		}
			if ( (node->dir) != NULL && (node->esq) == NULL){
				return (calcular(node->dir) * (-1));
			}
		
    }
    else if(ch==BIN_OP){
        if(node->info=='+')
            return (calcular(node->esq)) + (calcular(node->dir));
        if(node->info=='*')
            return (calcular(node->esq)) * (calcular(node->dir));
        if(node->info=='/')
            return (calcular(node->esq)) / (calcular(node->dir));
    }

    return 0;
}

void preorder(struct tree *node){
     if (node != NULL){
     	printf("(");
    	   if (node->info == SEP) {
        printf("%d", node->num);
        } else {
            printf("%c",node->info);
        }
        preorder(node->esq);
        preorder(node->dir);
        printf(")");
    }
}

void inorder(struct tree *node){
    if (node !=NULL){
    	printf("(");
        inorder(node->esq);
        if (node->info == SEP) {
            printf("%d", node->num);
        } else {
            printf("%c",node->info);
        }
        inorder(node->dir);
         printf(")");
    } 
}

void postorder(struct tree *node){
   if (node !=NULL){
    	printf("(");
        postorder(node->esq);
        postorder(node->dir);
         if (node->info == SEP) {
            printf("%d", node->num);
        } else {
            printf("%c",node->info);
        }
         printf(")");
    } 
}
/* Push operando*/
void operand(int num)
{
    //printf("operand: push: %d\n", num);
    node        = Cria_Nodo_Tree();
    node->num   = num;
    node->info  = SEP;
    node->esq  = NULL;
    node->dir = NULL;
    push(node);
}

void operators(char ch)
{
    node = Cria_Nodo_Tree();
    node->num = 0;
    node->info  = ch;
    node->dir = pop();
    if (verifica(node->info)!=UN_OP)
        node->esq  = pop();
    push(node);
}

int main(struct tree *node){
    int i,j,p,nextP,ans,numero_expressoes,op;
    Fila *expressoes = NULL;
    Fila *conversion = NULL;
    i = numero_expressoes = 0;

    char infix[MAX], postfix[MAX];
    
     printf("\n\t\t*****************Arvore de expressao aritmetica***************");
     printf("\n\n\t\tDigite as expressoes\t ou\t Digite 0 Para sair do programa");
    do {
    	printf("\n\t");
        scanf("%s", infix);

        if (infix[i] == 'F')
            break;

        infix_postfix(infix,postfix);
        insere_no_fila(&expressoes, postfix);
    } while (1);


    while(expressoes!=NULL)
    {
        numero_expressoes++;
        strcpy(postfix,expressoes->exp);

        printf(" -------- Calculo Expressao %i--------\n", numero_expressoes);
        

        for(i=0;postfix[i]!='\0';i++)
        {
            p=verifica(postfix[i]);
            if (p==OPERAND) {
                //printf("operand: START: i=%d\n", i);
                j=i;
                while (postfix[j+1] != '\0' && verifica(postfix[j+1])==OPERAND) {
                    printf("%c\n", postfix[j+1]);
                    ++j;
                }
                
                operand(atoi(postfix+i));
                i=j;
               // printf("operand: END: i=%d\n", i);
            } else if (p==BIN_OP||p==UN_OP || p==EXP_OP)
                operators(postfix[i]);
            else if (p==UN_OP)
                operators(postfix[i++]);
            else if (p==EXP_OP)
            
                operators(postfix[i]);
            else if (p==IS_SEP)
                printf("Ignorando Separador...\n");
        }

       	ans = calcular(pilha[topo]);
       	if(p==UN_OP && ans< 0){
       		printf("Impossivel calcular raiz de numero negativo");
		   }else{
		   	printf("\nO resultado da expressao eh:   %d " ,ans);
		   }
        expressoes=expressoes->prox;
        printf("\nO percurso pre ordem eh:         ");
        preorder(pilha[topo]);
        printf("\nO percurso em ordem eh:         ");
        inorder(pilha[topo]);
        printf("\nO percurso pos ordem eh:         ");
        postorder(pilha[topo]);

        	printf("\n\n");
    } 
    		free_lista(expressoes);
    		free_arvore(pilha[topo]);
			printf("Liberando Arvore...");
}

