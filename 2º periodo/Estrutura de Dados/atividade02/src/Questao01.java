import java.util.*;

//Implementar um programa para localizar uma determinada palavra, fornecida pelo usuário,
//em uma lista de 10 palavras pré-definidas.

public class Questao01 {
    public static void main(String[] args) throws Exception{
        String palavras[] = {"Garfo", "Carro", "Ferro", "Judas", "Caderno", "Teclado", 
        "Perfume", "Parede", "Prato", "Colher"};
        boolean existe = false;

        Scanner ler = new Scanner(System.in);

        System.out.println("Informe uma palavra para localizar: ");
        String localizarPalavra = ler.next();

        for (String palavra : palavras) {
            if(localizarPalavra.equals(palavra)) {
                System.out.println("Palavra existente!");
                existe = true;
                break;
            } else {
                existe = false;
            }
        }

        if(!existe) {
            System.out.println("Palavra não existente!");
        }

        ler.close();
    }
}
