#!/bin/bash

do_update () {
  REPO=$1
  echo "---> creating repodata for $REPO"
  createrepo $REPO
  echo "---> fixing permissions"
  chmod a+rx $REPO/repodata
  chmod a+r $REPO/repodata/*
}

if [ $# -lt 1 ]; then
  do_update /var/www/html/sites/bernd2009/Repos/Geuzen/MeeGo/current
  do_update /var/www/html/sites/bernd2009/Repos/Geuzen/Fedora/current
else
  DISTRO=$1
  do_update  /var/www/html/sites/bernd2009/Repos/Geuzen/$DISTRO/current
fi

echo "---> all done"

