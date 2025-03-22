#-------------
#
# - Projeto Cálculo Nmeŕico - 
#   Fernanda Martins BV3032345
#   Gabriel Maia Miguel BV3035522 -
#
#-------------

import math

def verifica_ValIntermed(f, a, b):

    if f(a) * f(b) < 0:
        print("\nO Teorema do Valor Intermediário pode ser aplicado: a função muda de sinal no intervalo fornecido.\n")
        return True
    else:
        print("\nO Teorema do Valor Intermediário não pode ser aplicado: f(a) e f(b) têm o mesmo sinal.\n")
        return False

def bisseccao(f, a, b, Toler=1e-2, IterMax=50):

    if f(a) * f(b) > 0:
        print("O método da bissecção falhou: f(a) e f(b) têm o mesmo sinal.")
        return None, True

    deltax = abs(b - a)

    for Iter in range(IterMax):

        deltax = deltax / 2
        x = (a + b) / 2
        Fx = f(x)
        erro = abs(b - a) / 2

        print(f"Iteração {Iter + 1}: x = {round(x, 4)}, Erro = {round(erro, 4)}")

        if erro <= Toler and abs(Fx) <= Toler:
            x = round(x, 4)
            erro = round(erro, 4)
            print(f"Solução encontrada (Bisseção): x = {x}, Iterações: {Iter + 1}, Erro: {erro}\n")
            return x, False

        if f(b) * Fx < 0:
            a = b
        b = x

    print("Número máximo de iterações atingido.")
    return round(x, 4), True

def secante(f, a, b, IterMax=50, Toler=1e-2):

    if f(a) * f(b) >= 0:
        print("O método da secante falhou: f(a) e f(b) têm o mesmo sinal.")
        return None

    a_n = a
    b_n = b

    for n in range(1, IterMax + 1):
        
        m_n = a_n - f(a_n) * (b_n - a_n) / (f(b_n) - f(a_n))
        f_m_n = f(m_n)
        erro = abs(m_n - a_n)

        print(f"Iteração {n}: x = {round(m_n, 4)}, Erro = {round(erro, 4)}")

        if erro <= Toler and abs(f_m_n) <= Toler:
            m_n = round(m_n, 4)
            erro = round(erro, 4)
            print(f"Solução encontrada (Secante): x = {m_n}, Iterações: {n}, Erro: {erro}\n")
            return m_n

        if f(a_n) * f_m_n < 0:
            b_n = m_n
        else:
            a_n = m_n

    print("Número máximo de iterações atingido.")
    return round(a_n - f(a_n) * (b_n - a_n) / (f(b_n) - f(a_n)), 4)

def escolhe_funcao():

    print("Escolha uma função para calcular a raiz:")
    print("1. f(x) = x^2 - 15")
    print("2. f(x) = sen(x) - e^x")
    print("3. f(x) = cos(x) - x")
    escolha = int(input("Digite o número correspondente à função escolhida: "))

    if escolha == 1:
        return lambda x: x**2 - 15
    elif escolha == 2:
        return lambda x: math.sin(x) - math.exp(x)
    elif escolha == 3:
        return lambda x: math.cos(x) - x
    else:
        print("Opção inválida.")
        return None

def encontra_raiz(f, a, b, Toler=1e-2, IterMax=50):
    
    if not verifica_ValIntermed(f, a, b):
        return None

    raiz_bisseccao, erro_bisseccao = bisseccao(f, a, b, Toler, IterMax)
    raiz_secante = secante(f, a, b, IterMax, Toler)

    # Retorna os resultados dos dois métodos
    return raiz_bisseccao, raiz_secante

def main():

    #Escolhe a função
    func = escolhe_funcao()
    if func is None:
        exit()

    #Solicita os intervalos
    a = float(input("Digite o valor do limite inferior (a): "))
    b = float(input("Digite o valor do limite superior (b): "))

    #Encontra as raízes
    resultado = encontra_raiz(func, a, b)

    #Verifica se o resultado não é None
    if resultado is None:
        print("Erro ao encontrar as raízes.")

#Chama a função main
if __name__ == "__main__":
    main()