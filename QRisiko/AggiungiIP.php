<?php 
 function VisitorIP()
    { 
    if(isset($_SERVER['HTTP_X_FORWARDED_FOR']))
        $TheIp=$_SERVER['HTTP_X_FORWARDED_FOR'];
    else $TheIp=$_SERVER['REMOTE_ADDR'];
 
    return trim($TheIp);
    }

$ThisIP=VisitorIP();
$ElencoServers = "ElencoServers.txt";
$fh = fopen($ElencoServers, 'r') or die("Can't open file");
$AllIPs =fread($fh, filesize($ElencoServers));
$IPList= explode("\n",$AllIPs);
$NumIP=count($IPList);
$Trovato=False;
for ($con=0;$con<$NumIP && !$Trovato; $con++){
	if($IPList[$con]==$ThisIP) {
		$Trovato=True;
	}
}
fclose($fh);

if (!$Trovato){
$fh = fopen($ElencoServers, 'a') or die("Can't open file");
fwrite($fh, $ThisIP);
fwrite($fh, "\n");
fclose($fh);
}
print $ThisIP;
?>