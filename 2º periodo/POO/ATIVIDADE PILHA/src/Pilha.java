public class Pilha {
	public int[] pilha; //Array do tipo inteiro 
    public int posicaoPilha; //Serve para saber uma posicao atual da pilha

    public Pilha() { //construtor
        this.posicaoPilha = -1; //valor neutro, ir� virar zero caso seja adicionado o primeiro valor
        this.pilha = new int[10]; //iniciando a pilha com 10 posicoes
    }

    public void push(int n) { //M�todo para inserir um elemento no topo da pilha
        if(this.posicaoPilha < pilha.length - 1) { //verifica se a posicao atual � menor que o tamanho da pilha
            this.pilha[++posicaoPilha] = n;
        }//caso nao seja ele nem adiciona o valor dentro da pilha, mostrando que ela esta cheia
    }

    public int top() { //M�todo para retornar o elemento que est� no topo da pilha
        return this.pilha[this.posicaoPilha];
    }

    public void pop() { //M�todo para remover o elemento no topo da pilha
        this.posicaoPilha--;
    }

    public static void main(String[] args) throws Exception {
        Pilha pilha = new Pilha();

        pilha.push(50);
        pilha.push(450);
        pilha.push(200);
        pilha.push(10);
        System.out.println(pilha.top());
        pilha.pop();
        System.out.println(pilha.top());
        
    }
}
