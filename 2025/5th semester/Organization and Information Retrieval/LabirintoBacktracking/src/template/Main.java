package template;

import br.com.davidbuzatto.jsge.core.engine.EngineFrame;
import java.awt.Color;
import java.util.ArrayList;

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

    // Labirinto onde 0 é o caminho a ser seguido, 1 indica parede e 2 o final do labirinto.
    private int[][] arrayLabirinto;
    private ArrayList<int[][]> listaLabirinto;
    private int pos;
    
    private Color parede = new Color(0, 0, 0);
    private Color finalLab = new Color (255, 105, 180);
    private Color caminho = new Color(255, 255, 255);

    public Main() {

        super(
                450, // largura
                450, // altura
                "Window Title", // título
                60, // quadros por segundo desejado
                true, // suavização
                false, // redimensionável   
                false, // tela cheia
                true, // sem decoração
                false, // sempre no topo
                false // fundo invisível
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

        listaLabirinto = new ArrayList<>();
        arrayLabirinto = new int[7][7]; // O labirinto é 7x7

        listaLabirinto.add(arrayLabirinto);
        pos = 0;
        
        // Labirinto onde 0 é o caminho a ser seguido, 1 indica parede e 2 o final do labirinto.
        arrayLabirinto = new int[][]{
            {0, 0, 0, 0, 0, 1, 1},
            {0, 1, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 2, 0}, //saida no (3,6)
            {0, 1, 1, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 1, 0, 0}
        };

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
        
    }

    /**
     *
     * Desenha o mundo do jogo. Todas as operações de desenho DEVEM ser feitas
     * aqui.
     *
     */
    @Override
    public void draw() {

        clearBackground(PURPLE);

        if (!listaLabirinto.isEmpty() && pos < listaLabirinto.size()) {
            desenharLabirinto(listaLabirinto.get(pos), getScreenWidth() / 50, getScreenHeight() / 50, 61, 1);
        }

    }

    private void desenharLabirinto(int[][] arrayLabirinto, int x, int y, int largura, int espacamento) {

        for (int i = 0; i < arrayLabirinto.length; i++) {
            for (int j = 0; j < arrayLabirinto[i].length; j++) {
                switch (arrayLabirinto[i][j]) {
                    case 0 -> fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                caminho
                        );
                    case 1 -> fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                parede
                        );
                    case 2 -> fillRectangle(
                                x + j * (largura + espacamento),
                                y + i * (largura + espacamento),
                                largura,
                                largura,
                                finalLab
                        );
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