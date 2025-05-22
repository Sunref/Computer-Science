package implementation;

import common.Entry;
import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.Before;
import java.util.ArrayList;
import java.util.List;

/**
 * Classe de testes unitários para a implementação da Trie.
 * Testa todas as operações básicas definidas na interface SymbolTable.
 * 
 * @author Fernanda Martins da Silva BV3032345
 * @version 1.0
 * Projeto: Organização e Recuperação da Informação
 */

public class TrieTest {
    
    /** Instância da Trie que será usada nos testes */
    private Trie<String> trie;
    
    /**
     * Configuração executada antes de cada teste.
     * Cria uma nova instância da Trie para garantir que cada teste
     * comece com uma estrutura vazia.
     */
    @Before
    public void setUp() {
        trie = new Trie<>();
    }
    
    /**
     * Testa o estado inicial de uma Trie recém-criada.
     * Verifica se está vazia e se o tamanho é zero.
     */
    @Test
    public void testEmptyTrie() {
        assertTrue("Nova trie deve estar vazia", trie.isEmpty());
        assertEquals("Nova trie deve ter tamanho 0", 0, trie.getSize());
    }
    
    /**
     * Testa as operações básicas de inserção e recuperação.
     * Verifica:
     * - Inserção de múltiplos valores
     * - Recuperação de valores inseridos
     * - Tentativa de recuperar chave inexistente
     * - Contagem correta do tamanho
     */
    @Test
    public void testPutAndGet() {
        trie.put("teste", "valor1");
        trie.put("casa", "valor2");
        trie.put("casamento", "valor3");
        
        assertEquals("Valor incorreto para chave 'teste'", "valor1", trie.get("teste"));
        assertEquals("Valor incorreto para chave 'casa'", "valor2", trie.get("casa"));
        assertEquals("Valor incorreto para chave 'casamento'", "valor3", trie.get("casamento"));
        assertNull("Chave inexistente deve retornar null", trie.get("outro"));
        assertEquals("Tamanho deve ser 3", 3, trie.getSize());
    }
    
    /**
     * Testa o comportamento ao tentar inserir uma chave null.
     * Deve lançar IllegalArgumentException.
     */
    @Test(expected = IllegalArgumentException.class)
    public void testPutNullKey() {
        trie.put(null, "valor");
    }
    
    /**
     * Testa o comportamento ao inserir um valor null.
     * Quando um valor null é inserido, a chave deve ser removida (comportamento de delete).
     */
    @Test
    public void testPutNullValue() {
        trie.put("teste", "valor");
        assertEquals("Tamanho deve ser 1 após inserção", 1, trie.getSize());
        
        trie.put("teste", null);
        assertEquals("Tamanho deve ser 0 após inserir valor null (delete)", 0, trie.getSize());
        assertNull("Valor deve ser null após inserir valor null", trie.get("teste"));
    }
    
    /**
     * Testa a operação de remoção.
     * Verifica:
     * - Remoção correta de uma chave
     * - Atualização do tamanho após remoção
     * - Valor removido retorna null
     * - Outras chaves permanecem inalteradas
     */
    @Test
    public void testDelete() {
        trie.put("teste", "valor1");
        trie.put("casa", "valor2");
        
        assertEquals("Tamanho deve ser 2 antes da deleção", 2, trie.getSize());
        trie.delete("teste");
        assertEquals("Tamanho deve ser 1 após deleção", 1, trie.getSize());
        assertNull("Valor deve ser null após deleção", trie.get("teste"));
        assertEquals("Outros valores devem permanecer intactos", "valor2", trie.get("casa"));
    }
    
    /**
     * Testa o método contains.
     * Verifica se retorna true para chaves existentes e false para inexistentes.
     */
    @Test
    public void testContains() {
        trie.put("teste", "valor");
        
        assertTrue("Deve conter a chave inserida", trie.contains("teste"));
        assertFalse("Não deve conter chave não inserida", trie.contains("outro"));
    }
    
    /**
     * Testa a recuperação de todas as chaves.
     * Verifica:
     * - Se todas as chaves inseridas são retornadas
     * - Se o número de chaves está correto
     * - Se não há chaves extras ou faltantes
     */
    @Test
    public void testGetKeys() {
        trie.put("a", "valor1");
        trie.put("b", "valor2");
        
        List<String> keys = new ArrayList<>();
        for (String key : trie.getKeys()) {
            keys.add(key);
        }
        
        assertEquals("Número incorreto de chaves", 2, keys.size());
        assertTrue("Deve conter a chave 'a'", keys.contains("a"));
        assertTrue("Deve conter a chave 'b'", keys.contains("b"));
    }
    
    /**
     * Testa o iterador da Trie.
     * Verifica:
     * - Se todos os pares chave-valor são acessíveis
     * - Se os pares estão corretos
     * - Se o número de iterações está correto
     */
    @Test
    public void testIterator() {
        trie.put("a", "valor1");
        trie.put("b", "valor2");
        
        int count = 0;
        for (Entry<String, String> entry : trie) {
            count++;
            String key = entry.getKey();
            String value = entry.getValue();
            assertTrue("Par chave-valor inesperado",
                    (key.equals("a") && value.equals("valor1")) ||
                    (key.equals("b") && value.equals("valor2")));
        }
        assertEquals("Número incorreto de entradas no iterator", 2, count);
    }
}