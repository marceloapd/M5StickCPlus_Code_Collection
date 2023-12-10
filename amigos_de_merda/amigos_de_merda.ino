#include <M5StickCPlus.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Safira";
const char* password = "6wp853rp";
const char* host = "https://api.openai.com/v1/chat/completions";
const char* bearerToken = "Bearer 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"; // Substitua pelo seu token real

void setup() {
  M5.begin(); 
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setRotation(1);
  
  WiFi.begin(ssid, password);
  M5.Lcd.print("Carregando");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  
  // Posiciona o texto "AMIGOS DE" na parte superior do centro
  M5.Lcd.setCursor(70, 50);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("AMIGOS DE");
  
  // Posiciona o texto "MERDA" na parte inferior do centro e em vermelho
  M5.Lcd.setCursor(70, 70);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.println("MERDA");
  
  // Posiciona o texto "M5STACK VERSION" no canto inferior direito e pequeno
  M5.Lcd.setCursor(2, 125);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.println("M5STACK VERSION");
  
  // Posiciona o texto "marceloapd" no canto inferior esquerdo
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.println("marceloapd");

  // Posiciona o texto "Powered by ChatGPT" no canto superior direito
  M5.Lcd.setCursor(120, 0);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(1);
  M5.Lcd.println("Powered by ChatGPT");
  M5.Lcd.setTextSize(2);
}

String removeAcentos(String input) {
  input.replace("á", "a");
  input.replace("à", "a");
  input.replace("â", "a");
  input.replace("ã", "a");
  input.replace("ä", "a");
  input.replace("é", "e");
  input.replace("è", "e");
  input.replace("ê", "e");
  input.replace("ë", "e");
  input.replace("í", "i");
  input.replace("ì", "i");
  input.replace("î", "i");
  input.replace("ï", "i");
  input.replace("ó", "o");
  input.replace("ò", "o");
  input.replace("ô", "o");
  input.replace("õ", "o");
  input.replace("ö", "o");
  input.replace("ú", "u");
  input.replace("ù", "u");
  input.replace("û", "u");
  input.replace("ü", "u");
  input.replace("ç", "c");
  input.replace("\"", "");
  // Acrescente outras substituições conforme necessário

  return input;
}

void loop() {
  // Verifica se o botão A foi pressionado
  M5.update();

  if (M5.BtnA.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print("Embaralhando...");
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(host);
      http.addHeader("Content-Type", "application/json");
      http.addHeader("Authorization", bearerToken);

      String requestBody = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"O objetivo do jogo é ser eleito o 'Amigo de Merda'. Para isso, os jogadores devem responder perguntas sobre si mesmos e sobre os outros jogadores. A pergunta é feita por um jogador que puxa uma carta do baralho. Todos os outros jogadores então apontam para quem eles acham que melhor atende à descrição da pergunta. O jogador que receber mais votos ganha a rodada. As perguntas do jogo são variadas e podem ser bastante picantes ou constrangedoras. Por exemplo, algumas das perguntas incluem: Quem é o mais provável de perder o celular na festa? Quem é o mais provável de roubar a comida do outro? Um de nós não se importa com os pobres. Quem? Quem será o último de nós a transar novamente? O jogo é uma ótima maneira de se divertir com os amigos e aprender mais sobre eles. No entanto, é importante jogar com espírito esportivo e não se levar muito a sério. Gere uma frase similar às das cartas desse jogo.\"}], \"temperature\": 0.8 , \"max_tokens\": 50}";
      int httpResponseCode = http.POST(requestBody);

      if (httpResponseCode > 0) {
        String response = http.getString();
        StaticJsonDocument<1024> doc;
        deserializeJson(doc, response);

        const char* messageContent = doc["choices"][0]["message"]["content"]; // Ajustado para acessar o ponto correto
        String message = String(messageContent);
        String messageWithoutAccents = removeAcentos(message);

        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setCursor(0, 0);
        M5.Lcd.println(messageWithoutAccents);
      } else {
        M5.Lcd.println("HTTP Error");
      }

      http.end();
    } else {
      M5.Lcd.println("WiFi Disconnected");
    }
  }

  delay(100); // Pequeno delay para limitar as verificações e proporcionar debounce
}