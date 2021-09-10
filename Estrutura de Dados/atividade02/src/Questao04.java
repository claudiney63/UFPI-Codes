import java.util.Scanner;

/**
Sabendo que a MEDIANA é o valor (pertencente ou não ao conjunto de dados) que divide o
conjunto de dados em dois subconjuntos de mesmo tamanho. De uma forma mais simples, é
o valor que divide o conjunto de dados ao meio. (Ver os exemplos abaixo):
Ex: Salário: 1500 1300 1200 1250 1600 1100 1450 1210 1980
Rol = {1100, 1200, 1210, 1250, 1300, 1450, 1500, 1600, 1980}
Md = 1300
Ex: Salário: 1500 1300 1200 1250 1600 1100 1450 1210 1980 1420
Rol = {1100, 1200, 1210, 1250, 1300, 1420, 1450, 1500, 1600, 1980}
Md = (1300 + 1420) / 2 = 2720 / 2 = 1360
Fazer um programa para ler o conjunto de valores numéricos (inteiros ou reais) e imprima o
valor da mediana.
*/

public class Questao04 {
    public static void main(String[] args) throws Exception{

        Scanner ler = new Scanner(System.in);

        System.out.println("Quantos valores deseja adicionar ao conjunto: ");
        int valores;
        do {
            valores = ler.nextInt();
            if(valores <= 0) {
                System.out.println("Valor negativo ou nulo, informe novamente: ");
            }
        }while(valores <= 0);

        float vetorValores[] = new float[valores];

        for (int i = 0; i < valores; i++) {
            System.out.println("Informe um valor: ");
            float valor = ler.nextFloat();
            vetorValores[i] = valor;
        }

        float aux;

        for (int i = 0; i < valores; i++) { //colocando os valores em ordem crescente
            for (int j = i+1; j < valores; j++) {
                if(vetorValores[i] > vetorValores[j]) {
                    aux = vetorValores[i];
                    vetorValores[i] = vetorValores[j];
                    vetorValores[j] = aux;
                }
            }
        }

        System.out.println("\n");

        for (float f : vetorValores) { //imprimindo-os em ordem crescente
            System.out.println(f);
        }

        if(valores%2 != 0) {
            System.out.println("\nMd = "+vetorValores[(valores-1)/2]);
        } else {
            System.out.println("\nMd = "+(vetorValores[(valores/2)-1]+vetorValores[valores/2])/2);
        }
        ler.close();
    }
}
