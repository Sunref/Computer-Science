/*
 * Exercício 9 - Comparar textos em dois campos
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 9: Verificar se os textos em dois campos são idênticos
function compararTextos() {
  const texto1 = document.getElementById("texto1").value.trim();
  const texto2 = document.getElementById("texto2").value.trim();

  // Verificar se os campos estão vazios
  if (!texto1 || !texto2) {
    document.getElementById("resultadoEx9").textContent =
      "Por favor, preencha ambos os campos de texto.";
    document.getElementById("resultadoEx9").style.color = "red";

    // Destacar campos vazios
    if (!texto1) document.getElementById("texto1").style.borderColor = "red";
    if (!texto2) document.getElementById("texto2").style.borderColor = "red";
    return;
  }

  // Comparar os textos
  if (texto1 === texto2) {
    document.getElementById("resultadoEx9").textContent =
      "Os textos são idênticos!";
    document.getElementById("resultadoEx9").style.color = "green";
  } else {
    document.getElementById("resultadoEx9").textContent =
      "Os textos são diferentes!";
    document.getElementById("resultadoEx9").style.color = "red";
  }

  // Resetar bordas
  document.getElementById("texto1").style.borderColor = "";
  document.getElementById("texto2").style.borderColor = "";
}

// Função para verificar input em tempo real
function verificarInput() {
  const texto1 = document.getElementById("texto1");
  const texto2 = document.getElementById("texto2");

  // Adicionar evento de input para ambos os campos
  texto1.addEventListener("input", function () {
    if (!this.value.trim()) {
      this.style.borderColor = "red";
    } else {
      this.style.borderColor = "";
    }
  });

  texto2.addEventListener("input", function () {
    if (!this.value.trim()) {
      this.style.borderColor = "red";
    } else {
      this.style.borderColor = "";
    }
  });
}

// Adicionar eventos de Enter para os inputs
document.getElementById("texto1").addEventListener("keypress", function (e) {
  if (e.key === "Enter") {
    document.getElementById("texto2").focus();
  }
});

document.getElementById("texto2").addEventListener("keypress", function (e) {
  if (e.key === "Enter") {
    compararTextos();
  }
});

// Inicializar a verificação de input quando a página carregar
document.addEventListener("DOMContentLoaded", verificarInput);
