#include "WordCount.h"
#include <string>

int WordCount::getNumWords() const {
  // returns number of words in vocabulary
  // @@@ likely invokes some method on this->wch
  // @@@ such as this->wch.getNumWords()
  return this->wch.getNumWords(); // @@@ stub
}
  
int WordCount::incrWordCount(std::string word) {
  // if word not in vocabulary, add it.
  // then increment occurence count for that word and return the count

  // @@@ likely consists only of something like:
  // @@@ return this->wch.incrWordCount(word);
  return this->wch.incrWordCount(word); // @@@ stub

}

int WordCount::getWordCount(std::string word) const {
  // if word does not exist in vocabulary, return 0
  // otherwise return count of that word
  
  // @@@ likely invokes the following:
  // @@@ return this->wch.getWordCount(word)

  return this->wch.getWordCount(word); // @@@ stub
}
  
void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
  // dump each word,count pair as CSV to ostream, sorted by word

  // likely invokes the following:
  // @@@ this->wch.dumpWordsSortedByWord(out);

  return this->wch.dumpWordsSortedByWord(out); // @@@ stub that does nothing
}
  
void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const { 
  // dump each word,count as CSV to ostream, sorted decreasing by occurence
  // dump each word,count pair as CSV to ostream, sorted by word
  // @@@ likely invokes the following:
  // @@@ this->wch.dumpWordsSortedByOccurnce(out);

  return this->wch.dumpWordsSortedByOccurence(out); // @@@ stub that does nothing
}

void WordCount::addAllWords(std::string text) {
  // Parse out text into individual words, and add each word
  // You should throw away punctuation EXCEPT for ' and - that occur in the
  // middle of words, e.g. don't, isn't, O'Brien, mother-in-law, should
  // all be treated as single words with the ' and/or - as part of the word.

  // @@@ likely implemented as
  // @@@ this->wch.addAllWords(text);
  
  return this->wch.addAllWords(text); // @@@ stub that does nothing

}
std::string WordCount::stripWord(std::string word){
  return WordCountHelper::stripWord(word);
}
bool WordCount::isWordChar(char c) {
  return
    (c >=65 && c <= 90) ||   // upper case
    (c >=97 && c <= 122) || //lower case
    (c == 32)|| //space
    (c == 45) ||
    (c >=48 && c <= 57 );    // digits
}

