package claudiney.gabriel.rayanne;

public class FilaComPrioridade {
	private Node inicio;
	private int quantidade = 0;
	
	public void inserir (Node novo) {
		if (estaVazia()) {
			novo.proximo = inicio;
			inicio = novo;
		}
		
		else {
			if (inicio.prioridade < novo.prioridade) {
				novo.proximo = inicio;
				inicio = novo;
			}
			
			else {
				Node temp = inicio;
				
				while (temp.proximo != null && temp.proximo.prioridade >= novo.prioridade) {
					temp = temp.proximo;
				}
				
				novo.proximo = temp.proximo;
				temp.proximo = novo;
			}
		}
		
	quantidade++;
	}
	
	public Pessoa remover () {
		if (estaVazia()) {
			return null;
		}
		
		else {
			Pessoa pessoa = inicio.pessoa;
			inicio = inicio.proximo;
			quantidade--;
			return pessoa;
		}
	}
	
	public boolean estaVazia () {
		return quantidade == 0;
	}
	
	public Pessoa verInicio () {
		if (estaVazia()) {
			return null;
		}
		
		else {
			return inicio.pessoa;
		}
	}
	
	public String listarFila () {
		if (estaVazia()) {
			return "Nao existem pessoas na fila!";
		}
		
		else {
			Node temp = inicio;
			String listagem = "";
			int contador = 1;
			
			while (contador <= quantidade) {
				listagem += "Posicao: " + contador + "\n";
				listagem += "Nome: " + temp.pessoa.getNome() + "\n";
				listagem += "Idade: " + temp.pessoa.getIdade() + "\n";
				listagem += "\n";
				
				temp = temp.proximo;
				
				contador++;
			}
			
			return listagem;
		}
	}
	
}
