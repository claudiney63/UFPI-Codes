#4 - Escreva o menu de opções abaixo. Leia as opções do usuário e execute a
# operação escolhida. Escreva uma mensagem de erro se a opção for inválida.
# • Escolha a opção:
# • 1 – Soma de 2 Números
# • 2 – Diferença entre 2 números (Maior pelo menor)
# • 3 – Produto entre 2 números
# • 4 – Divisão entre 2 números (denominador não pode ser zero)
# • Opção:

opcao = 0
while opcao >= 0 :
    print("\n========== MENU ==========")
    print("0 - Sair")
    print("1 - Soma de 2 Números")
    print("2 - Diferença de 2 Números")
    print("3 - Produto de 2 Números")
    print("4 - Divisão de 2 Números")
    opcao = int(input("Opção: "))
    print("\n")

    if opcao == 1 :
        n1 = float(input("Informe um número: "))
        n2 = float(input("Informe outro número: "))
        print("Soma: ", n1+n2)

    elif opcao == 2 :
        n1 = float(input("Informe um número: "))
        n2 = float(input("Informe outro número: "))
        if n1 > n2 :
            print("Diferença: ", n1-n2)
        else :
            print("Difereça: ", n2-n1)

    elif opcao == 3 :
        n1 = float(input("Informe um número: "))
        n2 = float(input("Informe outro número: "))
        print("Multiplicação: ", n1*n2)

    elif opcao == 4 :
        n1 = float(input("Informe um número: "))
        n2 = float(input("Informe outro número: "))

        while n2 == 0 :
            n2 = float(input("Informe outro número: "))
        print("Divisão: ", n1/n2)
        
    elif opcao == 0 :
        opcao = -1
    else :
        print("Informe uma opção valida!")

print("Fim do Programa")