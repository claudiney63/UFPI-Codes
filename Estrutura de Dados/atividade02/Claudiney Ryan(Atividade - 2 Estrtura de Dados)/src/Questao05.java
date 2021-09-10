import java.util.*;

/**
Sabendo que a MODA é o valor que mais aparece num conjunto de dados. (Ver os exemplos
abaixo):
Ex: Idade: {12, 11, 12, 13, 12, 11, 13, 12, 12, 11, 14, 13, 13, 12, 11, 12, 13, 14, 11, 14}
Mo = 12 (pois é a idade que aparece mais vezes no conjunto)
Ex: Nr. Calçados: {35, 33, 36, 35, 37, 36, 39, 40, 42, 43, 35, 36, 42}
Mo = 35 ou Mo = 36 (conjunto de dados multimodal)
Fazer um programa para ler o conjunto de valores numéricos (inteiros ou reais) e imprima o
valor da mediana.
*/

public class Questao05 {
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

        float valoresRecebidos[] = new float[valores];

        for (int i = 0; i < valores; i++) { //recebendo valores e preenchendo vetor
            System.out.println("Informe um valor: ");
            float valor = ler.nextFloat();
            valoresRecebidos[i] = valor;
        }

        Map<Float, Integer> valoresRepetidos = new HashMap<Float, Integer>();
        int cont = 0;

        for(int i = 0; i < valores; i++) { //comparando cada valor com o conjunto de valores
            for(int j = 0; j < valores; j++) { //e contando quantas vezes ele se repete
                if(valoresRecebidos[i] == valoresRecebidos[j]) {
                    cont++;
                }
            }
             //adciona o valor ao mapa como chave e calcula quantas vezes se repete
            valoresRepetidos.put(valoresRecebidos[i], cont); 
            cont = 0;
        }

        int vezesRepetidas[] = new int[valores], i = 0;

        //pego a quantidade de vezes repetidas de cada valor
        for (Map.Entry<Float, Integer> entry : valoresRepetidos.entrySet()) {
            //Float key = entry.getKey();
            int value = entry.getValue();
            vezesRepetidas[i] = value;
            i++;
            //System.out.println(key+" se repete "+value+" vezes");
        }

        int aux = 1, auxCont = 0;

        for (int val : vezesRepetidas) { //caso um unico valor ou mais se repitam mais vezes ou
            //uma unica vez mais que outras quantidades de repetição, uso um auxiliar 
            //para capturar essa quantidade
            if(aux < val) {
                aux = val;
            } else {
                auxCont++;
            }
        }

        System.out.println("\n");

        //se a quantidade for igual ao numero de valores do conjunto ele mostra que não possui moda
        if(auxCont == valores) {
            System.out.println("Esse conjunto não possui MODA ou é AMODAL");
        } else { //caso contrario apresenta a maior quantidade de valores repetidos de um unico ou mais
            for (Map.Entry<Float, Integer> entry : valoresRepetidos.entrySet()) {
                Float key = entry.getKey();
                int value = entry.getValue();
                if(value == aux) {
                    System.out.println(key+" é a MODA e se repete "+value+" vezes");
                }
            }
        }

        ler.close();
    }
}