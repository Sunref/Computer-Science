package common;

/**
 * Classe que representa uma entrada (par chave-valor) em uma estrutura de dados.
 * Esta classe é imutável em relação à chave, mas permite alteração do valor.
 *
 * @param <Key> tipo da chave
 * @param <Value> tipo do valor
 * 
 * @author Fernanda Martins da Silva BV3032345
 * @version 1.0
 * Projeto: Organização e Recuperação da Informação
 */
public class Entry<Key, Value> {
    
    /** A chave do par chave-valor. É final para garantir imutabilidade. */
    private final Key key;
    
    /** O valor associado à chave. Pode ser modificado após a criação. */
    private Value value;
    
    /**
     * Construtor que cria uma nova entrada com uma chave e valor.
     *
     * @param key a chave da entrada (não pode ser modificada depois)
     * @param value o valor inicial associado à chave
     */
    public Entry(Key key, Value value) {
        this.key = key;
        this.value = value;
    }
    
    /**
     * Retorna a chave desta entrada.
     *
     * @return a chave armazenada
     */
    public Key getKey() {
        return key;
    }
    
    /**
     * Retorna o valor associado à chave.
     *
     * @return o valor atual
     */
    public Value getValue() {
        return value;
    }
    
    /**
     * Atualiza o valor associado à chave.
     *
     * @param value o novo valor a ser associado à chave
     */
    public void setValue(Value value) {
        this.value = value;
    }
}