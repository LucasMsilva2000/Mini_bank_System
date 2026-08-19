🏦 Mini Bank System

Sistema bancário simples desenvolvido em C, rodando via terminal (CLI). Permite depositar, sacar, transferir dinheiro e consultar o histórico de transações, com tudo sendo registrado em um arquivo de texto.

✨ Funcionalidades
💰 Depositar dinheiro
💸 Sacar dinheiro (com verificação de saldo)
🔄 Transferir dinheiro entre contas
📋 Consultar detalhes da conta (nome, número, saldo)
🧾 Consultar histórico de transações
📝 Registro automático de cada transação em Conta.txt, com data e hora
🖥️ Como executar
Pré-requisitos

Você precisa de um compilador C instalado, como o GCC.

Compilando
bash
gcc -o bank bank.c
Rodando
bash
./bank

No Windows (via terminal do VS Code ou cmd):

bash
bank.exe
📖 Como usar

Ao iniciar o programa, você informa seu nome e número da conta. Em seguida, o menu principal aparece:

===== Menu Principal =====
1. Depositar dinheiro
2. Sacar dinheiro
3. Transferir dinheiro
4. Detalhes da conta
5. Detalhes das transacoes
6. Sair

Basta digitar o número da opção desejada e seguir as instruções na tela.

🗂️ Estrutura do projeto
Mini_bank_System/
├── bank.c        # Código-fonte principal
├── Conta.txt     # Gerado automaticamente com o histórico de transações
└── README.md
🚧 Possíveis melhorias futuras
 Persistir o saldo entre execuções (atualmente reinicia em R$10.000 a cada vez que o programa roda)
 Suporte a múltiplas contas reais, com autenticação por senha
 Validação mais robusta das entradas do usuário
