package implementation;

import common.Entry;
import common.SymbolTable;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Implementação de uma árvore Trie (também conhecida como árvore digital ou árvore de prefixos).
 * Uma Trie é uma estrutura de dados especializada para armazenamento e recuperação de strings,
 * onde todas as strings que compartilham um prefixo comum compartilham um caminho comum na árvore.
 *
 * Esta implementação:
 * - Suporta caracteres ASCII estendido (256 caracteres)
 * - Permite inserção, remoção e busca em tempo O(L), onde L é o comprimento da string
 * - Mantém as strings em uma estrutura compacta que economiza espaço para prefixos comuns
 *
 * @param <Value> tipo do valor associado a cada string
 * 
 * @author Fernanda Martins da Silva BV3032345
 * @version 1.0
 * Projeto: Organização e Recuperação da Informação
 */
public class Trie<Value> implements SymbolTable<String, Value> {
    
    /** Tamanho do alfabeto - usando ASCII estendido (256 caracteres) */
    private static final int R = 256;
    
    /** Nó raiz da Trie */
    private Node root;
    
    /** Número total de chaves na Trie */
    private int size;
    
    /**
     * Classe interna que representa um nó na Trie.
     * Cada nó contém:
     * - Um valor (pode ser null se não for fim de palavra)
     * - Um array de referências para os próximos nós (um para cada caractere possível)
     */
    private static class Node<Value> {
        /** Valor armazenado neste nó (null se não for fim de palavra) */
        private Value val;
        
        /** Array de referências para os próximos nós (um para cada caractere) */
        private Node<Value>[] next = new Node[R];
    }
    
    /**
     * Insere ou atualiza um par chave-valor na Trie.
     * Se o valor for null, a chave é removida.
     *
     * @param key a string a ser inserida/atualizada
     * @param val o valor a ser associado à string
     * @throws IllegalArgumentException se a chave for null
     */
    @Override
    public void put(String key, Value val) {
        if (key == null) {
            throw new IllegalArgumentException("Key cannot be null");
        }
        if (val == null) {
            delete(key);
        } else {
            root = put(root, key, val, 0);
        }
    }
    
    /**
     * Método recursivo auxiliar para inserção.
     * Percorre/cria o caminho na Trie para a string dada.
     *
     * @param x nó atual sendo processado
     * @param key string sendo inserida
     * @param val valor a ser associado à string
     * @param d índice do caractere atual da string
     * @return o nó atual (pode ser um novo nó se não existia)
     */
    private Node<Value> put(Node<Value> x, String key, Value val, int d) {
        if (x == null) {
            x = new Node<>();
        }
        if (d == key.length()) {
            if (x.val == null) {
                size++;  // Incrementa tamanho apenas se for nova chave
            }
            x.val = val;
            return x;
        }
        char c = key.charAt(d);
        x.next[c] = put(x.next[c], key, val, d + 1);
        return x;
    }
    
    /**
     * Recupera o valor associado a uma string na Trie.
     *
     * @param key a string a ser buscada
     * @return o valor associado à string, ou null se não encontrada
     * @throws IllegalArgumentException se a chave for null
     */
    @Override
    public Value get(String key) {
        if (key == null) {
            throw new IllegalArgumentException("Key cannot be null");
        }
        Node<Value> x = get(root, key, 0);
        if (x == null) {
            return null;
        }
        return x.val;
    }
    
    /**
     * Método recursivo auxiliar para busca.
     * Percorre a Trie seguindo os caracteres da string.
     *
     * @param x nó atual sendo processado
     * @param key string sendo buscada
     * @param d índice do caractere atual da string
     * @return o nó correspondente ao último caractere, ou null se não encontrado
     */
    private Node<Value> get(Node<Value> x, String key, int d) {
        if (x == null) {
            return null;
        }
        if (d == key.length()) {
            return x;
        }
        char c = key.charAt(d);
        return get(x.next[c], key, d + 1);
    }
    
    /**
     * Remove uma string e seu valor associado da Trie.
     *
     * @param key a string a ser removida
     * @throws IllegalArgumentException se a chave for null
     */
    @Override
    public void delete(String key) {
        if (key == null) {
            throw new IllegalArgumentException("Key cannot be null");
        }
        root = delete(root, key, 0);
    }
    
    /**
     * Método recursivo auxiliar para remoção.
     * Remove a string e realiza limpeza de nós não utilizados.
     *
     * @param x nó atual sendo processado
     * @param key string sendo removida
     * @param d índice do caractere atual da string
     * @return o nó atual ou null se pode ser removido
     */
    private Node<Value> delete(Node<Value> x, String key, int d) {
        if (x == null) {
            return null;
        }
        if (d == key.length()) {
            if (x.val != null) {
                size--;  // Decrementa tamanho apenas se havia valor
            }
            x.val = null;
        } else {
            char c = key.charAt(d);
            x.next[c] = delete(x.next[c], key, d + 1);
        }
        
        // Remove nó se não tiver valor e não tiver filhos
        if (x.val != null) {
            return x;
        }
        for (int c = 0; c < R; c++) {
            if (x.next[c] != null) {
                return x;
            }
        }
        return null;
    }
    
    /**
     * Verifica se uma string existe na Trie.
     *
     * @param key a string a ser verificada
     * @return true se a string existir e tiver valor associado, false caso contrário
     * @throws IllegalArgumentException se a chave for null
     */
    @Override
    public boolean contains(String key) {
        if (key == null) {
            throw new IllegalArgumentException("Key cannot be null");
        }
        return get(key) != null;
    }
    
    /**
     * Verifica se a Trie está vazia.
     *
     * @return true se não houver strings armazenadas, false caso contrário
     */
    @Override
    public boolean isEmpty() {
        return size == 0;
    }
    
    /**
     * Retorna o número de strings armazenadas na Trie.
     *
     * @return quantidade de strings com valores associados
     */
    @Override
    public int getSize() {
        return size;
    }
    
    /**
     * Retorna todas as strings armazenadas na Trie.
     * As strings são coletadas através de uma travessia em profundidade.
     *
     * @return objeto iterável contendo todas as strings
     */
    @Override
    public Iterable<String> getKeys() {
        List<String> keys = new ArrayList<>();
        collect(root, new StringBuilder(), keys);
        return keys;
    }
    
    /**
     * Método recursivo auxiliar para coletar todas as strings.
     * Realiza uma travessia em profundidade na Trie.
     *
     * @param x nó atual sendo processado
     * @param prefix prefixo acumulado até o momento
     * @param keys lista onde as strings são armazenadas
     */
    private void collect(Node<Value> x, StringBuilder prefix, List<String> keys) {
        if (x == null) {
            return;
        }
        if (x.val != null) {
            keys.add(prefix.toString());
        }
        for (char c = 0; c < R; c++) {
            prefix.append(c);
            collect(x.next[c], prefix, keys);
            prefix.setLength(prefix.length() - 1);  // Remove último caractere ao retornar
        }
    }
    
    /**
     * Retorna um iterador que percorre todos os pares string-valor na Trie.
     * O iterador retorna objetos Entry contendo a string e seu valor associado.
     *
     * @return iterador para os pares string-valor
     */
    @Override
    public Iterator<Entry<String, Value>> iterator() {
        return new Iterator<Entry<String, Value>>() {
            // Usa um iterador de strings internamente
            private final Iterator<String> keyIterator = getKeys().iterator();
            
            @Override
            public boolean hasNext() {
                return keyIterator.hasNext();
            }
            
            @Override
            public Entry<String, Value> next() {
                String key = keyIterator.next();
                return new Entry<>(key, get(key));
            }
        };
    }
}