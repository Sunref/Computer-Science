/*
 * Exercício 3 - Verificar se um ano é bissexto
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 3: Verificar se um ano é bissexto
function verificarBissexto(ano) {
  // Um ano é bissexto se for divisível por 4
  // Mas não é bissexto se for divisível por 100, a menos que também seja divisível por 400
  if ((ano % 4 === 0 && ano % 100 !== 0) || ano % 400 === 0) {
    return "Ano Bissexto";
  }
  return "Não é Ano Bissexto";
}

// Função para manipular o DOM e mostrar o resultado
function verificarAnoBissexto() {
  const inputAno = document.getElementById("anoBissexto");
  const ano = parseInt(inputAno.value);

  if (isNaN(ano) || ano <= 0) {
    document.getElementById("resultadoEx3").textContent =
      "Por favor, digite um ano válido.";
    return;
  }

  const resultado = verificarBissexto(ano);
  document.getElementById("resultadoEx3").textContent = `${ano}: ${resultado}`;
}

// Adicionar evento de pressionar Enter no input
document
  .getElementById("anoBissexto")
  .addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      verificarAnoBissexto();
    }
  });
