package projetoesdlinear;

import aesd.ds.implementations.linear.DoublyLinkedList;
import java.awt.Color;
import java.awt.event.KeyEvent;
import javax.swing.JOptionPane;
import projetoesdlinear.engine.Engine;

/**
 * Simulador de lista:
 *     Simula as seguintes operações de uma lista encadeada/ligada/dinâmica:
 *         - Inserir no fim;
 *         - Inserir em posição especificada;
 *         - Alterar em posição especificada;
 *         - Remover de posição especificada
 * 
 * @author Prof. Dr. David Buzatto
 */
public class SimuladorLista extends Engine {

    // declaração de variáveis
    private  DoublyLinkedList<String> lista;
    private String removerPosicao;
    private String count;
    private String posicaoRemovida;
    private String novoValor;
    
  
    private int raio;
    private int distanciaEntreElementos;
    private int tamanhoFonte;

    public SimuladorLista() {

        // cria a janela do jogo ou simulação
        super( 
            800,                  // 800 pixels de largura
            600,                  // 600 pixels de largura
            "Simulador de Lista", // título da janela
            true,                 // ativa a suavização (antialiasing)
            60 );                 // 60 quadros por segundo

    }

    /**
     * Processa a entrada inicial fornecida pelo usuário e cria
     * e/ou inicializa os objetos/contextos/variáveis do jogo ou simulação.
     */
    @Override
    public void criar() {
        lista = new DoublyLinkedList<>();

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
        desenharOpcoesEstadoLista();
        desenharLista();
    }
    
    private void desenharOpcoesEstadoLista() {

        int yInicial = 30;

        drawText("1) Inserir no fim", 10, yInicial, tamanhoFonte, BLACK);
        drawText("2) Inserir em posição", 10, yInicial += 30, tamanhoFonte, BLACK);
        drawText("3) Alterar em posição", 10, yInicial += 30, tamanhoFonte, BLACK);
        drawText("4) Remover de posição", 10, yInicial += 30, tamanhoFonte, BLACK);

        drawText((removerPosicao == null ? "Nenhuma posição foi removida " : "Removeu a posição " + posicaoRemovida + " com valor " + removerPosicao),
                10, yInicial += 30, tamanhoFonte, BLUE);
        
        drawText((count == null ? "Nenhuma posição foi alterada " : "A posição " + count  + " foi alterada para o valor " + novoValor ) ,
                10, yInicial += 30, tamanhoFonte, BLUE);
       

        if (lista.isEmpty()) {
            drawText("Litsa vazia!", 10, yInicial += 30, tamanhoFonte, ORANGE);
        }

    }
    
    private void desenharLista(){
        int elementoAtual = 0;
        int yCentroAnterior = getScreenHeight()/2;
        int tamanho = lista.getSize();
        int yCentro = yCentroAnterior;
        
        int xInicialLista = 50;
        
        if(tamanho ==0){
            desenharSetaVazia(101, yCentro);
            desenharSetaVazia(65, yCentro + 35);
            
            drawText("Início", yCentro - raio - 245, yCentro + 5, tamanhoFonte, BLACK);
            drawText("Fim", yCentro - raio - 245, yCentro + 40, tamanhoFonte, BLACK);
            
        }
        
        for (String valor : lista){
            int xCentro = xInicialLista + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 1);
            int xCentroAnterior = xInicialLista + (raio * 2 + distanciaEntreElementos) * (elementoAtual + 2);

            // desenha o círculo e o valor inserido na fila
            drawCircleLines(xCentro, yCentro, raio, BLACK);
            drawText(valor,
                    xCentro - measureText(valor, tamanhoFonte) / 2,
                    yCentro + 5,
                    tamanhoFonte,
                    BLACK);
            
            if(elementoAtual < tamanho - 1){
                desenharConexaoLista(xCentro, yCentro, xCentroAnterior, yCentro);
            } else {
                
                // linha final indicando o fim da fila
                int xUltimo = xInicialLista + (raio * 2 + distanciaEntreElementos) * tamanho;
                
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
                    inserirNoFim();
                    break;

                case KeyEvent.VK_2:
                case KeyEvent.VK_NUMPAD2:
                    inserirPosicao();
                    break;
                    
                case KeyEvent.VK_3:
                case KeyEvent.VK_NUMPAD3:
                    alterarPosicao();
                    break;

                case KeyEvent.VK_4:
                case KeyEvent.VK_NUMPAD4:
                    removerPosicao();
                    break;
            }
        }
    }
    
    // metodo que insere no fim da lista
    private void inserirNoFim(){
        String valor = JOptionPane.showInputDialog("Valor a inserir no fim:");
        if(valor !=null && !valor.isBlank()){
            lista.add(valor);
        }
    }
    
    //metodo que insere em uma posição especifica
    private void inserirPosicao(){
        String valor = JOptionPane.showInputDialog("Valor a inserir:");
        if(valor != null && !valor.isBlank()){
            try{ 
                int posicao = Integer.parseInt(JOptionPane.showInputDialog("Posicao: "));
                if( posicao <0 || posicao > lista.getSize()){
                    JOptionPane.showMessageDialog(null, "Posição inválida! A posição deve estar entre 0 e " + lista.getSize());
                }else {
                    lista.add(posicao,valor);
                }
            }catch (NumberFormatException e){
                JOptionPane.showMessageDialog(null, "Entrada inválida! Por favor, insira um número.");
            }
        }
    }
    
    //metodo que altera uma posição especifica
    private void alterarPosicao(){
        try{
            int posicaoAlt =  Integer.parseInt(JOptionPane.showInputDialog("Posição a alterar: "));
            if(posicaoAlt <0 || posicaoAlt >= lista.getSize()){
                JOptionPane.showMessageDialog(null, "Posição inválida!");
                return;
            }
            novoValor = JOptionPane.showInputDialog("Novo valor: ");
            count = Integer.toString(posicaoAlt);
            if(novoValor != null && !novoValor.isBlank()){
                lista.set(posicaoAlt, novoValor);
            }
        }catch(NumberFormatException e){
            JOptionPane.showMessageDialog(null, "Entrada inválida! Por favor, insira um número.");
        }
    }
    
    //metodo que remove posição
    private void removerPosicao(){
        try{
            int posicao  = Integer.parseInt(JOptionPane.showInputDialog("Posição a remover:"));
            if(posicao < 0|| posicao >= lista.getSize()) {
                JOptionPane.showMessageDialog(null, "Posição inválida! A posição deve estar entre 0 e " + (lista.getSize() - 1));
                return;
            }
            posicaoRemovida = Integer.toString(posicao);
            removerPosicao = lista.remove(posicao);
        }catch(NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Entrada inválida! Por favor, insira um número.");
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
    
    private void desenharSetaInicio(int xCentro, int yCentro) {
        
        drawLine(xCentro - raio - 30, yCentro, xCentro - raio, yCentro, RED); 
        desenharSeta(xCentro - raio, yCentro, 10, 0, RED);
        drawText("Início", xCentro - raio - 100, yCentro + 5, tamanhoFonte, BLACK);
        
    }
    
    // Desenha as conexões entre os elementos da fila
    private void desenharConexaoLista(int xInicial, int yInicial, int xFinal, int yFinal) {

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
        new SimuladorLista();
    }
    
}
