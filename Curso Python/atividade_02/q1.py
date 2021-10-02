# 1 – Faça um programa que receba dois números e mostre qual deles é o maior.

num1 = float(input("Digite um número: "))

num2 = float(input("Digite um número: "))

if num1 > num2 : 
    print(num1, "é maior que", num2) 
elif num2 > num1 :
    print(num2, "é maior que", num1)
else :
    print(num2, "é igual a", num1)
