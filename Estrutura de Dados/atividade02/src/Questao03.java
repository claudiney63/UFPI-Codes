import java.util.*;

//Ler N valores inteiros, representando a idade de cada aluno(a), encontrar a média e
//determinar o quanto cada inteiro se desvia dessa média.

public class Questao03 {
    public static void main(String[] args) throws Exception{

        int somaIdades = 0;

        Scanner ler = new Scanner(System.in);

        System.out.println("Quantos alunos informarão a idade: ");
        int alunos;
        do {
            alunos = ler.nextInt();
            if(alunos <= 0) {
                System.out.println("Valor negativo ou nulo, informe novamente: ");
            }
        }while(alunos <= 0);

        int idadesAlunos[] = new int[alunos];
        int idadeAluno = 0;

        for (int i = 0; i < alunos; i++) {
            System.out.println("Informe a idade: ");
            do {
                idadeAluno = ler.nextInt();
                if(idadeAluno < 1) {
                    System.out.println("Idade negativa ou nula, informe novamente: ");
                }
            }while(idadeAluno < 1);
            idadesAlunos[i] = idadeAluno;
            somaIdades += idadeAluno;
        }

        System.out.println("\nMédia = "+somaIdades/alunos+" anos\n");

        for (int idade : idadesAlunos) {
            int desvio = (somaIdades/alunos) - idade;
            System.out.println("Idade ("+idade+") possui desvio da média de "+desvio+" anos");
        }
        ler.close();
    }
}
