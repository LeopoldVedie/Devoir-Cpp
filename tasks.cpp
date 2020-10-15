#include<iostream>
#include<vector>
#include "tasks.h"
#include <string>
using namespace std;
#define PBSTR "|||||||||||||||"
#define PBWIDTH 15

string Date(){
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string date = to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_mon + 1) + "/" + to_string(ltm->tm_year + 1900) + " at " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return date;
}


bool test_priority (Task a, Task b) {
    return (a.priority > b.priority);
}

Task::Task (string t, string d, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), close(""), comments({}), achiev(0) {
    open = Date();
}

Task::Task (string t, string d, string op, int i, int p) :
title(t), description(d), priority(p), id(i), status("open"), open(op), close(""), comments({}), achiev(0) {}

void Task::print (string str) {
    cout << id << " ] " << title << " : " << description << " -> " << status << ", opened on "<< open;
    if (status ==  "close" ) {
        cout << " and closed on " << close;
    }
    else {    
        string priority_level;
        switch(priority){
            case 0:
                priority_level = "low";
                break;
            case 1:
                priority_level = "normal";
                break;
            case 2:
                priority_level = "high";
                break;
            case -1:
                priority_level = "finish";
                break;
            default:
                priority_level = "very high";
                break;
        }
        cout << ". Priority: " << priority << " ("<< priority_level << ") "  << endl ;
        progress_bar(achiev);
        cout << endl;}
    if (not(comments.empty())) {
        cout << "  Comments:" << endl;
        int len=comments.size();
        for (int i {}; i<len; i++) {
            cout << "      ->" << comments[i] << endl;
        }
    }
    cout << str;
}

void Task::closure () {
    status="close";
    close = Date ();
    priority=-1;
    achiev = 100;
}

void Task::closure_initialization (string cl) {
    status="close";
    close=cl;
    priority=-1;
    achiev=100;
}

void progress_bar (double progress)
{
    int val = (int) (progress );
    int lpad = (int) (progress / 100 * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}