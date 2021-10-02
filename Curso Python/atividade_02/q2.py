# 2 - Leia um número fornecido pelo usuário. Se esse número for positivo, calcule a
# raiz quadrada do número. Se o número for negativo, mostre uma mensagem
# dizendo que o número é invalido.

import math

num = float(input("Digite um número: "))

if num > 0 :
    raiz = math.sqrt(num)
    print("Raiz quadrada:", raiz)
else :
    print("Número invalido!")
