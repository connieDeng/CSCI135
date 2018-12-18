#!/usr/bin/env  perl
#treequery.pl
# 
# Usage                : treequery.pl nyctreedata.csv
#            
# Written by           : Connie Deng
# Created on           : December 13, 2018
#               
# Description          : user inputs tree name and program prints out info
#
#*******************************************************************************             

$^W = 1;     # turn on warnings
use strict;  # behave!

#*******************************************************************************
#                                 Main Program                                 *
#*******************************************************************************

my @fields;
my @recs;
my @lines;
my %tree;
my %gps_coordinates;
my @nyc_trees;


while ( <DATA> ) #read line by line
{
	chomp;
	@lines = <DATA>;
}

#print $#lines; is 12+1 = 13
for(my $x = 0; $x < $#lines+1; $x++)
{	#find ending
	my @treeInfo = split(',',$lines[$x]); #splitting each tree stuff

	my $id = $treeInfo[0];
	my $diameter = $treeInfo[1];
	my $condition = $treeInfo[2];
	my $name = $treeInfo[3];
	my $zipcode = $treeInfo[4];
	my $boroname = $treeInfo[5];
	my $neighborhood = $treeInfo[6];
	my $latitude = $treeInfo[7];
	my $longitude = $treeInfo[8];

	my %gps_coordinates = (
		latitude => $latitude,
		longitude => $longitude,
	);

	#my $coord_ref = \%gps_coordinates;

	my $tree = {
		tree_id => $id,
		tree_dbh => $diameter,
		health => $condition,
		pc_common => $name,
		zipcode => $zipcode,
		boroname => $boroname,
		nta_name => $neighborhood,
		gps_coordinates => {%gps_coordinates},
	};

	#my $hash_ref = \%tree;

	push(@nyc_trees, $tree);
}

#--------------------------------------------------------------------------------

my $input = "";

until($input eq "quit")
{
	
	my $ifMatchCount = 0; #count
	my $zipcodes; 
	my ($manhattan, $bronx, $brooklyn, $queens, $statenIsland, $diameter) = (0)x6;
	my $boroughMaxCount = 0;
	my $boroughMax;

	print "Enter the name of a type of tree, or enter \"quit\" to quit: ";
	my $input = <STDIN>;
	chomp $input;

	if($input eq "quit")
	{
		print "You have quit";
		exit;
	}


	for(my $x = 0; $x < $#lines+1; $x++)
	{
		if($input eq ${$nyc_trees[$x]}{pc_common})
		{
			$ifMatchCount++;
			$zipcodes .= "${$nyc_trees[$x]}{zipcode}" . ",";
			
			if(${$nyc_trees[$x]}{boroname} eq "Manhattan"){ $manhattan++; }
			elsif(${$nyc_trees[$x]}{boroname} eq "Bronx"){ $bronx++; }
			elsif(${$nyc_trees[$x]}{boroname} eq "Brooklyn"){ $brooklyn++; }
			elsif(${$nyc_trees[$x]}{boroname} eq "Queens"){ $queens++; }
			elsif(${$nyc_trees[$x]}{boroname} eq "Staten Island"){ $statenIsland++; }

			if($manhattan > $boroughMaxCount){ $boroughMaxCount = $manhattan; $boroughMax = "Manhattan"; }
			if($bronx > $boroughMaxCount){ $boroughMaxCount = $bronx; $boroughMax = "Bronx"; }
			if($brooklyn > $boroughMaxCount){ $boroughMaxCount = $brooklyn; $boroughMax = "Brooklyn"; }
			if($queens > $boroughMaxCount){ $boroughMaxCount = $queens; $boroughMax = "Queens"; }
			if($statenIsland > $boroughMaxCount){ $boroughMaxCount = $statenIsland; $boroughMax = "Staten Island"; }
			
			$diameter += ${$nyc_trees[$x]}{tree_dbh};
		}
	}

	until($ifMatchCount != 0)
	{
		print "Enter the name of a type of tree, or enter \"quit\" to quit: ";
		my $input = <STDIN>;
		chomp $input;

				
		if($input eq "quit")
		{
			print "You have quit";
			exit;
		}


		for(my $x = 0; $x < $#lines+1; $x++)
		{
			if($input eq ${$nyc_trees[$x]}{pc_common})
			{
				$ifMatchCount++;
				$zipcodes .= "${$nyc_trees[$x]}{zipcode}" . ",";
				
				if(${$nyc_trees[$x]}{boroname} eq "Manhattan"){ $manhattan++; }
				elsif(${$nyc_trees[$x]}{boroname} eq "Bronx"){ $bronx++; }
				elsif(${$nyc_trees[$x]}{boroname} eq "Brooklyn"){ $brooklyn++; }
				elsif(${$nyc_trees[$x]}{boroname} eq "Queens"){ $queens++; }
				elsif(${$nyc_trees[$x]}{boroname} eq "Staten Island"){ $statenIsland++; }

				if($manhattan > $boroughMaxCount){ $boroughMaxCount = $manhattan; $boroughMax = "Manhattan"; }
				if($bronx > $boroughMaxCount){ $boroughMaxCount = $bronx; $boroughMax = "Bronx"; }
				if($brooklyn > $boroughMaxCount){ $boroughMaxCount = $brooklyn; $boroughMax = "Brooklyn"; }
				if($queens > $boroughMaxCount){ $boroughMaxCount = $queens; $boroughMax = "Queens"; }
				if($statenIsland > $boroughMaxCount){ $boroughMaxCount = $statenIsland; $boroughMax = "Staten Island"; }
				
				$diameter += ${$nyc_trees[$x]}{tree_dbh};
			}
		}
	}

	if($ifMatchCount >= 1)
	{
		print "\n";
		print "total number of such trees: " . $ifMatchCount . "\n";
		print "zip codes in which this tree is found: " . substr($zipcodes, 0 , -1) . "\n";
		print "borough containing the largest number of such trees: " . $boroughMax . ", with " . $boroughMaxCount . "\n";
		print "average diameter: " . $diameter/$ifMatchCount . "\n";
		print "\n";
	}	
}

print "You have quit";
exit;

__DATA__
581553,4,Good,cherry,11434,Queens,St. Albans,40.68408642,-73.77201854
583275,4,Good,purple-leaf plum,11103,Queens,Astoria,40.76553688,-73.90696932
511007,4,Good,cherry,10467,Bronx,Williamsbridge-Olinville,40.8848441,-73.86146396
569027,4,Good,honeylocust,11420,Queens,South Ozone Park,40.67903189,-73.83057015
580636,4,Good,American linden,11368,Queens,North Corona,40.75143158,-73.86878943
537116,4,Good,scarlet oak,11203,Brooklyn,East Flatbush-Farragut,40.64326038,-73.94387206
561876,4,Good,cherry,11357,Queens,Whitestone,40.79470456,-73.80234284
584311,4,Good,cherry,10303,Staten Island,Mariner's Harbor-Arlington-Port Ivory-Graniteville,40.63015897,-74.15652676
571150,4,Fair,cherry,11385,Queens,Ridgewood,40.70566037,-73.90690157
560808,4,Good,cherry,11412,Queens,St. Albans,40.70454242,-73.75365891
558335,4,Good,cherry,11436,Queens,Baisley Park,40.66968196,-73.79450061
581082,4,Good,cherry,11434,Queens,Baisley Park,40.6831719,-73.77918746
579510,4,Fair,cherry,11434,Queens,Baisley Park,40.6879589,-73.78201691
576570,4,Good,cherry,10314,Staten Island,New Springville-Bloomfield-Travis,40.60993544,-74.16670559
