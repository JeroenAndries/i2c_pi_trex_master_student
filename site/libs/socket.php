<?php 

class Client
{
	private $socket;
	private $host = "10.180.35.115";
	private $port = "9999";
	
	public function __construct(){
		// Create a client socket
		$this->socket = socket_create(AF_INET, SOCK_STREAM, 0);
		
	}

	public function connect(){
		// Connects to socket server
		socket_connect($this->socket, $this->host, $this->port);
		
	}

	public function close(){
		// close the connection
		socket_close($this->socket);
	}

	public function writeJSON($array){
		// Change array to string
		$string = json_encode($array);
		// Write string to socket
		socket_write($this->socket, $string."\n");
	}

	public function read()
	{
		// Reads the socket until newline character
		$buffer = socket_read($this->socket, 1024, PHP_NORMAL_READ);
		// Change the json string to an array 
		$array = json_decode($buffer);
		return $array;
	}
}