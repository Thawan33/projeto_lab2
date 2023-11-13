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
//implementação do historico de compras--------------------------------
struct Nolista{
    double valor_compra;
    int quantidade_itens;
    Nolista* prox;
    Nolista* ant;
};

struct Descritor{
    int tamanho;
    Nolista* ini;
    Nolista* fim;
};

Descritor* criar_lista(){
    Descritor* d = new Descritor;
    d->tamanho = 0;
    d->ini = NULL;
    d->fim = NULL;
    return d;
}

void print(Nolista* lista,int cont){
    if(lista != NULL){
        cout << "Compra [" << cont << "] quantidade de itens: " << lista->quantidade_itens << endl << "Compra [" << cont << "] total da compra: R$" << lista->valor_compra << "\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n";
        print(lista->prox,cont+1);
    }
}

void append(Descritor* lista,double valor,int quant){
    Nolista* novo = new Nolista;
    novo->valor_compra = valor;
    novo->quantidade_itens = quant;
    novo->prox = NULL;
    novo->ant = NULL;
    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho++;
    }else{
        Nolista* p = lista->ini;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
        novo->ant = p;
        lista->tamanho++;
        lista->fim = novo;
    }
}

//fim das implementações do historico de compras

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

void ver_carrinho(Nopilha* carrinho,int cont){
    if(!isempty(carrinho)){
        cout << "["<< cont << "] - "<< carrinho->produto->nome << " - R$" << carrinho->produto->preco << " - " << carrinho->produto->quant << " unidade(s)\n";
        ver_carrinho(carrinho->prox,cont+1);
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
void finalizar_compra(Nopilha* carrinho, Descritor* historico){
    double soma = 0;
    int quantidade_total = 0;
if(carrinho == NULL){
	cout << "Nenhum produto adicionado :( ";
} else{
    
        

    pagamento:
    system("cls");
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n RESUMO DA COMPRA \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "Produtos: \n";
    while(carrinho != NULL){
        Nopilha* aux = remover_produto(carrinho);
        cout << aux->produto->nome << " - R$" << aux->produto->preco << " - " << aux->produto->quant << " unidade(s)\n";
        soma += ((aux->produto->preco) * (aux->produto->quant));
        quantidade_total += aux->produto->quant;
    }
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "O valor total da compra foi de: R$" << soma << endl;
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << " Forma de pagamento: \n [1] Cartao de credito \n [2] Cartao de debito \n [3] Boleto \n [4] Pix \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
    char opc;
    cin >> opc;
    switch(opc){
        case '1':
            cout << "CARTAO DE CREDITO\n";
            cout << "Deseja dividir em quantas parcelas? \n> ";
            int parcelas;
            cin >> parcelas;
            if (parcelas > 12 || parcelas < 1){
                cout << "Numero de parcelas invalido";
                system ("pause");
                goto pagamento;
            }
            cout << "\nO valor das parcelas sera de: R$" << soma/parcelas << endl;
            break;
        case '2':
            cout << "CARTAO DE DEBITO\nEm breve voce recebera um email com o comprovante de pagamento\n";
            break;
        case '3':
            cout << "BOLETO\n";
            cout << "O boleto foi enviado para o seu email\nVoce tem 3 dias ate o vencimento :)\n";
            break;
        case '4':
            cout << "PIX\nO codigo do pix foi enviado para o seu email\nVoce tem 30 minutos para pagar o pix :)\n";
            break;
        default:
            cout << "Opcao invalida";
            system ("pause");
            goto pagamento;
    }

    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "Obrigado por comprar na Nozama! :D \n";
    append(historico,soma,quantidade_total);
}
}

// FUNÇÃO PARA A ESCOLHA DOS PRODUTOS
void menu(Nopilha* carrinho,Descritor* historico){
    char remove;
    char opc,opc2;
    string tamanho;
    int quant;
    string nome;
    inicio:
    system("cls");
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nSEJA BEM-VINDO A NOZAMA! \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "CATEGORIA DE PRODUTOS DISPONIVEIS \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << " [1] Eletronicos \n [2] Eletrodomesticos \n [3] Alimentos \n [4] vestuario \n [5] Livros \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n [6] Carrinho de compras \n [7] Finalizar compra \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
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
            cout << "Produto adicionado com sucesso!\n";
            system ("pause");
            goto inicio;
        case '2':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,1200,quant,"celular UIphone 26");
            cout << "Produto adicionado com sucesso!\n";
            system ("pause");
            goto inicio;
        case '3':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2200,quant,"videogame Station Play 5");
            cout << "Produto adicionado com sucesso!\n";
            system ("pause");
            goto inicio;
        case '4':
            cout << "Quantidade: ";
            cin >> quant;
            nozama(carrinho,2500,quant,"televisao Mansung Smart 4K");
            cout << "Produto adicionado com sucesso!\n";
            system ("pause");
            goto inicio;
        
        default:
            cout << "Opcao invalida";
            cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    break;
	            }else{
	                	goto inicio;
					};
        
}
    case '2':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Geladeira R$2000 \n [2] Fogao R$1200 \n [3] Microondas R$2200 \n [4] Maquina de lavar R$2500 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2000,quant,"geladeira");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,1200,quant,"fogao");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2200,quant,"microondas");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,2500,quant,"maquina de lavar");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            default: 
                cout << "Opcao invalida";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    break;
	            }else{
	                	goto inicio;
					};
        }
    case '3':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Arroz R$10 \n [2] Feijao R$5 \n [3] Macarrao R$3 \n [4] Carne R$20 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,10,quant,"arroz");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,5,quant,"feijao");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,3,quant,"macarrao");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,20,quant,"carne");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            default:
                cout << "Opcao invalida";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    break;
	            }else{
	                	goto inicio;
					};
        }
    case '4':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Camiseta R$100 \n [2] Calca R$50 \n [3] Casaco R$300 \n [4] Sapato R$250 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        
        switch(opc2){
            case '1':
            	cout << "Tamanhos disponiveis: [P] [M] [GG]\n > ";
            	cin >> tamanho;
                cout << "\nQuantidade: ";
                cin >> quant;
                nozama(carrinho,100,quant,"camiseta");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '2':
            	cout << "Tamanhos disponiveis: [37] [39] [42]\n > ";
            	cin >> tamanho;
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,50,quant,"calca");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '3':
                cout << "Tamanhos disponiveis: [P] [M] [G]\n > ";
            	cin >> tamanho;
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,300,quant,"casaco");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,250,quant,"sapato");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            default:
                cout << "Opcao invalida";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    break;
	            }else{
	                	goto inicio;
					};
        }
    case '5':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Para todos os garotos que ja matei R$12,50 \n [2] As trancas do rei careca (VOL 1) - R$50 \n [3] A volta dos que nao foram - R$36,90 \n [4] Seneca: Como ser pai de menina R$19,90 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,12.50,quant,"livro 1");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '2':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,50,quant,"livro 2");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '3':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,36.90,quant,"livro 3");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            case '4':
                cout << "Quantidade: ";
                cin >> quant;
                nozama(carrinho,19.90,quant,"livro 4");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                goto inicio;
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    break;
	            }else{
	                	goto inicio;
					};
        }
    case '6':
        system("cls");
        cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n CARRINHO DE COMPRAS \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        if(carrinho == NULL){
        	cout << "Nenhum produto adicionado :( ";
        } else{
        ver_carrinho(carrinho,1);
        }
        cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "Deseja cancelar o carrinho? [S] [N]\n >";
        cin >> remove;
            if(remove == 'S' || remove == 's'){
             carrinho = NULL;
             goto inicio;
            }
            else{
                goto inicio;          
              }
        cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        break;
	case '7':
        //chamar função de finalizar compra
        finalizar_compra(carrinho,historico);
        break;
    default:
        cout << "Opcao invalida";
        goto inicio;

}
}
void usuario(){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
    string usuario, senha_teste, login, senha_real;
    cout << "**Bem vindo a Nozama!\nPara iniciar, crie um usuario e uma senha.\nUsuario: " << endl;
    cin >> usuario;
    cout << ">> Crie uma senha: ";
    cin >> senha_teste;
    system("cls");
    cout << "-=-=-=-=-=-=-=-=- LOGIN -=-=-=-=-=-=-=-=-" << endl;
    cout << ">> Usuario: ";
    cin >> login;
    cout << ">> Senha: ";
    cin >> senha_real;
    while(login != usuario or senha_real != senha_teste){
        cout << ">> As informacoes nao conferem, por favor, tente novamente:" << endl;
        cout << ">> Usuario: ";
        cin >> login;
        cout << ">> Senha: ";
        cin >> senha_real;
    }
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n" << endl;
}

int main(){
    char opc;
    Nopilha* carrinho = criar_Nopilha();
    usuario();
    Descritor* historico = criar_lista();
    
    do{
        menu(carrinho,historico);
        cout << "Deseja fazer mais compras? [S] para sim: ";
        cin >> opc;
        system("cls");
    }
    while(opc == 'S' || opc == 's');

    do{
        cout << "deseja ver seu historico de compras? [S] para sim: ";
        cin >> opc;
        system("cls");
    }
    while(opc != 'S' && opc != 's');
    if(opc == 's' || opc == 'S'){
        print(historico->ini,1);
    }
    
    system("pause");
    return 0;
}