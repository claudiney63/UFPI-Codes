# 4. Peça para o usuário digitar uma palavra. Conte quantas vogais ele inseriu na
# palavra e imprima essas informações posteriormente.

palavra = input("Informe uma palavra: ")
soma = 0

print(f"\nVogal \'a\': {palavra.count('a')}")
soma += palavra.count('a')
print(f"Vogal \'e\': {palavra.count('e')}")
soma += palavra.count('e')
print(f"Vogal \'i\': {palavra.count('i')}")
soma += palavra.count('i')
print(f"Vogal \'o\': {palavra.count('o')}")
soma += palavra.count('o')
print(f"Vogal \'u\': {palavra.count('u')}")
soma += palavra.count('u')
print(f"Total: {soma}")