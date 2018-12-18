#!/usr/bin/env  perl
# make_array_of_recs.pl  -- shows how to build arrays of records
# 
# Usage                : make_array_of_recs.pl
#            
# Written by           : Stewart Weiss
# Created on           : December 10, 2009
# Modified on          : November 28, 2010
#                        Changed the print function to be symmetric with the
#                        createRec function
#               
# Description          : This shows how to create an array of simple records
#                        in which a record is a hash consisting of three scalars  
#                        and an array of integers.
#                        The data is stored in the file after the __DATA__ 
#                        keyword.
#
#*******************************************************************************             

$^W = 1;     # turn on warnings
use strict;  # behave!

#*******************************************************************************
#                                 Main Program                                 *
#*******************************************************************************

#my $tree_file = $ARGV[0];

my @nyc_trees;

my $nyc_trees;


my @lines;
# open file or exit with error message
while ( <DATA> ) #read line by line
{
	chomp;
	@lines = <DATA>;
}

print @lines;

__DATA__
225375,0,Fair,kousa dogwood,11361,Queens,Bayside-Bayside Hills,40.76670803,-73.76635512
17797,0,Good,bald cypress,10040,Manhattan,Washington Heights North,40.8533469,-73.93064497
253182,0,Good,cherry,10461,Bronx,Schuylerville-Throgs Neck-Edgewater Park,40.84072347,-73.8357429
223183,0,Good,cherry,11004,Queens,Glen Oaks-Floral Park-New Hyde Park,40.74530344,-73.70445039
224930,0,Poor,maple,11372,Queens,Jackson Heights,40.75544269,-73.87959983
291613,0,Fair,honeylocust,10465,Bronx,Schuylerville-Throgs Neck-Edgewater Park,40.82608329,-73.81439699
223260,0,Good,eastern redbud,11004,Queens,Glen Oaks-Floral Park-New Hyde Park,40.74421873,-73.70487975
280704,0,Good,Norway maple,11434,Queens,Springfield Gardens North,40.67402274,-73.7664819