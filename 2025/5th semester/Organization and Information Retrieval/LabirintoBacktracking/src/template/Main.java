package template;

import br.com.davidbuzatto.jsge.core.engine.EngineFrame;
import br.com.davidbuzatto.jsge.core.utils.CoreUtils;
import br.com.davidbuzatto.jsge.core.utils.DrawingUtils;
import br.com.davidbuzatto.jsge.geom.Rectangle;

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
    
    public Main() {
        
        super(
            800,                 // largura
            450,                 // algura
            "Window Title",      // título
            60,                  // quadros por segundo desejado
            true,                // suavização
            false,               // redimensionável   
            false,               // tela cheia
            true,                // sem decoração
            false,               // sempre no topo
            false                // fundo invisível
        );
        
    }
    
    /**
     * 
     * Cria o mundo do jogo.
     * Esse método executa apenas uma vez durante a inicialização da engine.
     * 
     */
    
    @Override
    public void create() {
        
    }

    /**
     * 
     * Lê a entrada do usuário e atualiza o mundo do jogo.
     * Os métodos de entrada devem ser usados aqui.
     * Atenção: Você NÃO DEVE usar nenhum dos métodos de desenho da engine aqui.
     * 
     * @param delta O tempo passado, em segundos, de um quadro para o outro.
     * 
     */
    @Override
    public void update( double delta ) {
        
    }
    
    /**
     * 
     * Desenha o mundo do jogo.
     * Todas as operações de desenho DEVEM ser feitas aqui.
     * 
     */
    @Override
    public void draw() {
        
        clearBackground( WHITE );

        String text = "JSimple Game Engine";
        Rectangle r = measureTextBounds( text, 40 );
        
        double x = getScreenWidth() / 2 - r.width / 2;
        double y = getScreenHeight() / 2 - r.height / 2;
        fillRectangle( x - 10, y, r.width + 20, r.height, BLACK );
        drawText( text, x, y + 10, 40, WHITE );
    
    }
    
    /**
     * 
     * Instancia a engine e a inicia.
     * 
     */
    public static void main( String[] args ) {
        
        new Main();
        
    }
    
}
