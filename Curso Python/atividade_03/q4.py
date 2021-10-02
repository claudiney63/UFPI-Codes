# 4 – Faça um programa que receba um número e mostre a sua tabuada.

num = float(input("Informe um número: "))
cont = 0

while cont <= 10 :
    print(num," x ",cont," = ",(num*cont))
    cont += 1