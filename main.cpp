#include <vector>
#include <iostream>
using namespace std;

const int NUM_ELEMENTS = 3;

void printSubSet (vector<int> &subSet) {
   cout << "{";
   for (int i = 0; i < subSet.size(); ++i) {
      if (i < subSet.size() - 1) {
         cout << subSet[i] << ",";
      } else {
         cout << subSet[i];
      }
   }
   cout << "}";
   
}

void makePower(int set[NUM_ELEMENTS], vector<int>& subSet, int index = -1) {

   if (index == NUM_ELEMENTS) {
      return;
   }

   printSubSet(subSet);
   
   for (int i = index + 1; i < NUM_ELEMENTS; ++i) {
      cout << ", ";
      subSet.push_back(set[i]);
      makePower(set, subSet, i);
      subSet.pop_back();
   }
   return;
}

int main() {
   int set[NUM_ELEMENTS];
   vector<int> subSet;
   cout << "Initial Set: {";
   for (int i = 1; i <= NUM_ELEMENTS; ++i) {
      set[i-1] = i;
      if (i != NUM_ELEMENTS) {
        cout << i << ", ";
      } else {
        cout << i;
      }
   }
   cout << "}" << endl;
   cout << "Power set size = " << pow(2, NUM_ELEMENTS) << endl;
   cout << "{ ";
   makePower(set, subSet);
   cout << " }" << endl;
   return 0;
}