#!/bin/sh
cd ~/daily
mail -s "Cron Log"  bernd@pirx < cronlog.log
if [ $? -eq 0 ] 
then
  echo "new log started" > cronlog.log
  date --utc >> cronlog.log
fi
