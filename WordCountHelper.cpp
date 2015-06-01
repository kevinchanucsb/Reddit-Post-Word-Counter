#include "WordCountHelper.h"
#include <algorithm>
#include <sstream>
#include "WordCount.h"
//Returns the size of vector "wordcount"
int WordCountHelper::getNumWords()const{
  return wordcount.size();
}
//Increases the count of occurrences of "word" by 1 if found, if not, the count of new word is 1
int WordCountHelper::incrWordCount(std::string word){
  for (size_t i=0; i<wordcount.size(); i++){
    if (wordcount[i].getWord()==word){
      return wordcount[i].incr();
    }
  }
  wordcount.emplace_back(word);
  return 1;
}
//Returns the number of occurrences of specific "word" if found, if not, returns 0
int WordCountHelper::getWordCount(std::string word)const{
  for (size_t i=0; i<wordcount.size();i++){
    if (wordcount[i].getWord()==word){
      return wordcount[i].getCount();
    }
  }
  return 0;
}
//Creates a copy of vector "wordcount" named temp and alphabetically sorts the objects in copied vector using pre-defined sortWords (from .h)
void WordCountHelper::dumpWordsSortedByWord(std::ostream &out)const{
  std::vector<vocab>temp(wordcount);
  std::sort(temp.begin(), temp.end(), vocab::sortWords);
  for (size_t i=0; i<wordcount.size();i++){
    out<< temp[i].getWord()<<","<<temp[i].getCount()<<std::endl;
  }
  return;
}
//Creates a copy of vector "wordcount" named temp and numerically sorts the objects in copied vector using pre-defined sortInts (from .h) and stable_sort (from stl), to NOT change the order of objects if the # of occurrences is the same
void WordCountHelper::dumpWordsSortedByOccurence(std::ostream &out)const{
  std::vector<vocab>temp(wordcount);
  std::sort(temp.begin(), temp.end(), vocab::sortWords);
  std::stable_sort(temp.begin(), temp.end(), vocab::sortInts);
  for (size_t i=0; i<wordcount.size(); i++){
    out<< temp[i].getWord()<<","<<temp[i].getCount()<<std::endl;
    }
  return;
}
//Given text of words separated by spaces, iss streams text into a newly declared string "word", and stripWord strips each word that is streamed into new string "word"
void WordCountHelper:: addAllWords(std::string text){
  std::string word;
  std::istringstream iss(text);
  while (iss>>word){
    incrWordCount(stripWord(word));
  }
  return;
}


std::string WordCountHelper::stripWord(std::string word) { 
  int count = 0;
  // return the word with any "non-word characters" from start and end removed
   while (!WordCount::isWordChar(word[count])){
    word.erase(0,1);
    
  }
  count = word.size()-1;
  while (!WordCount::isWordChar(word[count])){
    word.erase(count);
    count--;
  }
  return word;
}
