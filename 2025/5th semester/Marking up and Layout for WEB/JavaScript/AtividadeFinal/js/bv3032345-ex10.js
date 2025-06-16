/*
 * Exercício 10 - Validar login e senha (nome completo e prontuário)
 * Fernanda Martins da Silva bv3032345
 */

// Exercício 10: Validar login (nome completo) e senha (prontuário)

// Função para validar nome completo
function validarNomeCompleto(nome) {
  // Verifica se o nome tem pelo menos duas palavras
  const palavras = nome.trim().split(/\s+/);
  return palavras.length >= 2;
}

// Função para validar prontuário
function validarProntuario(prontuario) {
  // Verifica se o prontuário segue o padrão: bv + 6 dígitos
  const regex = /^bv\d{6}$/;
  return regex.test(prontuario.toLowerCase());
}

// Função principal de validação
function validarLogin() {
  const loginInput = document.getElementById("login");
  const senhaInput = document.getElementById("senha");

  const login = loginInput.value.trim();
  const senha = senhaInput.value.trim();

  // Resetar estilos
  loginInput.style.borderColor = "";
  senhaInput.style.borderColor = "";

  let mensagens = [];

  // Validar login (nome completo)
  if (!login) {
    mensagens.push("O nome completo é obrigatório.");
    loginInput.style.borderColor = "red";
  } else if (!validarNomeCompleto(login)) {
    mensagens.push("Por favor, digite seu nome completo (nome e sobrenome).");
    loginInput.style.borderColor = "red";
  }

  // Validar senha (prontuário)
  if (!senha) {
    mensagens.push("O prontuário é obrigatório.");
    senhaInput.style.borderColor = "red";
  } else if (!validarProntuario(senha)) {
    mensagens.push(
      "O prontuário deve seguir o padrão: bv + 6 dígitos (exemplo: bv222222)",
    );
    senhaInput.style.borderColor = "red";
  }

  // Mostrar resultado
  const resultadoElement = document.getElementById("resultadoEx10");

  if (mensagens.length > 0) {
    resultadoElement.textContent = mensagens.join("\n");
    resultadoElement.style.color = "red";
  } else {
    resultadoElement.textContent = "Login e senha válidos!";
    resultadoElement.style.color = "green";
  }
}

// Adicionar eventos de Enter para os inputs
document.getElementById("login").addEventListener("keypress", function (e) {
  if (e.key === "Enter") {
    document.getElementById("senha").focus();
  }
});

document.getElementById("senha").addEventListener("keypress", function (e) {
  if (e.key === "Enter") {
    validarLogin();
  }
});

// Função para limpar mensagens de erro ao digitar
function limparErroAoDigitar(input) {
  input.style.borderColor = "";
  document.getElementById("resultadoEx10").textContent = "";
}

// Adicionar eventos de input para limpar erros
document.addEventListener("DOMContentLoaded", function () {
  const loginInput = document.getElementById("login");
  const senhaInput = document.getElementById("senha");

  loginInput.addEventListener("input", function () {
    limparErroAoDigitar(this);
  });

  senhaInput.addEventListener("input", function () {
    limparErroAoDigitar(this);
  });
});
