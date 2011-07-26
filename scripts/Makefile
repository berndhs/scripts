
DESTDIR=${HOME}/bin

SCRIPTS =  \
	pushgit \
	clearssh \
	list-zypp-packs \
	addgpl.sh         \
	colors.sh	\
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
        repack.sh \
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
	addresses \
	add-links \
	syncmail \
	pushmail \
        pullmail \
	pushnotes \
        pullnotes \
	change-background \


all:
	@echo "to install scripts, do make install DESTDIR=/where/you/want/it"
	@echo "           default: ${DESTDIR}"
	@echo "to install bashrc, do make installbash"

install:
	install -m 0755 -p ${SCRIPTS} ${DESTDIR}

installbash:
	if [ -e bashrc ] ; then cp bashrc ${HOME}/.bashrc ; fi


