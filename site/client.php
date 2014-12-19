
<?php 
function post_var($variable,$type="default"){
	if($type=="default"){
		$result ="";
	}elseif ($type=="bool") {
		$result = false;
	}
	
	if (isset($_POST[$variable])) {
		$result = $_POST[$variable];
	}
	return $result;
}

require_once("libs/socket.php");

error_reporting(E_ALL);   
ini_set('display_errors', 1);

$write = post_var("write");
$read = post_var("read");

$client = new Client();
$client->connect();
if (!empty($write)){
	echo "Writing";
	$client->writeJSON($write);
	$return = $client->read();
	if($json != $return){
		echo "Error clould not update the TRex settings!";
	}
} elseif (!empty($read)) {
	$client->writeJSON(["device_path" => "/dev/i2c-1", "i2c_address" => 7]);
	echo $client->read();
}
$client->close();


