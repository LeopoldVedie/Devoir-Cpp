#include "fonction.h"
using namespace std;

vector<string> char_to_string_vec (int argc, char** argv) {
    vector<string> string_vec {};
    for (int i {}; i<argc; i++) {
        string_vec.push_back(argv[i]);
    }
    return string_vec;
}

vector<string> extract (string file) {
    ifstream ifs;
    ifs.open(file);
    vector<string> extr {};
    string line;
    while (getline(ifs, line)) {
        extr.push_back(line);
    }
    cout << endl;;
    ifs.close();
    return extr;
}

void write (string file, const vector<string> & argv, int i, int nb) {
    ofstream ofs;
    ofs.open(file,ofstream::out | ofstream::app);
    for (int j = 0; j<nb; j++) {
        ofs << argv[i+j] << endl;
    }
    ofs.close();
}

void write_string (string file, const string & str){
    ofstream ofs;
    ofs.open(file,ofstream::out | ofstream::app);
    ofs << str << endl;
    ofs.close();
}


To_Do initialization (const vector<string> & string_vec) {
    To_Do list; 
    int argc = string_vec.size();
    int i = 0;
    while (i<argc) {
        if (string_vec[i] == "add") {
            add_initialization(string_vec, list, i);
            continue;
        }
        if (string_vec[i] == "close") {
            close_initialization(string_vec, list, i);
            continue;
        }
        if (string_vec[i] == "change") {
            change(string_vec, list, i);
            continue;
        }
        if (string_vec[i] == "comments") {
            comments(string_vec, list, i);
            continue;
        }
    }

    return list;
};

void add_initialization (const vector<string> &  string_vec, To_Do & list, int & i) {
    string title = "Title missing";
    string description = "Description missing";
    string opening_date;
    int id;
    int p = 0;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--title") {
            i++;
            title = string_vec[i];
            i++;
            continue;
        }
        if (string_vec[i] == "--description") {
            i++;
            description = string_vec[i];
            i++;
            continue;
        }
        if (string_vec[i] == "--priority") {
            i++;
            p = stoi(string_vec[i]);
            i++;
            continue;
        }
        if (string_vec[i] == "--date") {
            i++;
            opening_date = string_vec[i];
            i++;
            
            continue;   
        }
        i++;
    }
    list.add_initialization(title, description, p, opening_date);
}

void close_initialization (const vector<string> & string_vec, To_Do & list, int & i) {
    string closure_date;
    int id;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--date") {
            i++;
            closure_date = string_vec[i];
            i++;
            continue;   
        }
        if (string_vec[i] == "--id") {
            i++;
            id = stoi(string_vec[i]);
            i++;
            continue;
        }
        i++;
    }
    list.close_initialization(id, closure_date);
}


string add (const vector<string> & string_vec, To_Do & list, int & i) {
    string title = "Title missing";
    string description = "Description missing";
    int id;
    int p = 0;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--title") {
            i++;
            title = string_vec[i];
            i++;
            continue;
        }
        if (string_vec[i] == "--description") {
            i++;
            description = string_vec[i];
            i++;
            continue;
        }
        if (string_vec[i] == "--priority") {
            i++;
            p = stoi(string_vec[i]);
            i++;
            continue;
        }
        i++;
    }
    string date;
    date = list.add_To_Do(title, description, p);
    return date;
}

string close (const vector<string> & string_vec, To_Do & list, int & i) {
    int id;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--id") {
            i++;
            id = stoi(string_vec[i]);
            i++;
            continue;
        }
        i++;
    }
    string date;
    date = list.close(id);
    return date;
}

void change (const vector<string> & string_vec, To_Do & list, int & i) {
    int id;
    int func {};
    int p {};
    int ac {};
    string t ;
    string descrip;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--priority") {
            i++;
            p = stoi(string_vec[i]);
            i++;
            continue;
        }
        if (string_vec[i] == "--achiev") {
            i++;
            ac = stoi(string_vec[i]);
            func = 1;
            i++;
            continue;
        }
        if (string_vec[i] == "--title") {
            i++;
            t = string_vec[i];
            func = 2;
            i++;
            continue;
        }
        if (string_vec[i]== "--description"){
            i++;
            descrip = string_vec[i];
            func = 3;
            i++;
            continue;
        }    
        if (string_vec[i] == "--id") {
            i++;
            id = stoi(string_vec[i]);
            i++;
            continue;
        }
        i++;
    }
    switch (func){
        case 0:
            list.change_priority(id,p);
            break;
        case 1:
            list.change_achiev(id,ac);
            break;
        case 2:
            list.change_title(id,t);
            break;
        case 3:
            list.change_description(id,descrip);
            break;
    }
}

void comments (const vector<string> & string_vec, To_Do & list, int & i) {
    string comments;
    int id;
    i++;
    while ((i<string_vec.size()) && (string_vec[i][0]=='-' && string_vec[i][1]=='-')) {
        if (string_vec[i] == "--comments") {
            i++;
            comments = string_vec[i];
            i++;
            continue;
        }
        if (string_vec[i] == "--id") {
            i++;
            id = stoi(string_vec[i]);
            i++;
            continue;
        }
        i++;
    }
    list.add_comments(id, comments);
}

void del (string file) {
    remove(file.c_str());
};