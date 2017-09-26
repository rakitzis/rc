str=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

N=$1
i=0
pat=''

while let "$i < $N"
do
    pat=$pat'a*'
    let "i = $i+1"
done
pat=$pat'b'

cmd='case '$str' in ('$pat') echo case-yes;; (*) echo case-no;; esac'
#echo $cmd; echo
eval $cmd

