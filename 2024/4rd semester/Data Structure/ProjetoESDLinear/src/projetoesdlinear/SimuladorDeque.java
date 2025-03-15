package projetoesdlinear;


import java.awt.Color;
import java.awt.event.KeyEvent;
import java.util.LinkedList;
import projetoesdlinear.engine.Engine;
import java.util.Deque;
import javax.swing.JOptionPane;

/**
 * Simulador de deque:
 *     Simula as operações de inserir no início e no fim e remover do início
 *     e do fim de uma deque encadeada/ligada/dinâmica.
 * 
 * @author Prof. Dr. David Buzatto
 */
public class SimuladorDeque extends Engine {

    // declaração de variáveis
    private Deque<String> deque;
    private String desenfileirarInicio;
    private String desenfileirarFim;
    
    private int raio;
    private int distanciaEntreElementos;
    private int tamanhoFonte;
    

    
    public SimuladorDeque() {

        // cria a janela do jogo ou simulação
        super( 
            800,                  // 800 pixels de largura
            600,                  // 600 pixels de largura
            "Simulador de Deque", // título da janela
            true,                 // ativa a suavização (antialiasing)
            60 );                 // 60 quadros por segundo

    }

    /**
     * Processa a entrada inicial fornecida pelo usuário e cria
     * e/ou inicializa os objetos/contextos/variáveis do jogo ou simulação.
     */
    @Override
    public void criar() {
        deque = new LinkedList<>();

        raio = 30;
        distanciaEntreElementos = 45;
        tamanhoFonte = 20;
        
    }

    /**
     * Atualiza os objetos/contextos/variáveis do jogo ou simulação.
     */
    @Override
    public void atualizar() {
    }

    /**
     * Desenha o estado dos objetos/contextos/variáveis do jogo ou simulação.
     */
    @Override
    public void desenhar() {
        desenharOpcoesEstadoDeque();
        desenharDeque();
        
    }

    
    private void desenharOpcoesEstadoDeque() {

        int yInicial = 30;

        drawText("1) Enfileirar no inicio", 10, yInicial, tamanhoFonte, BLACK);
        drawText("2) Enfileirar no fim", 10, yInicial += 30, tamanhoFonte, BLACK);
        drawText("3) Desenfileirar no inicio", 10, yInicial += 30, tamanhoFonte, BLACK);
        drawText("4) Desenfileirar no fim", 10, yInicial += 30, tamanhoFonte, BLACK);

        drawText("Desenfileirou no inicio: " + (desenfileirarInicio == null ? "nenhum" : desenfileirarInicio),
                10, yInicial += 30, tamanhoFonte, BLUE);
        
        drawText("Desenfileirou no fim: " + (desenfileirarFim == null ? "nenhum" : desenfileirarFim),
                10, yInicial += 30, tamanhoFonte, BLUE);
        

        if (deque.isEmpty()) {
            drawText("Deque vazio!", 10, yInicial += 30, tamanhoFonte, ORANGE);
        }

    }
    
    private void desenharDeque(){
        int elementoAtual = 0;
        int yCentroAnterior = getScreenHeight()/2;
        int yCentro = yCentroAnterior;
        int tamanho = deque.size();
        int xInicialDeque = 50;
        
        if(tamanho == 0){
            desenharSetaVazia(101, yCentro);
            desenharSetaVazia(65, yCentro + 35);
            
            drawText("Início", yCentro - raio - 245, yCentro + 5, tamanhoFonte, BLACK);
            drawText("Fim", yCentro - raio - 245, yCentro + 40, tamanhoFonte, BLACK);
            
        }
        
        for (String valor : deque){
            int xCentro = xInicialDeque + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 1);
            int xCentroAnterior = xInicialDeque + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 2);

            // desenha o círculo e o valor inserido na fila
            drawCircleLines(xCentro, yCentro, raio, BLACK);
            drawText(valor,
                    xCentro - measureText(valor, tamanhoFonte) / 2,
                    yCentro + 5,
                    tamanhoFonte,
                    BLACK);
            
            if(elementoAtual < tamanho - 1){
                desenharConexaoDequeProximo(xCentro, yCentro, xCentroAnterior, yCentro);
                desenharConexaoDequeAnterior(xCentro, yCentro, xCentroAnterior, yCentro);
            } else {
                
                // desenha a seta final em todo ultimo elemento
                desenharSetaFinal(xCentro, yCentro, xCentro + 50, yCentro);
                
                // linha final indicando o fim da fila
                int xUltimo = xInicialDeque + (raio * 2 + distanciaEntreElementos) * tamanho;
                
                // desenha a linha do fim ao último elemento
                drawLine(xUltimo, yCentro + 30, xUltimo, yCentro + raio + 30, RED);
                
                // desenha a seta apontando o ultimo elemento ^
                desenharSeta(xCentro, yCentro + raio, 10, 270, RED);
                
                drawText("Fim", xUltimo - 20, yCentro + raio + 50, tamanhoFonte, BLACK); 
            }
            
            if (elementoAtual == 0) {
                
                desenharSetaInicio(xCentro, yCentro);
                
            }
            
            elementoAtual++;
        }   
    }
    
    @Override
    public void tratarTeclado(KeyEvent e, KeyboardEventType ket) {

        if (ket == KeyboardEventType.PRESSED) {

            String valor;

            switch (e.getKeyCode()) {

                case KeyEvent.VK_1:
                case KeyEvent.VK_NUMPAD1:
                    EnfileirarInicio();
                    break;

                case KeyEvent.VK_2:
                case KeyEvent.VK_NUMPAD2:
                    EnfileirarFim();
                    break;
                    
                case KeyEvent.VK_3:
                case KeyEvent.VK_NUMPAD3:
                    DesenfileirarInicio();
                    break;

                case KeyEvent.VK_4:
                case KeyEvent.VK_NUMPAD4:
                    DesenfileirarFim();
                    break;
            }
        }
    }
    
    private void EnfileirarInicio(){
        String valor = JOptionPane.showInputDialog("Valor a enfileirar no inicio:");

        if (valor != null && !valor.isBlank()) {
            deque.addFirst(valor);
        }
    }
    
    private void EnfileirarFim() {
        String valor = JOptionPane.showInputDialog("Valor a enfileirar no fim:");
        if (valor != null && !valor.isBlank()) {
            deque.addLast(valor);
        }
    }
    
    private void DesenfileirarInicio(){
        if (!deque.isEmpty()){
            desenfileirarInicio = deque.removeFirst();
        }
    }
    
    private void DesenfileirarFim() {
        if (!deque.isEmpty()){
            desenfileirarFim = deque.removeLast();
        }
    }
    
    private void desenharSetaVazia(int x, int y) {
        
        int comprimentoLinha = 20;  // comprimento da linha
        int alturaBarraMenor = 10;  // altura da barra menor
        int alturaBarraMaior = 15;  // altura da barra maior

        // linha
        drawLine(x, y, x + comprimentoLinha, y, BLACK);

        // Barra menor
        int xBarraMenor = x + comprimentoLinha;
        drawLine(xBarraMenor, y - alturaBarraMenor / 2, xBarraMenor, y + alturaBarraMenor / 2, BLACK);
        
        // barra maior
        int xBarraMaior = xBarraMenor + 5;
        drawLine(xBarraMaior, y - alturaBarraMaior / 2, xBarraMaior, y + alturaBarraMaior / 2, BLACK);
        
    }
    
    // desenha a seta do ultimo elemento, indicando proximo vazio
    private void desenharSetaFinal(int xInicial, int yInicial, int xFinal, int yFinal) {
        
        int novoYInicial = yInicial - raio;

        // ponto de controle da curva
        int xControle = (xInicial + xFinal) / 2;
        int yControle = novoYInicial - 15;  // ajusta a elevação

        // desenhar a curva
        drawSplineSegmentBezierQuadratic(
            xInicial, novoYInicial, 
            xControle, yControle, 
            xFinal, yFinal - raio,
            2, RED
        );

        // ajuste da ponta da seta
        int alturaBarraMenor = 6;  // barra menor
        int alturaBarraMaior = 12; // barra maior
        int deslocamento = 5;  // deslocamento horizontal para barra maior

        // barra menor (alinhada verticalmente com o ponto final)
        drawLine(
            xFinal, (yFinal - raio) - alturaBarraMenor / 2, 
            xFinal, (yFinal - raio) + alturaBarraMenor / 2, 
            RED
        );

        // barra maior (levemente deslocada para a direita)
        drawLine(
            xFinal + deslocamento, (yFinal - raio) - alturaBarraMaior / 2, 
            xFinal + deslocamento, (yFinal - raio) + alturaBarraMaior / 2, 
            RED
        );
        
    }
    
    private void desenharSetaInicio(int xCentro, int yCentro) {
        
        drawLine(xCentro - raio - 30, yCentro, xCentro - raio, yCentro, RED); 
        desenharSeta(xCentro - raio, yCentro, 10, 0, RED);
        drawText("Início", xCentro - raio - 100, yCentro + 5, tamanhoFonte, BLACK);
        
    }
    
    // Desenha as conexões de "próximo" entre os elementos da fila
    private void desenharConexaoDequeProximo(int xInicial, int yInicial, int xFinal, int yFinal) {

        // ajustando os pontos de início e fim para o topo das bolinhas
        int yTopoInicial = yInicial - raio; // topo da primeira bolinha
        int yTopoFinal = yFinal - raio;     // topo da segunda bolinha

        // ponto de controle para a curva
        double xControle = (xInicial + xFinal) / 2;
        double yControle = (yTopoInicial + yTopoFinal) / 2 - 25; // Levanta um pouco a curva

        // desenha a curva entre as bolinhas
        drawSplineSegmentBezierQuadratic(
                xInicial, yTopoInicial,
                xControle, yControle,
                xFinal - 2, yTopoFinal - 2, // (para não ficar tão grudado na bolinha)
                1, RED);

        drawText("Próximo", xControle - 30, yControle, 15, RED);

        // desenha a seta apontando para a próxima bolinha
        desenharSeta(xFinal, yTopoFinal - 2, 10, 45, RED); // yTopoFinal - 2 para não ficar tão grudado na bolinha (tinha achado feio antes) e 45 = 45 graus
    }
    
    // Desenha as conexões de "anterior" entre os elementos da fila
    private void desenharConexaoDequeAnterior(int xInicial, int yInicial, int xFinal, int yFinal) {

        // ajustando os pontos de início e fim para o topo das bolinhas
        int yTopoInicial = yInicial + raio; // topo da primeira bolinha
        int yTopoFinal = yFinal + raio;     // topo da segunda bolinha

        // ponto de controle para a curva
        double xControle = (xInicial + xFinal) / 2;
        double yControle = (yTopoInicial + yTopoFinal) / 2 + 25; // Levanta um pouco a curva

        // desenha a curva entre as bolinhas
        drawSplineSegmentBezierQuadratic(
                xInicial, yTopoInicial,
                xControle, yControle,
                xFinal - 2, yTopoFinal, // (para não ficar tão grudado na bolinha)
                1, BLUE);

        drawText("Anterior", xControle - 30, yControle, 15, BLUE);

        // desenha a seta apontando para a próxima bolinha
        desenharSeta(xFinal - 105, yTopoFinal, 10, 225, BLUE); // yTopoFinal - 2 para não ficar tão grudado na bolinha (tinha achado feio antes) e 45 = 45 graus
    }
    
    private void desenharSeta(double x, double y, int tamanho, double graus, Color cor) {

        drawLine(
                x, y,
                x + Math.cos(Math.toRadians(graus - 135)) * tamanho,
                y + Math.sin(Math.toRadians(graus - 135)) * tamanho,
                cor
        );

        drawLine(
                x, y,
                x + Math.cos(Math.toRadians(graus + 135)) * tamanho,
                y + Math.sin(Math.toRadians(graus + 135)) * tamanho,
                cor
        );

    }
    
    public static void main( String[] args ) {
        new SimuladorDeque();
    }
}