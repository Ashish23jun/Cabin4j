#include <iostream>
#include <string>
using namespace std;

int main() {
  string sentence;
  getline(cin, sentence);

  string keywords[] = {"good", "great", "excellent", "happy", "positive", "love"};
  int nKeywords = sizeof(keywords) / sizeof(keywords[0]);

  bool Positive = false, Negative = false;
  for (int i = 0; i < nKeywords; i++) {
    if (sentence.find(keywords[i]) != string::npos) {
      Positive = true;
      break;
    }
  }

  if (!Positive) {
    string NKeywords[] = {"bad", "terrible", "horrible", "sad", "negative", "hate", "dislike"};
    int numNkeywords = sizeof(NKeywords) / sizeof(NKeywords[0]);
    for (int i = 0; i < numNkeywords; i++) {
      if (sentence.find(NKeywords[i]) != string::npos) {
        Negative = true;
        break;
      }
    }
  }

 
  if (Positive) {
    cout << "Positive";
  } else if (Negative) {
    cout << "Negative";
  } else {
    cout << "Neutral";
  }
  cout << endl;

  return 0;
}
