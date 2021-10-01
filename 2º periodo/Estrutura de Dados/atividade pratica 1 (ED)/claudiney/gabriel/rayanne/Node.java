package claudiney.gabriel.rayanne;

public class Node {
	public Node proximo;
	public Pessoa pessoa;
	public int prioridade;
	
	Node (Pessoa pessoa) {
		this.pessoa = pessoa;
		this.prioridade = calcularPrioridade(pessoa.getIdade());
	}
	
	public int calcularPrioridade(int idade) {
		return idade / 10;
	}
}