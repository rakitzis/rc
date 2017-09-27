#! /usr/bin/env bash

Error () { echo 1>&2 "$@"; }
Fatal () { Error "$@"; exit 1; }

###################################################################################################################
case $# in 
(1) : ;;
(*) Fatal Usage: $0 '<POSITIVE_NUMBER>' ;;
esac

if ! let "N=$1"; then
    Fatal Usage: $0 '<POSITIVE_NUMBER>'
fi
if let "$N <= 0"; then
    Fatal Usage: $0 '<POSITIVE_NUMBER>'
fi

###################################################################################################################
str='aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'

i=0
pat=''

###################################################################################################################
while let "$i < $N"
do
    pat=$pat'a*'
    let "i = $i+1"
done
pat=$pat'b'

###################################################################################################################
cmd='case '$str' in ('$pat') echo case-yes;; (*) echo case-no;; esac'
#echo $cmd; echo
eval $cmd

