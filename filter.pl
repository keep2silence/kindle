#!/usr/bin/perl -w
#
while (<>) {
	next if (/^\s*$/);
	next if (/举报/);
	next if (/作者/);
	next if (/mark/);
	exit if (/^References/);

	printf;
}

