#!/usr/bin/perl -w

use strict;

while (<>) {
	if (/^\s+(.+。\n)/) {
		print $1;
		next;
	}

	if (/。\n/) {
		printf;
		next;
	}

	if (/楼主.+时间/) {
		printf;
		next;
	}

	if (/^\s+(\S.+)/) {
		printf $1;
		next;
	}

	if (/\n/) {
		chomp;
		printf;
		next;
	}

	printf;
}
