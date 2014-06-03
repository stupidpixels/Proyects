#include "body.h"

/* DEFINING SETTERS. ( MUTATORS )
------------------------------------------------------------------------------*/
  void Body::setName(std::string N) {

      Name = N ;
  }

  void Body::setAge(int A) {

      Age = (A > 0) ? A : 0 ;
  }

  void Body::setSex(int X) {

      Sex = (X > 0) ? X : 0 ;
  }

  void Body::setHeight(int H) {

      Height = (H > 0.0) ? H : 0 ;
  }

  void Body::setWeight(double W) {

      Weight = (W > 0.0) ? W : 0.0 ;
  }

  void Body::setActivity(int A) {

      Activity = A ;
  }

/* DEFINE GETTERS. ( ACCESSORS )
------------------------------------------------------------------------------*/
  std::string Body::getName() const {

      return Name ;
  }

  int Body::getAge() const {

      return Age ;
  }

  int Body::getSex() const {

      return Sex ;
  }

  double Body::getHeight() const {

      return Height ;
  }

  double Body::getWeight() const {

      return Weight ;
  }

  int Body::getActivity() const {

      return Activity ;
  }

/* DEFINE EQUATIONS. ( ACCESSORS )
------------------------------------------------------------------------------*/
  int Body::getC_Carbs() const {

      return getDailyEnergy() * 55/100 ;
  }

  int Body::getG_Carbs() const {

    return ((getDailyEnergy() * 55/100) / 4) ;
  }

  int Body::getC_Pro() const {

    return getDailyEnergy() * 15/100 ;
  }

  int Body::getG_Pro() const {

    return ((getDailyEnergy() * 15/100) / 4) ;
  }

  int Body::getC_Fat() const{

    return getDailyEnergy() * 30/100 ;
  }

  int Body::getG_Fat() const{

    return ((getDailyEnergy() * 30/100) / 9) ;
  }

  double Body::getBMI() const {

    const int CD = 703 ;

    return ((Weight * CD) / Height) / Height ;
  }

  std::string Body::getCondition() const {

    if (getBMI() <= 18.5)
      return "UNDERWEIGHT!! -- " ;
    else if (getBMI() > 18.5 && getBMI() < 25)
      return  "NORMAL -- " ;
    else
      return "OVERWEIGHT!! -- " ;
  }

  double Body::getFat() const {

    if (Age < 12)
      return (1.51 * getBMI()) + (0.70 * Age) - (3.6 * Sex) - 1.4 ;
    else
      return (1.20 * getBMI()) + (0.23 * Age) - (10.8 * Sex) - 5.4 ;
  }

  int Body::getBMR() const {

    if (Sex == 0)
      return 655 + (4.35 * Weight) + (4.7 * Height) - (4.7 * Age) ;
    else
      return 66 + (6.23 * Weight) + (12.7 * Height) - (6.8 * Age) ;
  }

  int Body::getDailyEnergy() const {

    if (Activity == 1)
      return getBMR() * 1.2 ;

    else if (Activity == 2)
      return getBMR() * 1.375 ;

    else if (Activity == 3)
      return getBMR() * 1.55 ;

    else if (Activity == 4)
      return getBMR() * 1.725 ;

    else
      return getBMR() * 1.9 ;
}

