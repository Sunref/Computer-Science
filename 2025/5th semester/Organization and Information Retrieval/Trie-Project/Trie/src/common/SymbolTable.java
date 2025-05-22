package common;

import common.Entry;

/**
 * Interface que define uma tabela de símbolos genérica (Symbol Table).
 * Uma tabela de símbolos é uma estrutura de dados que armazena pares de chave-valor,
 * permitindo a recuperação eficiente de valores através de suas chaves.
 *
 * @param <Key> tipo da chave - deve ser comparável
 * @param <Value> tipo do valor associado à chave
 * 
 * @author Fernanda Martins da Silva BV3032345
 * @version 1.0
 * Projeto: Organização e Recuperação da Informação
 */
public interface SymbolTable<Key, Value> extends Iterable<Entry<Key, Value>> {
    
    /**
     * Recupera o valor associado a uma chave.
     * 
     * @param key chave a ser buscada
     * @return valor associado à chave, ou null se a chave não existir
     * @throws IllegalArgumentException se a chave for null
     */
    Value get(Key key);
    
    /**
     * Insere ou atualiza um par chave-valor na tabela.
     * Se o valor for null, a chave é removida da tabela.
     * 
     * @param key chave a ser inserida/atualizada
     * @param val valor a ser associado à chave
     * @throws IllegalArgumentException se a chave for null
     */
    void put(Key key, Value val);
    
    /**
     * Remove a chave e seu valor associado da tabela.
     * 
     * @param key chave a ser removida
     * @throws IllegalArgumentException se a chave for null
     */
    void delete(Key key);
    
    /**
     * Verifica se uma chave existe na tabela.
     * 
     * @param key chave a ser verificada
     * @return true se a chave existir, false caso contrário
     * @throws IllegalArgumentException se a chave for null
     */
    boolean contains(Key key);
    
    /**
     * Verifica se a tabela está vazia.
     * 
     * @return true se a tabela não contiver elementos, false caso contrário
     */
    boolean isEmpty();
    
    /**
     * Retorna o número de pares chave-valor na tabela.
     * 
     * @return quantidade de elementos na tabela
     */
    int getSize();
    
    /**
     * Retorna todas as chaves na tabela.
     * A ordem das chaves depende da implementação.
     * 
     * @return objeto iterável contendo todas as chaves
     */
    Iterable<Key> getKeys();
}