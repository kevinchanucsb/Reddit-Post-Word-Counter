#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include "WordCountHelper.h"

class WordCount {
 public:
 WordCount() : wch(WordCountHelper())  {} 
  int getNumWords() const; // returns number of words in vocabulary
  
  int incrWordCount(std::string word); // if word not in vocabulary, add it.
  // then increment occurence count for that word and return the count

  // overloaded version that can take a C-string  
  int incrWordCount(const char * const word) {
    return incrWordCount(std::string(word));
  }
  
  int getWordCount(std::string word) const;
  // if word does not exist in vocabulary, return 0, otherwise return count.

  // overloaded version that can take a C-string  
  int getWordCount(const char * const word) {
    return getWordCount(std::string(word));
  }
  
  void dumpWordsSortedByWord(std::ostream &out) const;
  // dump each word,count pair as CSV to std::ostream, sorted by word

  void dumpWordsSortedByOccurence(std::ostream &out) const;
  // dump each word,count as CSV to std::ostream, sorted decreasing by occurence

  void addAllWords(std::string text);
  // parse out text into individual words, and add each word

  static bool isWordChar(char c);

  static std::string stripWord(std::string word);

 private:
  // WordCountHelper is an object that wraps the "private" parts of WordCount.
  // It allows us to "pin down" the public interface of WordCount so that this .h
  // will not change, regardless of the implementation of WordCountHelper
  
  WordCountHelper wch;
};


#endif // WORDCOUNT_H
