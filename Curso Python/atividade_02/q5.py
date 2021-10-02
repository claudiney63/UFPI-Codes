# 5 – Faça um programa que resolva equações do segundo grau.

import math

a = float(input("Informe o valor de a: "))

if a == 0 :
    print("Não é uma equação do 2º grau")

else :
    b = float(input("Informe o valor de b: "))
    c = float(input("Informe o valor de c: "))

    delta = math.sqrt((b*b)-4.0*(a*c))

    if delta < 0 :
        print("Não existem raizes")
    else :
        x1 = ((-1.0*b) + delta) / (2.0*a)
        x2 = ((-1.0*b) - delta) / (2.0*a)

        print("x' = ", x1)
        print("x'' = ", x2)
        