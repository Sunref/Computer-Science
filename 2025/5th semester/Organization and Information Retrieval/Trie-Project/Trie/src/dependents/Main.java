package dependents;

import implementation.Trie;

/**
 * Classe Principal do Projeto
 * 
 * @author Fernanda Martins da Silva BV3032345
 * @version 1.0
 * Projeto: Organização e Recuperação da Informação
 */
public class Main {
    public static void main(String[] args) {
        // Criando uma nova Trie
        Trie<Integer> trie = new Trie<>();
        
        // Testando inserções
        System.out.println("Inserindo nomes na Trie...");
        trie.put("Fernanda", 1);
        trie.put("Fernando", 2);
        trie.put("Gabriel", 3);
        trie.put("Gabriela", 4);
        trie.put("Marcelo", 5);
        trie.put("Maria", 6);
        trie.put("Marina", 7);
        trie.put("Pedro", 8);
        
        // Testando buscas
        System.out.println("\nTestando buscas:");
        System.out.println("Valor para 'Fernanda': " + trie.get("Fernanda"));   // deve mostrar 1
        System.out.println("Valor para 'Gabriel': " + trie.get("Gabriel"));     // deve mostrar 3
        System.out.println("Valor para 'Marina': " + trie.get("Marina"));       // deve mostrar 7
        
        // Testando contains
        System.out.println("\nTestando contains:");
        System.out.println("Contém 'Marcelo'? " + trie.contains("Marcelo"));   // deve mostrar true
        System.out.println("Contém 'Marcos'? " + trie.contains("Marcos"));     // deve mostrar false
        
        // Mostrando todas as chaves
        System.out.println("\nTodos os nomes na Trie:");
        for (String key : trie.getKeys()) {
            System.out.println(key + " -> " + trie.get(key));
        }
        
        // Testando remoção
        System.out.println("\nTestando remoção:");
        System.out.println("Removendo 'Maria'");
        trie.delete("Maria");
        System.out.println("Contém 'Maria'? " + trie.contains("Maria"));      // deve mostrar false
        
        // Mostrando o tamanho
        System.out.println("\nTamanho da Trie: " + trie.getSize());
    }
}