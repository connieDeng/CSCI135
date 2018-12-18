/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab9C, e.g., Lab1C

Task C. TimeSlot ending time and printTimeSlot
*/


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Time 
{ 
	public:
	int h;
	int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER}; //Genre can be anything in the {}

class Movie 
{ 
	public: 
	string title;
	Genre genre;     // only one genre per movie
	int duration;    // in minutes
};

class TimeSlot 
{ 
	public: 
	Movie movie;     // what movie
	Time startTime;  // when it starts
};

void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
TimeSlot timeEarlier(TimeSlot ts1, TimeSlot ts2);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

int main()
{
	TimeSlot mv1 = {{"Back to the Future", COMEDY, 116}, {9,15}};
	TimeSlot mv2 = {{"Back to the Future", COMEDY, 116}, addMinutes({9,15}, 116)};
	TimeSlot mv3 = {{"Back to the Future", COMEDY, 116}, addMinutes({12,7}, 116)};
	TimeSlot mv4 = {{"Back to the Future", COMEDY, 116}, addMinutes({14,3}, 116)};
	TimeSlot mv5 = {{"Back to the Future", COMEDY, 116}, addMinutes({15,59}, 116)};
	
	printTimeSlot(mv4);
}

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time) //hours are converted to min by *60
{
	return (time.h*60) + time.m;
}

int minutesUntil(Time earlier, Time later)
{
	return ((later.h*60) + later.m) - ((earlier.h*60) + earlier.m); 
}

Time addMinutes(Time time0, int min)
{
	Time x = { 0 , 0 };	
	int addedTime = time0.m + min;

	if ((addedTime) >= 60) //when time is >= 60 minutes
	{
		x.h = time0.h + (addedTime/60); //add the hours
		x.m += (addedTime % 60); //add the remainder of minutes
	}
	
	else				//if min does not go over 60
	{
		x.h = time0.h;		//hours does not change
		x.m = time0.m + min;	//simply add minutes
	}

	return x;
}

void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) 
	{
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
	printMovie(ts.movie); 
	cout << " [starts at ";
	printTime(ts.startTime);
	cout << ", ends by ";
	printTime(addMinutes(ts.startTime, ts.movie.duration));
	cout << "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
	TimeSlot mv = {nextMovie, addMinutes(ts.startTime, ts.movie.duration)};
	
	return mv;
}

bool timeEarlier(Time time1, Time time2)
{
	if(minutesSinceMidnight(time1) < minutesSinceMidnight(time2))
	{
		return true;
	}
	
	else
		return false;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
	Time timeAstart = ts1.startTime;
	Time timeBstart = ts2.startTime;
	Time timeAend = addMinutes(ts1.startTime, ts1.movie.duration);
	Time timeBend = addMinutes(ts2.startTime, ts2.movie.duration);
	
	if(timeEarlier(timeAstart, timeBend) && timeEarlier(timeBstart,timeAend))
	{
		return true;
	}
	
	else
		return false;
}