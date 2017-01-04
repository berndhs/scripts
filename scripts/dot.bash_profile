# .bash_profile


# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

#ssh keys for github
ssh-add ~/.ssh/id_rsa
#see if we have ipv6 link, if not try to start aiccu
REAC=`which re-aiccu`
sudo $REAC

# User specific environment and startup programs

PATH=$PATH:$HOME/bin:$HOME/.local/bin:$HOME/bin
LD_LIBRARY_PATH="/usr/local/lib64;/usr/local/lib;/usr/lib64;/usr/lib;/opt/lib64;/opt/lib"

export PATH
unset QTDIR
export QTDIR
unset QTLIB
export QTLIB
unset QTINC
export QTINC
