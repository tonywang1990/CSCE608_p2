/* Global utility functions and objects, also defines general inlcude libs*/
#ifndef UTILITY
#define UTILITY

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<iterator>
#include<cstdlib>
#include<ctime>
#include "Block.h"
#include "Config.h"
#include "Disk.h"
#include "Field.h"
#include "MainMemory.h"
#include "Relation.h"
#include "Schema.h"
#include "SchemaManager.h"
#include "Tuple.h"

#include<vector>
#include<ctype.h>
#include<cassert>
#include<queue>


using namespace std;

// list of node types
enum TYPE{SELECT, PROJECT, PRODUCT, JOIN, THETA, DISTINCT, SORT, LEAF}; 

// Node class
class Node{
public:
	TYPE type;
	vector<string> param;
	Relation* view;
	vector<Node*> children;
	Node(TYPE t, vector<string> p): type(t), param(p), view(NULL){
	}
	Node(TYPE t): type(t), view(NULL){
	}
};


// free blocks in memory
extern queue<int> free_blocks;
// map of type and its name
extern map<TYPE, string> T;


// global utiltity functions
void initMapT();

string strip(string &str);

template <class T>
void print(vector<T> V){
	for (int i = 0; i < V.size(); i++){
		cout<<V[i]<<" ";
	}
	cout<<endl;
};

vector<string> splitBy(string str, string delimiter);

void resetFreeBlocks();

void appendTupleToRelation(Relation* relation_ptr, MainMemory& mem, Tuple& tuple);

bool eval(vector<string> postfix, Tuple &left, Tuple &right);
int opType(string x);
string findValBinary(string name, Tuple &left, Tuple &right);
string findVal(string name, Tuple &T);
#endif
