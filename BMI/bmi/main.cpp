/* HEADER    :
  ----------------------------------------------------------------------------//
 - DEVELOPER : Frank Gonzalez ( Haze ~ )
 - DATE : SUMMER 2014
 - LICENCES : OPEN SOURCE

// CONCEPT   :
  ----------------------------------------------------------------------------//
 -
 - PLATFORMS : DEVELOPMENT (MOBILE, DESKTOP)
 - SYSTEMS : DEVELOPMENT (MAC OS, WIN, ANDROID, iOS)

// FORMULAS  :
  ----------------------------------------------------------------------------//
 - BMI
 - BMR
 - BODY FAT

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std ;

class Person {

private:
  string Name ;
  int    Age ;
  int    Sex ;
  int    Height ;
  double Weight ;
  int    Activity ;

public:

/* DEFAULT CONSTRUCTOR
------------------------------------------------------------------------------*/
  Person() {

    Age = 0 ;
    Sex = 1 ;
    Height = 0 ;
    Weight = 0.0 ;
    Activity = 1 ;
  }

/* DEFINING SETTERS. ( MUTATORS )
------------------------------------------------------------------------------*/
  void setName(string N) {

    Name = N ;
  }

  void setAge(int A) {

    Age = (A > 0) ? A : 0 ;
  }

  void setSex(int X) {

    Sex = (X > 0) ? X : 0 ;
  }

  void setHeight(int H) {

    Height = (H > 0.0) ? H : 0 ;
  }

  void setWeight(double W) {

    Weight = (W > 0.0) ? W : 0.0 ;
  }

  void setActivity(int A) {

    Activity = A ;
  }

/* DEFINE GETTERS. ( ACCESSORS )
------------------------------------------------------------------------------*/
  string getName() const {

    return Name ;
  }

  int getAge() const {

    return Age ;
  }

  int getSex() const {

    if (Sex == 1)
      return 1 ;

    else
      return 0 ;
  }

  double getHeight() const {

    return Height ;
  }

  double getWeight() const {

    return Weight ;
  }

  int getActivity() const {

    return Activity ;
  }

/* EQUATIONS TO BE USED.
------------------------------------------------------------------------------*/
  int getC_Carbs() const {

    return getDailyEnergy() * 55/100 ;
  }

  int getG_Carbs() const {

    return ((getDailyEnergy() * 55/100) / 4) ;
  }

  int getC_Pro() const {

    return getDailyEnergy() * 15/100 ;
  }

  int getG_Pro() const {

    return ((getDailyEnergy() * 15/100) / 4) ;
  }

  int getC_Fat() const {

    return getDailyEnergy() * 30/100 ;
  }

  int getG_Fat() const {

    return ((getDailyEnergy() * 30/100) / 9) ;
  }

/* BODY MASS INDEX CALCULATOR.
------------------------------------------------------------------------------*/
  double getBMI() const {

    const int CD = 703 ;

    int BMI ;

    BMI = ((Weight * CD) / Height) / Height ;

    return BMI ;
  }

  string getCondition() const {

    if (getBMI() <= 18.5)
      return "UNDERWEIGHT!! -- " ;

    else if (getBMI() > 18.5 && getBMI() < 25)
      return  "NORMAL -- " ;

    else
      return "OVERWEIGHT!! -- " ;

  }

/* BODY FAT PERCENTAGE CALCULATOR.
------------------------------------------------------------------------------*/
  double getFat() const {

    if (Age < 12)
      return (1.51 * getBMI()) + (0.70 * Age) - (3.6 * Sex) - 1.4 ;

    else
      return (1.20 * getBMI()) + (0.23 * Age) - (10.8 * Sex) - 5.4 ;
  }

/* BASAL METABOLIC RATE CALCULATOR.
------------------------------------------------------------------------------*/
  int getBMR() const {

    int BMR ;

    if (Sex == 0)
      BMR = 655 + (4.35 * Weight) + (4.7 * Height) - (4.7 * Age) ;

    else
      BMR = 66 + (6.23 * Weight) + (12.7 * Height) - (6.8 * Age) ;

    return BMR ;
  }

/* ACTIVITY RATE DEFINITION.
------------------------------------------------------------------------------*/
  int getDailyEnergy() const {

  int Daily = 1 ;

  switch(Activity) {

    case 1 :
      Daily = getBMR() * 1.2 ;
      break ;

    case 2 :
      Daily = getBMR() * 1.375 ;
      break ;

    case 3 :
      Daily = getBMR() * 1.55 ;
      break ;

    case 4 :
      Daily = getBMR() * 1.725 ;
      break ;

    case 5 :
      Daily = getBMR() * 1.9 ;
      break ;
    }
    return Daily ;
  }
} ;


/* CLIENT PROTOTYPES.
------------------------------------------------------------------------------*/
Person Read(void) ;
void Output(Person) ;

/* CLIENT DEFINITION.
------------------------------------------------------------------------------*/
int main() {

  Person Frank ;

  Frank = Read() ;

  Output(Frank) ;

  return EXIT_SUCCESS ;
}

/* READ DEFINITION.
------------------------------------------------------------------------------*/
Person Read(void) {

  Person temp ;

  int value ;
  string word ;

  cout << "Enter the Name --------> " ;
  cin  >> word ;
  temp.setName(word) ;

  cout << "Enter the Age ---------> " ;
  cin  >> value ;
  temp.setAge(value) ;

  cout << "Enter the Sex ---------> " ;
  cin  >> value ;
  temp.setSex(value) ;

  cout << "Enter the Weight ------> " ;
  cin  >> value ;
  temp.setWeight(value) ;

  cout << "Enter the Height ------> " ;
  cin  >> value ;
  temp.setHeight(value) ;

  cout << "Enter Activity Level --> " ;
  cin  >> value ;
  temp.setActivity(value) ;

  return temp ;
}

/* OUTPUT WITH FILES AND SCREEN.
------------------------------------------------------------------------------*/
void Output(Person temp) {

  ofstream Ofile ;

  Ofile.open(temp.getName().c_str()) ;

  cout << fixed << setprecision(2) ;
  Ofile<< fixed << setprecision(2) ;

  cout << "\n\t<<< CURRENT STATE >>>" ;
  cout << "\n-------------------------------------\n" ;

  Ofile << "\n\t<<< CURRENT STATE >>>" ;
  Ofile << "\n-------------------------------------\n" ;

  cout << " NAME    : "  << temp.getName()   << endl ;
  Ofile << " NAME    : "  << temp.getName()   << endl ;

  cout << " AGE     : "  << temp.getAge()    << endl ;
  Ofile << " AGE     : " << temp.getAge()    << endl ;

  cout << " SEX     : "  << temp.getSex()    << endl ;
  Ofile << " SEX     : " << temp.getSex()    << endl ;

  cout << " Weight  : "  << temp.getWeight() << endl ;
  Ofile << " Weight  : " << temp.getWeight() << endl ;

  cout << " Height  : "  << temp.getHeight() << endl ;
  Ofile << " Height  : " << temp.getHeight() << endl ;

  cout << " BMI     : "  << temp.getBMI()    << " -- " ;
  cout << temp.getCondition() << endl ;

  Ofile << " BMI     : " << temp.getBMI()    << " -- " ;
  Ofile << temp.getCondition() << endl ;

  cout << " FAT %   : " << temp.getFat()     << endl ;
  Ofile << " FAT %   : " << temp.getFat()    << endl ;


  cout << " BMR     : " << temp.getBMR()     << endl ;
  Ofile << " BMR     : " << temp.getBMR()    << endl ;

  cout << "\n\t<<< NUTRITIONAL NEEDS >>>" ;
  cout << "\n-------------------------------------\n" ;

  Ofile << "\n\t<<< NUTRITIONAL NEEDS >>>" ;
  Ofile << "\n-------------------------------------\n" ;

  cout << " Carbs   : " << temp.getC_Carbs() << " Cal/Day -- "
       << temp.getG_Carbs() << " Grams/Day\n" ;
  Ofile << " Carbs   : " << temp.getC_Carbs() << " Cal/Day -- "
        << temp.getG_Carbs() << " Grams/Day\n" ;

  cout << " Protein : " << temp.getC_Pro()   << "  Cal/Day -- "
       << temp.getG_Pro() << "  Grams/Day\n" ;
  Ofile << " Protein : " << temp.getC_Pro()   << "  Cal/Day -- "
        << temp.getG_Pro() << "  Grams/Day\n" ;

  cout << " Fat     : " << temp.getC_Fat()   << "  Cal/Day -- "
       << temp.getG_Fat() << "  Grams/Day\n" ;
  Ofile << " Fat     : " << temp.getC_Fat()   << "  Cal/Day -- "
        << temp.getG_Fat() << "  Grams/Day\n" ;

  cout << " Total   : " << temp.getDailyEnergy() << " Cal/Day\n" ;
  Ofile << " Total   : " << temp.getDailyEnergy() << " Cal/Day\n" ;

  Ofile.close() ;
}