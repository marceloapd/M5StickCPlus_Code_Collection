# Projeto OpenAI: "Amigos de Merda" 

Este projeto é baseado no uso do **M5StickCPlus**, um dispositivo de desenvolvimento ESP32, vontade de se divertir com os amigos e um toque de inteligência artificial do modelo **GPT-3.5-turbo da OpenAI**.

Este dispositivo irá mostrar uma série de perguntas, a partir de um pressionamento de botão, geradas pelo modelo de linguagem GPT-3.5-turbo que são similares às perguntas do jogo "Amigos de Merda". Tem o objetivo de proporcionar uma interação divertida, curiosa e às vezes constrangedora entre amigos.

## Como funciona

As perguntas são geradas pelo modelo de linguagem GPT-3.5-turbo da OpenAI. Após um pressionamento de botão, o M5StickC conecta-se à API da OpenAI, envia um exemplo de pergunta e solicita a geração de uma frase similar. A pergunta gerada é então exibida na tela do M5StickC. 

## Configuração e Uso

1. Instale as bibliotecas necessárias listadas no início do código no seu Ambiente de Desenvolvimento Integrado (IDE) Arduino.

2. Substitua os campos "ssid" e "password" pelas informações de sua rede Wi-Fi. Substitua "Bearer sk-token" pelo seu token real da OpenAI.

3. Flash o código para o seu M5StickCPlus.

4. Após o dispositivo se conectar ao Wi-Fi, pressione o botão A para gerar a pergunta.

## Importante

- Este código usa caracteres Unicode para remover acentos das respostas da API da OpenAI.

- Certifique-se de jogar em um ambiente confortável, seguro e acolhedor, onde todos tenham liberdade para expressar suas opiniões, mas lembre-se de respeitar os limites e sensibilidades dos outros.

Nota: Este projeto não tem nenhuma afiliação com o jogo oficial "Amigos de Merda".

## Dependências
- Biblioteca M5StickCPlus
- Biblioteca WiFi
- Biblioteca HTTPClient
- Biblioteca ArduinoJson