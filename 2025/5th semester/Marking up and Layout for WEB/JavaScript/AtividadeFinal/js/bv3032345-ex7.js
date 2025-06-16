/*
 * Exercício 7 - Ordenar vetor em ordem decrescente
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 7: Criar um novo vetor com três valores em ordem decrescente
function ordenarVetor() {
  // Pegar os valores dos inputs
  const valor1 = parseInt(document.getElementById("valor1").value);
  const valor2 = parseInt(document.getElementById("valor2").value);
  const valor3 = parseInt(document.getElementById("valor3").value);

  // Verificar se todos os valores são números válidos
  if (isNaN(valor1) || isNaN(valor2) || isNaN(valor3)) {
    document.getElementById("resultadoEx7").textContent =
      "Por favor, preencha todos os campos com números válidos.";
    return;
  }

  // Criar vetor com os valores
  const vetor = [valor1, valor2, valor3];

  // Ordenar o vetor em ordem decrescente
  const vetorOrdenado = vetor.sort((a, b) => b - a);

  // Mostrar o resultado
  document.getElementById("resultadoEx7").textContent =
    `Vetor original: [${valor1}, ${valor2}, ${valor3}]\nVetor ordenado: [${vetorOrdenado.join(", ")}]`;
}

// Função para ordenar quando pressionar Enter em qualquer input
function adicionarEventoEnter(inputId) {
  document.getElementById(inputId).addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      // Verifica se todos os campos estão preenchidos
      const valor1 = document.getElementById("valor1").value;
      const valor2 = document.getElementById("valor2").value;
      const valor3 = document.getElementById("valor3").value;

      if (valor1 && valor2 && valor3) {
        ordenarVetor();
      }
    }
  });
}

// Adicionar eventos de Enter para todos os inputs
document.addEventListener("DOMContentLoaded", function () {
  adicionarEventoEnter("valor1");
  adicionarEventoEnter("valor2");
  adicionarEventoEnter("valor3");
});
