#include "wifi.h"
#include "socketio.h"
int vel = 0;
void setup() {
    Serial.begin(115200);
    delay(250);
    init_wifi();
    init_socket();
}

unsigned long previousmillis = 0; 
void loop() {
    connection_socket();
    unsigned long currentmillis = millis();

    if (currentmillis - previousmillis >= 1000) {
      previousmillis = currentmillis;
      String mensagem = "Sinal do sensor: ";
      mensagem.concat(vel++);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
      //send_socket(String(currentmillis));
      send_socket(mensagem);
    }
    
}
