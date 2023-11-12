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
double finalizar_compra(Nopilha* carrinho){
    double soma = 0;
if(carrinho == NULL){
	cout << "Nenhum produto adicionado :( ";
	return NULL;
    while(carrinho != NULL){
        Nopilha* aux = remover_produto(carrinho);
        soma += ((aux->produto->preco) * (aux->produto->quant));
}
return soma;
}

// FUNÇÃO PARA A ESCOLHA DOS PRODUTOS
void menu(Nopilha* carrinho){
    char opc,opc2;
    int quant;
    double preco;
    string nome;
    inicio:
    system("cls");
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nSEJA BEM-VINDO A LOJA NOZAMA! \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "CATEGORIA DE PRODUTOS DISPONIVEIS \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << " [1] Eletronicos \n [2] Eletrodomesticos \n [3] Alimentos \n [4] vestuario \n [5] Livros \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n [6] Finalizar compra \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
    cin >> opc;
    switch(opc){
    case '1':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Notebook UltraBook 15 - R$2000 \n [2] Celular UIphone 26 - R$1200 \n [3] Videogame Station Play 5 - R$2200 \n [4] Televisao Mansung Smart 4K - R$2500 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
        cin >> opc2;
        switch(opc2){
        case '1':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2000,quant,"notebook UltraBook 15");
            cout << "Produto adicionado com sucesso!";
            goto inicio;
        case '2':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,1200,quant,"celular UIphone 26");
            cout << "Produto adicionado com sucesso!";
            goto inicio;
        case '3':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2200,quant,"videogame Station Play 5");
            cout << "Produto adicionado com sucesso!";
            goto inicio;
        case '4':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2500,quant,"televisao Mansung Smart 4K");
            cout << "Produto adicionado com sucesso!";
            goto inicio;
        
        default:
            cout << "Opcao invalida";
        break;
}
    case '2':
        cout << "ofertas do dia!\n";
        cout << " [1] Geladeira R$2000 \n [2] Fogao R$1200 \n [3] Microondas R$2200 \n [4] Maquina de lavar R$2500 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2000,quant,"geladeira");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,1200,quant,"fogao");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2200,quant,"microondas");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2500,quant,"maquina de lavar");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            default: 
                cout << "Opcao invalida";
        }
    case '3':
        cout << "Ofertas do dia!\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Arroz R$10 \n [2] Feijao R$5 \n [3] Macarrao R$3 \n [4] Carne R$20 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"arroz");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"feijao");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"macarrao");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"carne");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            default:
                cout << "Opcao invalida";
        }
    case '4':
        cout << "Ofertas do dia!\n";
        cout << " [1] Camiseta R$100 \n [2] Calca R$50 \n [3] Casaco R$300 \n [4] Sapato R$250 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"camiseta");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"calca");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"casaco");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"sapato");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            default:
                cout << "Opcao invalida";
        }
    case '5':
        cout << "Ofertas do dia!\n";
        cout << " [1] Para todos os garotos que já matei R$10 \n [2] As tranças do rei careca (VOL 1) - R$50 \n [3] A volta dos que nao foram - R$34 \n [4] Seneca: Como ser pai de menina R$20 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"livro 1");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"livro 2");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"livro 3");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"livro 4");
                cout << "Produto adicionado com sucesso!";
                goto inicio;
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho);
                    break;
	            }else{
	                	goto inicio;
					};
        }
	case '6':
        //chamar função de finalizar compra
        finalizar_compra(carrinho);
        break;
    default:
        cout << "Opcao invalida";
        goto inicio;

}
}

int main(){
    Nopilha* carrinho = criar_Nopilha();
    menu(carrinho);
    
    return 0;
}
