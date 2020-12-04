// solution to https://www.hackerrank.com/challenges/attribute-parser/problem

// other solutions, see the leaderboard of above problem. I also have downloaded some-
// hackerrank_attribute_parser_copy_1.cpp

#include "stdc++.h"

using namespace std;

struct Attr {
    string name;
    string value;
};

struct Tag {
    string name;
    vector<Attr> attributes;
    vector<Tag> child;
};

void processTags(vector<Tag> *tags, Tag *parent, int *lines) {
    if(*lines == 0) {
        return;
    }
    string str;
    vector<string> tokens;

    *lines = *lines - 1;

    getline(cin, str);
    stringstream stream(str);
    string s;
    while(getline(stream, s, ' ')) {
        if(*s.begin() == '=') {
           continue;
        }
        if(*s.begin() == '<') {
            s.erase(s.begin(), s.begin() + 1);
        }
        if(*s.begin() == '"') {
            s.erase(s.begin(), s.begin() + 1);
        }
        if(*(s.end()-1) == '>') {
            s.erase(s.end()-1, s.end());
        }
        if(*(s.end() - 1) == '"') {
            s.erase(s.end()-1, s.end());
        }
        tokens.push_back(s);
    }
    if(*(tokens[0].begin()) == '/') {
        return;
    }
    Tag tagEntry;
    tagEntry.name = tokens[0];
    for (vector<string>::iterator itr = tokens.begin() + 1; itr != tokens.end(); itr = itr+2)
    {
        Attr attribute;
        attribute.name = *itr;
        attribute.value = *(itr + 1);
        (tagEntry.attributes).push_back(attribute);
    }
    processTags(tags, &tagEntry, lines);
    if(parent == NULL) {
        (*tags).push_back(tagEntry);
    } else {
        ((*parent).child).push_back(tagEntry);
    }
    if(*lines != 0) {
            processTags(tags, parent, lines);
        }
    return;
}

void coutSpaces(int length) {
    for (int i = 0; i < length; ++i)
    {
        cout << " ";
    }
}

void coutTabs(int length) {
    for (int i = 0; i < length; ++i)
    {
        cout << "\t";
    }
}


void printTag(Tag tag, int length) {
    coutTabs(length);
    cout << tag.name << endl;
    for(vector<Attr>::iterator i = tag.attributes.begin(); i != tag.attributes.end(); i++) {
        coutTabs(length);
        cout << (*i).name << " = " << (*i).value;
        if(i != tag.attributes.end() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    for (vector<Tag>::iterator i = tag.child.begin(); i != tag.child.end(); i++)
    {
        printTag(*i, length + 1);
    }
}

void processQuery(vector<Tag> tags) {
    string query;
    getline(cin, query);
    string s;
    vector<string> tokens;
    stringstream stream(query);
    while(getline(stream, s, '~')) {
        tokens.push_back(s);
    }
    if(tokens.size() < 2) {
        cout << "Not Found!" << endl;
        return;
    }
    string attribute = tokens[1];
    string queryTags = tokens[0];
    stringstream stream2(queryTags);
    vector<string> tagsVector;
    while(getline(stream2, s, '.')) {
        tagsVector.push_back(s);
    }
    if(tagsVector.size() == 0) {
        tagsVector.push_back(queryTags);
    }
    vector<Tag> current = tags;
    vector<Attr> attributes;
    for (vector<string>::iterator itr = tagsVector.begin(); itr != tagsVector.end(); itr++)
    {
        bool found = false;
        for (vector<Tag>::iterator i = current.begin(); i != current.end(); i++)
        {
            cout << (*i).name << endl;
            cout << *itr << endl;
            cout << (*itr).compare((*i).name) << endl;
            if((*itr).compare((*i).name) == 0) {
                found = true;
                if(itr == tagsVector.end() - 1) {
                    attributes = (*i).attributes;
                }
                current = (*i).child;
                break;
            }
        }
        if(!found) {
            cout << "Not Found!" << endl;
            return;
        }
    }
    for (vector<Attr>::iterator itr = attributes.begin(); itr != attributes.end(); itr++)
    {
        if(((*itr).name).compare(attribute) == 0){
            cout << (*itr).value << endl;
            return;
        }
    }
    cout << "Not Found!" << endl;
}

int main() {
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<Tag> tags;
    processTags(&tags, NULL, &n);

    // for (vector<Tag>::iterator itr = (tags).begin(); itr != (tags).end(); itr++)
    // {
    //     printTag(*itr, 0);
    // }

    while(q--) {
        processQuery(tags);
    }

    return 0;
}
