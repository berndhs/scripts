#!/bin/bash
set -x
REPO=/var/www/html/sites/bernd2009/Repos/Geuzen/current
createrepo $REPO
chmod a+rx $REPO/repodata
chmod a+r $REPO/repodata/*

