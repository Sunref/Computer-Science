/*
 * Exercício 4 - Juntar strings de um vetor usando ";"
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 4: Converter vetor de strings em uma única string separada por ";"
function juntarVetorStrings(vetor) {
    // Verifica se o vetor está vazio
    if (!vetor || vetor.length === 0) {
        return "";
    }

    // Junta os elementos do vetor usando ";" como separador
    return vetor.join(';');
}

// Função para manipular o DOM e mostrar o resultado
function juntarStrings() {
    const input = document.getElementById('stringArray');
    const texto = input.value.trim();

    if (!texto) {
        document.getElementById('resultadoEx4').textContent = 'Por favor, digite algumas palavras.';
        return;
    }

    // Divide o texto em um array usando espaço como separador e remove espaços extras
    const vetorPalavras = texto.split(' ').filter(palavra => palavra.length > 0);

    if (vetorPalavras.length === 0) {
        document.getElementById('resultadoEx4').textContent = 'Por favor, digite palavras válidas.';
        return;
    }

    const resultado = juntarVetorStrings(vetorPalavras);
    document.getElementById('resultadoEx4').textContent = `Resultado: ${resultado}`;
}

// Adicionar evento de pressionar Enter no input
document.getElementById('stringArray').addEventListener('keypress', function(e) {
    if (e.key === 'Enter') {
        juntarStrings();
    }
});
