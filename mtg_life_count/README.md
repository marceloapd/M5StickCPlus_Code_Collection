# Contador de Pontos de Vida para M5StickCPlus

## Descrição

Este é um software de contador de vida simples projetado para o jogo Magic The Gathering (MTG), desenvolvido para acompanhar os totais de vida dos jogadores. Ele foi desenvolvido para o dispositivo M5StickCPlus e exibe dois contadores de vida: um para o jogador vermelho e outro para o jogador azul. Cada contador começa com um total de vida de 40 pontos.

## Características

* Dois contadores de vida
* Diminui o total de vida quando o botão correspondente é pressionado
* Redefine o total de vida para 40 no início de um novo jogo

## Uso

1. Ligue seu M5StickCPlus.
2. Carregue este software.
3. No início de um jogo, o total de pontos de vida de cada jogador será definido como 40.
4. O total de pontos de vida do jogador vermelho pode ser diminuído pressionando o botão "PWR".
5. O total de pontos de vida do jogador azul pode ser diminuído pressionando o botão "BtnB".

## Desenvolvimento Futuro

Esperamos adicionar no futuro suporte para mais mecânicas como:

* Contador de dano de comandante
* Contadores de veneno
* Mais jogadores
* E muitas outras mecânicas relacionadas com MTG

## Contribuindo

Contribuições são sempre bem-vindas, sinta-se à vontade para abrir um pull-request com novos recursos ou melhorias.

## Codificação
Este código foi escrito em C++ para o dispositivo Arduino, M5StickCPlus. Tenha em mente que deve ser instalada a biblioteca `M5StickCPlus.h` do Arduino's Library Manager.

Aproveite seus jogos de Magic com um contador de vida eficiente, eletrônico e estiloso!