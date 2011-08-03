#!/bin/bash
REPO=/var/www/html/sites/bernd2009/Repos/Geuzen/MeeGo/current
echo "---> creating repodata"
createrepo $REPO
echo "---> fixing permissions"
chmod a+rx $REPO/repodata
chmod a+r $REPO/repodata/*
echo "---> all done"

