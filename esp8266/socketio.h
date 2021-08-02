#ifndef __SOCKETIO_H__
#define __SOCKETIO_H__

#include <Arduino.h>
#include <ArduinoJson.h>

#include <WebSocketsClient.h>
#include <SocketIOclient.h>

void init_socket();
void connection_socket();
void send_socket(String info);
void socketIOEvent(socketIOmessageType_t type, uint8_t * payload, size_t length);
#endif
