#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LENGTH 102
#define MAX_TEAM 12

typedef struct {
    char weekday[4];
    int day, month;
    double time;
    char home_team [4], away_team [4];
    int goal_home_team, goal_away_team;
    int spectators;
} match;

typedef struct {
    char name[4];
    int point;
    int goals_made;
    int goals_let_in;
} team;

// Funktionensprototyper
void get_data(match matches[]);
void create_a_team(team teams[], match matches[]);
int cmpfunc (const void * a, const void * b);
int get_score(team *team, match match);
void print_functions(team teams[]);
int index_of_(char *team_name);
int are_strings_equal(char *str1, char *str2);


int main() {
    team teams[MAX_TEAM] = {0};
    match matches[FILE_LENGTH];
    get_data(matches);
    create_a_team(teams, matches);
    print_functions(teams);

    return 0;
}

void get_data(match matches[]){
    int i = 0;
// filpointer
    FILE *file_football = fopen("fodbold_kampe.txt", "r");

    if (file_football == NULL ) {
        printf( "kampe-2022-2023.txt file failed to open.");
    }

    while(!feof(file_football)) {

        // Scanner hver linje
        fscanf(file_football, "%s %d/%d %lf %s - %s %d - %d %d",
               matches[i].weekday,
               &matches[i].day,
               &matches[i].month,
               &matches[i].time,
               matches[i].home_team,
               matches[i].away_team,
               &matches[i].goal_home_team,
               &matches[i].goal_away_team,
               &matches[i].spectators);
        i++;

    }
    fclose(file_football);

}

// Get teams from matches function
// Gets team and calls insert_team_into_array function:
void create_a_team(team teams[], match matches[]) {
    int home_team_index, away_team_index;

    // Loop through all matches
    for(int i = 0 ; i < FILE_LENGTH; i++) {
        char *home_team_name = matches[i].home_team;
        char *away_team_name = matches[i].away_team;

        // Get index of team 1 and 2 for the teams-array
        home_team_index = index_of_(home_team_name);
        away_team_index = index_of_(away_team_name);

        // check if index is out of range
        if (home_team_index == -1 || away_team_index == -1) {
            printf("index is out of range");
            exit(EXIT_FAILURE);
        }

        team *home_team = &teams[home_team_index];
        team *away_team = &teams[away_team_index];

        // then set create the team
        strcpy(home_team->name, home_team_name); // set the name
        home_team->point += get_score(home_team, matches[i]);
        home_team->goals_made += matches[i].goal_home_team;
        home_team->goals_let_in += matches[i].goal_away_team;

        strcpy(away_team->name, away_team_name); // set the name
        away_team->point += get_score(away_team, matches[i]);
        away_team->goals_made += matches[i].goal_away_team;
        away_team->goals_let_in += matches[i].goal_home_team;
    }

    // sorts through all the elements in the array teams
    qsort(teams, MAX_TEAM, sizeof(team), cmpfunc);

}

int cmpfunc (const void * a, const void * b) {
    int score_difference_1, score_difference_2;

    team *team_1 = (team *) a;
    team *team_2 = (team *) b;


    if (team_1->point == team_2->point) {
      score_difference_1 = team_1->goals_made - team_1->goals_let_in;
      score_difference_2 = team_2->goals_made - team_2->goals_let_in;

      return score_difference_2 - score_difference_1;

    } else {

        return team_2->point - team_1->point;
    }

}


//             team struct match struct
int get_score(team *team, match match){
    int goal_difference, score_for_the_team, score_against_the_team;

    if (strcmp(team->name, match.home_team)) {
        score_for_the_team = match.goal_away_team;
        score_against_the_team = match.goal_home_team;

    } else {
        score_for_the_team = match.goal_home_team;
        score_against_the_team = match.goal_away_team;
    }

    goal_difference = score_for_the_team - score_against_the_team;

    if (goal_difference > 0) {
        return 3;
    } else if (goal_difference == 0) {
        return 1;
    } else {
        return 0;
    }
}

void print_functions(team teams[]){
    for (int i = 0; i < 12; i++) {
        printf("%s\t|%d\t|%d\t|%d \n",
               teams[i].name,
               teams[i].point,
               teams[i].goals_made,
               teams[i].goals_let_in);

    }

}

int index_of_(char *team_name) {
    if (are_strings_equal(team_name, "FCM"))
        return 0;
    else if (are_strings_equal(team_name, "VFF"))
        return 1;
    else if (are_strings_equal(team_name, "LBK"))
        return 2;
    else if (are_strings_equal(team_name, "FCK"))
        return 3;
    else if (are_strings_equal(team_name, "BIF"))
        return 4;
    else if (are_strings_equal(team_name, "OB"))
        return 5;
    else if (are_strings_equal(team_name, "AGF"))
        return 6;
    else if (are_strings_equal(team_name, "RFC"))
        return 7;
    else if (are_strings_equal(team_name, "AaB"))
        return 8;
    else if (are_strings_equal(team_name, "ACH"))
        return 9;
    else if (are_strings_equal(team_name, "SIF"))
        return 10;
    else if (are_strings_equal(team_name, "FCN"))
        return 11;
    else
        return -1;
}

int are_strings_equal(char *str1, char *str2) {

    return strcmp(str1, str2) == 0;

}
