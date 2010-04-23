#!/bin/sh

cd ~/data/moreweather

TIMESTAMP=`date +%s`
CURCAN="can_current.jpg"
CUREURO="euro_current.png"
wget http://www.weatheroffice.gc.ca/data/satellite/goes_nam_1070x_100.jpg -O ${CURCAN}
wget http://www.dwd.de/bvbw/generator/Sites/DWDWWW/Content/Oeffentlichkeit/WV/WVFK/English/Dynamisches/Regional/mete__IR__SW__aktuell__m00s,templateId=poster,property=poster.png -O foo.png -O ${CUREURO}

mv $CURCAN CAN_${TIMESTAMP}.jpg
mv $CUREURO EURO_${TIMESTAMP}.jpg

ls -ltr | tail -5
