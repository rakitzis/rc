#! /usr/bin/env bash

Script=$0
Error () { echo 1>&2 "$@"; }
Fatal () { Error "$@"; exit 1; }
Usage () { Fatal Usage: $Script '[--case|--file|--all|--echo]' '<POSITIVE_NUMBER>'; }

DO_CASE=false
DO_FILE=false
ECHO_CMD=false
###########################################################################
while let "$# > 0"
do
    case x$1 in
    (x-case|x--case|x-switch|x--switch) DO_CASE=true ;;
    (x-file|x--file|x-ls|x--ls)         DO_FILE=true ;;
    (x-all|x--all)                      DO_CASE=true; DO_FILE=true ;;
    (x-echo|x--echo)                    ECHO_CMD=true ;;
    (*)                                 break ;;
    esac
    shift
done

###########################################################################
let "$# == 1" || Usage
let "N=$1"    || Usage
let "$N <= 0" && Usage

###########################################################################
str=""
i=0
while let "$i < 100"; do
    str="${str}a"
    let "i = $i+1"
done

###########################################################################
pat=''

i=0
while let "$i < $N"; do
    pat=$pat'a*'
    let "i = $i+1"
done
pat=$pat'b'
###########################################################################

echo 'shell=sh, N='$N; echo


EvalCmd () { 
    typeset cmd="$@"
    if $ECHO_CMD; then
        echo "Cmd: $cmd"
        echo -n 'Result: '
    fi
    eval "$cmd"
}

###########################################################################
###########################################################################
nl="
"
if $DO_CASE; then
    patWithStr="pattern${nl}    ${pat}${nl}with string${nl}    ${str}"
    Matches="sh: 'case' matches ${patWithStr}"
    NotMatches="sh: 'case' does not match ${patWithStr}"
    cmd="case ${str} in (${pat}) true ;; (*) false;; esac"
    if EvalCmd $cmd; then
        echo "$Matches"
    else
        echo "$NotMatches"
    fi
fi

#--------------------------------------------------------------------------
if $DO_FILE; then
    echo
    test -f $str || touch $str
    cmd="ls $pat"

    EvalCmd "$cmd"

    rm -f $str
fi

#--------------------------------------------------------------------------

