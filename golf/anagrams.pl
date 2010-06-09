#!/usr/bin/perl -w
#map {
#	chomp; tr/A-Z/a-z/; s/[^a-z]//;
#	$sorted_letters = join '', sort split //;
#	$str = $_;
#	$words{$sorted_letters} = $_ if !$words{$sorted_letters};
#	push @{$words{$sorted_letters}}, $_ if !$seen{$str};
#	$seen{$str}++;
#	}<>;
#
#for $w (sort {
#		$#{$words{$b}} <=> $#{$words{$a}} 
#	} keys grep @{$w{$_}}>1, %words) {
#
#	print "@{$words{$w}}\n";
#}
#map{chomp;tr/A-Z/a-z/;s/[^a-z]//;$s=join'',sort split //;$t=$_;$w{$s}=$t if!$w{$s};push@{$w{$s}},$t if!grep/$t/,@{$w{$s}}}<>;for(sort{@{$w{$b}}<=>@{$w{$a}}}grep@{$w{$_}}>1,keys%w){print "@{$w{$_}}\n"}
#map{chomp;tr/A-Z/a-z/;s/[^a-z]//;$s=join'',sort split //;$t=$_;$w{$s}=$t if!$w{$s};push@{$w{$s}},$t if!grep/$t/,@{$w{$s}}}<>;for(grep@{$w{$_}}>1,keys%w){print "@{$w{$_}}\n"}
#map{chomp;tr/A-Z/a-z/;$s=join'',sort split //;$t=$_;$w{$s}=$t if!$w{$s};push@{$w{$s}},$t if!$m{$t}++}<>;for(grep@{$w{$_}}>1,keys%w){print "@{$w{$_}}\n"}
#map{chomp;tr/A-Z/a-z/;$s=join'',sort split //;$t=$_;$w{$s}=$t if!$w{$s};push@{$w{$s}},$t if!$m{$t}++}<>;map{print"@{$w{$_}}\n"}grep@{$w{$_}}>1,keys%w
#map{chomp;$t=$_=lc;$s=join'',sort split //;$w{$s}=$t if!$w{$s};push@{$w{$s}},$t if!$m{$t}++}<>;map{print"@{$w{$_}}\n"}grep@{$w{$_}}>1,keys%w

chop,$_{join'',sort split//,lc}.="$_ "for<>;/ ./&&print for%_
