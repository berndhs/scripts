#!/bin/bash -x

NOW=`date --utc`
cd ~/public_html/daily/

rm ECIR.JPG
curl -o ECIR.JPG  http://www.goes.noaa.gov/GIFS/ECIR.JPG 
echo $? >> ~/public_html/daily/done
ls -l ECIR*
pwd
#php ~/bin/storeIR.php ~/public_html/daily/ECIR.JPG
php ~/bin/storeSQLi.php ~/public_html/daily/ECIR.JPG
echo $? >> ~/public_html/daily/done
ls -l ECIR.J* >> ~/public_html/daily/done

rm WCIR.JPG
curl -o WCIR.JPG  http://www.goes.noaa.gov/GIFS/WCIR.JPG
echo $? >> ~/public_html/daily/done
ls -l WCIR*
pwd
#php ~/bin/storeIR.php ~/public_html/daily/WCIR.JPG
php ~/bin/storeSQLi.php ~/public_html/daily/WCIR.JPG
echo $? >> ~/public_html/daily/done
ls -l WCIR.J* >> ~/public_html/daily/done


CURCAN=CAN.jpg
tm ${CURCAN}
curl -o ${CURCAN} http://weather.gc.ca/data/satellite/goes_enam_1070_100.jpg
php ~/bin/storeSQLi.php ~/public_html/daily/${CURCAN}


date >> ~/public_html/daily/done
