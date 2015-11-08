#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H_

#include <string.h>
#include <stdlib.h>
#include <WString.h>
#include <WiFi.h>
#include "Arduino.h"

class WebSocketClient {
	public:
		typedef void (*DataArrivedDelegate)(WebSocketClient client, String data);
		bool connect(char hostname[], char path[] = "/", int port = 80);
        bool connected();
        void disconnect();
		void monitor();
		void setDataArrivedDelegate(DataArrivedDelegate dataArrivedDelegate);
		void send(String data);
	private:
        String getStringTableItem(int index);
        void sendHandshake(char hostname[], char path[]);
        WiFiClient _client;
        DataArrivedDelegate _dataArrivedDelegate;
        bool readHandshake();
        String readLine();
};


#endif
