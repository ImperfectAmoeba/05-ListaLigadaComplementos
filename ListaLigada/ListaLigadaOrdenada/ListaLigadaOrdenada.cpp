#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}
//ta meio freestyle porque eu não consegui baixar o visual studio 2019 e o visual studio code é pessimo de compilar C++ mas o João ajudou demais a entender o código
void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	//verificação padrão
	if (novo == NULL)
	{
		return;
	}
	//pede para o usuario digitar
	cout << "Digite o elemento: ";
	//usuario digita 'novo' que esta apontando para o 'valor' 
	cin >> novo->valor;
	//'novo' aponta para o proximo que é nulo porque AINDA NAO tem mais de um valor digitado pelo usuário
	novo->prox = NULL;

	//esse eu penei pra entender pelo amor de deus
	//ponteiro do 'achou'(valor a ser comparado com os outros da lista) é equivalente a posicaoElemento (numero do elemento na lista) onde 'novo' aponta pro 'valor'(da posicao) e diz em qual lugar da lista o número está
	NO* achou = posicaoElemento(novo->valor);
	//se 'achou' nao existir na lista
	if (achou == NULL)
	{
		//o primeiro valor equivale ao novo
		primeiro = novo;
	}
	else
	{
		// se o nó auxiliar for equivalente ao 'primeiro'
		NO* aux = primeiro;
		//enquanto o auxiliar que aponta para o proximo for diferente de NULL **E** o auxiliar que aponta para o proximo que aponta para o valor for menor que novo que aponta para o valor
		while (aux->prox != NULL && aux->prox->valor < novo->valor) {
			//auxiliar equivale a ele mesmo e começa a apontar para o proximo
			aux = aux->prox;
		}

		/*
			//caso o novo que aponta para o valor for menor que o auxiliar que aponta pro proximo que aponta pro valor (??????????????)
			if (novo->valor < aux->prox->valor) {
				//se o novo que aponta para o valor for menor que o auxiliar que aponta para o valor
				if(novo->valor < aux->valor){
					//primeiro equivale ao novo
				primeiro = novo;
				//novo aponta para o proximo que equivale ao auxiliar
				novo->prox = aux;
				}
			}//fim do if
		NO* aux = NULL; //no auxiliar fica nulo
		aux->prox = novo;//auxiliar aponta para o proximo que equivale ao novo
		novo*/
	}
}

void excluirElemento()
{

}

void buscarElemento()
{

}





