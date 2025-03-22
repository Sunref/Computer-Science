#--------------------------
#                          
# @author FernandaDesktop  
# Fernanda Martins da Silva
# BV3032345                
#                          
#--------------------------

import random

def adicionarElementos(matriz, elementos):
    for elemento, posicao in elementos.items():
        linha, coluna = posicao
        matriz[linha][coluna] = elemento

def marcaCaminho(matriz, caminho):

    contaSimbolos = {'Vertical': 0, 'Horizontal': 0, 'Diagonal': 0} #conta os simbolos

    for x, y, symbol in caminho:
        if matriz[x][y] != 'R':
            matriz[x][y] = symbol #marca o simbolo R caso posicao ocupada seja pelo rato

        #contagem dos símbolos
        if symbol == '|':
            contaSimbolos['Vertical'] += 1
        elif symbol == '-':
            contaSimbolos['Horizontal'] += 1
        else:
            contaSimbolos['Diagonal'] += 1

    return contaSimbolos

linha = 15  #num linhas da matriz
coluna = 15  #num colunas da matriz
matriz = [[' '] * coluna for _ in range(linha)]

#add gato e rato na matriz randomicamente
gatoX = random.randint(0, linha - 1)
gatoY = random.randint(0, coluna - 1)
ratoX = random.randint(0, linha - 1)
ratoY = random.randint(0, coluna - 1)

elementos = {'G': (gatoX, gatoY),
            'R': (ratoX, ratoY)}

adicionarElementos(matriz, elementos)

#calcula o caminho do G até o R
caminho = []
PosAtual = (gatoX, gatoY)

while PosAtual != (ratoX, ratoY):
    dx = 1 if PosAtual[0] < ratoX else -1 if PosAtual[0] > ratoX else 0 #determina as direcoes
    dy = 1 if PosAtual[1] < ratoY else -1 if PosAtual[1] > ratoY else 0 #determina as direcoes

    #com base nas direcoes, atribue um simbolo
    if dx == 0:
        symbol = '-'  #horizontal
    elif dy == 0:
        symbol = '|'  #vertical
    elif dx * dy == 1:
        symbol = '\\'  #diagonal sup. esquerda ou inf. direita
    else:
        symbol = '/'  #diagonal sup. direita ou inf. esquerda

    NovaPos = (PosAtual[0] + dx, PosAtual[1] + dy, symbol)
    caminho.append(NovaPos)
    PosAtual = NovaPos[:-1]

#remove pos. inicial do caminho
caminho = [(x, y, symbol) for x, y, symbol in caminho if (x, y) != elementos['G']]

#caso o gato estiver longe, marca o caminho original da matriz
NumCasas = len(caminho)
if NumCasas > 10:
    print("O rato está longe demais!")
else:
    contaSimbolos = marcaCaminho(matriz, caminho)

    print("O gato andou", NumCasas, "posicao(oes). As direcoes foram:")
    for symbol, count in contaSimbolos.items():
        print(f"{symbol}: {count}")