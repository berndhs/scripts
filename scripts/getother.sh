#!/bin/sh

cd ~/data/moreweather

TIMESTAMP=`date +%s`
echo "ran at $TIMESTAMP" > LAST_RUN
CUREURO="euro_current.png"
CURCAN=CAN_${TIMESTAMP}.jpg
CANFILE=$CURCAN

wget http://www.weatheroffice.gc.ca/data/satellite/goes_enam_1070_100.jpg -O ${CURCAN}
if [ -e ${CURCAN} ] ; then
  echo ${CURCAN} >> LAST_RUN
fi

wget http://www.dwd.de/bvbw/generator/Sites/DWDWWW/Content/Oeffentlichkeit/WV/WVFK/English/Dynamisches/Regional/mete__IR__SW__aktuell__m00s,templateId=poster,property=poster.png -O ${CUREURO}

SMALLEURO="euro.jpg"
convert $CUREURO $SMALLEURO
EUROFILE=EURO_${TIMESTAMP}.jpg
echo $EUROFILE
mv ${SMALLEURO} $EUROFILE
if [ -e ${EUROFILE} ]; then
  echo ${EUROFILE} >> LAST_RUN
fi

DAILYDIR="/var/www/html/pictures/daily"  
cp ${CURCAN} ${DAILYDIR}/can.jpg
cp ${CUREURO} ${DAILYDIR}/euro.jpg
cp ${CURCAN} CAN.JPG
${HOME}/bin/storeinDB CAN.JPG
cp ${CUREURO} EURO.JPG
${HOME}/bin/storeinDB EURO.JPG
ls -l $CANFILE $EUROFILE
ls -l ${DAILYDIR}
