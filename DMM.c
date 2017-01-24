#include "DMM.h"

FILE *open_load() {

	FILE * infile = NULL;
	infile = fopen("load.txt", "r");
	//prints if the file could not be opened
	if (infile == NULL) {
		printf("Could not open \"load.txt\"\n");
	}
	return infile;
}

//preconditon there must be a string in string
//int the format of hours:mins:secs
void sort_time(int *hours, int *mins, int*secs, char * string) {

	char *token[4] = {NULL, NULL,NULL,NULL};
	int index = 0;
	token[index]=strtok(string, ":");
	while (token[index] != NULL) {
		index++;
		token[index]=strtok(NULL, ":");
	}
	if (token[2] != NULL) {
		*hours = atoi(token[0]);
		*mins = atoi(token[1]);
		*secs = atoi(token[2]);
	}
	else if (token[1] != NULL) {
		*mins = atoi(token[0]);
		*secs = atoi(token[1]);
	}
	else {
		*secs = atoi(token[0]);
	}
}

int load_record(FILE *infile, Record* new_record) {

	char *temp = NULL;
	int pos = 0;
	int hours = 0, mins = 0, secs = 0;
	int is_more = 1;
	//checks to see if the file is open
	if (infile != NULL) {

		//artist
		temp = (char *)malloc(sizeof(char));
		*temp = fgetc(infile);
		if (*(temp + pos) != EOF) {
			
			
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				new_record->artist = temp;
			}
			else {
				new_record->artist = NULL;
				free(temp);
			}
		}
		//albumb
		
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				new_record->album = temp;
			}
			else {
				new_record->album = NULL;
				free(temp);
			}
			
		}
		//song title
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				new_record->song_title = temp;
			}
			else {
				new_record->song_title = NULL;
				free(temp);
			}
		}
		//genre
		
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				new_record->genre = temp;
			}
			else {
				new_record->genre = NULL;
				free(temp);
			}
		}
		//time
		
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				sort_time(&hours, &mins, &secs, temp);
				new_record->song_length.hours = hours;
				new_record->song_length.mins = mins;
				new_record->song_length.secs = secs;
			}
			else {
				new_record->song_length.hours = -1;
				new_record->song_length.mins = -1;
				new_record->song_length.secs = -1;
			}
			free(temp);
		}
		//times played
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				new_record->num_times_played = atoi(temp);
			}
			else {
				new_record->num_times_played = -1;
			}
			free(temp);
		}
		//rating
		
		if (*(temp + pos) != EOF) {
			pos = 0;
			temp = (char *)malloc(sizeof(char));
			*temp = fgetc(infile);
			while (*(temp + pos) != '\n'&&*(temp + pos) != EOF) {

				pos++;
				temp = realloc(temp, sizeof(char)*(pos + 1));
				*(temp + pos) = fgetc(infile);
			}
			*(temp + pos) = '\0';
			if (*temp != '\0') {
				if (atoi(temp) > 0 && atoi(temp) < 6)
					new_record->rating = atoi(temp);
				else
					new_record->rating = -1;
			}
			else {
				new_record->rating = -1;
			}
		}
		*temp = fgetc(infile);
		
	}
	else {
		printf("ERROR: NULL POINTER FILE NOT OPEN\n");
		is_more = 0;
	}
	if (*(temp) == EOF) {
		is_more = 0;
	}
	free(temp);
	return is_more;
	

}

void print_record(Record rec) {

	if(rec.artist!=NULL)
		printf("Artist: %s\n", rec.artist);
	else
		printf("Artist: -UNKOWN-\n");
	if (rec.album != NULL)
		printf("Album Title: %s\n", rec.album);
	else
		printf("Album Title: -UNKNOWN-\n");
	if(rec.song_title!=NULL)
		printf("Song Title: %s\n", rec.song_title);
	else 
		printf("Song Title: -UNKNOWN-\n");
	if(rec.genre!=NULL)
		printf("Genre: %s\n", rec.genre);
	else
		printf("Genre: -UNKOWN-\n");
	if (rec.song_length.hours != -1 || rec.song_length.mins != -1 || rec.song_length.secs != -1)
		printf("Song length: %d:%d:%d\n", rec.song_length.hours, rec.song_length.mins, rec.song_length.secs);
	else
		printf("Song length: -UNKNOWN-\n");
	if (rec.num_times_played != -1)
		printf("number of times played: %d\n", rec.num_times_played);
	else
		printf("number of times played: -UNKNOWN-\n");
	if (rec.rating != -1)
		printf("rating: %d\n", rec.rating);
	else
		printf("rating: -UNKNOWN-\n");
	printf("\n");
}

Record * make_record(){

	Record * p_temp = NULL;
	p_temp = (Record *)malloc(sizeof(Record));
	return p_temp;
}

void init_list(List *new_list) {
	new_list->p_head = NULL;
}

void load_records_from_file(FILE *infile,List *new_list) {

	rewind(infile);
	int cont_read = 0;
	Record * p_temp = NULL;
	do {
		p_temp = make_record();
		cont_read = load_record(infile, p_temp);
		if (new_list->p_head == NULL) {//first item

			new_list->p_head = p_temp;//shallow copy
			p_temp->p_next = p_temp->p_prev = p_temp;
		}
		else {//more than 1 item insert at front
			p_temp->p_next = new_list->p_head;
			p_temp->p_prev = new_list->p_head->p_prev;
			p_temp->p_prev->p_next = p_temp;
			new_list->p_head->p_prev = p_temp;
		}
	} while (cont_read == 1);
}

void print_list(List curr_list) {

	Record *p_temp = NULL;
	Record *p_init = NULL;
	p_init=p_temp = curr_list.p_head;
	 do{
		 print_record(*p_temp);
		p_temp = p_temp->p_next;
	}while (p_temp != p_init);
}

//only one elemnt hell yeah
void swap_elements(Record *current_element) {

	current_element->p_next->p_prev = current_element->p_prev;
	current_element->p_next->p_next->p_prev = current_element;
	current_element->p_prev->p_next = current_element->p_next;
	current_element->p_prev = current_element->p_next;
	current_element->p_next = current_element->p_next->p_next;
	current_element->p_prev->p_next = current_element;
}

int compare_time(Record rec1, Record rec2) {

	int compare = 0;
	int length1 = 0;
	int length2 = 0;
	length1 = (rec1.song_length.hours * 60 * 60) + (rec1.song_length.mins * 60) + (rec1.song_length.secs);
	length2 = (rec2.song_length.hours * 60 * 60) + (rec2.song_length.mins * 60) + (rec2.song_length.secs);
	if (length1 <length2) {
		compare = -1;
	}
	else if (length2 < length1) {
		compare = 1;
	}
	return compare;
}

void sort_list(SC choice, List *list_to_sort) {

	Record *p_temp = NULL;
	Record *p_u=NULL;
	Record *p_init = NULL;
	
	p_init = p_temp = list_to_sort->p_head;
	switch (choice) {
		//sorting list by albumb name
		case Artist:
			do {//finds the lowest value
				if (strcmp(list_to_sort->p_head->artist, p_temp->artist) > 0) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			//bubble sort
			p_u = list_to_sort->p_head;
			while (p_u->p_prev!= list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next!= p_u) {
					
					if (strcmp(p_temp->artist, p_temp->p_next->artist) > 0) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
					p_u = p_u->p_prev;
			}
			break;
		case Album:
			do {//finds the lowest value
				if (strcmp(list_to_sort->p_head->album, p_temp->album) > 0) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			//bubble sort
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (strcmp(p_temp->album, p_temp->p_next->album) > 0) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
		case Song:
			do {//finds the lowest value
				if (strcmp(list_to_sort->p_head->song_title, p_temp->song_title) > 0) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			//bubble sort
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (strcmp(p_temp->song_title, p_temp->p_next->song_title) > 0) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
		case Genre:
			do {//finds the lowest value
				if (strcmp(list_to_sort->p_head->genre, p_temp->genre) > 0) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			//bubble sort
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (strcmp(p_temp->genre, p_temp->p_next->genre) > 0) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
		case Song_length:
			do {
				if (compare_time(*(list_to_sort->p_head), *(p_temp)) > 0) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (compare_time(*(p_temp), *(p_temp->p_next)) > 0) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
		case Num_played:
			do {
				if (list_to_sort->p_head->num_times_played> p_temp->num_times_played) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (p_temp->num_times_played>p_temp->p_next->num_times_played) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
		case Rating:
			do {
				if (list_to_sort->p_head->rating> p_temp->rating) {
					list_to_sort->p_head = p_temp;
				}
				p_temp = p_temp->p_next;
			} while (p_temp != p_init);
			p_u = list_to_sort->p_head;
			while (p_u->p_prev != list_to_sort->p_head) {
				p_temp = list_to_sort->p_head->p_next;
				while (p_temp->p_next != p_u) {

					if (p_temp->rating>p_temp->p_next->rating) {
						swap_elements(p_temp);
					}
					else {
						p_temp = p_temp->p_next;
					}
				}
				p_u = p_u->p_prev;
			}
			break;
	}
}

void save_list(List list_to_save ,FILE *outfile) {

	Record *p_init = NULL;
	Record *p_temp = NULL;

	//returns us to the begining of the text file
	rewind(outfile);
	p_init = p_temp = list_to_save.p_head;
	//list not empty
	if (p_temp != NULL) {
		do {
			if (p_temp->artist != NULL)
				fprintf(outfile,"%s\n", p_temp->artist);
			else
				fprintf(outfile,"\n");
			if (p_temp->album != NULL)
				fprintf(outfile,"%s\n", p_temp->album);
			else
				fprintf(outfile,"\n");
			if (p_temp->song_title != NULL)
				fprintf(outfile,"%s\n", p_temp->song_title);
			else
				fprintf(outfile,"\n");
			if (p_temp->genre != NULL)
				fprintf(outfile,"%s\n", p_temp->genre);
			else
				fprintf(outfile,"\n");
			if (p_temp->song_length.hours != -1 || p_temp->song_length.mins != -1 || p_temp->song_length.secs != -1)
				fprintf(outfile,"%d:%d:%d\n", p_temp->song_length.hours, p_temp->song_length.mins, p_temp->song_length.secs);
			else
				fprintf(outfile,"\n");
			if (p_temp->num_times_played != -1)
				fprintf(outfile,"%d\n", p_temp->num_times_played);
			else
				fprintf(outfile,"\n");
			if (p_temp->rating != -1)
				fprintf(outfile,"%d\n", p_temp->rating);
			else
				fprintf(outfile,"\n");
			if(p_temp->p_next!=p_init)
				fprintf(outfile,"\n");
			p_temp = p_temp->p_next;
		} while (p_temp != p_init);
	}
	else {
		printf("list is empty can't save\n");
	}
}

FILE *open_save_file() {
	FILE *outfile = NULL;
	outfile = fopen("save.txt", "r+");
	return outfile;
}

void delete_record(Record* rec) {
	
	rec->p_prev->p_next = rec->p_next;
	rec->p_next->p_prev = rec->p_prev;
	free(rec->album);
	free(rec->artist);
	free(rec->genre);
	free(rec->song_length.hours);
	free(rec->song_title);
	free(rec);
}

void delete_list(List *list_to_delete) {

	Record *p_temp = NULL;
	//list not empty
	if (list_to_delete->p_head != NULL) {
		do {
			p_temp = list_to_delete->p_head->p_next;
			if (list_to_delete->p_head->p_next != list_to_delete->p_head->p_prev)
				delete_record(p_temp);
			else
				list_to_delete->p_head = NULL;
		} while (list_to_delete->p_head = NULL);
	}
	else {
		printf("list already empty could not delete\n");
	}
}

void load_record_user(List *list_to_load) {

	Record *p_temp = NULL;
	p_temp = make_record();
	printf("If you don't know any of the information please leave that line blank\n");
	printf("you must enter the information this way\n");
	printf("Artist\nAlbum Title\nSong Title\nGenre\nSong Length(hours:mins:secs)\nNumber of times played\nRating\n");
	printf("Press enter when you are done\n\n");
	load_record(stdin, p_temp);
	if (p_temp->album == NULL&&p_temp->artist == NULL&&p_temp->genre == NULL&&p_temp->song_title == NULL&&p_temp->num_times_played == -1 && p_temp->rating == -1 && p_temp->song_length.hours == -1) {
		printf("There was no information here record was not saved\n");
		free(p_temp->album);
		free(p_temp->artist);
		free(p_temp->genre);
		free(p_temp->song_title);
		free(p_temp);
	}
	else {
		if (list_to_load->p_head == NULL) {//first item

			list_to_load->p_head = p_temp;//shallow copy
			p_temp->p_next = p_temp->p_prev = p_temp;
		}
		else {//more than 1 item insert at front
			p_temp->p_next = list_to_load->p_head;
			p_temp->p_prev = list_to_load->p_head->p_prev;
			p_temp->p_prev->p_next = p_temp;
			list_to_load->p_head->p_prev = p_temp;
		}
	}
}

void user_delete(List *curr_list) {

	Record *p_temp = NULL;
	char temp[50] = "";
	int found = 0;
	int size = 0;
	printf("Enter in the name of the song you want to delete\n");
	fgets(temp,50,stdin); 
	size = strlen(temp);
	temp[size-1] = '\0';

	
	p_temp = curr_list->p_head;
	do {
		p_temp = p_temp->p_next;
		if (strcmp(p_temp->song_title, temp)==0) {
			found = 1;
		}
	} while (p_temp != curr_list->p_head&&found!=1);
	if (found == 1) {
		if (p_temp == curr_list->p_head) {
			curr_list->p_head = curr_list->p_head->p_next;
		}
		delete_record(p_temp);
		printf("record successfuly deleted\n");
	}
	else
		printf("File could not be located\n");
}

void user_edit(List *curr_list) {

	Record *p_temp = NULL;
	char temp[50] = "";
	char*new_string = NULL;
	int found = 0;
	int choice = 0;
	int hours = 0, mins = 0, secs = 0;
	printf("Enter in the name of the song you want to edit\n");
	int size = 0;
	fgets(temp, 50, stdin);
	size = strlen(temp);
	temp[size - 1] = '\0';

	p_temp = curr_list->p_head;
	do {
		p_temp = p_temp->p_next;
		if (strcmp(p_temp->song_title, temp)==0) {
			found = 1;
		}
	} while (p_temp != curr_list->p_head && found != 1);
	if (found == 1) {

		do {
		print_record(*p_temp);
		printf("What feild do you want to edit?\n");
		printf("1.Artist\n2.Album\n3.Song Title\n4. Genre\n5.Song Length\n6.Number Played\n7.Rating\n");
		scanf("%d", &choice);
		} while (!(choice<8 && choice>-1));
		printf("Please enter youre change\n");
		switch (choice){
			case Artist+1:
				scanf("%s", temp);
				new_string = (char*)malloc((sizeof(char))*(strlen(temp) + 1));
				strcpy(new_string, temp);
				free(p_temp->artist);
				p_temp->artist = new_string;
				break;
			case Album+1:
				scanf("%s", temp);
				new_string = (char*)malloc((sizeof(char))*(strlen(temp) + 1));
				strcpy(new_string, temp);
				free(p_temp->album);
				p_temp->album = new_string;
				break;
			case Song+1:
				scanf("%s", temp);
				new_string = (char*)malloc((sizeof(char))*(strlen(temp) + 1));
				strcpy(new_string, temp);
				free(p_temp->song_title);
				p_temp->song_title = new_string;
				break;
			case 4:
				scanf("%s", temp);
				new_string = (char*)malloc((sizeof(char))*(strlen(temp) + 1));
				strcpy(new_string, temp);
				free(p_temp->genre);
				p_temp->genre = new_string;
				break;
			case 5:
				printf("int the format hours:sec:min\n");
				scanf("%s", temp);
				sort_time(&hours, &mins, &secs, temp);
				p_temp->song_length.hours = hours;
				p_temp->song_length.mins = mins;
				p_temp->song_length.secs = secs;
				break;
			case 6:
				scanf("%d", &choice);
				p_temp->num_times_played = choice;
				break;
			case 7:
				do {
					scanf("%d", &choice);
					if (!(choice > 0 && choice < 6)) {
						printf("Rating can only be from 1-5");
					}
				} while (!(choice > 0 && choice < 6));
				p_temp->rating = choice;
				break;
		}
	}
	else {
		printf("The record could not be found\n");
	}
}

void menue() {

	int choice = 0;
	SC sort_c = 1;
	List new_list;
	FILE* save = NULL;
	FILE *load = NULL;
	load = open_load();
	save = open_save_file();
	init_list(&new_list);

	do {
		
		printf("Plese chose a choice(You canot load from an empty file!)\n");
		printf("0. Exit\n");
		printf("1. Load records(save.txt)\n");
		printf("2. Load records(load.txt)\n");
		printf("3. Save records(save.txt)\n");
		printf("4. Insert a record manualy\n");
		printf("5. Delete a record\n");
		printf("6. Edit a record/rate\n");
		printf("7. Sort Record\n");
		printf("8. Print list\n");
		printf("9. Delete list\n");
		do{
			scanf("%d", &choice);
			if (!(choice<10 && choice>-1)) {
				printf("Please chose a valid option\n");
				getchar();
			}
		} while (!(choice<10 && choice>-1));
		switch (choice) {
			case 0:
				break;
			case 1:
				load_records_from_file(save, &new_list);
				system("PAUSE");
				break;
			case 2:
				load_records_from_file(load, &new_list);
				system("PAUSE");
				break;
			case 3:
				save_list(new_list, save);
				system("PAUSE");
				break;
			case 4:
				getchar();
				load_record_user(&new_list);
				system("PAUSE");
				break;
			case 5:
				if (new_list.p_head != NULL) {
					getchar();
					user_delete(&new_list);
				}
				else {
					printf("List is empty can't delete\n");
				}
				system("PAUSE");
				break;
			case 6:
				if (new_list.p_head != NULL) {
					getchar();
					user_edit(&new_list);
				}
				else {
					printf("List is empty can't edit\n");
				}
				system("PAUSE");
				break;
			case 7:
				if (new_list.p_head != NULL) {
					getchar();
					do {
						printf("Please chose which way you want to sort the list\n");
						printf("1.Artist\n2.Album\n3.Song Title\n4.Genre\n5.Song Length\n6.Number Played\n7.Rating\n");
						scanf("%d", &sort_c);
						if (!(sort_c<8 && sort_c>-1)) {
							getchar();
						}
					} while (!(sort_c<8 && sort_c>-1));
					sort_list(sort_c - 1, &new_list);
				}
				else {
					printf("List is empty can't sort\n");
				}
				system("PAUSE");
				break;
			case 8:
				if (new_list.p_head != NULL) {
					system("cls");
					print_list(new_list);
				}
				else {
					printf("List is empty can't print\n");
				}
				system("PAUSE");
				break;
			case 9:
				delete_list(&new_list);
				system("PAUSE");
		}
		system("cls");
		//sorts the list after changes have been made
		if (new_list.p_head != NULL) {
			sort_list(sort_c-1, &new_list);
		}
	} while (choice != 0);
	printf("Thank you for useing DMM\n");
	fclose(load);
	fclose(save);
}