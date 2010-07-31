
DESTDIR=${HOME}/bin

SCRIPTS =  \
	addgpl.sh         \
	doxephyr         \
	float          \
	getir         \
	get_more_goes.sh \
	getother.sh    \
	gitadd.sh    \
	listrepos.sh\
	loopxephyr \
	maillogs.sh  \
	makearchive.sh  \
	mark_copyright \
	runcopydb.sh  \
	showir       \
	special.sh  \
	storeIR.php \
	time.php   \
	setq47 \
	setqsim \
	initqt47 \
	initqtsim \
	synserv \
	synmeego \
	connectgogo \


all:
	@echo "to install scripts, do make install DESTDIR=/where/you/want/it"
	@echo "           default: ${DESTDIR}"
	@echo "to install bashrc, do make installbash"

install:
	install -p ${SCRIPTS} ${DESTDIR}

installbash:
	if [ -e bashrc ] ; then cp bashrc ${HOME}/.bashrc ; fi


