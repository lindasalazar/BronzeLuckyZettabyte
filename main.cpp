#include<iostream>
#include<string>
using namespace std;

class GreenTea
{
private:
bool delicious;
string nameTea;
public:
void setDelicious(bool);
bool getDelicious();
void setNameTea(string);
string getNameTea();
};

void GreenTea::setDelicious(bool d)
{
  delicious = d;
}

bool GreenTea::getDelicious()
{
  return delicious;
}
void GreenTea::setNameTea(string nt)
{
  nameTea = nt;
}

string GreenTea::getNameTea()
{
  return nameTea;
}

class Student
{
private:
string name;
int id;
char letterGrade;
GreenTea preference;
public:
void setName(string);
string getName();
void setId(int);
int getId();
void setLetterGrade(char);
char getLetterGrade();
void setPreference(GreenTea);
GreenTea getPreference();
void printTranscript();
};

void Student::setName(string n)
{
  name = n;
}

string Student::getName()
{
  return name;
}

void Student::setId(int i)
{
  id = i;
}

int Student::getId()
{
  return id;
}

void Student::setLetterGrade(char lg)
{
  letterGrade = lg;
}

char Student::getLetterGrade()
{
  return letterGrade;
}

void Student::setPreference(GreenTea p)
{
  preference = p;
}

GreenTea Student::getPreference()
{
  return preference;
}

void Student::printTranscript()
{
  cout << "\nName: " << name;
  cout << "\nID: " << id;
  cout << "\nGrade: " << letterGrade;
  cout << "\nTea Name: " << preference.getNameTea();

  if(preference.getDelicious() == true)
  {
    cout << "\nWell said, McMillanite, " << preference.getNameTea() << ", green tea is great!!!" << endl;
  }
  else
  {
    cout << "\n :'(" << endl;
  }
}
void populateStudentWithDefaultData(Student &s)
{
  GreenTea ut;
  ut.setNameTea("Matcha Green Tea - China");
  ut.setDelicious(true);

  s.setName("Linda Salazar");
  s.setId(123456);
  s.setLetterGrade('F');
  s.setPreference(ut);

  cout << "Start Data: ";
  s.printTranscript();

}

void fnClass(Student student)
{
  cout << "\nA pass by value object process (least effective):";
  char newGrade = '\0';
  cout << "\nINSIDE fnClass()" << endl;
  cout << "\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
  cout << "\nWhat would like the new grade to be: ";
  cin >> newGrade;
  student.setLetterGrade(newGrade);
  cout << "\n\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
  cout << "\nUPDATED TRANSCRIPT *** pass by value ****" << endl;
  student.printTranscript();
}

void fnClassRef(Student &student)
{
  cout << "\nA pass by REFERENCE object process (Best Method):";
  char newGrade = '\0';
  cout << "\nINSIDE fnClassRef()" << endl;
  cout << "\t" << student.getId() << ":" << student.getName() << " earned a(n): " << student.getLetterGrade();
  cout << "\nWhat would like the new grade to be: ";
  cin >> newGrade;
  student.setLetterGrade(newGrade);
  cout << "\n\t" << student.getId() << ":" << student.getName() << " earned (n): " << student.getLetterGrade();
  cout << "\nUPDATED TRANSCRIPT *** pass by references (&)) ****" << endl;
  student.printTranscript();
}

void funClassPtr(Student* student)
{
  cout << "\nA pass by pointer * object process (Alternative Method):";
  char newGrade = '\0';
  cout << "\nINSIDE fnClassPtr()" << endl;
  cout << "\t" << student->getId() << ":" << student->getName() << " earned a(n): " << student->getLetterGrade();
  cout << "\nWhat would like the new grade to be: ";
  cin >> newGrade;
  student->setLetterGrade(newGrade);
  cout << "\n\t" << student->getId() << ":" << student->getName() << " earned a(n): " << student->getLetterGrade();
  cout << "\nUPDATED TRANSCRIPT *** pass by references (*)) ****" << endl;
  student->printTranscript(); 
}

int main()
{
  cout << "\nPrint Undergraduate Student" << endl;
  Student undergraduate;
  populateStudentWithDefaultData(undergraduate);

  GreenTea gt;
  gt.setNameTea("Sencha");
  gt.setDelicious(false);

  Student graduate;
  graduate.setId(1587);
  graduate.setName("Cool Dude");
  graduate.setLetterGrade('C');
  graduate.setPreference(gt);

  cout << "\nPrint Graduate Student" << endl;
  cout << "Start Data: ";
  graduate.printTranscript();

  cout << "\nI Say again..." << endl;
  if(graduate.getPreference().getDelicious() == true)
  {
    cout << "\nWell said, Mcmillanite, " << graduate.getPreference().getNameTea() << ", green tea is great!!!" << endl;
  }
  else
  {
    cout << "\n :'(" << endl;
  }

  fnClass(undergraduate);
  fnClass(graduate);
  fnClassRef(undergraduate);
  fnClassRef(graduate);
  funClassPtr(&undergraduate);
  funClassPtr(&graduate);

  
  return 0;
}