#include <iostream>
using namespace std;

struct item{
    double preco;
    int quant;
    string nome;
};

struct Nopilha{
    item* produto;
    Nopilha* prox;
};

//função para iniciar a pilha apontada para NULL
Nopilha* criar_Nopilha(){
    return NULL;
}

//função para verificar se a pilha está vazia
bool isempty(Nopilha* carrinho){
    return(carrinho == NULL);
}

//função para adcionar produto no carrinho, produto será sempre adcionado ao topo da pilha
void adcionar_produto(Nopilha*& carrinho,double preco,int quant,string nome){
    Nopilha* novo = new Nopilha;
    novo -> produto -> preco = preco;
    novo -> produto -> quant  = quant;
    novo -> produto -> nome = nome;
    novo -> prox = carrinho;
    carrinho = novo;
}

//função para remover ultimo produto adcionado ao carrinho e retornar ele
Nopilha* remover_produto(Nopilha*& carrinho){
    if(isempty(carrinho)){
        return NULL;
    }else{
        Nopilha* p = carrinho;
        carrinho = carrinho -> prox;
        return p;
    }
}

int main(){
    Nopilha* carrinho = criar_Nopilha();

    return 0;
}