#include "game.h"


static int add_to_arr(void *a_param, int argc, char **argv, char **column) {
	static int i = 0;

	int *mas = (int*)a_param; // !!

	mas[i++] = atoi(argv[0]);

	argc = 0;
	column = NULL;

	if ( i == 10) i = 0;
    return 0;
}

static void tostring(char *str, int num) {
    int i, rem, len = 0, n;

    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }

    str[len] = '\0';
}

static void error(int rc, char **err) {
    if (rc != SQLITE_OK) {
        fprintf(stderr, "ERROR: %s\n", *err);
        sqlite3_free(*err);
        *err = NULL;
    }
}

void record(int result) {

	sqlite3 *db;

	sqlite3_open("resource/records.db", &db);

	char *sql = "SELECT score FROM records;";

	char *err_msg = NULL;

	int arr11[11];// = malloc(11 * sizeof(int));

	int rc = sqlite3_exec(db, sql, add_to_arr, arr11, &err_msg);

    error(rc, &err_msg);

	arr11[10] = result;


    for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11; j++){
		    if (arr11[j] < arr11[i]){
		        int temp = arr11[i];
			    arr11[i] = arr11[j];
			    arr11[j] = temp;
		    }
		}
    }

    int arr10[10];// = malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
		arr10[i] = arr11[i];
	}

//	free(arr11);

	char final_arr[10][5];

	for (int i = 0; i < 10; ++i) {
		tostring(final_arr[i], arr10[i]);
	}

//    free(arr10);

	char *command = "UPDATE records SET score = ";

    char *p1 = malloc(50); //strlen("UPDATE records SET score = 0000 WHERE number = 1;") * sizeof(char)
	strcpy(p1, command);
	strcat(p1, final_arr[0]);
	strcat(p1, " WHERE number = 1;");

	//printf("%s\n", p1);

    char *p2 = malloc(50);
    strcpy(p2, command);
	strcat(p2, final_arr[1]);
	strcat(p2, " WHERE number = 2;");

    //printf("%s\n", p2);

    char *p3 = malloc(50);
    strcpy(p3, command);
	strcat(p3, final_arr[2]);
	strcat(p3, " WHERE number = 3;");

    //printf("%s\n", p3);

    char *p4 = malloc(50);
    strcpy(p4, command);
	strcat(p4, final_arr[3]);
	strcat(p4, " WHERE number = 4;");

    //printf("%s\n", p4);

    char *p5 = malloc(50);
    strcpy(p5, command);
	strcat(p5, final_arr[4]);
	strcat(p5, " WHERE number = 5;");

    //printf("%s\n", p5);

    char *p6 = malloc(50);
    strcpy(p6, command);
	strcat(p6, final_arr[5]);
	strcat(p6, " WHERE number = 6;");

    //printf("%s\n", p6);

    char *p7 = malloc(50);
    strcpy(p7, command);
	strcat(p7, final_arr[6]);
	strcat(p7, " WHERE number = 7;");

    //printf("%s\n", p7);

	char *p8 = malloc(50);
    strcpy(p8, command);
	strcat(p8, final_arr[7]);
	strcat(p8, " WHERE number = 8;");

    //printf("%s\n", p8);

    char *p9 = malloc(50);
    strcpy(p9, command);
	strcat(p9, final_arr[8]);
	strcat(p9, " WHERE number = 9;");

	//printf("%s\n", p9);

	char *p10 = malloc(50);
    strcpy(p10, command);
	strcat(p10, final_arr[9]);
	strcat(p10, " WHERE number = 10;");

	//printf("%s\n", p10);

	int err = sqlite3_exec(db, p1, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p2, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p3, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p4, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p5, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p6, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p7, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p8, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p9, 0, 0, &err_msg);
    error(err, &err_msg);

    err =sqlite3_exec(db, p10, 0, 0, &err_msg);
    error(err, &err_msg);

	free(p1);
	free(p2);
    free(p3);
    free(p4);
    free(p5);
    free(p6);
    free(p7);
    free(p8);
    free(p9);
    free(p10);

	sqlite3_close(db);
}

