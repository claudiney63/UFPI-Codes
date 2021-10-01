# 4 – Leia uma temperatura em graus Celsius e apresente-a convertida em graus
# Fahrenheit. Fórmula de conversão é: F = C * (9.0/5.0) + 32.0, sendo F a
# temperatura Fahrenheit e C a temperatura em Celsius.

c = float(input("Digite a temperatura em Celsius: "))
print("Temperatura em Fahrenheit: ", (c * (9.0/5.0)) + 32.0)