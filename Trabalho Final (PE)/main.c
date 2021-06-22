#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct //struct tBonus
{
  int teto;
  float valor;
  float valor_bonificar;
} tBonus;

typedef struct //struct tCompra
{
  float valor_total_compra;
  int compra_cancelada;
  tBonus bonus;
} tCompra;

typedef struct //struct tCliente
{
  char nome[50];
  char cpf[12];
  char telefone [15];
  char email[30];
  int bonus;
  float total_compras;
  tCompra ultima_compra;
} tCliente;

/*
Funçaõ que verifica se um cpf informado para cadastrar um cliente
já é existente, caso exista um cpf igual, a função retorna 1, 
caso não eista ela apenas retorna 0. Ela recebe 3 parametros, 
o struct clientes como vetor, o cpf que esta sendo cadastrado e
o tamanho atual do vetor clientes.
*/
int verificarCPF(tCliente clientes[MAX], char cpf_informado[12], int *posicao_atual)
{
	int i;
	for(i = 0; i <= *posicao_atual; i++) {
		if(strcmp(clientes[i].cpf, cpf_informado) == 0) {
			return i; //retorna o indice do cliente com cpf igual
		}
	}
	return -1; //retorna -1 caso não exista clientes com cpf igual
}

/*
Função cadastrar cliente, que recebe 3 paramentros, o vetor do struct clientes,
recebe opcao do menu clientes, para ter um controle para retornar para o menu principal,
apos a finalização dessa função, alem da posicao final do vetor, para manter um controle
sobre o preenchimento do vetor.
*/
int cadastrarCliente(tCliente clientes[MAX], int *opcao, int *posicao_atual) 
{
	system("cls");
	char cpf_informado[12], nome_informado[50];
	char telefone_informado[15], email_informado[30];
	int pos;
	printf("\n---- CADASTRANDO CLIENTE (%d) ----\n", *posicao_atual+2); //numero do cliente que sera cadastrado.
	printf("Qual o CPF? Informe: ");
	scanf("%s", cpf_informado);
	//essa verificação so acontece apartir do segundo cliente sendo cadastrado,
	//ja que o primeiro cliente não é preciso ver se existe um cpf em comum.
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual))!=-1 && *posicao_atual>-1) {
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF ja cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		return *opcao = 0; //retorna opcao do menu clientes como 0, mandando para o menu principal.
	}
	//o vetor só é incrementdo caso não exista cpf ja existente ou seja o primeiro.
	pos = *posicao_atual+1;
	strcpy(clientes[pos].cpf, cpf_informado); //atribuindo no vetor clientes o cpf informado.
	printf("Qual o nome? Informe: ");
	scanf("%s", nome_informado);
	strcpy(clientes[pos].nome, nome_informado); //atribuindo no vetor clientes o nome informado.
	printf("Qual o telefone? Informe: ");
	scanf("%s", telefone_informado);
	strcpy(clientes[pos].telefone, telefone_informado); //atribuindo no vetor clientes o telefone informado.
	printf("Qual o email? Informe: ");
	scanf("%s", email_informado);
	strcpy(clientes[pos].email, email_informado); //atribuindo no vetor clientes o email informado.
	clientes[pos].bonus = 1; //atribuindo bonus zero para o cliente novato.
	clientes[pos].total_compras = 0.0; //novo cliente não possui um total de compras.
	printf("----------------------------------\n");
	printf("\nCLIENTE CADASTRADO COM SUCESSO!\n");
	printf("\n----------------------------------\n");
	system("pause");
	system("cls");
	 
	return *posicao_atual+=1; //retorna a posicao final do vetor incrementada +1, ja que foi cadastrado um cliente.
}

/*
Função responsavel por alterar o email, pergunta o novo email, recebe tambem
os parametros vetor de um struct de clientes e a posicao do cliente que tera o email alterado.
*/
void alterarEmail(tCliente clientes[MAX], int *posicao_cliente_existente)
{
	system("cls");
	char novo_email[30];
	printf("Qual o novo email? Informe: ");
	scanf("%s", novo_email);
	printf("----------------------------\n");
	strcpy(clientes[*posicao_cliente_existente].email, novo_email);
	system("cls");
	printf("\n------------------------\n");
	printf("\nEmail alterado com sucesso.\n");
	printf("\n------------------------\n");
	system("pause");
	system("cls");
	return;
}

/*
Função responsavel por alterar o telefone, pergunta o novo telefone, recebe tambem
os parametros vetor de um struct de clientes e a posicao do cliente que tera o telefone alterado.
*/
void alterarTelefone(tCliente clientes[MAX], int *posicao_cliente_existente)
{
	system("cls");
	char novo_telefone[15];
	printf("Qual o novo telefone? Informe: ");
	scanf("%s", novo_telefone);
	printf("----------------------------\n");
	strcpy(clientes[*posicao_cliente_existente].telefone, novo_telefone);
	system("cls");
	printf("\n------------------------\n");
	printf("\nTelefone alterado com sucesso.\n");
	printf("\n------------------------\n");
	system("pause");
	system("cls");
	return;
}

/*
Função responsavel por alterar o nome, pergunta o novo nome, recebe tambem
os parametros vetor de um struct de clientes e a posicao do cliente que tera o nome alterado.
*/
void alterarNome(tCliente clientes[MAX], int *posicao_cliente_existente)
{
	system("cls");
	char novo_nome[50];
	printf("Qual o novo nome? Informe: ");
	scanf("%s", novo_nome);
	printf("----------------------------\n");
	strcpy(clientes[*posicao_cliente_existente].nome, novo_nome);
	system("cls");
	printf("\n------------------------\n");
	printf("\nNome alterado com sucesso.\n");
	printf("\n------------------------\n");
	system("pause");
	system("cls");
	return;
}

/*
Função responsavel por alterar o cpf, pergunta o novo cpf, recebe tambem
os parametros vetor de um struct de clientes e a posicao do cliente que tera o cpf alterado.
Porem o cpf so é alterado caso não exista um ja cadastrado para outros clientes, incluindo o cpf original do cliente
em especifico que sera alterado.
*/
void alterarCPF(tCliente clientes[MAX], int *posicao_atual, int *posicao_cliente_existente) 
{
	system("cls");
	char cpf_alterado[12];
	printf("Qual o novo CPF? Informe: ");
	scanf("%s", cpf_alterado);
	printf("----------------------------\n");
	if(verificarCPF(clientes, cpf_alterado, &(*posicao_atual))!=-1) {
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF ja cadastrado.\n");
		printf("\n------------------------\n");
		system("pause");
		system("cls");
	} else {
		strcpy(clientes[*posicao_cliente_existente].cpf, cpf_alterado);
		system("cls");
		printf("\n------------------------\n");
		printf("\nCPF alterado com sucesso.\n");
		printf("\n------------------------\n");
		system("pause");
		system("cls");
	}
	return;
}

/*
Essa função chama o menu alterar cadastro, de um cliente ja existente, recebe os parametros
vetor de um struct clientes, recebe opcao do menu clientes, para ter um controle
para retornar para o menu principal, alem da posicao final do vetor, para manter um controle
sobre o preenchimento do vetor, a posicao no vetor do cliente que tera seus dados modificados.
*/
int menuAlterarCadastro(tCliente clientes[MAX], int *opcao, int *posicao_atual, int *posicao_cliente_existente) 
{ 
	system("cls");
	int escolha;
	do{
		printf("\n---- MENU ALTERAR CADASTRO ----\n");
		printf("1 - Alterar CPF\n2 - Alterar nome\n3 - Alterar telefone\n4 - Alterar email\n0 - Voltar ao menu principal");
		printf("\n----------------------------\n");
		printf("Escolha: ");
		scanf("%d", &escolha); //o usuario escolhe qual opcao deseja.
		printf("----------------------------\n");
		//caso a escolha seja um desses cases, chamara a função especificada. 
		//porem caso a escolha não seja um dessas em amostra o menu se repete ate o usuario escolher uma delas.
		switch(escolha) {
			case 1 : alterarCPF(clientes, &(*posicao_atual), &(*posicao_cliente_existente));
				break;
			case 2: alterarNome(clientes, &(*posicao_cliente_existente));
				break;
			case 3: alterarTelefone(clientes, &(*posicao_cliente_existente));
				break;
			case 4: alterarEmail(clientes, &(*posicao_cliente_existente));
				break;
			case 0://printf("\nMenu Alterar Cadastro Finalizado!\n\n----------------------------\n"); 
				return *opcao = 0; //retorno de opcao como zero, onde volta para o menu principal.
				//passando pelo menu clientes e saindo ja dele diretamente.
				break;
			default: printf("\nEscolha uma opcao valida!\n\n----------------------------\n");
		}
	} while(escolha != 0);
	system("cls");
}

/*
Essa função é responsavel por procurar o cpf do cliente que sera alterado, recebe os parametros
vetor de um struct clientes, recebe opcao do menu clientes, para ter um controle
para retornar para o menu principal, alem da posicao final do vetor, para manter um controle
sobre o preenchimento do vetor.
*/
int alterarCliente(tCliente clientes[MAX], int *opcao, int *posicao_atual) 
{
	system("cls");
	char cpf_informado[12];
	printf("\n---- ALTERANDO CLIENTE ----\n");
	printf("Qual o CPF do cliente? \nInforme: ");
	scanf("%s", cpf_informado); //ususario informa o cpf do cliente que deseja fazer alterações nas informações.
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual)) == -1) {
		//caso o cpf não exista, da erro e retorna para o menu principal.
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0; //opcao zerada para passar direto pelo menu clientes e ir ao menu principal.
	}
	//caso exista, pegamos a posicao do cliente no vetor que iremos alterar e guardamos.
	int posicao_cliente_existente = verificarCPF(clientes, cpf_informado, &(*posicao_atual));
	//chamamos o menu alterar cadastro, parar alterar as informações.
	menuAlterarCadastro(clientes, &(*opcao), &(*posicao_atual), &posicao_cliente_existente);
	system("cls");
	return 0;
}

/*
Essa função apenas imprime na tela as informaçoes do cliente que o usuario informou o cpf,
caso ele nao exista o cpf, imprime que o cpf nao foi casdatrado. Recebe os parametros
vetor de um struct clientes, recebe opcao do menu clientes, para ter um controle
para retornar para o menu principal, alem da posicao final do vetor, para manter um controle
sobre o preenchimento do vetor.
*/
int consultarCliente(tCliente clientes[MAX], int *opcao, int *posicao_atual) 
{
	system("cls");
	char cpf_consulta[12];
	int encontrou_cpf = 0, i;
	printf("\nQual o CPF do cliente?\nInforme: ");
	scanf("%s", cpf_consulta);
	for(i = 0; i <= *posicao_atual; i++) {
		if(strcmp(clientes[i].cpf, cpf_consulta) == 0) {
			system("cls");
			printf("\n---- CONSULTA DE CLIENTE ----\n");
			printf("NOME: %s\n", clientes[i].nome);
			printf("CPF: %s\n", clientes[i].cpf);
			printf("TELEFONE: %s\n", clientes[i].telefone);
			printf("EMAIL: %s\n", clientes[i].email);
			printf("BONUS: %d\n", clientes[i].bonus);
			printf("TOTAL EM COMPRAS: %.2f\n\n", clientes[i].total_compras);
			//ultima compra deve ser implementado.
			encontrou_cpf = 1;
			break;
		}
	}
	if(encontrou_cpf == 0) {
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0;
	} else {
		system("pause");
		system("cls");
		return 0;
	}
}

int removerCliente(tCliente clientes[MAX], int *opcao, int *posicao_atual)
{
	system("cls");
	char cpf_informado[12];
	printf("\n---- REMOVENDO CLIENTE ----\n");
	printf("Qual o CPF do cliente? \nInforme: ");
	scanf("%s", cpf_informado); //ususario informa o cpf do cliente que deseja excluir.
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual)) == -1) {
		//caso o cpf não exista, da erro e retorna para o menu principal.
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		return *opcao = 0; //opcao zerada para passar direto pelo menu clientes e ir ao menu principal.
	}
	int i = verificarCPF(clientes, cpf_informado, &(*posicao_atual)), escolha, cont;
	system("cls");
	printf("\n--------------------------------------------\n");
	printf("NOME: %s\n", clientes[i].nome);
	printf("CPF: %s\n", clientes[i].cpf);
	printf("TELEFONE: %s\n", clientes[i].telefone);
	printf("EMAIL: %s\n", clientes[i].email);
	printf("BONUS: %d\n", clientes[i].bonus);
	printf("TOTAL EM COMPRAS: %.2f\n", clientes[i].total_compras);
	printf("--------------------------------------------\n");
	printf("Tem zerteza que deseja remover esse cliente?\n");
	printf("[1 - SIM / 0 - NAO]\n");
	printf("--------------------------------------------\n");
	printf("Escolha: ");
	scanf("%d", &escolha);
	if(escolha == 1) { //caso o usuario aceite remover
		if(i == *posicao_atual) { //caso seja o ultimo no vetor, so diminui e remove direto.
			system("cls");
			printf("\n--------------------------------------------\n");
			printf("\nCADASTRO DO CLIENTE EXCLUIDO!\n");
			printf("\n--------------------------------------------\n");
			system("pause");
			system("cls");
			return *posicao_atual-=1;
		} else {
			//apartir do indice do vetor do cliente que quero remover ate o penultimo.
			//Passando os posteriores para a posicao anterior.
			for(cont = i; cont <= *posicao_atual-1; cont++) { 
				strcpy(clientes[cont].cpf, clientes[cont+1].cpf); 
				strcpy(clientes[cont].nome, clientes[cont+1].nome); 
				strcpy(clientes[cont].telefone, clientes[cont+1].telefone); 
				strcpy(clientes[cont].email, clientes[cont+1].email); 
				clientes[cont].bonus = clientes[cont+1].bonus; 
				clientes[cont].total_compras = clientes[cont+1].total_compras;
			}
			system("cls");
			printf("\n--------------------------------------------\n");
			printf("\nCADASTRO DO CLIENTE EXCLUIDO!\n");
			printf("\n--------------------------------------------\n");
			system("pause");
			system("cls");
			return *posicao_atual-=1;
		}
	} else { //se o usuario não aceitar remover volta para o menu principal
		system("cls");
		printf("\n--------------------------------------------\n");
		printf("\nCADASTRO DO CLIENTE NAO EXCLUIDO!\n");
		printf("\n--------------------------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0;
	}
}

/*
Função que imprime e controla o MENU CLIENTES,
chamando as outras subfunções(CADASTRAR, ALTERAR, CONSULTAR, REMOVER), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2, 3, 4 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para o 
menu principal junto de um avsio de saida.
*/
void menuClientes(tCliente clientes[MAX], int *posicao_atual)
{
	system("cls");
	int opcao;
	do {
		printf("\n---- MENU CLIENTE ----\n");
		printf("1 - Cadastrar\n2 - Alterar\n3 - Consultar\n4 - Remover\n0 - Sair\n");
		printf("----------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: cadastrarCliente(clientes, &opcao, &(*posicao_atual));
				break;
			case 2: alterarCliente(clientes, &opcao, &(*posicao_atual));
				break;
			case 3: consultarCliente(clientes, &opcao, &(*posicao_atual));
				break;
			case 4: removerCliente(clientes, &opcao, &(*posicao_atual));
				break;
			case 0: opcao = 0;//printf("\nMenu Cliente Finalizado!\n\n------------------------\n");
				break;
			default: printf("\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	system("cls");
	return;
}

int efetivarCompra(tCliente clientes[MAX], int *opcao, int *posicao_atual)
{
	system("cls");
	char cpf_informado[12];
	printf("\n-------- EVETIVAR COMPRA --------\n");
	printf("Qual o CPF do cliente? \nInforme: ");
	scanf("%s", cpf_informado); //ususario informa o cpf do cliente que deseja efetivar a compra.
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual)) == -1) {
		//caso o cpf não exista, da erro e retorna para o menu principal.
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0; //opcao zerada para passar direto pelo menu compra e ir ao menu principal.
	} 
	int i = verificarCPF(clientes, cpf_informado, &(*posicao_atual)), escolha_bonus;
	float valor_compra, pagamento_cliente;
	printf("---------------------------------\n");
	printf("\nBONUS = %d\n", clientes[i].bonus);
	printf("VALOR CORRESPONDENTE = R$ %.2f\n", ((float)clientes[i].bonus * 0.5));
	printf("\n---------------------------------\n");
	printf("Qual o valor da compra? R$ ");
	do {
		scanf("%f", &valor_compra);
		if(valor_compra < 0) {
			printf("\nErro: valor negativo\nDigite novamente: ");
		}
	} while(valor_compra < 0);
	if(clientes[i].bonus != 0) {
		printf("\nDeseja utilizar seu bonus? \n[1 - SIM / 0 - NAO]\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &escolha_bonus);
		if(escolha_bonus == 1) {
			float valor_bonus = clientes[i].bonus*0.5;
			valor_compra = valor_compra - valor_bonus;
			int valor_bonus_atualizado = 0;
			if(valor_compra < 0.0) { //to com bonus de teste//
				valor_bonus = valor_compra * -1;
				valor_compra = 0.0;
				valor_bonus_atualizado = (int)(valor_bonus/0.5);
			}
			printf("---------------------------------\n");
			printf("\nBONUS ATUAL = %d\n", valor_bonus_atualizado);
			printf("VALOR DA COMPRA ATUALIZADO = R$ %.2f\n", valor_compra);
			printf("\n---------------------------------\n");
		}
	}
	printf("\nQual o valor do pagamento do cliente? R$ ");
	do {
		scanf("%f", &pagamento_cliente);
		if(pagamento_cliente < 0) {
			printf("\nErro: valor negativo\nDigite novamente: ");
		}
	} while(pagamento_cliente < 0);
	if(valor_compra > pagamento_cliente) {
		int escolha_fornecer_dinheiro;
		printf("“\nErro: Valor do pagamento inferior ao valor da compra.");
		printf("\nDeseja fornecer mais dinheiro? ");
		printf("\n[1 - SIM / 0 - NAO]\n");
		printf("Escolha: ");
		scanf("%d", escolha_fornecer_dinheiro);
		if(escolha_fornecer_dinheiro == 1) {
			
		}
	}
	
	return 0;
}

void cancelarCompra()
{
	return;
}

/*
Função que imprime e controla o MENU COMPRAS,
chamando as outras subfunções(EFETIVAR, CANCELAR), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para 
o menu principal junto de um avsio de saida.
*/
void menuCompras(tCliente clientes[MAX], int *posicao_atual)
{
	system("cls");
	int opcao;
	do {
		printf("\n---- MENU COMPRA ----\n");
		printf("1 - Efetivar\n2 - Cancelar\n0 - Sair\n");
		printf("------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: efetivarCompra(clientes, &opcao, &(*posicao_atual));
				break;
			case 2: cancelarCompra();
				break;
			case 0: printf("\nMenu Compra Finalizado!\n\n------------------------\n");
				break;
			default: printf("\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	//system("cls");
	return;
}

void configurarBonus()
{
	return;
}

void exibirBonus()
{
	return;
}

/*
Função que imprime e controla o MENU BONUS,
chamando as outras subfunções(CONFIGURAR, EXIBIR), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para o 
menu principal junto de um avsio de saida.
*/
void menuBonus()
{
	system("cls");
	int opcao;
	do {
		printf("\n---- MENU BONUS ----\n");
		printf("1 - Configurar\n2 - Exibir\n0 - Sair\n");
		printf("------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: configurarBonus();
				break;
			case 2: exibirBonus();
				break;
			case 0: printf("\nMenu Bonus Finalizado!\n\n------------------------\n");
				break;
			default: printf("\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	return;
}

void listarClientes()
{
	return;
}

void listarBonus() 
{
	return;
}

void listarClientePorCompra()
{
	return;
}

/*
Função que imprime e controla o MENU RELATORIOS,
chamando as outras subfunções(LISTAR CLIENTES, LISTAR BONUS, 
LISTAR CLIENTES POR COMPRA), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2, 3 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para o 
menu principal junto de um avsio de saida..
*/
void menuRelatorios()
{
	system("cls");
	int opcao;
	do {
		printf("\n---- MENU RELATORIOS ----\n");
		printf("1 - Listar clientes\n2 - Listar bonus\n3 - Listar cliente por compras\n0 - Sair\n");
		printf("------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: listarClientes();
				break;
			case 2: listarBonus();
				break;
			case 3: listarClientePorCompra();
				break;
			case 0: printf("\nMenu Relatorios Finalizado!\n\n------------------------\n");
				break;
			default: printf("\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	return;
}

/*
Função que imprime e controla o MENU PRINCIPAL,
chamando as outras subfunções(CLIENTE, COMPRA, BONUS, RELATORIOS), 
atraves de um switch case, caso a opcao escolhida seja invalida(não seja 1, 2, 3, 4 ou 0), 
ira retornar um aviso, e ira pedir para o usuario informar 
novamente outro valor, o programa so é finalizado com a opcao 0.
*/
void menuPrincipal(tCliente clientes[MAX], int *posicao_atual) 
{
	system("cls");
	int opcao;
	do {
		printf("\n---- MENU PRINCIPAL ----\n");
		printf("1 - Cliente\n2 - Compra\n3 - Bonus\n4 - Relatorios\n0 - Sair\n");
		printf("------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: menuClientes(clientes, &(*posicao_atual));
				break;
			case 2: menuCompras(clientes, &(*posicao_atual));
				break;
			case 3: menuBonus();
				break;
			case 4: menuRelatorios();
				break;
			case 0: printf("\nPrograma Finalizado!\n");
				break;
			default: system("cls"); printf("\n------------------------\n\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	return;
}

int main(int argc, char *argv[]) {
	system("mode con:cols=60 lines=30"); //apenas modifica o tamanho da janela do cmd
	tCliente clientes[MAX];
	int posicao_atual = -1;
	menuPrincipal(clientes, &posicao_atual);
	return 0;
}
