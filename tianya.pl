#!/usr/bin/perl -w 

use strict;

my $find_bbs_content = 0;
my $find_alt_content = 0;
my $lou_zhu_say = 0;
while (<>) {
	if (/div class="atl-content"/) {
		$find_alt_content = 1;
		next;
	}

	if (/host-ico.+楼主/) {
		$lou_zhu_say = 1;
	}

	my $line = $_;
	if (/div class="bbs-content"/) {
		$find_bbs_content = 1;
		$find_alt_content = 0;
		next;
	}

	if ($find_bbs_content == 1) {
		if (/\/div/) {
			$find_bbs_content = 0;
			next;
		}
		
		if ($lou_zhu_say == 0) {
			next;
		}

		$line =~ s/<br>//g;
		printf ($line);
		$lou_zhu_say = 0;
	}
}
