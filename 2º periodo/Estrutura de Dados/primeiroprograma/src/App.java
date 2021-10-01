import java.util.Scanner;

public class App {

    static String getRandomString(int i) //metodo usado para gerar as palavras, recebe um parametro
    //que define a quantidade de letras
    { 
        String theAlphaNumericS; //variavel que recebe todas as letras
        StringBuilder builder;
        
        theAlphaNumericS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

        builder = new StringBuilder(i); 

        for (int m = 0; m < i; m++) { 
            int myindex = (int)(theAlphaNumericS.length() * Math.random()); 

            builder.append(theAlphaNumericS.charAt(myindex)); 
        } 
        return builder.toString(); 
    } 
    public static void main(String[] args) throws Exception {

        /*
        *variveis que controlam a quantidade de palavras geradas
        *um contador, uma variavel de controle para perceber a existencia de uma palavra
        *e uma varivel que recebe a palavra que o usuario deseja
         */
        int TAM = 1000, i, existe = 0;
        String palavras[] = new String[TAM];
        String palavra;

        Scanner ler = new Scanner(System.in);

        for(i = 0; i < TAM; i++) { //guardando palavras no vetor e apresentando-as
            palavras[i] = getRandomString(7);
            System.out.println(palavras[i]);
        }

        System.out.print("Qual palavra deseja? : "); //perguntando qual palavra deseja
        palavra = ler.nextLine();

        for(i = 0; i < TAM; i++) { 
        //fazendo comparações com a palavra informada com todas do vetor
            if(palavra.equals(palavras[i])) {
                existe = 1; //caso exista a variavel existe recebe 1 saindo do loop 
                break;
            } 
        }

        if (existe == 1) { //se a variavel tem valor como 1, entao existe
            System.out.println("Palavra existe na lista!");
        } else { //caso contrario a palavra não 
            System.out.println("Palavra não existe na lista!");
        }
    }
}