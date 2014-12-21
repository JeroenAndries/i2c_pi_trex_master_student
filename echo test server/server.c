/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
//includes om de nodige functies te kunnen gebruiken
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>


void error(char *msg)
{   //weergeven van de laatste error in stderr 
    perror(msg);
    //uit het programma stappen met foutmelding 1
    exit(1);
}


int main(int argc, char *argv[])
{	//default buffer grote declareren en initialiseren
     const int bufferSize = 2048;
     //declaratie integer variabelen
     int sockfd, newsockfd, portno, clilen;
     // declaratie char buffer, nodig om de ontvangen tekst in te plaatsen
     char buffer[bufferSize];
     //struct declaratie
     struct sockaddr_in serv_addr, cli_addr;
     //variabele om te rekenen
     int n;
     // als de argumenten lijst kleiner is dan 2
     // is er geen poort meegegeven ==> error message ==> server niet starten
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     //openen van de socket
     //socket(IPV4,2weg communicatie,geen specifiek protocol)
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     //controle indien de socket geopend is
     if (sockfd < 0) 
        error("ERROR opening socket");
    //de arrau vullen met nullen
     bzero((char *) &serv_addr, sizeof(serv_addr));
     //string converten naar integer(poort nummer)
     portno = atoi(argv[1]);
     //IPV4 communicatie is gebruikt
     serv_addr.sin_family = AF_INET;
     //iedereen mag de server benaderen
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     //poortnummer toevoegen
     serv_addr.sin_port = htons(portno);
     //controle indien de server gestart kan worden
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
    //lus die de communicatie behandeld
     while(true){
        //Luisteren op de socket
	     listen(sockfd,5);
         // de groote van cli_addr struct bepalen
	     clilen = sizeof(cli_addr);
         // nieuwe socket openen die zal communiceren.
	     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
         //indien dit mislukt een fout geven en de buffer vullen met nullen
	     if (newsockfd < 0) 
		  error("ERROR on accept");
	     bzero(buffer,bufferSize);
         //lezen van de socket en de data in de buffer plaatsen
	    n = read(newsockfd,buffer,bufferSize);
        //indien n = 0 dan is de client niet meer verbonven 
        if(n==0){
            printf("client disconnected");
            continue;
        }
	     //zolang er geen einde is moet er blijven gelezen worden
	     while(strstr(buffer,"\n") == NULL) {
            //de gelezen data toevoegen aan de buffer, en de size van de buffer verlagen met het aantal gelezen karakters
               n = n + read(newsockfd,buffer+n,bufferSize-n);
	     }
         //een null toevoegen aan de buffer om zeker een string te kunne make
	     buffer[n+1]= 0 ;
         // als n kleiner is dan 0 dan is er een niets gelezen van de socket
	     if (n < 0) error("ERROR reading from socket");
         //de ontangen tekst weergeven
	     printf("Received message: %s\n",buffer);
	    //als er een specifieke tekst in het buffer zit dan antwoorden met een voorgedeffinieerde tekst.
        //dit is een testmechanisme voor de site.	  	
	     if (strstr(buffer,"{\"device_path\": \"/dev/i2c-1\", \"i2c_address\": 7}") != NULL)
	     { // weergeven dat de tekst gevonden is geweest.
	     	printf("string detected\n");
	     	// de voor gedeffinieerde tekst in he buffer plaatsten.
	     	strcpy(buffer, "{\"device_path\": \"/dev/i2c-1\", \"i2c_address\": 7, \"errors\": {\"start_byte\": false, \"pwm_frequency\": false, \"motor_speed\": false, \"servo_position\": false, \"impact_sensitivity\": false, \"low_battery\": false, \"i2c_address\": false, \"i2c_speed\": false}, \"battery_voltage\": 7.52, \"motor_current\": {\"left\": 2.15, \"right\": 5.71}, \"encoder_count\": {\"left\": 125, \"right\": 800}, \"accelero_meter\": [0, 125, 88], \"impact\": [0, 125, 88]}");
	     }
         // de lengte ven het buffer bepalen.
	     n = strlen(buffer);
         //verzenden van de data in het buffer
 	     n = write(newsockfd,buffer,n);
         //indien n<0 dan is het niet gelukt om te zenden naar de socket	     
	     if (n < 0) error("ERROR writing to socket");
         //alle printf's zeker uitevoeren
	     fflush(stdout);
	     //return 0; 
     }
}
