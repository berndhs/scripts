<?php      
$pdo = new PDO('mysql:host=localhost;dbname=satview','berndsat','');

$filename = $argv[1];
$blobbytes = fopen($filename,'rb');
$picname = basename($filename);

$insert = "INSERT INTO `satpics` ( ident, picname, remark, image ) VALUES (:ident,:picname,:remark,:image) ";
$t_str = sprintf("%d",time(0));
$ident = $t_str;
printf("ident is %s\n",$ident);
$remark = "from php";
$stmt = $pdo->prepare($insert);
$stmt->bindParam(':ident',$ident);
$stmt->bindParam(':picname',$picname);
printf ("picname %s\n",$picname);
$stmt->bindParam(':remark',$remark);
$stmt->bindParam(':image',$blobbytes, PDO::PARAM_LOB);

$rslt = $stmt->execute();

printf ("%d rows inserted.\n",$rslt);

?>
