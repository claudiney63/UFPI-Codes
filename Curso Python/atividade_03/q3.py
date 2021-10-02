# 3 – Faça um programa que receba um número e mostre todos os seus divisores.

num = float(input("Informe um número: "))
divisor = 1

while divisor <= num :
    if num%divisor == 0 :
        print(divisor)
    divisor = divisor + 1