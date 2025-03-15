/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package esdc4aula02;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * Resolução do Exercício i2.1
 * 
 * @author Prof. Dr. David Buzatto
 */

public class Exercicioi2p1 {
    
    /**
     * Verifica se uma expressão composta por pares de símbolos arbitrários está
     * balanceada.
     * 
     * @param expression A expressão a ser verificada.
     * @param pairs Um conjunto de caracteres em que cada dois representam um
     * par de caracteres usados na verificação.
     * @return Se a expressão está balanceada.
     * @throws IllegalArgumentException Caso os pares forem fornecidos de forma
     * errada, ou seja, se houver uma quantidade ímpar de elementos, faltando 
     * assim a dupla de fechamento de um par.
     */
    
    public static boolean isBalanced( String expression, char... pairs ) 
            throws IllegalArgumentException {
        
        Map<Character, Character> pares = new HashMap<>();
        
        for(int i = 0; i < pairs.length; i += 2){
            pares.put(pairs[i + 1], pairs[i]);
        }
        
        Stack<Character> operacao = new Stack<>();
        
        for(char c : expression.toCharArray())
        {
            if(pares.containsValue(c)) { 
                operacao.push(c);
            }else if(pares.containsKey(c)){ 
                
                if (operacao.isEmpty() || operacao.pop() != pares.get(c)){
                    return false; 
                }
                
            }
            
        }
        
        return operacao.isEmpty();        
        
    }
    
}
