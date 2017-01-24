#include "test_DMM.h"

void test_load() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
}

void test_swap() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	printf("\n");
	swap_elements(new_list.p_head->p_next);
	print_list(new_list);

}

void test_sort() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	printf("\n");

	sort_list(Artist, &new_list);
	print_list(new_list);
}

void test_save() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	FILE *outfile = NULL;
	outfile = open_save_file();
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	save_list(new_list, outfile);
	delete_list(&new_list);
	load_records_from_file(outfile, &new_list);
	printf("\n");
	print_list(new_list);

}

void test_user_input() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	printf("\n");
	load_record_user(&new_list);
	print_list(new_list);
}

void test_delete() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	printf("\n");
	user_delete(&new_list);
	print_list(new_list);

}

void test_edit() {

	List new_list;
	int success = 0;
	FILE* infile = NULL;
	infile = open_load();
	init_list(&new_list);
	load_records_from_file(infile, &new_list);
	print_list(new_list);
	printf("\n");
	user_edit(&new_list);
	print_list(new_list);
}