#include <Arduino.h>

//Adicionando a biblioteca Firebase Arduino Client Library for ESP8266 and ESP32@
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Variáveis do Wi-fi
#define WIFI_SSID "FOO"
#define WIFI_PASSWORD "BAR"

//Variáveis do Firebase
#define API_KEY "AIzaSyCY1eu3N-FG55IdcOSf8mCpwyEtQjEhHP8"
#define DATABASE_URL "https://fir-esp32-8dc9a-default-rtdb.firebaseio.com/"

//Variáveis globais que servem para manipular o Firebase
FirebaseData fbdo; //Define Firebase Data object
FirebaseAuth auth; //Define Firebase Auth object
FirebaseConfig config; //Define Firebase Config object

//led da placa
#define LED_AZUL 2

//Configuração do Wi-fi
void wifiSetup(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando ao Wi-fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
}

//Configuração do Firebase
void firebaseSetup(){
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = "teste@teste.com";
  auth.user.password = "Teste123";

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true); //tenta se reconectar sempre que o wi-fi cair
}

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Configurando a rede Wi-fi e o Firebase");
  wifiSetup();
  firebaseSetup();

  pinMode(LED_AZUL,OUTPUT); //aqui é de fato onde eu sinalizo que quero utilizar o LED
}

int count_times = 1;
int device_status = 1;
int firebase_connect_count = 0;
int areaServico_lamp_status = 0;
int banheiro_lamp_status = 0;
int banheiro02_lamp_status = 0;
int closet_lamp_status = 0;
int cozinha_lamp_status = 0;
int deck_lamp_status = 0;
int garagem_lamp_status = 0;
int piscina_lamp_status = 0;
int quarto01_lamp_status = 0;
int quarto01_ar_status = 0;
int quarto02_lamp_status = 0;
int quarto02_ar_status = 0;
int salaEstar_lamp_status = 0;
int salaEstar_ar_status = 0;
int salaJantar_lamp_status = 0;
int suite_lamp_status = 0;
int suite_ar_status = 0;
int varanda_lamp_status = 0;

void loop() {
  delay(2000);

  if (Firebase.ready()){
    if(firebase_connect_count == 0) {
      Serial.println("Você está autenticado ao banco de dados Firebase!");
      firebase_connect_count = 1;
    }
  
    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/area-servico/lampada"))) {
      if(fbdo.to<int>() != areaServico_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da área de serviço está desligada");
          digitalWrite(LED_AZUL,LOW);
          areaServico_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da área de serviço está ligada");
          digitalWrite(LED_AZUL,HIGH);
          areaServico_lamp_status = 1; 
        }
      }
    } 
    
    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/banheiro/lampada"))) {
      if(fbdo.to<int>() != banheiro_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do banheiro está desligada");
          banheiro_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do banheiro está ligada");
          banheiro_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/banheiro02/lampada"))) {
      if(fbdo.to<int>() != banheiro02_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do banheiro 02 foi desligada");
          banheiro02_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do banheiro 02 foi ligada");
          banheiro02_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/closet/lampada"))) {
      if(fbdo.to<int>() != closet_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do closet foi desligada");
          closet_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do closet foi ligada");
          closet_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/cozinha/lampada"))) {
      if(fbdo.to<int>() != cozinha_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da cozinha foi desligada");
          cozinha_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da cozinha foi ligada");
          cozinha_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/deck/lampada"))) {
      if(fbdo.to<int>() != deck_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do deck foi desligada");
          deck_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do deck foi ligada");
          deck_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/garagem/lampada"))) {
      if(fbdo.to<int>() != garagem_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da garagem foi desligada");
          garagem_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da garagem foi ligada");
          garagem_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/piscina/lampada"))) {
      if(fbdo.to<int>() != piscina_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da piscina foi desligada");
          piscina_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da piscina foi ligada");
          piscina_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/quarto01/lampada"))) {
      if(fbdo.to<int>() != quarto01_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do quarto 01 foi desligada");
          quarto01_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do quarto 01 foi ligada");
          quarto01_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/quarto01/ar-condicionado"))) {
      if(fbdo.to<int>() != quarto01_ar_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("O ar-condicionado do quarto 01 foi desligado");
          quarto01_ar_status = 0;
        } else {
          Serial.println("O ar-condicionado do quarto 01 foi ligado");
          quarto01_ar_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/quarto02/lampada"))) {
      if(fbdo.to<int>() != quarto02_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada do quarto 02 foi desligada");
          quarto02_lamp_status = 0;
        } else {
          Serial.println("A lâmpada do quarto 02 foi ligada");
          quarto02_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/quarto02/ar-condicionado"))) {
      if(fbdo.to<int>() != quarto02_ar_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("O ar-condicionado do quarto 02 foi desligado");
          quarto02_ar_status = 0;
        } else {
          Serial.println("O ar-condicionado do quarto 02 foi ligado");
          quarto02_ar_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/sala-estar/lampada"))) {
      if(fbdo.to<int>() != salaEstar_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da sala de estar foi desligada");
          salaEstar_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da sala de estar foi ligada");
          salaEstar_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/sala-estar/ar-condicionado"))) {
      if(fbdo.to<int>() != salaEstar_ar_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("O ar-condicionado da sala de estar 02 foi desligado");
          salaEstar_ar_status = 0;
        } else {
          Serial.println("O ar-condicionado da sala de estar 02 foi ligado");
          salaEstar_ar_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/sala-jantar/lampada"))) {
      if(fbdo.to<int>() != salaJantar_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da sala de jantar foi desligada");
          salaJantar_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da sala de jantar foi ligada");
          salaJantar_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/suite/lampada"))) {
      if(fbdo.to<int>() != suite_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da suite foi desligada");
          suite_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da suite foi ligada");
          suite_lamp_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/suite/ar-condicionado"))) {
      if(fbdo.to<int>() != suite_ar_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("O ar-condicionado da suite foi desligado");
          suite_ar_status = 0;
        } else {
          Serial.println("O ar-condicionado da suite foi ligado");
          suite_ar_status = 1;
        }
      }
    }

    if(Firebase.RTDB.getInt(&fbdo, F("/casa04/varanda/lampada"))) {
      if(fbdo.to<int>() != varanda_lamp_status) {
        if(fbdo.to<int>() == 0) {
          Serial.println("A lâmpada da varanda foi desligada");
          varanda_lamp_status = 0;
        } else {
          Serial.println("A lâmpada da varanda foi ligada");
          varanda_lamp_status = 1;
        }
      }
    }
  }
}