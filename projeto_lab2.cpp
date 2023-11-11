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
// FUNÇÃO PARA A ESCOLHA DOS PRODUTOS
void menu(Nopilha* carrinho){
    char opc,opc2;
    int quant;
    double preco;
    string nome;
    cout << "Selecione a categoria dos produtos que deseja comprar \n";
    cout << " [1] Eletronicos \n [2] Eletrodomésticos \n [3] Alimentos \n [4] vestuário \n [5] Livros \n [6] Finalizar compra \n";
    cin >> opc;
    switch(opc){
    case '1':
        cout << "\n ** ofertas do dia!\n";
        cout << "[1] Notebook UltraBook 15 - R$2000 \n [2] Celular UIphone 26 - R$1200 \n [3] Videogame Station Play 5 - R$2200 \n [4] Televisao Mansung Smart 4K - R$2500 \n ";
        cin >> opc2;
        switch(opc2){
        case '1':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2000,quant,"notebook UltraBook 15");
        case '2':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,1200,quant,"celular UIphone 26");
        case '3':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2200,quant,"videogame Station Play 5");
        case '4':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2500,quant,"televisao Mansung Smart 4K");
            break;
        }
        default:
            cout << "Opcao invalida";
        break;
    case '2':
        cout << "ofertas do dia!\n";
        cout << " [1] Geladeira R$2000 \n [2] Fogao R$1200 \n [3] Microondas R$2200 \n [4] Maquina de lavar R$2500 \n ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2000,quant,"geladeira");
                break;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,1200,quant,"fogao");
                break;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2200,quant,"microondas");
                break;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2500,quant,"maquina de lavar");
                break;
            default: 
                cout << "Opcao invalida";
    case '3':
        cout << "Ofertas do dia!\n";
        cout << " [1] Arroz R$10 \n [2] Feijao R$5 \n [3] Macarrao R$3 \n [4] Carne R$20 \n ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"arroz");
                break;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"feijao");
                break;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"macarrao");
                break;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"carne");
                break;
            default:
                cout << "Opcao invalida";
        }
    case '4':
        cout << "Ofertas do dia!\n";
        cout << " [1] Camiseta R$100 \n [2] Calca R$50 \n [3] Casaco R$300 \n [4] Sapato R$250 \n ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"camiseta");
                break;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"calca");
                break;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"casaco");
                break;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"sapato");
                break;
            default:
                cout << "Opcao invalida";
        }
    case '5':
        cout << "Ofertas do dia!\n";
        cout << " [1] Para todos os garotos que já matei R$10 \n [2] As tranças do rei careca (VOL 1) - R$50 \n [3] A volta dos que nao foram - R$34 \n [4] Seneca: Como ser pai de menina R$20 \n ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"livro 1");
                break;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"livro 2");
                break;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"livro 3");
                break;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"livro 4");
                break;
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'){
                    //chamar função de finalizar compra
                    break;
        }
    case '6':
        //chamar função de finalizar compra
        break;
    default:
        cout << "Opcao invalida";
    }
}

int main(){
    Nopilha* carrinho = criar_Nopilha();
    menu(carrinho);
    return 0;
}
