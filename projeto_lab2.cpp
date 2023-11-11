#include <iostream>
using namespace std;

struct Item{
    double preco;
    int quant;
    string nome;
};

struct Nopilha{
    Item* produto;
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
void adcionar_produto(Nopilha*& carrinho,Item* produto){
    Nopilha* novo = new Nopilha;
    novo -> produto = produto;

    //adcionar novo Nopilha no topo
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

//função para retorna produto preço e quantidade
void nozama(Nopilha*& carrinho,double preco,int quant,string nome){
    Item* produto = new Item;
    produto -> preco = preco;
    produto -> quant = quant;
    produto -> nome = nome;
    adcionar_produto(carrinho,produto);
}

void menu(Nopilha* carrinho){
    char opc,opc2;
    int quant;
    double preco;
    string nome;
    cout << "Selecione a categoria dos produtos que deseja comprar \n";
    cout << "[1] Eletronicos \n";
    cin >> opc;
    switch(opc){
    case '1':
        cout << "ofertas do dia!\n";
        cout << "[1] Notebook R$2000 \n [2] Celular R$1200 \n [3] Videogame R$2200 \n [4] Televisao Smart R$2500 \n ";
        cin >> opc2;
        switch(opc2){
        case '1':
            cout << "Digite a quantidade que deseja comprar: ";
            cin >> quant;
            nozama(carrinho,2000,quant,"notebook");
        case '2':
            cout << "Digite a quantidade que deseja comprar: ";
            cin >> quant;
            nozama(carrinho,1200,quant,"celular");
        case '3':
            cout << "Digite a quantidade que deseja comprar: ";
            cin >> quant;
            nozama(carrinho,2200,quant,"videogame");
        case '4':
            cout << "Digite a quantidade que deseja comprar: ";
            cin >> quant;
            nozama(carrinho,2500,quant,"televisao smart");
        }
        break;
    
    default:
        break;
    }
}

int main(){
    Nopilha* carrinho = criar_Nopilha();

    return 0;
}
