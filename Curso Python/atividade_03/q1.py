# 1 – Faça um programa que receba um número e mostre o seu fatorial.

num = float(input("Informe um número: "))
i = 1
total = 1

while num > 0 :
    total *= i
    i = i + 1
    num = num - 1

print("Fatorial: ", total)
