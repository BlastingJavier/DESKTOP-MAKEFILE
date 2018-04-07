/**
 * @brief It tests link module
 *
 * @file link_test.c
 * @author Francisco Javier Nanclares
 * @version 2.0
 * @date 16-01-2018
 * @updated 19-01-2018
 * @copyright GNU Public License
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "link.h"
 #include "link_test.h"
 #include "test.h"


 #define MAX_TESTS 23


 int main (int argc,char ** argv){

   int test = 0;
   int all = 1;

   if (argc < 2) {
       printf("Running all test for module Link:\n");
   } else {
       test = atoi(argv[1]);
       all = 0;
       printf("Running test %d:\t", test);
 if (test < 1 && test > MAX_TESTS) {
   printf("Error: unknown test %d\t", test);
   exit(EXIT_SUCCESS);
       }
   }


 if (all || test ==1 ) test1_link_create();
 if (all || test ==2 ) test2_link_create();
 if (all || test ==3 ) test3_link_create();
 if (all || test ==4 ) test1_link_set_name();
 if (all || test ==5 ) test2_link_set_name();
 if (all || test ==6 ) test1_link_set_id();
 if (all || test ==7 ) test2_link_set_id();
 if (all || test ==8 ) test1_link_set_bool_state();
 if (all || test ==9 ) test2_link_set_bool_state();
 if (all || test ==10 ) test1_link_set_id_space1();
 if (all || test ==11 ) test2_link_set_id_space1();
 if (all || test ==12 ) test1_link_set_id_space2();
 if (all || test ==13 ) test2_link_set_id_space2();
 if (all || test ==14 ) test1_link_get_name();
 if (all || test ==15 ) test2_link_get_name();
 if (all || test ==16 ) test1_link_get_id();
 if (all || test ==17 ) test2_link_get_id();
 if (all || test ==18 ) test1_link_get_bool_state();
 if (all || test ==19 ) test2_link_get_bool_state();
 if (all || test ==20 ) test1_link_get_id_space1();
 if (all || test ==21 ) test2_link_get_id_space1();
 if (all || test ==22 ) test1_link_get_id_space2();
 if (all || test ==23 ) test2_link_get_id_space2();

 PRINT_PASSED_PERCENTAGE;

 return 1;

}



void test1_link_create() {
  int result = link_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
}

void test2_link_create() {
  Link *s;
  s = link_create(4);
  PRINT_TEST_RESULT(link_get_id(s) == 4);
}

void test3_link_create() {
  Link *s;
  s = link_create(4);
  PRINT_TEST_RESULT(link_get_id(s) == 4);
}

void test1_link_set_name() {
  Link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_name(s, "Link1") == OK);
}

void test2_link_set_name() {
  Link *s = NULL;
  PRINT_TEST_RESULT(link_set_name(s, "Link1") == ERROR);
}

void test1_link_set_id() {
  Link *s;
  s = link_create(1);
  PRINT_TEST_RESULT(link_set_id(s,2) == OK);
}

void test2_link_set_id() {
  Link *s = NULL;
  PRINT_TEST_RESULT(link_set_id(s,1) == ERROR);
}

void test1_link_set_bool_state(){
  Link *s = NULL;
  s = link_create(1);
  PRINT_TEST_RESULT(link_set_bool_state(s,TRUE) == OK);
}

void test2_link_set_bool_state(){
  Link *s = NULL;
  PRINT_TEST_RESULT(link_set_bool_state(s,TRUE) == ERROR);
}

void test1_link_set_id_space1(){
  Link *s = NULL;
  s = link_create(1);
  PRINT_TEST_RESULT(link_set_id_space1(s,2) == OK);
}

void test2_link_set_id_space1(){
  Link *s = NULL;
  PRINT_TEST_RESULT(link_set_id_space1(s,2) == ERROR);
}

void test1_link_set_id_space2(){
  Link *s = NULL;
  s = link_create(1);
  PRINT_TEST_RESULT(link_set_id_space2(s,2) == OK);
}

void test2_link_set_id_space2(){
  Link *s = NULL;
  PRINT_TEST_RESULT(link_set_id_space2(s,2) == ERROR);
}

void test1_link_get_name() {
  Link *s;
  s = link_create(1);
  link_set_name(s, "Link1");
  PRINT_TEST_RESULT(strcmp(link_get_name(s), "Link1") == 0);

}

void test2_link_get_name() {
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_name(s) == NULL);

}

void test1_link_get_id() {
    Link *s;
    s = link_create(1);
    PRINT_TEST_RESULT(link_get_id(s) == 1);

}

void test2_link_get_id() {
    Link *s;
    s = link_create(1);
    link_set_id(s,2);
    PRINT_TEST_RESULT(link_get_id(s) == 2);
}

void test1_link_get_bool_state() {
    Link *s;
    s = link_create(5);
    link_set_bool_state(s, TRUE);
    PRINT_TEST_RESULT(link_get_bool_state(s) == TRUE);
}

void test2_link_get_bool_state() {
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_bool_state(s) == FALSE);
}

void test1_link_get_id_space1() {
    Link *s;
    s = link_create(5);
    link_set_id_space1(s, 2);
    PRINT_TEST_RESULT(link_get_id_space1(s) == 2);
}

void test2_link_get_id_space1() {
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_id_space1(s) == NO_ID);
}

void test1_link_get_id_space2() {
    Link *s;
    s = link_create(5);
    link_set_id_space2(s, 2);
    PRINT_TEST_RESULT(link_get_id_space2(s) == 2);
}

void test2_link_get_id_space2() {
    Link *s = NULL;
    PRINT_TEST_RESULT(link_get_id_space2(s) == NO_ID);
}
