# 2 – Leia um conjunto de números reais, armazenando-o em vetor e calcular o
# quadrado das componentes deste vetor, armazenando o resultado em outro
# vetor. Os conjuntos têm 10 elementos cada. Imprimir todos os conjuntos.

i = 0
valores = []
valores_ao_quadrado = []
while i < 10 :
    valor = float(input("Informe um número: "))
    valores.insert(i, valor)
    valores_ao_quadrado.insert(i, (valor*valor))
    i += 1

print("Valores: ", valores)
print("Valores ao quadrado: ", valores_ao_quadrado)