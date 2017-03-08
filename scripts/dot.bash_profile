# .bash_profile


# Get the aliases and functions
if [ -f /etc/bash_profile ]; then
	. /etc/bash_profile
fi

#ssh keys for github et al
ssh-add ~/.ssh/id_rsa

# User specific environment and startup programs

# PATH=$PATH:$HOME/bin:$HOME/.local/bin:$HOME/bin
LD_LIBRARY_PATH="/usr/local/lib64;/usr/local/lib;/usr/lib64;/usr/lib;/opt/lib64;/opt/lib"

export PATH
unset QTDIR
export QTDIR
unset QTLIB
export QTLIB
unset QTINC
export QTINC
