package claudiney.gabriel.rayanne;
import java.util.*;

public class App {
	public static void main(String[] args) {
		/*Pessoa pessoa1 = new Pessoa("Gabriel", 93);
		Pessoa pessoa2 = new Pessoa("Claudiney", 60);
		Pessoa pessoa3 = new Pessoa("Rayanne", 72);
		Pessoa pessoa4 = new Pessoa("Enzo", 69);
		Pessoa pessoa5 = new Pessoa("Ciro", 95);
		
		Node node1 = new Node(pessoa1);
		Node node2 = new Node(pessoa2);
		Node node3 = new Node(pessoa3);
		Node node4 = new Node(pessoa4);
		Node node5 = new Node(pessoa5);
		
		FilaComPrioridade fila = new FilaComPrioridade();
		fila.inserir(node1);
		fila.inserir(node2);
		fila.inserir(node3);
		fila.inserir(node4);
		fila.inserir(node5);
		
		/*System.out.println(fila.remover());
		System.out.println(fila.remover());
		
		System.out.println(fila.listarFila());*/

		FilaComPrioridade fila = new FilaComPrioridade();
		Scanner in = new Scanner(System.in);
		int escolha, idade, qtdPrioridade = 0, qtdNormal = 0;
		String nome;

		do {
			System.out.println(
			"====================== MENU ======================\n"+
			"1) chegada de pessoa para atendimento;\n" + 
			"2) atendimento de uma pessoa;\n"+
			"3) listar todas as pessoas da fila;\n"+
			"4) gerar estatísticas;\n"+
			"0) fechar programa\n"+
			"==================================================\n"
			);

			escolha = in.nextInt();

			switch (escolha) {
				case 1:
					System.out.println("Informe o nome da pessoa: ");
					nome = in.next();
					System.out.println("Informe a idade da pessoa: ");
					do{
						idade = in.nextInt();
						if(idade < 1) {
							System.out.println("Idade negativa ou nula, informe novamente: ");
						}
					}while(idade < 1);
					Pessoa pessoa = new Pessoa(nome, idade);
					Node node = new Node(pessoa);
					fila.inserir(node);
					break;
				case 2:
					if(fila.estaVazia()) {
						System.out.println("Fila fazia!\n");

					} else {
						Pessoa pessoaAtendida;
						pessoaAtendida = fila.remover();
						
						System.out.println(
						"===== PESSOA ATENDIDA =====\n" + 
						pessoaAtendida+ 
						"\n===========================\n");

						if(pessoaAtendida.getIdade() > 60) {
							qtdPrioridade += 1;
						} else {
							qtdNormal += 1;
						}
					}
					break;
				case 3:
					System.out.println(
					"====== PESSOAS NA FILA ======\n" + 
					fila.listarFila()+
					"===========================");
					break;
				case 4:
					float porcentagemPrioridade, porcentagemNormal;
					int totalDeAtendimentos = qtdNormal + qtdPrioridade;

					if(totalDeAtendimentos == 0) {
						porcentagemNormal = 0;
						porcentagemPrioridade = 0;
						
					} else {
						porcentagemNormal = (float)(qtdNormal*100)/totalDeAtendimentos;
						porcentagemPrioridade = (float)(qtdPrioridade*100)/totalDeAtendimentos;
					}

					System.out.println("Atendimentos Prioritarios: " + porcentagemPrioridade + "%\n"
					+"Atendimentos Normais: " + porcentagemNormal + "%\n"
					+"Total de Atendimentos: " + totalDeAtendimentos + "\n");
					break;
				case 0:
					if(fila.estaVazia()) {
						System.out.println("Pessoas atendidas: "+(qtdNormal+qtdPrioridade)+"\n");
						escolha = 0;
					} else {
						System.out.println("Fila não está vazia!\n");
						escolha = -1;
					}
					break;
				default:
					System.out.println("Informe uma opção valida!\n");
					break;
			}

		}while(escolha != 0);

		in.close();
		
//		System.out.println(fila.verInicio());
//		fila.remover();
//		
//		System.out.println(fila.verInicio());

	}

}
