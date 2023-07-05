#include <iostream>
#include <time.h>
using namespace std;

#define TAM 9
#define TAM2 41

int main() {
  srand(time(NULL)); 
  
  int Menu, Matrizgabarito, i=0, j=0,
      MatrizGabarito[TAM][TAM] = {0},
      MatrizFixa[TAM][TAM] = {5, 3, 4, 6, 7, 8, 9, 1, 2, 
                              6, 7, 2, 1, 9, 5, 3, 4, 8,
                              1, 9, 8, 3, 4, 2, 5, 6, 7,
                              8, 5, 9, 7, 6, 1, 4, 2, 3,
                              4, 2, 6, 8, 5, 3, 7, 9, 1,
                              7, 1, 3, 9, 2, 4, 8, 5, 6,
                              9, 6, 1, 5, 3, 7, 2, 8, 4,
                              2, 8, 7, 4, 1,  9, 6, 3, 5,
                              3, 4, 5, 2, 8, 6, 1, 7, 9},
      matrizJogo[TAM][TAM] = {0}, contador = 0, contVit = 0, comp = 0;

  /* A variável "Menu" foi criada para ser utilizada na estrutura Switch/Case para definirmos os botões do jogo em função dela.*/

  do {
    cout << "1 - Jogar \n";
    cout << "2 - Sobre \n";
    cout << "3 - Sair \n";
    cin >> Menu;

    if (Menu <= 0 || Menu > 3)
      cout << "Número invalido, selecione uma opção válida.\n"  << endl;
    /* Evitar erros na hora de escolher a opção do menu*/

    switch (Menu) {
    case 1:

      system("clear");
      Matrizgabarito =
          rand() % 4 + 1; // escolhe aleatorimente um número de 1 a 4 para realizar uma operação com a matriz fixa

      switch (Matrizgabarito) {
      case 1: // por meio dessa lógica, a matriz gabarito será uma cópia da matriz fixa.
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            MatrizGabarito[i][j] = MatrizFixa[i][j];
          }
        }

        break;

      case 2: // Por meio dessa lógica, ocorre a transposição das linhas e colunas da matriz.
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            MatrizGabarito[j][i] = MatrizFixa[i][j];
          }
        }

        break;

      case 3: // Por meio dessa lógica, obtém-se a condição de invetida por linha.
        for (int i = TAM - 1; i >= 0; i--) {
          for (int j = 0; j < TAM; j++) {
            MatrizGabarito[TAM - i - 1][j] = MatrizFixa[i][j];
            //
          }
        }

        break;

      case 4: // Por meio dessa lógica, obtém-se a condição de invertida por coluna.
        for (int i = 0; i < TAM; i++) {
          for (int j = TAM - 1; j >= 0; j--) {
            MatrizGabarito[i][TAM - j - 1] = MatrizFixa[i][j];
          }
        }

        break;
      }

      while (contador < TAM2) {
        
        /*Preenche uma posição aleatória da matriz jogo com um valor da matriz gabarito*/
        i = rand() % 9;
        j = rand() % 9;
        if (matrizJogo[i][j] == 0) {
          matrizJogo[i][j] = MatrizGabarito[i][j];
          contador++; //só conta se a numero for zero
        }
      }

      /* sorteia aleatóriamente uma linha e uma coluna da matriz jogo, inicialmente preenchida apenas com 0 em todas as posições, e preenche essa posiçõe com o mesmo número da respectiva posição da matriz gabarito, até que as 41 posições estejam preenchidas*/

      for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
          cout << matrizJogo[i][j] << "\t";
        }
        cout << "\n";
      } // exibe a matriz jogo

      cout << "Todos os espaços com 0 devem ser preenchidos de acordo com as regras do Sudoku, digite a posição que você deseja preencher e seu respectivo número. "<< endl;

      do {
        comp = 0; // A váriavel comp é usada para comparar a matriz jogo com a matriz gabarito, dessa forma caso algum elemento das duas não coincidir, ele recebe 1, se não permanece 0.
        for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
            if (matrizJogo[i][j] != MatrizGabarito[i][j]) {
              comp = 1;
            }
          }
        } // Verificar se a matrizJogo é igual à MatrizGabarito

        /*Caso elas sejam diferentes, o jogo continua, se forem iguais é mostrado o aviso de vitória*/

        if (comp == 1) {

          cout << "Digite a linha: "; // Solicita a linha ao jogador
          cin >> i;
          cout << endl;

          cout << "Digite a coluna: "; // Solicita a coluna ao jogador
          cin >> j;
          cout << endl;

          if (i < 0 || j>8 || i>8 || j < 0) {
            // Verifica se a posição selecionada pelo jogador está fora do intervalo válido (0 a 8)
            cout << "Posição inválida, digite uma posição válida: "<< endl; // Evita erros quando o jogador escrever uma posição inválida
          } else if (matrizJogo[i][j] == 0) {
            // Verifica se a posição selecionada está vazia na matriz de jogo
            cout << "Digite o número: "; // Solicita o número ao jogador para preencher a posição
            cin >> matrizJogo[i][j];
            if (matrizJogo[i][j] == MatrizGabarito[i][j]) {
              // Verifica se o número preenchido pelo jogador é igual ao número correto na matriz gabarito
              cout << endl << "Número correto!" << endl << endl;
              contVit++; // incrementa o contador de vitórias

              for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++) {
                  cout << matrizJogo[i][j] << "\t";
                }
                cout << "\n";
              } // Mostra a matriz jogo atualizada

              cout << endl;
            } else if (matrizJogo[i][j] < 1 || matrizJogo[i][j] > 9) {
              matrizJogo[i][j] = 0;//O número preenchido volta a ser 0, pois é um número inválido
              cout << endl<< "Número inválido, digite um número entre 1 e 9."<< endl; // Evita erros quando o jogador escrever um número inválido
            } else {
              // O número preenchido pelo jogador é diferente do número correto na matriz gabarito
              matrizJogo[i][j] = 0;// o valor volta a ser zero, pois o usuário errou o número
              cout << endl << "Número incorreto!" << endl << endl;
              contVit++;
            }
          } else{
            cout << "Posição já preenchida, escolha uma posição 0."<< endl; // Evita erros quando o jogador escrever uma posição que já está preenchida
          }
        } else {
          // O jogo foi concluído e o jogador ganhou
          cout << endl<< "Parábens! Você ganhou! Você pecisou de " << contVit<< " jogadas para ganhar." << endl;
          cout << "Pressione Enter para voltar ao menu...";

          for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
              matrizJogo[i][j] = 0;
            }
          }
          contVit = 0;  // reinicia a contagem de vitórias
          contador = 0; // reinicia a contagem

          /*Zera a matriz jogo novamente, assim como o contador de jogadas necessarias para ganhar e o contador, para caso o jogador opte por jogar novamente, ela seja preenchida adequadamente*/

          cin.ignore();
          cin.get();
          system("clear");
        }

      } while (comp == 1);

      /* Equanto comp for igual a 1 a matriz jogo não coincide com a matriz gabarito, logo o jogador ainda não preencheu todo jogo corretamente e o jogo se repete, até que que as duas matrizes sejam iguais, logo o comp permanecerá 0 e a mensagem de vitória irá surgir na tela*/

      break;

    case 2:

      system("clear");

      cout << "Univali - Engenharia da Computação - 1º semestre - Junho de 2023 "<< "\n";
      cout << "Acadêmicos: Isabella Zermiani Bastos, Milene Emmel, Henry José e Sthephany Araceli Melho Dos Santos."<< "\n";
      cout << "Disciplina: Algoritmos e programação I"<< "\n";
      cout << "Professor: Rafael Ballottin Martins"<< "\n"<< "\n";

      cout << "Pressione Enter para continuar...";
      cin.ignore();
      cin.get();
      system("clear"); // Limpa a tela antes de exibir o menu novamente

      break;

    } // Fim do Switch "Menu"
  } while (Menu != 3);
  system("clear");
  return 0;

  /* While descreve a condição de encerramento do jogo caso digitem o número 3, que foi o número escolhido como botão de sair do jogo.*/
}