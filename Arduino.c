#include <Arduino.h>

String body_info;

float potVertSuperior;
float potVertInferior;
int taxaVarredura;
int numCiclos;

void setup() {
  Serial.begin(9600);
}

void receive_from_python() { 
	int i, qtd = 0, k = 0;
	char vet[4][6]; //Informa o numero de paramentros que viram no body_info

	//Separa da string completa as informações por ";" 
	for (i = 0; i < body_info.length(); i++){
		if ( body_info[i] != ';'){
			vet[qtd][k] = body_info[i];
			k++;
		}
		else if ( body_info[i] == ';') {
			qtd++;
			k = 0;
		}	
	}

	//Recupera cada info enviada atribuindo as variáveis ja declaradas
	for(i = 0; i < (qtd+1); i++){
		potVertSuperior = atof(vet[0]);
		potVertInferior = atof(vet[1]);
		taxaVarredura = atoi(vet[2]);
		numCiclos = atoi(vet[3]);
	}    
		
}

void loop() {
	
	while(Serial.available()){
		body_info = Serial.readString();
		Serial.println(body_info);

		receive_from_python();
		Serial.print("potVertSuperior: ");
		Serial.println(potVertSuperior);
		Serial.print("potVertInferior: ");
		Serial.println(potVertInferior);
		Serial.print("taxaVarredura: ");
		Serial.println(taxaVarredura);
		Serial.print("numCiclos: ");
		Serial.println(numCiclos);

		Serial.println("\n");
	}
}
