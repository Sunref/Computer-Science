/*
 * Exercício 8 - Buscar string por posição em um vetor
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 8: Retornar string de um vetor com base na posição digitada
// Vetor de strings fixo para o exercício
const vetorStrings = [
  "JavaScript",
  "HTML",
  "CSS",
  "Node.js",
  "React",
  "Python",
  "Java",
  "PHP",
  "C++",
  "Ruby",
  "Swift",
];

// Função para buscar string pela posição
function buscarStringPorPosicao(posicao) {
  // Verifica se a posição está dentro dos limites do vetor
  if (posicao >= 0 && posicao < vetorStrings.length) {
    return vetorStrings[posicao];
  }
  return null;
}

// Função para manipular o DOM e mostrar o resultado
function buscarString() {
  const input = document.getElementById("posicaoVetor");
  const posicao = parseInt(input.value);

  // Validações
  if (isNaN(posicao)) {
    document.getElementById("resultadoEx8").textContent =
      "Por favor, digite um número válido.";
    return;
  }

  if (posicao < 0 || posicao > 10) {
    document.getElementById("resultadoEx8").textContent =
      "Por favor, digite um número entre 0 e 10.";
    return;
  }

  const resultado = buscarStringPorPosicao(posicao);

  if (resultado) {
    document.getElementById("resultadoEx8").textContent =
      `Posição ${posicao}: "${resultado}"\nVetor completo: [${vetorStrings.join(", ")}]`;
  } else {
    document.getElementById("resultadoEx8").textContent =
      `Posição ${posicao} não encontrada no vetor.\nVetor completo: [${vetorStrings.join(", ")}]`;
  }
}

// Adicionar evento de pressionar Enter no input
document
  .getElementById("posicaoVetor")
  .addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      buscarString();
    }
  });

// Mostrar o vetor inicial quando a página carregar
document.addEventListener("DOMContentLoaded", function () {
  document.getElementById("resultadoEx8").textContent =
    `Vetor disponível: [${vetorStrings.join(", ")}]`;
});
