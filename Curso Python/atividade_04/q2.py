# 2. Peça que o usuário digite seu nome, sua idade e seu hobby favorito. Crie
# uma F-String que apresente essas informações, e depois imprima-a.

nome = input("Informe seu nome: ")
idade = int(input("Informe sua idade: "))
hobby = input("Informe seu hobby: ")

f_string = f"Nome: {nome};\nIdade: {idade};\nHobby: {hobby};"

print(f_string)