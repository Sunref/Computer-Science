/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package esdc4aula02;

import aesd.ds.implementations.linear.ResizingArrayStack;

/**
 * Resolução do Exercício i2.2
 * 
 * @author Prof. Dr. David Buzatto
 */

public class Exercicioi2p2 {
    
    /**
     * Converte uma expressão aritmética pré-fixada para infixa.
     * 
     * Algoritmo:
     *     - Processe a expressão pré-fixada em ordem inversa (direita para
     *       esquerda);
     *         - Se o token for um operando, empilhe-o;
     *         - Se o token for um operador, desempilhe dois operandos da pilha
     *           e crie uma string concatenando-os na forma:
     *               infix = "( " + operando1 + operador + operando2 + " )" 
     *           e empilhe essa string.
     *     - Repita até o fim da expressão pré-fixada.
     *     - A expressão infixa estará no topo da pilha ao fim do processo.
     * 
     * @param prefix A expressão pré-fixada.
     * @return A expressão infixa correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException.
     */
    
    public static String prefixToInfix( String prefix ) throws IllegalArgumentException {
        
        ResizingArrayStack<String> operacao = new ResizingArrayStack<>();
        
        for(int i = prefix.length() - 1; i >= 0; i--){
            
            char currentChar = prefix.charAt(i);
            
            if(isOperand(currentChar)){
                
                StringBuilder num = new StringBuilder();  
                
                while(i >= 0 && Character.isDigit(prefix.charAt(i))){
                    
                    num.append(prefix.charAt(i));
                    i--;
                    
                }
                
                i++;
                operacao.push(num.reverse().toString());
                
            }else if(isOperator(currentChar)){
                
                String val1 = operacao.pop();
                String val2 = operacao.pop();
                String infix = "( " + val1 + " " + currentChar + " " + val2 + " )";
                operacao.push(infix);
                
            }
        }
        
        return operacao.peek();
        
    }
    
    /**
     * Converte uma expressão aritmética pré-fixada para pós-fixada.
     * 
     * Algoritmo:
     *     - Processe a expressão pré-fixada em ordem inversa (direita para
     *       esquerda);
     *         - Se o token for um operando, empilhe-o;
     *         - Se o token for um operador, desempilhe dois operandos da pilha
     *           e crie uma string concatenando-os na forma:
     *               postfix = operando1 + operando2 + operador 
     *           e empilhe essa string.
     *     - Repita até o fim da expressão pré-fixada.
     *     - A expressão pós-fixada estará no topo da pilha ao fim do processo.
     * 
     * @param prefix A expressão pré-fixada.
     * @return A expressão pós-fixada correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException.
     */
    
    public static String prefixToPostfix( String prefix ) throws IllegalArgumentException {
        
        ResizingArrayStack<String> operacao = new ResizingArrayStack<>();
        
        for(int i = prefix.length() - 1; i >= 0; i--){
            
            char currentChar = prefix.charAt(i);
            
            if(Character.isWhitespace(currentChar)){
                continue;
            }
            
            if(isOperand(currentChar)){
                
                StringBuilder num = new StringBuilder();  
                
                while(i >= 0 && Character.isDigit(prefix.charAt(i))){
                    
                    num.append(prefix.charAt(i));
                    i--;
                    
                }
                
                i++;
                operacao.push(num.reverse().toString());
                
            }else if(isOperator(currentChar)){
                
                String val1 = operacao.pop();
                String val2 = operacao.pop();
                String infix = val1 + " " + val2 + " " + currentChar;
                operacao.push(infix);
                
            }
        }
        
        return operacao.peek();
        
    }
    
    /**
     * Converte uma expressão aritmética pós-fixada para infixa.
     * 
     * Algoritmo:
     *     - Processe a expressão pós-fixada da esquerda para a direita;
     *         - Se o token for um operando, empilhe-o;
     *         - Se o token for um operador, desempilhe dois operandos da pilha
     *           e crie uma string concatenando-os na forma:
     *               infix = "( " + operando2 + operador + operando1 + " )" 
     *           e empilhe essa string.
     *     - Repita até o fim da expressão pós-fixada.
     *     - A expressão infixa estará no topo da pilha ao fim do processo.
     * 
     * @param postfix A expressão pós-fixada.
     * @return A expressão infixa correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException.
     */
    
    public static String postfixToInfix( String postfix ) throws IllegalArgumentException {
        
        ResizingArrayStack<String> operacao = new ResizingArrayStack<>();

        for(int i = 0; i < postfix.length(); i++){
            
            char currentChar = postfix.charAt(i);

            if(Character.isWhitespace(currentChar)){
                continue;
            }

            if(isOperand(currentChar)){
                
                StringBuilder num = new StringBuilder();

                while(i < postfix.length() && Character.isDigit(postfix.charAt(i))){
                    
                    num.append(postfix.charAt(i));
                    i++;
                    
                }
                
                i--;
                operacao.push(num.toString());
                
            }else if (isOperator(currentChar)){
                
                String val2 = operacao.pop();
                String val1 = operacao.pop();
                String infix = "( " + val1 + " " + currentChar + " " + val2 + " )";
                operacao.push(infix);
                
            }
        }

        return operacao.peek();
        
    }
    
    /**
     * Converte uma expressão aritmética pós-fixada para pré-fixada.
     * 
     * Algoritmo:
     *     - Processe a expressão pós-fixada da esquerda para a direita;
     *         - Se o token for um operando, empilhe-o;
     *         - Se o token for um operador, desempilhe dois operandos da pilha
     *           e crie uma string concatenando-os na forma:
     *               prefix = operador + operando2 + operando1
     *           e empilhe essa string.
     *     - Repita até o fim da expressão pós-fixada.
     *     - A expressão pré-fixada estará no topo da pilha ao fim do processo.
     * 
     * @param postfix A expressão pós-fixada.
     * @return A expressão pré-fixada correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException.
     */
    
    public static String postfixToPrefix( String postfix ) throws IllegalArgumentException {
        
        ResizingArrayStack<String> operacao = new ResizingArrayStack<>();

        for(int i = 0; i < postfix.length(); i++){
            
            char currentChar = postfix.charAt(i);

            if(Character.isWhitespace(currentChar)){
                continue;
            }

            if(isOperand(currentChar)){
                
                StringBuilder num = new StringBuilder();

                while(i < postfix.length() && Character.isDigit(postfix.charAt(i))){
                    
                    num.append(postfix.charAt(i));
                    i++;
                    
                }
                
                i--;
                operacao.push(num.toString());
                
            }else if (isOperator(currentChar)){
                
                String val2 = operacao.pop();
                String val1 = operacao.pop();
                String prefix = currentChar + " " + val1 + " " + val2;
                operacao.push(prefix);
                
            }
        }

        return operacao.peek();
        
    }
    
    /**
     * Converte uma expressão aritmética infixa para pré-fixada.
     * 
     * Algoritmo:
     *     - Converta a expressão infixa para pós-fixada;
     *     - Use a expressão pós-fixada resultante para convertê-la em 
     *       pré-fixada, retornando o resultado.
     * 
     * @param infix A expressão infixa.
     * @return A expressão pré-fixada correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException. Nesse caso a exceção será lançada pelos métodos
     * invocados.
     */
    
    public static String infixToPrefix( String infix ) throws IllegalArgumentException {
        
        String postfix = infixToPostfix(infix);
        return postfixToPrefix(postfix);
        
    }
    
    /**
     * Converte uma expressão aritmética infixa para pós-fixada.
     * 
     * Algoritmo:
     *     - Processe a expressão infixa da esquerda para a direita;
     *     - Se o token for um operando, concatene-o à expressão pós-fixada
     *       que está sendo gerada, mais um espaço;
     *     - Se o token for um parêntese esquerdo, empilhe-o;
     *     - Se o token for um parêntese direito:
     *         - Enquanto a pilha não estiver vazia e o topo da pilha não for um
     *           parêntese esquerdo, desempilhe o topo e concatene-o à expressão
     *           pós-fixada que está sendo gerada, mais um espaço;
     *         - Após o enquanto, desempilhe o topo da pilha, descartando-o;
     *     - Se o token for um operador:
     *         - Enquanto a pilha não estiver vazia e a precedência do token for
     *           menor ou igual à precedência do topo da pilha, desempilhe o
     *           topo e se o que foi desempilhado for um operador, concatene-o à
     *           expressão pós-fixada que está sendo gerada, mais um espaço;
     *         - Após o enquanto, empilhe o token.
     *
     * Após o processamento de todos os tokens é preciso lidar com o que sobrou
     * na pilha. Sendo assim:
     * 
     *     - Enquanto a pilha não estiver vazia:
     *         - Desempilhe o topo da pilha e, se ele for um parênteses
     *           esquerdo, a expressão é inválida, então lance uma exceção do
     *           tipo IllegalArgumentException. Caso contrário, verifique se o
     *           que foi desempilhado é um operador. Se for, concatene-o à
     *           expressão pós-fixada que está sendo gerada, mais um espaço;
     *     
     * A expressão pós-fixada estará pronta na estrutura em que você está
     * armazenando a geração.
     * 
     * @param infix A expressão infixa.
     * @return A expressão pós-fixada correspondente.
     * @throws IllegalArgumentException Caso a expressão seja inválida, ou seja,
     * quando no processo de análise alguma operação peek ou pop lançar uma 
     * EmptyStackException ou se sobrar algum parêntese esquerdo na pilha
     * no final do processo de análise.
     */
    
    public static String infixToPostfix( String infix ) throws IllegalArgumentException {
        
        ResizingArrayStack<Character> operacao = new ResizingArrayStack<>();
        StringBuilder postfix = new StringBuilder();

        for(int i = 0; i < infix.length(); i++){
            
            char currentChar = infix.charAt(i);

            if(Character.isWhitespace(currentChar)){
                continue;
            }

            if(isOperand(currentChar)){
                
                StringBuilder num = new StringBuilder();

                while(i < infix.length() && Character.isDigit(infix.charAt(i))){
                    
                    num.append(infix.charAt(i));
                    i++;
                    
                }
                
                i--;
                postfix.append(num).append(" ");
                
            }else if(isLeftParenthesis(currentChar)){
                
                operacao.push(currentChar);
                
            }else if(isRightParenthesis(currentChar)){
                
                while(!operacao.isEmpty() && !isLeftParenthesis(operacao.peek())){
                    
                    postfix.append(operacao.pop()).append(" ");
                    
                }
                
                if(operacao.isEmpty()){
                    
                    throw new IllegalArgumentException();
                    
                }
                
                operacao.pop();
                
            }else if(isOperator(currentChar)){
                
                while(!operacao.isEmpty() && getPrecedence(currentChar) <= getPrecedence(operacao.peek())){
                    
                    postfix.append(operacao.pop()).append(" ");
                    
                }
                
                operacao.push(currentChar);
            }
        }

        while(!operacao.isEmpty()){
            
            char op = operacao.pop();
            if (isLeftParenthesis(op)){
                
                throw new IllegalArgumentException();
                
            }
            
            postfix.append(op).append(" ");
            
        }

        return postfix.toString().trim();
        
    }
    
    /**
     * Verifica se um token é um parênteses esquerdo.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um parênteses esquerdo, falso caso
     * contrário.
     */
    public static boolean isLeftParenthesis( char token ) {
        return token == '(';
    }
    
    /**
     * Verifica se um token é um parênteses esquerdo.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um parênteses esquerdo, falso caso
     * contrário.
     */
    public static boolean isLeftParenthesis( String token ) {
        return isLeftParenthesis( token.charAt( 0 ) );
    }
    
    /**
     * Verifica se um token é um parênteses direito.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um parênteses direito, falso caso
     * contrário.
     */
    public static boolean isRightParenthesis( char token ) {
        return token == ')';
    }
    
    /**
     * Verifica se um token é um parênteses direito.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um parênteses direito, falso caso
     * contrário.
     */
    public static boolean isRightParenthesis( String token ) {
        return isRightParenthesis( token.charAt( 0 ) );
    }
    
    /**
     * Verifica se um token é um operando.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um operando, falso caso
     * contrário.
     */
    public static boolean isOperand( char token ) {
        return token >= '0' && token <= '9'/* || 
               token >= 'A' && token <= 'Z' ||
               token >= 'a' && token <= 'z'*/;
    }
    
    /**
     * Verifica se um token é um operando.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um operando, falso caso
     * contrário.
     */
    public static boolean isOperand( String token ) {
        return isOperand( token.charAt( 0 ) );
    }
    
    /**
     * Verifica se um token é um operador.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um operador, falso caso
     * contrário.
     */
    public static boolean isOperator( char token ) {
        switch ( token ) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }
    
    /**
     * Verifica se um token é um operador.
     * 
     * @param token Token a ser verificado.
     * @return Verdadeiro caso o token seja um operador, falso caso
     * contrário.
     */
    public static boolean isOperator( String token ) {
        return isOperator( token.charAt( 0 ) );
    }
    
    /**
     * Obtém a precedência de um operador.
     * 
     * @param operator Operador a ser verificado.
     * @return O valor da precedência do operador testado.
     */
    public static int getPrecedence( char operator ) {
        switch ( operator ) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
        return 0;
    }
    
    /**
     * Obtém a precedência de um operador.
     * 
     * @param operator Operador a ser verificado.
     * @return O valor da precedência do operador testado.
     */
    public static int getPrecedence( String operator ) {
        return getPrecedence( operator.charAt( 0 ) );
    }
    
}
