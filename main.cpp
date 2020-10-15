#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "tasks.h"
#include "TODO_list.h"
#include "fonction.h"
using namespace std;

int main(int argc, char** argv) {
    vector<string> extraction;
    string file;
    vector<string> string_vec = char_to_string_vec(argc, argv);
    To_Do To_Do_list;
    int i = 1;
    
    if (string_vec.size() > i && string_vec[i] == "--file") {
        i++;
        file = string_vec[i];
        i++;
    }
    else {
        file = "list.todo";
    }
    if (string_vec.size() > i-1 && string(argv[i]) == "del")  {
            del(file);
            i++;
    }
    else {
        extraction = extract(file);
        To_Do_list = initialization(extraction);
    }
    while (i<string_vec.size()) {
        if (string_vec[i] == "print") {
            if (i+1<string_vec.size() && string_vec[i+1] == "--priority") {
                i=i+2;
                To_Do_list.print(stoi(string_vec[i]));
                i++;
            }
            else {
                To_Do_list.print(0);
                i++;
            }
            continue;
        }
        if (string_vec[i] == "add") {
            int j = i;
            string date = add(string_vec, To_Do_list, i);
            write(file,string_vec,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(file,word,0,1);
            write_string(file,date);
            continue;
        }
        if (string_vec[i] == "close") {
            int j = i;
            string date = close(string_vec, To_Do_list, i);
            write(file,string_vec,j,i-j);
            vector<string> word {};
            word.push_back("--date");
            write(file,word,0,1);
            write_string(file,date);
            continue;
        }
        if (string_vec[i] == "del") {
            del(file);
            i += 1;
            To_Do list {};
            continue;
        }
        if (string_vec[i] == "comments") {
            int j = i;
            comments(string_vec, To_Do_list, i);
            write(file,string_vec,j,i-j);
            continue;
        }
        if (string_vec[i] == "change") {
            int j = i;
            change(string_vec, To_Do_list, i);
            write(file,string_vec,j,i-j);
            continue;
        }
    }
    return 0;
};