#!/usr/bin/make


DESTDIR=${HOME}/bin

SCRIPTS =  `find . -executable -type f`

ALLSCRIPTS = initqt57 ${SCRIPTS}


all:
	@echo "to install scripts, do make install DESTDIR=/where/you/want/it"
	@echo "           default: ${DESTDIR}"
	@echo "to install bashrc, do make installbash"

list:
	echo "Scripts to install are:"
	echo ${ALLSCRIPTS}

install:
	install -d ${DESTDIR}
	install -m 0755 -p ${ALLSCRIPTS} ${DESTDIR}
	make installprofile

installbash:
	if [ ! -w /root ] ; then 
	  echo "sorry need to write to /root for this"
	  exit 1
	fi
	if [ -e bashrc ] ; then cp bashrc ${HOME}/.bashrc ; fi
	if [ -e root.bashrc ] ; then cp root.bashrc /root/.bashrc ; fi

installprofile:
	if [ -e dot.bash_profile ] ; then cp dot.bash_profile ${HOME}/.bash_profile ; fi



