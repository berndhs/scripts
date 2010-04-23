<?php

for ($a=1;$a<$argc;$a++) {
        $fn = $argv[$a];
	echo "\tmtime " . date("r",filemtime($fn)) . " \t" . $fn . "\r\n";
}

?>
