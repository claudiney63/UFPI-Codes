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
	clientes[pos].bonus = 0; //atribuindo bonus zero para o cliente novato.
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
			printf("TOTAL EM COMPRAS: R$ %.2f\n", clientes[i].total_compras);
			printf("ULTIMA COMPRA: R$ %.2f\n\n", clientes[i].ultima_compra.valor_total_compra);
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


int efetivarCompra(tCliente clientes[MAX], tBonus *bonificacao, int *opcao, int *posicao_atual)
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
	
	//pegando o indice do cliente com o cpf em especifico.
	int i = verificarCPF(clientes, cpf_informado, &(*posicao_atual)), escolha_bonus;
	float valor_compra, pagamento_cliente;
	
	//mostra o bonus do cliente em especifico e o quanto vale esse bonus.
	printf("\n---------------------------------\n");
	printf("BONUS = %d\n", clientes[i].bonus);
	printf("VALOR CORRESPONDENTE = R$ %.2f", clientes[i].bonus * bonificacao->valor);
	printf("\n---------------------------------\n");
	
	printf("\nQual o valor da compra? R$ ");
	do {
		scanf("%f", &valor_compra);
		if(valor_compra < 0) {
			printf("\nErro: valor negativo!\nDigite novamente: R$ ");
		}
	} while(valor_compra < 0);
	
	float aux_ultima_compra = valor_compra; //serve para auxiliar caso a compra não seja feita.
	int aux_valor_bonus = clientes[i].bonus; //serve para auxiliar caso o bonus seja gasto, porem a compra não feita.
	
	if(clientes[i].bonus != 0) { //faz a pergunta de uso do bonus apenas se ele for diferente de zero.
		printf("\nDeseja utilizar seu bonus? \n[1 - SIM / 0 - NAO]\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &escolha_bonus);
		if(escolha_bonus == 1) { //se ele deseja usar, faz o gasto completo do bonus se possivel.
			//converto o bonus em dinheiro
			float valor_bonus = clientes[i].bonus * bonificacao->valor; 
			valor_compra = valor_compra - valor_bonus;
			int valor_bonus_atualizado = 0; //atribuo o bonus como zero se for totalmente gasto
			if(valor_compra < 0.0) { //aqui vejo se o bonus foi totalmente gasto, caso contrario
			//o cliente recebe o restante não gasto.
				valor_bonus = valor_compra * -1;
				valor_compra = 0.0; //zera caso o bonus seja maior que o valor da compra
				valor_bonus_atualizado = (int)(valor_bonus/bonificacao->valor); //como o bonus não zerou ele recebe o restante
			}
			clientes[i].bonus = valor_bonus_atualizado; //atualizando bonus apos utilizar o mesmo.
			printf("\n---------------------------------\n");
			printf("BONUS ATUAL = %d", valor_bonus_atualizado);
			printf("\nVALOR DA COMPRA ATUALIZADO = R$ %.2f\n", valor_compra);
			printf("---------------------------------\n");
		}
	}
	
	printf("\nQual o valor do pagamento do cliente? R$ ");
	do {
		scanf("%f", &pagamento_cliente); //pergunta quando o cliente vai pagar, valor é
		//forçado a ser positivo
		if(pagamento_cliente < 0) {
			printf("\nErro: valor negativo\nDigite novamente: R$ ");
		}
	} while(pagamento_cliente < 0);
	
	do{ //caso o pagamento do cliente sela inferior ao valor da compra
		if(valor_compra > pagamento_cliente) {
			int escolha_fornecer_dinheiro;
			printf("\nErro: Valor do pagamento inferior ao valor da compra.");
			printf("\nDeseja fornecer mais dinheiro? ");
			printf("\n[1 - SIM / 0 - NAO]\n");
			printf("Escolha: ");
			scanf("%d", &escolha_fornecer_dinheiro);
			if(escolha_fornecer_dinheiro == 1) { //pede ao cliente para fornecer mais dinheiro
				float valor_adicional;
				printf("\nInforme quanto deseja adicionar: R$ ");
				scanf("%f", &valor_adicional);
				pagamento_cliente += valor_adicional;
			} else { //se o dinheiro não for fornecido e continuar inferior, o bonus gasto é devolvido
				clientes[i].bonus = aux_valor_bonus;
				system("cls");
				printf("\n---------------------------------\n");
				printf("COMPRA NAO EFETIVADA\nValor devolvido ao cliente: R$ %.2f\n", pagamento_cliente);
				printf("---------------------------------\n\n");
				system("pause");
				system("cls");
				return 0;
			}
		}
	}while(valor_compra > pagamento_cliente); //continua enquanto o pagamento ser inferior à compra.
	
	//apos o dinheiro ser fornecido corretamente, a ultima compra é atualizada
	clientes[i].ultima_compra.valor_total_compra = aux_ultima_compra; //atualizando o valor da ultima compra.
	clientes[i].total_compras += (float)aux_ultima_compra; //atualizando o total de compras.
	
	//o cliente so recebe o bonus, caso não tenha chegado no teto e tenha pago um valor minimo para ser bonificado
	if(pagamento_cliente >= bonificacao->valor_bonificar && clientes[i].bonus < bonificacao->teto+1) {
		if(pagamento_cliente-valor_compra == 0.0) {
			clientes[i].bonus += (int)(pagamento_cliente/bonificacao->valor_bonificar);
		} else { //tira a diferença do preco caso seja maior que o valor da compra
			float diferenca_preco = pagamento_cliente-valor_compra;
			clientes[i].bonus += (int)((pagamento_cliente-diferenca_preco)/bonificacao->valor_bonificar);
		}		
	}
	//o bonus é diminuido caso tenha passado do teto, voltando para o teto
	if(clientes[i].bonus > bonificacao->teto) {
		clientes[i].bonus -= (clientes[i].bonus-bonificacao->teto);
	}
	
	if(pagamento_cliente > valor_compra) {
		printf("\n---------------------------------\n");
		printf("\nTROCO = R$ %.2f\n", pagamento_cliente-valor_compra);
		printf("\n---------------------------------\n");
		system("pause");
	}
	
	clientes[i].ultima_compra.compra_cancelada = 0; //zerando compra cancelada.
	
	system("cls");//limpa tudo, apos a compra ser realizada corretamente
	printf("\n---------------------------------\n");
	printf("\nCOMPRA EFETIVADA COM SUCESSO\n");
	printf("\n---------------------------------\n");
	system("pause");
	system("cls");
	
	return 0;
}


int cancelarCompra(tCliente clientes[MAX], tBonus *bonificacao, int *opcao, int *posicao_atual)
{	
	system("cls");
	char cpf_informado[12];
	printf("\n-------- CANCELAR COMPRA --------\n");
	printf("Qual o CPF do cliente? \nInforme: ");
	scanf("%s", cpf_informado); //ususario informa o cpf do cliente que deseja cancelar a compra.
	
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual)) == -1) {
		//caso o cpf não exista, da erro e retorna para o menu principal.
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0; //opcao zerada para passar direto pelo menu compra e ir ao menu principal.
	
	} else { //caso exista um cpf entao é perguntado
		int i = verificarCPF(clientes, cpf_informado, &(*posicao_atual));
		int escolha;
		do {
			printf("\nQual compra deseja cancelar?\n");
			printf("[1 - Ultima compra, 2 - Outra compra]\n");
			printf("informe: ");
			scanf("%d", &escolha);
		} while(escolha != 1 && escolha != 2);
		
		int escolha_cancelamento;
		
		if(escolha == 1) {
			if(clientes[i].ultima_compra.compra_cancelada == 1) {
				printf("\nERRO: Ultima compra ja cancelada!\n");
				system("pause");
				system("cls");
				return *opcao = 0; //se a compra ja tiver sido cancelada retorna ao menu principal
			} else {
				printf("\n-----------------------\n");
				printf("Valor da compra: R$ %.2f\n", clientes[i].ultima_compra.valor_total_compra);
				printf("Bonus: ??");
				printf("\n-----------------------\n");
				printf("\nTem certeza que deseja cancelar essa compra?\n");
				printf("[1 - Sim | 0 - Nao]\n");
				printf("Informe: ");
				scanf("%d", &escolha_cancelamento);
				if(escolha_cancelamento != 1) {
					printf("\nCOMPRA NAO CANCELADA!\n");
					system("pause");
					system("cls");
					return *opcao = 0;
				} else { //caso seja cancelada atualiza o bonus e valor total
					clientes[i].total_compras -= clientes[i].ultima_compra.valor_total_compra; //atualizando o valor total de compras
					//clientes[i].bonus += *bonus_cancela_ultimaCompra; //atualizando bonus  do cliente
					clientes[i].ultima_compra.compra_cancelada = 1;
					printf("\nCOMPRA CANCELADA!\n");
					system("pause");
					system("cls");
					return 0;
				}
			}
		} else if(escolha == 2) {
			float valor_compra_cancelar;
			printf("\nQual o valor da compra a ser cancelada?\n");
			printf("Informe: R$ ");
			scanf("%f", &valor_compra_cancelar);
			printf("\n-----------------------\n");
			printf("Valor da compra: R$ %.2f\n", valor_compra_cancelar);
			printf("Bonus: %d", (int)(valor_compra_cancelar/bonificacao->valor_bonificar));
			printf("\n-----------------------\n");
			printf("\nTem certeza que deseja cancelar essa compra?\n");
			printf("[1 - Sim | 0 - Nao]\n");
			printf("Informe: ");
			scanf("%d", &escolha_cancelamento);
			if(escolha_cancelamento != 1) {
				printf("\nCOMPRA NAO CANCELADA!\n\n");
				system("pause");
				system("cls");
				return *opcao = 0;
			} else { //caso seja cancelada atualiza o bonus e valor total
				clientes[i].total_compras -= valor_compra_cancelar; //atualizando o valor total de compras
				clientes[i].bonus -= ((int)(valor_compra_cancelar/bonificacao->valor_bonificar)); //atualizando bonus  do cliente
				printf("\nCOMPRA CANCELADA!\n\n");
				system("pause");
				system("cls");
				return 0;
			}
		}
	}
	
	return 0;
}

/*
Função que imprime e controla o MENU COMPRAS,
chamando as outras subfunções(EFETIVAR, CANCELAR), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para 
o menu principal junto de um avsio de saida.
*/
void menuCompras(tCliente clientes[MAX], tBonus *bonificacao, int *posicao_atual)
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
			case 1: efetivarCompra(clientes, &(*bonificacao), &opcao, &(*posicao_atual));
				break;
			case 2: cancelarCompra(clientes, &(*bonificacao), &opcao, &(*posicao_atual));
				break;
			case 0: system("cls");
				break;
			default: printf("\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
}


int configurarBonus(tBonus *bonificacao, int *opcao)
{
	system("cls");
	int escolha;
	do{
		printf("------ CONFIGURAR BONUS ------\n");
		printf("1 - Alterar teto\n2 - Alterar valor do bonus\n3 - Alterar valor para receber bonus\n0 - Sair");
		printf("\n------------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &escolha);
		
		switch(escolha) {
			case 1:
				system("cls");
				printf("Qual o novo valor do teto?\nInforme: ");
				do{
					scanf("%d", &bonificacao->teto);
					if(bonificacao->teto < 0) {
						printf("\nErro: valor negativo. \nDigite novamente: ");
					}
				}while(bonificacao->teto < 0);
				printf("\n------------------------------------\n");
				printf("Teto do bonus configurado com sucesso!");
				printf("\n------------------------------------\n\n");
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Qual o novo valor de 1 bonus?\nInforme: R$ ");
				do{
					scanf("%f", &bonificacao->valor);
					if(bonificacao->valor < 0.0) {
						printf("\nErro: valor negativo. \nDigite novamente: R$ ");
					}
				}while(bonificacao->valor < 0.0);
				printf("\n------------------------------------\n");
				printf("Valor do bonus configurado com sucesso!");
				printf("\n------------------------------------\n\n");
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf("Qual o novo valor para receber o bonus?\nInforme: R$ ");
				do{
					scanf("%f", &bonificacao->valor_bonificar);
					if(bonificacao->valor_bonificar < 0.0) {
						printf("\nErro: valor negativo. \nDigite novamente: R$ ");
					}
				}while(bonificacao->valor_bonificar < 0.0);
				printf("\n-----------------------------------------------\n");
				printf("Valor para receber bonus bonfigurado com sucesso!");
				printf("\n-----------------------------------------------\n\n");
				system("pause");
				system("cls");
				break;
			case 0: system("cls");
				break;
			default: system("cls"); printf("\n------------------------\n\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(escolha != 0);
	
	return *opcao = 0;
}


int exibirBonus(tCliente clientes[MAX], tBonus *bonificacao, int *opcao, int *posicao_atual)
{
	system("cls");
	char cpf_informado[12];
	printf("\n-------- EXIBIR BONUS --------\n");
	printf("Qual o CPF do cliente? \nInforme: ");
	scanf("%s", cpf_informado); //ususario informa o cpf do cliente que deseja exibir o bonus.
	
	if(verificarCPF(clientes, cpf_informado, &(*posicao_atual)) == -1) {
		//caso o cpf não exista, da erro e retorna para o menu principal.
		system("cls");
		printf("\n------------------------\n");
		printf("\nErro: CPF nao cadastrado.\n\n");
		printf("------------------------\n");
		system("pause");
		system("cls");
		return *opcao = 0; //opcao zerada para passar direto pelo menu bonus e ir ao menu principal.
	} 
	
	int i = verificarCPF(clientes, cpf_informado, &(*posicao_atual));
	
	printf("\n-------------------------------\n");
	printf("BONUS = %d\nVALOR CORRESPONDENTE = R$ %.2f", clientes[i].bonus, clientes[i].bonus * bonificacao->valor);
	printf("\n-------------------------------\n");
	system("pause");
	system("cls");
	return 0;
}

/*
Função que imprime e controla o MENU BONUS,
chamando as outras subfunções(CONFIGURAR, EXIBIR), atraves de um switch case,
caso a opcao escolhida seja invalida(não seja 1, 2 ou 0), ira retornar um aviso,
e ira pedir para o usuario informar novamente outro valor, o menu 
só é finalizado caso o usuario digite 0, retornando para o 
menu principal junto de um avsio de saida.
*/
void menuBonus(tCliente clientes[MAX], tBonus *bonificacao, int *posicao_atual)
{
	system("cls");
	int opcao;
	do {
		printf("\n------ MENU BONUS ------ \n");
		printf("1 - Configurar\n2 - Exibir\n0 - Sair\n");
		printf("------------------------\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		printf("------------------------\n");
		
		switch(opcao) {
			case 1: configurarBonus(&(*bonificacao), &opcao);
				break;
			case 2: exibirBonus(clientes, &(*bonificacao), &opcao, &(*posicao_atual));
				break;
			case 0: system("cls");
				break;
			default: system("cls"); printf("\n------------------------\n\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	return;
}

void listarClientes(tCliente clientes[MAX], int *posicao_atual)
{
	system("cls");
	int i;
	if(*posicao_atual == -1) {
		printf("\nNenhum cliente cadastrado ainda!!!!\n\n");
	}
	for(i = 0; i <= *posicao_atual; i++) {
		printf("\n---- CLIENTE (%d) ----\n", i+1);
		printf("NOME: %s\n", clientes[i].nome);
		printf("CPF: %s\n", clientes[i].cpf);
		printf("TELEFONE: %s\n", clientes[i].telefone);
		printf("EMAIL: %s\n", clientes[i].email);
		printf("BONUS: %d\n", clientes[i].bonus);
		printf("TOTAL EM COMPRAS: R$ %.2f\n", clientes[i].total_compras);	
	}
	printf("\n");
	system("pause");
	system("cls");
	return;
}

void listarBonus(tCliente clientes[MAX], tBonus *bonificacao, int *posicao_atual) 
{
	system("cls");
	int i;
	if(*posicao_atual == -1) {
		printf("\nNenhum cliente cadastrado ainda!!!!\n\n");
	}
	for(i = 0; i <= *posicao_atual; i++) {
		printf("\n------------- CLIENTE (%d) -------------\n", i+1);
		printf("BONUS = %d\nVALOR CORRESPONDENTE = R$ %.2f\n", clientes[i].bonus, clientes[i].bonus * bonificacao->valor);
		printf("\n----------------------------------------\n");
	}
	printf("\n");
	system("pause");
	system("cls");
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
void menuRelatorios(tCliente clientes[MAX], tBonus *bonificacao, int *posicao_atual)
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
			case 1: listarClientes(clientes, &(*posicao_atual));
				break;
			case 2: listarBonus(clientes, &(*bonificacao), &(*posicao_atual));
				break;
			case 3: listarClientePorCompra();
				break;
			case 0: system("cls");
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
void menuPrincipal(tCliente clientes[MAX], tBonus *bonificacao, int *posicao_atual) 
{
	system("cls");
	int opcao;
	if(*posicao_atual == -1) { //declaro um unico momento os valores iniciais da bonificação
		bonificacao->teto = 100;
		bonificacao->valor = 0.5;
		bonificacao->valor_bonificar = 100.0;
	}
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
			case 2: menuCompras(clientes, &(*bonificacao), &(*posicao_atual));
				break;
			case 3: menuBonus(clientes, &(*bonificacao), &(*posicao_atual));
				break;
			case 4: menuRelatorios(clientes, &(*bonificacao), &(*posicao_atual));
				break;
			case 0: printf("\nPrograma Finalizado!\n");
				break;
			default: system("cls"); printf("\n------------------------\n\nEscolha uma opcao valida!\n\n------------------------\n");
		}
	} while(opcao != 0);
	return;
}

int main(int argc, char *argv[]) {
	tCliente clientes[MAX];
	tBonus bonificacao;
	int posicao_atual = -1; //inicio posição com -1, so ira para zero caso o cliente seja cadastrado
	menuPrincipal(clientes, &bonificacao, &posicao_atual);
	return 0;
}
