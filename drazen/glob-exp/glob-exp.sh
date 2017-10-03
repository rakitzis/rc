#! /usr/bin/env bash

Script=$0
Error () { echo 1>&2 "$@"; }
Fatal () { Error "$@"; exit 1; }
Usage () { Fatal Usage: $Script '[-if|-switch|-file|-echo]' '<POSITIVE_NUMBER>'; }

DO_CASE=false
DO_FILE=false
ECHO_CMD=false
###########################################################################
while let "$# > 0"
do
    case x$1 in
    (x-case)   DO_CASE=true ;;
    (x-file)   DO_FILE=true ;;
    (x-echo)   ECHO_CMD=true ;;
    (*)        break ;;
    esac
    shift
done

###########################################################################
let "$# == 1" || Fatal Usage: $0 '<POSITIVE_NUMBER>' 
let "N=$1"    || Fatal Usage: $0 '<POSITIVE_NUMBER>'
let "$N <= 0" && Fatal Usage: $0 '<POSITIVE_NUMBER>'

###########################################################################
str='aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'

i=0
pat=''
###########################################################################
while let "$i < $N"; do
    pat=$pat'a*'
    let "i = $i+1"
done
pat=$pat'b'

echo 'shell=sh, N='$N

###########################################################################
###########################################################################
if $DO_CASE; then
    cmd='case '$str' in ('$pat') echo case-yes;; (*) echo case-no;; esac'
    if $ECHO_CMD; then
        echo $cmd; echo
    fi
    eval $cmd
fi

#--------------------------------------------------------------------------
if $DO_FILE; then
    test -f $str || touch $str
    s="ls $pat"
    time bash -c "$s"
fi

#--------------------------------------------------------------------------

