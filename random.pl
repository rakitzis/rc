#! /usr/bin/perl

$count = 10;
$size = rand(1000);

for ($i = 0; $i < $count; ++$i) {
    open OUT, "> t$i" or die;
    for ($j = 0; $j < $size; ++$j) {
	printf OUT "%c", rand(256);
    }
    close OUT;
    $cmd = "./rc t$i";
    print $cmd, "\n";
    system $cmd;
}
