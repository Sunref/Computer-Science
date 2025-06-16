/*
 * Exercício 2 - Apresentar a data atual em formato dd/mm/yyyy
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 2: Apresentar a data atual no formato dd/mm/yyyy
function formatarData(data) {
  const dia = String(data.getDate()).padStart(2, "0");
  const mes = String(data.getMonth() + 1).padStart(2, "0");
  const ano = data.getFullYear();

  return `${dia}/${mes}/${ano}`;
}

// Função para atualizar a data na página
function mostrarDataAtual() {
  const dataAtual = new Date();
  const dataFormatada = formatarData(dataAtual);
  document.getElementById("dataAtual").textContent =
    `Data atual: ${dataFormatada}`;
}

// Atualizar a data quando a página carregar
document.addEventListener("DOMContentLoaded", mostrarDataAtual);

// Atualizar a data a cada segundo
setInterval(mostrarDataAtual, 1000);
