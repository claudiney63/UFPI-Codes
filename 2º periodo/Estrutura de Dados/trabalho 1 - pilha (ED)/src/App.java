import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        ResizingArrayStack<String> pilha = new ResizingArrayStack<String>();
        boolean encerrar = true;
        int escolha;

        Scanner ler = new Scanner(System.in);

        do{
            System.out.println(
                "1) inserir um nome na pilha;\n"
                + "2) remover o último nome inserido;\n"
                + "3) listar os nomes armazenados na pilha;\n"
                + "4) mostrar o tamanho da pilha;\n"
                + "5) sair da aplicação;\n"
            );

            escolha = ler.nextInt();

            if(escolha == 1) {
                String nome = ler.nextLine();
                pilha.push(nome);
            } else if(escolha == 2) {
                pilha.pop();
            } else if(escolha == 3) {
                for (String nomePilha : pilha) {
                    System.out.println(nomePilha);
                }
            } else if(escolha == 4) {
                
            }

            if(escolha < 1 && escolha > 5) {
                System.out.println("Informe um valor valido!");
            }

        }while(encerrar);
        
    }
}
