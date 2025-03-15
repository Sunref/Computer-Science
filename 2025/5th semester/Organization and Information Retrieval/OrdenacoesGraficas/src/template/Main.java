package template;

import br.com.davidbuzatto.jsge.core.engine.EngineFrame;
import java.util.ArrayList;
import java.util.List;

/**
 * Modelo de projeto básico da JSGE.
 * 
 * JSGE basic project template.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class Main extends EngineFrame {
    
    private int[] array;
    private List<int[]> lista;
    private int pos;
    
    private double tempoParaMudar;
    private double contadorTempo;
    
    public Main() {
        super ( 800, 450, "Ordenações", 60, true );
    }
    
    @Override
    public void create() {
        array = new int[]{ 9, 10, 5, 6, 3, 1, 2, 8 };
        lista = new ArrayList<>();
        tempoParaMudar = 1;
        copiarArray( lista, array );
        ordenar( array );
    }

    @Override
    public void update( double delta ) {
        
        contadorTempo += delta;
        
        if ( contadorTempo > tempoParaMudar ) {
            contadorTempo = 0;
            if ( pos < lista.size() - 1 ) {
                pos++;
            }
        }
        
    }

    @Override
    public void draw() {
        
        clearBackground( WHITE );
        desenharArray( lista.get( pos ), 10, getScreenHeight() / 2, 30, 10, 10 );
        
    }
    
    private void copiarArray( List<int[]> lista, int[] array ) {
        int[] novoArray = new int[array.length];
        System.arraycopy( array, 0, novoArray, 0, array.length );
        lista.add( novoArray );
    }
    
    private void desenharArray( 
            int[] array,
            int x, 
            int y, 
            int largura, 
            int espacamento, 
            int tamanhoPedaco ) {
        
        for ( int i = 0; i < array.length; i++ ) {
            fillRectangle( 
                    x + i * ( largura + espacamento ), 
                    y - array[i] * tamanhoPedaco, 
                    largura, 
                    array[i] * tamanhoPedaco, 
                    BLACK
            );
        }
        
    }
    
    private void ordenar( int[] array ) {
        
        for ( int i = 0; i < array.length - 1; i++ ) {
            int menor = i;
            for ( int j = i + 1; j < array.length; j++ ) {
                if ( array[j] < array[menor] ) {
                    menor = j;
                }
            }
            int t = array[i];
            array[i] = array[menor];
            array[menor] = t;
            copiarArray( lista, array );
        }
        
    }
    
    /**
     * Instancia a engine e a inicia.
     * 
     * Instantiates the engine and starts it.
     */
    public static void main( String[] args ) {
        new Main();
    }
    
}
