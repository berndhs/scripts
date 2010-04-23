<?php      
$con = mysql_connect("localhost","weather","quetzalcoatl");

$db = "weather";

$filename = $argv[1];

mysql_select_db($db);

$query_1 = "INSERT INTO `satpics` ( ident, picname, remark, image ) VALUES ( ";
$t_str = sprintf("%d",time(0));
$query_2 = $t_str;
$query_3 = $argv[1];
$query_4 = "from php";
$query_5 = mysql_real_escape_string(file_get_contents($filename));

mysql_query( $query_1 
       . $query_2 
       . " , '" 
       . mysql_real_escape_string($filename)
       . "' , '" 
       . $query_4 
       . "' , '"
       . $query_5 
       . "' )"
	     ) ;

mysql_close($con);

?>
