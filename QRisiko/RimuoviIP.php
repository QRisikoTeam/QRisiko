<?php 
$fileName = "myfile.txt";

 function VisitorIP()
    { 
    if(isset($_SERVER['HTTP_X_FORWARDED_FOR']))
        $TheIp=$_SERVER['HTTP_X_FORWARDED_FOR'];
    else $TheIp=$_SERVER['REMOTE_ADDR'];
 
    return trim($TheIp);
    }

function GetLineNum(){

	$ThisIP=VisitorIP();
	$ElencoServers = "ElencoServers.txt";
	$fh = fopen($ElencoServers, 'r') or die("Can't open file");
	$AllIPs =fread($fh, filesize($ElencoServers));
	$IPList= explode("\n",$AllIPs);
	$NumIP=count($IPList);
	$Trovato=-1;
	for ($con=0;$con<$NumIP && $Trovato<0; $con++){
		if($IPList[$con]==$ThisIP) {
			$Trovato=$con;
		}
	}
	fclose($fh);
	return ($Trovato+1);
}


function delLineFromFile($fileName, $lineNum){
// check the file exists 
  if(!is_writable($fileName))
    {
    // exit the function
    exit;
    }
  else
      {
    // read the file into an array    
    $arr = file($fileName);
    }

  // the line to delete is the line number minus 1, because arrays begin at zero
  $lineToDelete = $lineNum-1;
 
  // check if the line to delete is greater than the length of the file
  if($lineToDelete > sizeof($arr))
    {
    // exit the function
    exit;
    }

  //remove the line
  unset($arr["$lineToDelete"]);

  // open the file for writing
  if (!$fp = fopen($fileName, 'w+'))
    {
      // exit the function
        exit;
        }
  
  // if $fp is valid
  if($fp)
    {
        // write the array to the file
        foreach($arr as $line) { if(!($line=="\n")) {fwrite($fp,$line);} }

        // close the file
        fclose($fp);
        }
}

$LineToDelete=GetLineNum();
if(!($LineToDelete<0))
delLineFromFile("ElencoServers.txt",$LineToDelete);
print VisitorIP();
?>