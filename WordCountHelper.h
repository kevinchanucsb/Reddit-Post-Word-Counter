#ifndef WORDCOUNTHELPER_H
#define WORDCOUNTHELPER_H
#include <string>
#include <iostream>
#include <vector>

class WordCountHelper {
 public:
  int getNumWords() const;
  void addAllWords(std::string text);
  int incrWordCount(std::string word);
  int getWordCount(std::string word) const;
  void dumpWordsSortedByWord(std::ostream &out)const;
  void dumpWordsSortedByOccurence(std::ostream &out)const;
  static std::string stripWord(std::string word);
  static bool isWordChar(char c);
  //vocab class that includes constructors, member variables, and helper functions
  class vocab{
    int count;
    std::string word;
  public:
    //default constructor for vocab
    vocab(){
      count=0;
      std::string word="";
    }
    //initializing constructor for vocab
    vocab(const std::string &word):count(1), word(word){}
    
    
    int incr(){
      count++;
      return count;
    }
    int getCount()const{
      return count;
    }
    std::string getWord()const{
      return word;
    }
    //sortInts compares counts of v1 and v2 of vector type vocab
    static bool sortInts(const vocab& v1, const vocab& v2){
      return(v2.count < v1.count);
    }
    //sortWords compares words of v1 and v2 alphabetically
    static bool sortWords(const vocab& v1, const vocab& v2){
      return(v1.getWord() < v2.getWord());
    }
 };
    
      

 
 private:
  // @@@ YOU DECIDE.   This is where you really implement the class
  std::vector<vocab>wordcount;
};


#endif // WORDCOUNTHELPER_H
