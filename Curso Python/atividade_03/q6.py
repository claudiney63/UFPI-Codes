# 6 – Faça um algoritmo para ler um número indeterminado de dados, contendo
# cada um, a idade de um indivíduo. O último dado, que não entrará nos cálculos,
# contém o valor de idade negativa. Calcular e imprimir a idade média deste grupo
# de indivíduos.

idade = 1
media = 0
cont = 0

while idade > 0 :
    idade = int(input("Informe uma idade: "))
    if idade > 0 :
        cont += 1
        media += idade

media = float(media/cont)

print("Média = ", media)