<!-- Dit is een client voor de server.
deze code is van stephe d'hondt, Enkel voor te testen van de appalicatie-->
<?php 
//de waarden via een post variabele doorsturen
function post_var($variable,$type="default"){
	if($type=="default"){
		$result ="";
	}elseif ($type=="bool") {
		$result = false;
	}
	// indien er gegevens zijn, deze opslaan in result
	if (isset($_POST[$variable])) {
		$result = $_POST[$variable];
	}
	// returnen van result
	return $result;
}
//het bestand socket.php importeren, de eerste keer dat de pagina geladen wordt.
//hierin staat de client klasse
require_once("libs/socket.php");
// alle fouten weergeven
error_reporting(E_ALL);   
ini_set('display_errors', 1);
//2 variabelen voor communicatie
$write = post_var("write");
$read = post_var("read");
//aanmaken van een client
$client = new Client();
//connecteren met de server
$client->connect();
//als er een waarde in write zit mag men de data doorsturen?
if (!empty($write)){
	echo "Writing";
	$client->writeJSON($write);
	$return = $client->read();
	//indien er een fout is bij het updaten van de instellingen
	if($json != $return){
		echo "Error clould not update the TRex settings!";
	}
	//indien write leeg is en read niet leeg
} elseif (!empty($read)) {
	//deze vraag sturen naar de server/trex/mbed
	$client->writeJSON(["device_path" => "/dev/i2c-1", "i2c_address" => 7]);
	//weergeve wat er gelezen werdt van de server.
	echo $client->read();
}
$client->close();


