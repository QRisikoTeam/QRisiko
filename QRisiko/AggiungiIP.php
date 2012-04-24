<?php 
 function VisitorIP()
    { 
    if(isset($_SERVER['HTTP_X_FORWARDED_FOR']))
        $TheIp=$_SERVER['HTTP_X_FORWARDED_FOR'];
    else $TheIp=$_SERVER['REMOTE_ADDR'];
 
    return trim($TheIp);
    }

function TrovaIP($ThisIPad){
	$ElencoServers = "ElencoServers.txt";
	$fh = fopen($ElencoServers, 'r') or die("Can't open file");
	$AllIPs =fread($fh, filesize($ElencoServers));
	$IPList= explode("\n",$AllIPs);
	$NumIP=count($IPList);
	$Trovato=False;
	for ($con=0;$con<$NumIP && !$Trovato; $con++){
		if($IPList[$con]==$ThisIPad) {
			$Trovato=True;
		}
	}
	fclose($fh);
	return $Trovato;
}

$ElencoServer = "ElencoServers.txt";
$ThisIP=VisitorIP();
$ListaIPs=explode(", ",$ThisIP);
for ($con1=0;$con1<count($ListaIPs);$con1++){
	if(!TrovaIP($ListaIPs[$con1])){
		$PrimaRiga=file_get_contents($ElencoServer)=='';
		$fh = fopen($ElencoServer, 'a') or die("Can't open file");
		if (!$PrimaRiga) {fwrite($fh,"\n");}
		fwrite($fh, $ListaIPs[$con1]);
		fclose($fh);
	}
}
print $ThisIP;
?>