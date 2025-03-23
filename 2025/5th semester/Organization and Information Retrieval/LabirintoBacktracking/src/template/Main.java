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

public class Main extends EngineFrame {

    private int[][] arrayLabirinto;
    private boolean andando;
    private double tempoParaMudar;
    private double contadorTempo;
    private Stack<int[]> pilhaCaminho;

    private final Color parede = new Color(40, 50, 52);
    private final Color fundo = new Color(20, 30, 30);
    private final Color finalLab = new Color(157, 182, 163);
    private final Color caminho = new Color(236, 236, 236);
    private final Color visitado = new Color(157, 182, 163);
    private final Color concluido = new Color(105, 152, 115);

    public Main() {
        
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
    public void create() {
        
        // Labirinto 7x7 onde:
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
    public void update(double delta) {
        
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
    public void draw() {
        
        clearBackground(fundo);
        
        desenharLabirinto(arrayLabirinto, getScreenWidth() / 50, getScreenHeight() / 50, 61, 1);
        
        drawText("Fim", 335, 165, 15, fundo);
        
    }

    private void desenharLabirinto(int[][] arrayLabirinto, int x, int y, int largura, int espacamento) {

        for (int i = 0; i < arrayLabirinto.length; i++) {
            for (int j = 0; j < arrayLabirinto[i].length; j++) {
                switch (arrayLabirinto[i][j]) {
                    case 0 ->
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                caminho
                        );
                    case 1 ->
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                parede
                        );
                    case 2 ->
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                finalLab
                        );
                    case 3 ->
                        fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                visitado
                        );
                    case 4 ->
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
    
    private void resolverLabirinto() {

        if (!pilhaCaminho.isEmpty()) {
            int[] atual = pilhaCaminho.peek();
            int x = atual[0];
            int y = atual[1];

            if (arrayLabirinto[x][y] == 2) {
                andando = true;
                arrayLabirinto[x][y] = 4;
                return;
            }

            arrayLabirinto[x][y] = 3;

            int[][] direcoes = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            boolean encontrouNovoCaminho = false;

            for (int[] d : direcoes) {
                int novoX = x + d[0];
                int novoY = y + d[1];

                if (novoX >= 0 && novoX < arrayLabirinto.length
                        && novoY >= 0 && novoY < arrayLabirinto[0].length
                        && (arrayLabirinto[novoX][novoY] == 0 || arrayLabirinto[novoX][novoY] == 2)) {
                    pilhaCaminho.push(new int[]{novoX, novoY});
                    encontrouNovoCaminho = true;
                    break;
                }
            }

            if (!encontrouNovoCaminho) {
                pilhaCaminho.pop();
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