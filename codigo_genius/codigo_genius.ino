#include <stdio.h>
#include "constants.h"

// VARIÁVEIS PARA DETERMINAR QUAL BOTÃO ESTÁ SENDO PRESSIONADO
char is_blue;
char is_green;
char is_yellow;
char is_red;
char which_button;

// VETOR QUE ARMAZENA VALORES ALEATÓRIOS GERADOS NO JOGO
int n_seq_vector = 1;
int *seq_vector;

/*
  LÊ QUAL BOTÃO ESTÁ SENDO PRESSIONADO:

  O delay() TEM A FUNÇÃO DE EVITAR QUE, AO MANTER O BOTÃO PRESSIONADO
  POR LONGOS PERÍODOS, O JOGO ACUSE SEQUÊNCIA INCORRETA, JÁ QUE, DESSA
  FORMA, UM MESMO VALOR SERIA RECEBIDO DIVERSAS VEZES (POR CONTA DA)
  FREQUÊNCIA DE PROCESSAMENTO;
*/
char pressed_button() {
  if (is_blue == 1 && is_green == 0 && is_yellow == 0 && is_red == 0) {
    delay(200);
    return 0;
  } else if (is_blue == 0 && is_green == 1 && is_yellow == 0 && is_red == 0) {
    delay(200);
    return 1;
  } else if (is_blue == 0 && is_green == 0 && is_yellow == 1 && is_red == 0) {
    delay(200);
    return 2;
  } else if (is_blue == 0 && is_green == 0 && is_yellow == 0 && is_red == 1) {
    delay(200);
    return 3;
  } else {
    return -1;
  }
}


// LÊ OS VALORES DOS BOTÕES INCONDICIONALMENTE
void read_buttons() {
  is_blue = digitalRead(BLUE_BTN);
  is_green = digitalRead(GREEN_BTN);
  is_yellow = digitalRead(YELLOW_BTN);
  is_red = digitalRead(RED_BTN);
}

void setup() {
  // DEFININDO BOTÕES DE ENTRADA
  pinMode(BLUE_BTN, INPUT);
  pinMode(GREEN_BTN, INPUT);
  pinMode(YELLOW_BTN, INPUT);
  pinMode(RED_BTN, INPUT);

  // DEFININDO LEDs DE SAÍDA
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  seq_vector = (int *)malloc(sizeof(int));
}

void loop() {
  // DEFINE ALEATORIAMENTE O VALOR DO NOVO ELEMENTO DO VETOR
  *(seq_vector + n_seq_vector) = 1;  // TODO AQUI DEVE TER UMA FUNÇÃO QUE GERE UM VALOR ALEATÓRIO

  while (which_button == -1)
    which_button = pressed_button();


  // INCREMENTA EM 1 O TAMANHO DO VETOR PARA QUE UM NOVO ELEMENTO SEJA INSERIDO, QUE SERÁ A PRÓXIMA COR
  // ADICIONADA À SEQUÊNCIA
  n_seq_vector++;
  seq_vector = realloc(seq_vector, n_seq_vector * sizeof(int));
}
