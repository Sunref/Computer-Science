package template;

import br.com.davidbuzatto.jsge.core.engine.EngineFrame;
import java.awt.Color;
import java.util.ArrayList;
import java.util.List;

/**
 * Modelo de projeto básico da JSGE.
 * 
 * JSGE basic project template.
 * 
 * @author Prof. Dr. David Buzatto
 * 
 * Implementação por: Fernanda Martins da Silva
 * 
 * 
 */

public class Main extends EngineFrame {
    
    private Color fundo = new Color(40, 50, 52);
    private Color barras = new Color(12, 18, 16);
    private Color barraDestacada = new Color(107, 121, 121);
    
//    not working properly
//    private List<Integer> menorDestacado;
    
    private int[] arraySelection;
    private List<int[]> listaSelection;

    private int[] arrayInsertion;
    private List<int[]> listaInsertion;

    private int[] arrayBubble;
    private List<int[]> listaBubble;

    private int[] arrayMerge;
    private List<int[]> listaMerge;
    
    private int pos;
    
    private double tempoParaMudar;
    private double contadorTempo;
    
    public Main() {
        
        super ( 800, 450, "Ordenações", 60, true, false, false, true, false );
        
    }
    
    @Override
    public void create() {
        
        arraySelection = new int[]{ 9, 10, 5, 6, 3, 1, 2, 8 };
        listaSelection = new ArrayList<>();
        
        arrayInsertion = new int[]{9, 10, 5, 6, 3, 1, 2, 8};
        listaInsertion = new ArrayList<>();

        arrayBubble = new int[]{9, 10, 5, 6, 3, 1, 2, 8};
        listaBubble = new ArrayList<>();

        arrayMerge = new int[]{9, 10, 5, 6, 3, 1, 2, 8};
        listaMerge = new ArrayList<>();
        
//        not working properly
//        menorDestacado = new ArrayList();
        
        tempoParaMudar = 1;
        
        copiarArray(listaSelection, arraySelection );
        selection(arraySelection );
        
        copiarArray(listaInsertion, arrayInsertion);
        insertion(arrayInsertion);

        copiarArray(listaBubble, arrayBubble);
        bubble(arrayBubble);

        copiarArray(listaMerge, arrayMerge);
        mergeSort(arrayMerge);
        
    }

    @Override
    public void update( double delta ) {
        
        contadorTempo += delta;
        
        if ( contadorTempo > tempoParaMudar ) {
            contadorTempo = 0;
            if ( pos < listaSelection.size() - 1 ) {
                pos++;
            }
        }
        
        if (contadorTempo > tempoParaMudar) {
            contadorTempo = 0;
            if (pos < listaInsertion.size() - 1) {
                pos++;
            }
        }

        if (contadorTempo > tempoParaMudar) {
            contadorTempo = 0;
            if (pos < listaBubble.size() - 1) {
                pos++;
            }
        }

        if (contadorTempo > tempoParaMudar) {
            contadorTempo = 0;
            if (pos < listaMerge.size() - 1) {
                pos++;
            }
        }
        
    }

    @Override
    public void draw() {
        
        clearBackground( fundo );
        
        drawText("Selection Sort:", 20, 50, 30, barras);
        drawText("Insertion Sort:", 450, 50, 30, barras);
        drawText("Bubble Sort:", 20, getScreenHeight() - 200, 30, barras);
        drawText("Merge Sort:", 450, getScreenHeight() - 200, 30, barras);

        desenharArray(listaSelection.get( pos ), 35, getScreenHeight() / 2, 30, 10, 10 );
        desenharArray(listaInsertion.get(pos), 450, getScreenHeight() / 2, 30, 10, 10);
        desenharArray(listaBubble.get(pos), 35, (getScreenHeight() / 2) + 180, 30, 10, 10);
        desenharArray(listaMerge.get(pos), 450, (getScreenHeight() / 2) + 180, 30, 10, 10);
        
    }
    
    private void copiarArray( List<int[]> lista, int[] array ) {
        
        int[] novoArray = new int[array.length];
        System.arraycopy( array, 0, novoArray, 0, array.length );
        lista.add( novoArray );
        
    }
    
    private void desenharArray(int[] array, int x, int y, int largura, int espacamento, int tamanhoPedaco) {

//        not working properly
//        int movido = -1;
//        if(pos < menorDestacado.size()){
//            movido = menorDestacado.get(pos);
//        }
        for (int i = 0; i < array.length; i++) {
            
//            not working properly
//            if (i == movido) {
//                fillRectangle(
//                        x + i * (largura + espacamento),
//                        y - array[i] * tamanhoPedaco,
//                        largura,
//                        array[i] * tamanhoPedaco,
//                        barraDestacada
//                );
//            }
            
            fillRectangle(
                    x + i * (largura + espacamento),
                    y - array[i] * tamanhoPedaco,
                    largura,
                    array[i] * tamanhoPedaco,
                    barras
            );

        }

    }
    
    private void selection( int[] arraySelection ) {
        
        for ( int i = 0; i < arraySelection.length - 1; i++ ) {
            
            int menor = i;
            for ( int j = i + 1; j < arraySelection.length; j++ ) {
                if ( arraySelection[j] < arraySelection[menor] ) {
                    menor = j;
                }
                
            }
            
            int t = arraySelection[i];
            arraySelection[i] = arraySelection[menor];
            arraySelection[menor] = t;
            copiarArray(listaSelection, arraySelection );
            
//            not working properly
//            menorDestacado.add(menor);
        }
        
    }
    
    public void insertion(int[] arrayInsertion) {
        
        for (int i = 1; i < arrayInsertion.length; i++) {
            int j = i;
            while (j > 0 && arrayInsertion[j - 1] > arrayInsertion[j]) {
                int t = arrayInsertion[j - 1];
                arrayInsertion[j - 1] = arrayInsertion[j];
                arrayInsertion[j] = t;
                j--;
            }
            
            copiarArray(listaInsertion, arrayInsertion);
            
        }
        
    }
    
    public void bubble(int[] arrayBubble) {

        for (int i = 0; i < arrayBubble.length - 1; i++) {
            for (int j = 0; j < arrayBubble.length - i - 1; j++) {
                if (arrayBubble[j] > arrayBubble[j + 1]) {
                    int t = arrayBubble[j];
                    arrayBubble[j] = arrayBubble[j + 1];
                    arrayBubble[j + 1] = t;
                }
            }
            copiarArray(listaBubble, arrayBubble);
        }

    }
    
    public void mergeSort(int[] arrayMerge) {
        
        int[] tempMS = new int[arrayMerge.length];
        topDown(arrayMerge, 0, arrayMerge.length - 1, tempMS);
        
    }

    private void topDown(int[] arrayMerge, int start, int end, int[] tempMS) {
        
        int middle;
        if (start < end) {
            middle = (start + end) / 2;
            topDown(arrayMerge, start, middle, tempMS);
            topDown(arrayMerge, middle + 1, end, tempMS);
            merge(arrayMerge, start, middle, end, tempMS);
        }
        
    }
    
    private void merge(int[] arrayMerge, int inicio, int meio, int fim, int[] tempMS) {
        
        int i = inicio;
        int j = meio + 1;
        
        for (int k = inicio; k <= fim; k++) {
            tempMS[k] = arrayMerge[k];
        }
        
        for (int k = inicio; k <= fim; k++) {
            if (i > meio) {
                arrayMerge[k] = tempMS[j++];
            } else if (j > fim) {
                arrayMerge[k] = tempMS[i++];
            } else if (tempMS[j] < tempMS[i]) {
                arrayMerge[k] = tempMS[j++];
            } else {
                arrayMerge[k] = tempMS[i++];
            }
        }
        
        copiarArray(listaMerge, arrayMerge);
        
    }
    
    /**
     * Instancia a engine e a inicia.
     * 
     * Instantiates the engine and starts it.
     * 
     */
    
    public static void main( String[] args ) {
        
        new Main();
        
    }
    
}
