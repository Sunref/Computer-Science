/*
 * Exercício 6 - Copiar string removendo vogais
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 6: Copiar uma string para outra retirando as vogais
function removerVogaisString(texto) {
  // Remove todas as vogais (maiúsculas e minúsculas, com e sem acentos)
  return texto.replace(
    /[aeiouáéíóúâêîôûãõàèìòùäëïöüAEIOUÁÉÍÓÚÂÊÎÔÛÃÕÀÈÌÒÙÄËÏÖÜ]/g,
    "",
  );
}

// Função para manipular o DOM e mostrar o resultado
function removerVogais() {
  const input = document.getElementById("textoVogais");
  const texto = input.value.trim();

  if (!texto) {
    document.getElementById("resultadoEx6").textContent =
      "Por favor, digite um texto.";
    return;
  }

  const textoSemVogais = removerVogaisString(texto);
  document.getElementById("resultadoEx6").textContent =
    `Texto original: ${texto}\nTexto sem vogais: ${textoSemVogais}`;
}

// Adicionar evento de pressionar Enter no input
document
  .getElementById("textoVogais")
  .addEventListener("keypress", function (e) {
    if (e.key === "Enter") {
      removerVogais();
    }
  });
