/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>

void error(char *msg)
{
    perror(msg);
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
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     //controle indien de socket geopend is
     if (sockfd < 0) 
        error("ERROR opening socket");
    //de arrau vullen met nullen
     bzero((char *) &serv_addr, sizeof(serv_addr));
     //string converten naar integer(poort nummer)
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     while(true){
	     listen(sockfd,5);
	     clilen = sizeof(cli_addr);
	     newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	     if (newsockfd < 0) 
		  error("ERROR on accept");
	     bzero(buffer,bufferSize);
	    n = read(newsockfd,buffer,bufferSize);
        if(n==0){
            printf("client disconnected");
            continue;
        }
	     
	     while(strstr(buffer,"\n") == NULL) {
               n = n + read(newsockfd,buffer+n,bufferSize-n);
	     }

	     buffer[n+1]= 0 ;
	     if (n < 0) error("ERROR reading from socket");
	     printf("Received message: %s\n",buffer);
	     
	     //printf("sizeX: %d\n",x);
	    
	  	
	     if (strstr(buffer,"{\"device_path\": \"/dev/i2c-1\", \"i2c_address\": 7}") != NULL)
	     {
	     	printf("string detected\n");
	     	
	     	strcpy(buffer, "{\"device_path\": \"/dev/i2c-1\", \"i2c_address\": 7, \"errors\": {\"start_byte\": false, \"pwm_frequency\": false, \"motor_speed\": false, \"servo_position\": false, \"impact_sensitivity\": false, \"low_battery\": false, \"i2c_address\": false, \"i2c_speed\": false}, \"battery_voltage\": 7.52, \"motor_current\": {\"left\": 2.15, \"right\": 5.71}, \"encoder_count\": {\"left\": 125, \"right\": 800}, \"accelero_meter\": [0, 125, 88], \"impact\": [0, 125, 88]}");
	     }
	     n = strlen(buffer);

	     
 	     n = write(newsockfd,buffer,n);


 	     
	     if (n < 0) error("ERROR writing to socket");
	     printf("einde programma\n");
	     fflush(stdout);
	     //return 0; 
     }
}
