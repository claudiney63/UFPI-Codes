# 1. Peça para o usuário digitar o seu nome completo. Imprima a quantidade de
# caracteres no nome do usuário (sem contar o caractere de espaço).

nome = input("Informe seu nome: ")

print(len(nome) - nome.count(' '))