/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package alg.avl.implementation;

import alg.avl.dependents.avl.AVLTree;
import alg.avl.dependents.avl.TraversalTypes;

public class Main {

    public static void main(String[] args) {
        AVLTree<Character, String> avlTree = new AVLTree<>();
        
        avlTree.put('J', "Julia");
        avlTree.put('K', "Kevin");
        avlTree.put('L', "Laura");
        avlTree.put('M', "Mark");
        avlTree.put('N', "Nina");

        System.out.println("Árvore Balanceada:");
        System.out.println(avlTree);

        avlTree.put('F', "Fernanda");

        System.out.println("Árvore Balanceada após inserir 'F':");
        System.out.println(avlTree);

        System.out.println("Buscando por 'L': " + avlTree.get('L'));
        System.out.println("Buscando por 'X': " + avlTree.get('X'));

        avlTree.delete('K');
        System.out.println("Árvore Balanceada após remover 'K':");
        System.out.println(avlTree);

        System.out.println("Percorrendo a TREE AVL:");
        for (AVLTree.Entry<Character, String> entry : avlTree.traverse(
            TraversalTypes.INORDER
        )) 
        {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}
