#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct length {
	
	int hours;
	int mins;
	int secs;
}Length;

typedef struct record {

	char *artist;
	char *album;
	char *song_title;
	char *genre;
	Length song_length;
	int num_times_played;
	int rating;
	struct record *p_next;
	struct record *p_prev;
}Record;

typedef struct list {

	Record * p_head;
}List;

typedef enum sort_choice {

	Artist,
	Album,
	Song,
	Genre,
	Song_length,
	Num_played,
	Rating
}SC;

//opens load.txt for reading
FILE *open_load();
//sorts the time string into 3 ints hours secs and mins
void sort_time(int *hours, int *mins, int*secs, char * string);
//loads one record into a record the order should be 
//Artist
//Albumb title
//Song title
//Genre
//Song Length
//Number of times played
//Rating
//if unkown skip to the next line
//if any of these are blank fill space with null caracter or -1
//precondition something must be there to load
//also must be a space between songs
int load_record(FILE *infile, Record * list);
//prints a single node in the list
void print_record(Record rec);
//organises time into proper variables
void sort_time(int *hours, int *mins, int*secs, char * string);
//creates a pointer to a new record on the heap
Record * make_record();
//initalizes list
void init_list(List *new_list);
//loads all records from a file
void load_records_from_file(FILE *infile, List *new_list);
//prints out the whole list
void print_list(List curr_list);
//swaps the current element with the one in front of it
void swap_elements(Record *current_element);
//works like strcmp() except with struct Record format
int compare_time(Record rec1, Record rec2);
//sorts the list based on choice(still has bugs)
void sort_list(SC choice, List *list_to_sort);
//saves the list into a text file
void save_list(List list_to_save, FILE *outfile);
//opens the save file for reading and writing
FILE *open_save_file();
//deletes one record while repairing the hole that was left
void delete_record(Record *rec);
//deletes the whole list
void delete_list(List *list_to_delete);
//loads a record from the user
void load_record_user(List *list_to_load);
//deletes a record from the user based on song name
void user_delete(List *curr_list);
//searches for a function and allows the user to edit the data
void user_edit(List *curr_list);
//puts all the pices together drives the full program
void menue();