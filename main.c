/*
Program: PA2: Digital Music Manager & Doubly Linked Lists
Programer: Connor Wright
Class: CPTS 122 Lecture 01 Lab 01 Summer 2016
Date: 6/14/16
Description: A music mannager that will organise music, store that music and use a doubly linked list

Changelog 
6/14/16
	definded the following structs in DMM.h
		Length
		Record
		Node
	created and tested 
		FILE *open_load()
		void sort_time()
		void load_record()
		void print_node()
		void test_load()

6/17/16
	Redefined the following structs because i was thinking about it the wrong way
		Record
			now has p_next and p_previous in the struct
		List(Node)
			redefined to be List has a pointer to the next head of the list
	Redifined the following functions to work with struct definitions
		void load_record()
		void print_record()(was print node)
		void test_load()
	Defined
		Record * make_record()
		void init_list()
		void load_records_from_file()
		void print_list()

6/18/16
	Updated the following functions to work with looped link list
		void print_list()
		void load_records_from_file()
	Defined enum type sort_choice(SC) to chose how to sort the list
	added
		void swap_elements()
		void sort_list() stuck on the sort will come back to it
6/19/16
	tried to fix the list sorting still bugs dont know if i will get to it
	added the following functions
		save_list()
		open_save_file()
		delete_record()
		delete_list()
		load_record_user()
		user_delete()
	Will need to lear a lot more about sorting the list 
	One good thing got the doubly linked circular list working so yayyyyyy
6/22/16(ish)
	Finally fixed the sorting issue YAYYYYYYYYYYYYYYYYYYYYYYY
	added menue() function
	added more safty so the user cant crash the program(as easily)

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////USES A DOUBLY LINKED CIRCULAR LIST///////////////////////
//////////////////////////////////////////////////////////////////////////////////

*/

#include "DMM.h"
#include "test_DMM.h"

int main() {

	//test_load();
	//test_swap();
	//test_sort();
	//test_save();
	//test_user_input();
	//test_delete();
	//test_edit();
	menue();


	return 0;
}