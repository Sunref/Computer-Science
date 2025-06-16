/*
 * Exercício 1 - Inverter String
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 1: Função que inverte uma string
function inverterString(texto) {
  return texto.split("").reverse().join("");
}

// Função para manipular o DOM e mostrar o resultado
function inverterTexto() {
  const texto = document.getElementById("textoInverter").value;

  if (!texto) {
    document.getElementById("resultadoEx1").textContent =
      "Por favor, digite um texto.";
    return;
  }

  const textoInvertido = inverterString(texto);
  document.getElementById("resultadoEx1").textContent =
    `Texto invertido: ${textoInvertido}`;
}

// Adicionar evento de pressionar Enter no input
document
  .getElementById("textoInverter")
  .addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      inverterTexto();
    }
  });
