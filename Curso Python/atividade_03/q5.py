# 5 – Na matemática, um número perfeito é um número inteiro para o qual a soma
# de todos os seus divisores positivos próprios (excluindo-o) é igual ao próprio
# número. Por exemplo, o número 6 é perfeito, pois 1+2+3 é igual a 6. Sua tarefa
# é escrever um programa que imprima se um determinado número é perfeito ou
# não.

num = float(input("Informe um número: "))
divisor = 1
soma = 0

while divisor < num :
    if num%divisor == 0 :
        print(divisor)
        soma += divisor  
    divisor = divisor + 1

if soma == num :
    print("PERFEITO")
else :
    print("NÃO PERFEITO")
