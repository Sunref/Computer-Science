package template;

import br.com.davidbuzatto.jsge.core.engine.EngineFrame;
import java.awt.Color;
import java.util.Stack;

/**
 *
 * Modelo de projeto básico da JSGE.
 *
 * JSGE basic project template.
 *
 * @author Prof. Dr. David Buzatto
 *
 * Projeto gráfico: Labirinto
 *
 * @author Fernanda Martins da Silva
 *
 */

public class Main extends EngineFrame{

    private int[][] arrayLabirinto;
    private int[][] tentativas;
    private Stack<int[]> pilhaCaminho;
    
    private boolean andando;
    private double tempoParaMudar;
    private double contadorTempo;
    
    // Cores... São muitas...
    private final Color parede = new Color(40, 50, 52);
    private final Color fundo = new Color(20, 30, 30);
    private final Color finalLab = new Color(157, 182, 163);
    private final Color caminho = new Color(236, 236, 236);
    private final Color visitado = new Color(157, 182, 163);
    private final Color concluido = new Color(105, 152, 115);

    public Main(){
        
        super(
                450,                    // Largura
                450,                    // Altura
                "Backtracking Maze",    // Título
                60,                     // FPS
                true,                   // Suavização
                false,                  // Redimensionável
                false,                  // Tela cheia
                true,                   // Sem decoração
                false,                  // Sempre no topo
                false                   // Fundo invisível
        );
        
    }
    
    
    /**
     *
     * Cria o mundo do jogo. Esse método executa apenas uma vez durante a
     * inicialização da engine.
     *
     */
    @Override
    public void create(){
        
        // Layout do labirinto (7, 7) onde:
        // 0 = caminho livre, 1 = parede, 2 = destino
        arrayLabirinto = new int[][]{
                {0, 0, 0, 0, 0, 1, 1},
                {0, 1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 2, 0}, // saída no (2,5)
                {0, 1, 1, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 1},
                {0, 1, 0, 0, 1, 0, 1},
                {1, 1, 1, 1, 1, 0, 0}
        };
        
        tentativas = new int[arrayLabirinto.length][arrayLabirinto[0].length];

        tempoParaMudar = 0.5;
        contadorTempo = 0;
        andando = false;

        pilhaCaminho = new Stack<>();
        pilhaCaminho.push(new int[]{0, 0});
        
    }

    /**
     *
     * Lê a entrada do usuário e atualiza o mundo do jogo. Os métodos de entrada
     * devem ser usados aqui. Atenção: Você NÃO DEVE usar nenhum dos métodos de
     * desenho da engine aqui.
     *
     * @param delta O tempo passado, em segundos, de um quadro para o outro.
     *
     */
    @Override
    public void update(double delta){
        
        contadorTempo += delta;

        if (!andando && contadorTempo >= tempoParaMudar) {
            contadorTempo = 0;
            resolverLabirinto();
        }
        
    }
    
    /**
     *
     * Desenha o mundo do jogo. Todas as operações de desenho DEVEM ser feitas
     * aqui.
     *
     */
    @Override
    public void draw(){
        
        clearBackground(fundo);
        
        desenharLabirinto(arrayLabirinto, getScreenWidth() / 50, getScreenHeight() / 50, 61, 1);
        
        drawText("Fim", 335, 163, 15, fundo);
        tentativas();
        
    }

    // Desenhando o layout do labirinto;
    private void desenharLabirinto(int[][] arrayLabirinto, int x, int y, int largura, int espacamento) {

        for (int i = 0; i < arrayLabirinto.length; i++){
            for (int j = 0; j < arrayLabirinto[i].length; j++){
                switch (arrayLabirinto[i][j]){
                    case 0 -> // Caminho livre
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                caminho
                        );
                    case 1 -> // Parede
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                parede
                        );
                    case 2 -> // Final do labirinto
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                finalLab
                        );
                    case 3 -> // Caminho percorrido
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                visitado
                        );
                    case 4 -> // Chegada no final do labirinto
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                concluido
                        );
                }
            }
        }

    }
    
    // Percorre o labirinto buscando a solução
    private void resolverLabirinto(){

        if (!pilhaCaminho.isEmpty()){ // Ainda existe caminho para explorar
            
            int[] atual = pilhaCaminho.peek();
            int x = atual[0];
            int y = atual[1];

            if (arrayLabirinto[x][y] == 2){ // Chegou ao final
                andando = true;
                arrayLabirinto[x][y] = 4; // Definindo nova cor para representar quando o final é alcançado
                return;
            }

            arrayLabirinto[x][y] = 3; // Definindo nova cor para representar o caminho percorrido
            tentativas[x][y] = 1; // Contando as tentativas de cada bloco
            tentativas[x][y]--;
            
            int[][] direcoes = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Baixo, direita, cima, esquerda
            boolean encontrouNovoCaminho = false;
            
            // Tentando encontrar um novo caminho válido no labirinto
            for (int[] d : direcoes){
                int novoX = x + d[0];
                int novoY = y + d[1];
                tentativas[x][y]++;
                
                if (novoX >= 0 && novoX < arrayLabirinto.length
                        && novoY >= 0 && novoY < arrayLabirinto[0].length
                        && (arrayLabirinto[novoX][novoY] == 0 
                        || arrayLabirinto[novoX][novoY] == 2)
                    ){
                    pilhaCaminho.push(new int[]{novoX, novoY});
                    encontrouNovoCaminho = true;
                    break;
                }
                
            }

            if (!encontrouNovoCaminho){
                pilhaCaminho.pop();
                tentativas[x][y]--;
            }
            
        }

    }
    
    // Conta as tentativas de cada bloco do labirinto... Não está 100% correto
    private void tentativas(){
        
        int xTela = getScreenWidth() / 50 + 5; 
        int yTela = getScreenHeight() / 50 + 2;
        int largura = 60; 
        int espacamento = 3;

        for (int i = 0; i < arrayLabirinto.length; i++) {
            for (int j = 0; j < arrayLabirinto[i].length; j++) {
                
                if (tentativas[i][j] > 0) {
                    int x = xTela + j * (largura + espacamento) + largura / 3; // Calculando o espaço para a impressão das tentativas
                    int y = yTela + i * (largura + espacamento) + 2 * largura / 3;

                    drawText(String.valueOf(tentativas[i][j]), x, y, 15, BLACK);
                }
                
            }
        }
        
    }

    /**
     *
     * Instancia a engine e a inicia.
     *
     */
    public static void main(String[] args) {
        
        new Main();
        
    }
}