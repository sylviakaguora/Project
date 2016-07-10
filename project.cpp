#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Subject{
  std::vector< class Observer *> observers;
  std::string text; 
public:
  void attach(Observer * obs){
    observers.push_back(obs);
  }
  void setString(std::string string_text){
    text = string_text;
    notify();
  }
  std::string getString(){ return text; }
  void notify();
};

class Observer{
  Subject* subject;
  
public:
  Observer(Subject* subject)
    : subject(subject){
    subject->attach(this); 
  }
  virtual void update() = 0;
protected:
  Subject* getSubject(){ return subject; }
};


class CharacterSubject : public Subject{
  //Concrete subject for CharacterObserver
};

class CharacterObserver : public Observer{
public:
  CharacterObserver(CharacterSubject* subj)
    : Observer(subj) {}
  void update(){ 
    std::string text = getSubject()->getString();   
    const int size =text.length();
    std::cout << text <<" has " << size << " characters";
  }
};

void Subject::notify(){ 
  for(auto obs: observers)
    (obs)->update();
}

class WordSubject : public Subject{
  //Concrete subject for WordObserver
};

class WordObserver : public Observer{
public:
  WordObserver(WordSubject* subj)
   : Observer(subj){}
   void update(){
     std::string text = getSubject()->getString();
     int noOfSpaces = 0;
     int i;
        for (i = 0; i < (text.length() - 1); i++)
        {
          if (std::isspace(text.at(i)))
          {
            noOfSpaces++;
            //Deal with double spaces
            while (std::isspace(text.at(i)) && std::isspace(text.at(i++)))
              if (text.at(i) == '\0')
                noOfSpaces--;
          }
        }
      //To deal with the intial space
        noOfSpaces++;
     std::cout << " and " << noOfSpaces << " words." << std::endl;
   }
};


using namespace std;
int main(){
  CharacterSubject cSubj;
  WordSubject subj;
  
  CharacterObserver character(&cSubj);
  WordObserver words(&subj);

  void saveToFile(std::string, std::string);
  std::string openFile(std::string);
  std::string editFile();
  
  string myFile;
  std::cout << "Give your file a name: ";
  getline(cin, myFile);
  
  saveToFile(editFile(), myFile);

  cSubj.setString(openFile(myFile));
  subj.setString(openFile(myFile));

  std::cout << "======================================" << std::endl << "Would you like to keep editing? [Y or N]"
    << std::endl << "=====================================" << std::endl;

  char choice;
  std::cin >> choice;
  if (choice == 'y' || choice == 'Y'){
    saveToFile(editFile(), myFile);
  } else {
    std::cout << "File saved!";
    subj.setString(openFile(myFile));
  }
  return 0;
}

std::string editFile(){
  std::string myText;
  std::cout << "===================================" << std::endl << "Press return to close and save file!"
  << std::endl << "==================================="  << std::endl << "Please enter the text you wish to write to the file: " << std::endl;
  getline(cin, myText);
  return myText;
}

void saveToFile(std::string textToFile, std::string fileName){
  ofstream newFile(fileName+".txt", ios::out | ios::app);

   if (newFile.is_open())
  {
    newFile << textToFile;
    newFile.close();   
  } else 
    std::cout << "Unable to open file!"; 
}

std::string openFile(std::string fileToOpen){
  std::string line;

  ifstream myFile(fileToOpen+".txt");
  if (myFile.is_open()){
    getline(myFile, line);
    myFile.close();
  } else 
  std::cout << "Unable to open file!";

  return line;  
}