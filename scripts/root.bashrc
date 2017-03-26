# .bashrc

# User specific aliases and functions

alias rm='rm -i'
alias cp='cp -i'
alias mv='mv -i'

alias zz='source ~/.bashrc'
alias mroe='more'
alias h=history

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

contains() {
    string="$1"
    substring="$2"
    if test "${string#*$substring}" != "$string"
    then
        return 0    # $substring is in $string
    else
        return 1    # $substring is not in $string
    fi
}

#root PS1
export PS1='\! \033[41m\u\033[0m@\h \D{%a %Y-%m-%d %R:%S} \W \$ '
