#!/usr/bin/perl -w
#
my $permit = 0;
while (<>) {
	if ($permit == 1 || /楼主：.+时间：/) {
		$permit = 1;

		if (/举报.+回复/) {
			$permit = 0;
			next;
		}
		printf;
	}
}

