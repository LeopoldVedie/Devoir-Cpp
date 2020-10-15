#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "tasks.h"
#include "TODO_list.h"
using namespace std;

To_Do::To_Do () : nb(0), list({}) {};

void To_Do::print (int p) {
    int l = list.size();
    int i = 0;
    while ((i<l) && (list[i].priority >= p)) {
        list[i].print("\n");
        i++;
    };
    cout << "" << endl;   
} 

string To_Do::add_To_Do (string t, string d, int p) {
    if (p>10) {p=10;}
    if (p<0) {p=0;}
    list.push_back(Task (t, d, nb, p));
    string date = list[list.size() - 1].open;
    nb++;
    sort(list.begin(),list.end(),test_priority);
    return date;
}

void To_Do::add_initialization (string t, string d, int p, string op) {
    if (p>10) {p=10;}
    if (p<0) {p=0;}
    list.push_back(Task (t, d, op, nb, p));
    nb++;
    sort(list.begin(),list.end(),test_priority);
}

int To_Do::position (string titre) {
    int i {};
    while (list[i].title != titre) {i++;};
    return i;
}

int To_Do::position (int ID) {
    int i {};
    while (list[i].id != ID) {i++;};
    return i;
}

void To_Do::add_comments (int ID, string c) {
    int i = position(ID);
    list[i].comments.push_back(c); 
    
}

void To_Do::change_priority (int ID, int p) {
    int i = position(ID);
    list[i].priority = p;
    sort(list.begin(),list.end(),test_priority); 
}

void To_Do::change_achiev (int ID, int a) {
    int i = position(ID);
    list[i].achiev = a; 
}

void To_Do::change_title (int ID, string t){
    int i = position(ID);
    list[i].title = t;
}

void To_Do::change_description (int ID, string descrip){
    int i = position(ID);
    list[i].description = descrip;
}

string To_Do::close (int ID) {
    int i = position(ID);
    string date;
    list[i].closure();
    date = list[i].close;
    sort(list.begin(),list.end(),test_priority); 
    return date;
}

void To_Do::close_initialization (int ID, string cl) {
    int i = position(ID);
    list[i].closure_initialization(cl);
    sort(list.begin(),list.end(),test_priority); 
}