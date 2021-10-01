package claudiney.gabriel.rayanne;

public class Pessoa {
	private String nome;
	private int idade;
	
	Pessoa (String nome, int idade) {
		this.nome = nome;
		this.idade = idade;
	}

	public String getNome() {
		return nome;
	}

	public int getIdade() {
		return idade;
	}
	
	public String toString() {
		return "Nome: " + nome + "\n" + "Idade: " + idade + "";
	}
}
