package projetoesdlinear;

import aesd.ds.exceptions.EmptyStackException;
import aesd.ds.implementations.linear.LinkedQueue;
import aesd.ds.interfaces.Queue;
import java.awt.Color;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;
import projetoesdlinear.engine.Engine;

/**
 * Simulador de fila: Simula as operações de enfileirar e desenfileirar de uma
 * fila encadeada/ligada/dinâmica.
 *
 * @author Prof. Dr. David Buzatto
 */
public class SimuladorFila extends Engine {

    // fila que passará pelas operações enfileirar e desenfileirar
    private Queue<String> fila;

    // valor desenfileirado na última operação de desenfileirar
    private String valorDesenfileirado;

    private int raio;
    private int distanciaEntreElementos;
    private int tamanhoFonte;

    public SimuladorFila() {

        // cria a janela da simulação
        super(
                800,                    // 800 pixels de largura
                600,                    // 600 pixels de altura
                "Simulador de Fila",    // título da janela
                true,                   // ativa a suavização (antialiasing)
                60);                    // 60 quadros por segundo
    }

    /**
     * Processa a entrada inicial fornecida pelo usuário e cria e/ou inicializa
     * os objetos/contextos/variáveis do jogo ou simulação.
     */
    @Override
    public void criar() {

        fila = new LinkedQueue<>();

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
        desenharOpcoesEstadoFila();
        desenharFila();
    }

    // desenha as opções para o usuário, além dos itens desenfileirados e o estado atual da fila
    private void desenharOpcoesEstadoFila() {

        int yInicial = 30;

        drawText("1) Enfileirar", 10, yInicial, tamanhoFonte, BLACK);
        drawText("2) Desenfileirar", 10, yInicial += 30, tamanhoFonte, BLACK);

        drawText("Desenfileirou: " + (valorDesenfileirado == null ? "nenhum" : valorDesenfileirado),
                10, yInicial += 30, tamanhoFonte, BLUE);

        if (fila.isEmpty()) {
            drawText("Fila vazia!", 10, yInicial += 30, tamanhoFonte, ORANGE);
        }

    }

    // desenha os estados da fila, os elementos e suas ligações
    private void desenharFila() {

        int elementoAtual = 0;
        int yCentroAnterior = getScreenHeight() / 2;
        int yCentro = yCentroAnterior;
        int tamanho = fila.getSize();
        int xInicialFila = 50;
        
        if(fila.isEmpty()){
            
            // desenha a seta vazia na frente do início e do fim
            desenharSetaVazia(101, yCentro);
            desenharSetaVazia(65, yCentro + 35);
    
            drawText("Início", yCentro - raio - 245, yCentro + 5, tamanhoFonte, BLACK);
            drawText("Fim", yCentro - raio - 245, yCentro + 40, tamanhoFonte, BLACK);
            
        }

        for (String valor : fila) {
            
            int xCentro = xInicialFila + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 1);
            int xCentroAnterior = xInicialFila + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 2);

            // desenha o círculo e o valor inserido na fila
            drawCircleLines(xCentro, yCentro, raio, BLACK);
            drawText(valor,
                    xCentro - measureText(valor, tamanhoFonte) / 2,
                    yCentro + 5,
                    tamanhoFonte,
                    BLACK);

            // desenho das conexões entre os elementos (os arco e as setas)
            if (elementoAtual < tamanho - 1) {
                
                desenharConexaoFila(xCentro, yCentro, xCentroAnterior, yCentro);
                
            } else {
                
                // desenha a seta final em todo ultimo elemento
                desenharSetaFinal(xCentro, yCentro, xCentro + 50, yCentro);
                
                // linha final indicando o fim da fila
                int xUltimo = xInicialFila + (raio * 2 + distanciaEntreElementos) * tamanho;
                
                // desenha a linha do fim ao último elemento
                drawLine(xUltimo, yCentro + 30, xUltimo, yCentro + raio + 30, RED);
                
                // desenha a seta apontando o ultimo elemento ^
                desenharSeta(xCentro, yCentro + raio, 10, 270, RED);
                
                drawText("Fim", xUltimo - 20, yCentro + raio + 50, tamanhoFonte, BLACK);
                
            }

            // Se for o primeiro elemento, desenhar seta indicando o início
            if (elementoAtual == 0) {
                
                desenharSetaInicio(xCentro, yCentro);
                
            }

            elementoAtual++;

        }

    }

    // identifica o teclado, qual foi a ação selecionada
    @Override
    public void tratarTeclado(KeyEvent e, KeyboardEventType ket) {

        if (ket == KeyboardEventType.PRESSED) {

            String valor;

            switch (e.getKeyCode()) {

                case KeyEvent.VK_1:
                case KeyEvent.VK_NUMPAD1:
                    simularEnfileirar();
                    break;

                case KeyEvent.VK_2:
                case KeyEvent.VK_NUMPAD2:
                    simularDesenfileirar();
                    break;

            }

        }

    }

    // adição do elemento a fila
    private void simularEnfileirar() {

        String valor = JOptionPane.showInputDialog("Valor a enfileirar:");

        if (valor != null && !valor.isBlank()) {
            fila.enqueue(valor);
        }

    }

    // retirada do elemento na fila (primeiro que entrou deve ser o primeiro a sair)
    private void simularDesenfileirar() {

        try {
            valorDesenfileirado = fila.dequeue();
        } catch (EmptyStackException exc) {
            // pilha vazia, o retorno será visual
        }

    }
    
    // desenha a seta indicando inicio e fim vazios
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
    
    // desenha a seta >
    private void desenharSetaInicio(int xCentro, int yCentro) {
        
        drawLine(xCentro - raio - 30, yCentro, xCentro - raio, yCentro, RED); 
        desenharSeta(xCentro - raio, yCentro, 10, 0, RED);
        drawText("Início", xCentro - raio - 100, yCentro + 5, tamanhoFonte, BLACK);
        
    }
    
    // Desenha as conexões entre os elementos da fila
    private void desenharConexaoFila(int xInicial, int yInicial, int xFinal, int yFinal) {

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

    // coordenadas para desenho da seta
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

    // inicia a simulação
    public static void main(String[] args) {
        new SimuladorFila();
    }

}
