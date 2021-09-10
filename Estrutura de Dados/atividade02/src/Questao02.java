import java.util.*;

//Ler N valores inteiros, representando a idade de cada aluno(a), encontrar a idade do aluno(a)
//mais novo e do aluno(a) mais velho.

public class Questao02 {
    public static void main(String[] args) throws Exception{

        int maisNovo = 0, maisVelho = 0;

        Scanner ler = new Scanner(System.in);

        System.out.println("Quantos alunos informarão a idade: ");
        int alunos = ler.nextInt();
        int idadeAluno = 0;

        for (int i = 0; i < alunos; i++) {
            System.out.println("Informe a idade: ");
            do {
                idadeAluno = ler.nextInt();
                if(idadeAluno < 1) {
                    System.out.println("Idade negativa ou nula, informe novamente: ");
                }
            }while(idadeAluno < 1);
            if(i == 0) { //ambos recebem mesma idade inicialmente
                maisNovo = idadeAluno;
                maisVelho = idadeAluno;
            }
            if(maisNovo > idadeAluno && i >= 1) { //apartir da segunda idade
                maisNovo = idadeAluno;
            } 
            if(maisVelho < idadeAluno && i >= 1) {//apartir da segunda idade
                maisVelho = idadeAluno;
            }
        }

        System.out.println("\nMais novo possui: "+maisNovo+" anos");
        System.out.println("Mais velho possui: "+maisVelho+" anos");
        ler.close();
    }
}
