# 6 – Faça um programa que receba três números e mostre-os em ordem
# crescente.

n1 = float(input("Informe um número: "))
n2 = float(input("Informe um número: "))
n3 = float(input("Informe um número: "))

listar = [n1, n2, n3]
listar.sort() 

print(listar)
