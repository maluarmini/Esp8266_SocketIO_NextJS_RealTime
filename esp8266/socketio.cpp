#include "socketio.h"

SocketIOclient socket;

// inicializa o socket.io-client
void init_socket(){
  socket.begin("192.168.0.8",4000);
  socket.onEvent(socketIOEvent);
  //Usa essa funcao caso queira receber algo do servidor socket
//  socket.on("info", event);
  delay(500);
}

void connection_socket(){
  socket.loop();
}

// envia uma mensagem para o servidor via socket
void send_socket(String info){
        DynamicJsonDocument doc(1024);
        JsonArray array = doc.to<JsonArray>();

        // add evnet name
        // Hint: socket.on('event_name', ....
        array.add("newinfo");

        // add payload (parameters) for the event
        JsonObject param1 = array.createNestedObject();
        param1["now"] = info;

        // JSON to String (serializion)
        String output;
        serializeJson(doc, output);
        Serial.println(output);
        // Send event
        socket.sendEVENT(output);
}


void socketIOEvent(socketIOmessageType_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case sIOtype_DISCONNECT:
            Serial.printf("[IOc] Disconnected!\n");
            break;
        case sIOtype_CONNECT:
            Serial.printf("[IOc] Connected to url: %s\n", payload);

            // join default namespace (no auto join in Socket.IO V3)
            socket.send(sIOtype_CONNECT, "/");
            break;
        case sIOtype_EVENT:
            Serial.printf("[IOc] get event: %s\n", payload);
            break;
        case sIOtype_ACK:
            Serial.printf("[IOc] get ack: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_ERROR:
            Serial.printf("[IOc] get error: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_EVENT:
            Serial.printf("[IOc] get binary: %u\n", length);
            hexdump(payload, length);
            break;
        case sIOtype_BINARY_ACK:
            Serial.printf("[IOc] get binary ack: %u\n", length);
            hexdump(payload, length);
            break;
    }
}
