/*
 * Exercício 5 - Encontrar valor em um vetor
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 5: Encontrar um valor em um vetor e retornar sua posição
function encontrarValorNoVetor(vetor, valor) {
  // Retorna o índice do valor no vetor ou -1 se não encontrar
  return vetor.indexOf(valor);
}

// Vetor de exemplo para busca
const vetorNumeros = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];

// Função para manipular o DOM e mostrar o resultado
function buscarValor() {
  const input = document.getElementById("valorBusca");
  const valor = parseInt(input.value);

  if (isNaN(valor)) {
    document.getElementById("resultadoEx5").textContent =
      "Por favor, digite um número válido.";
    return;
  }

  const posicao = encontrarValorNoVetor(vetorNumeros, valor);

  if (posicao === -1) {
    document.getElementById("resultadoEx5").textContent =
      `O valor ${valor} não foi encontrado no vetor: [${vetorNumeros.join(", ")}]`;
  } else {
    document.getElementById("resultadoEx5").textContent =
      `O valor ${valor} foi encontrado na posição ${posicao} do vetor: [${vetorNumeros.join(", ")}]`;
  }
}

// Adicionar evento de pressionar Enter no input
document
  .getElementById("valorBusca")
  .addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      buscarValor();
    }
  });

// Mostrar o vetor inicial quando a página carregar
document.addEventListener("DOMContentLoaded", function () {
  document.getElementById("resultadoEx5").textContent =
    `Vetor para busca: [${vetorNumeros.join(", ")}]`;
});
