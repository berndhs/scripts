
TIMESTAMP=`date +%s`
CURCAN=CAN.jpg
CANFILE=$CURCAN

curl -o ${CURCAN} http://weather.gc.ca/data/satellite/goes_enam_1070_100.jpg
php ~/bin/storePCO.php ~/public_html/daily/${CURCAN}

