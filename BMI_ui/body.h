#ifndef BODY_H
#define BODY_H

#include <iostream>

class Body {
private:

  std::string Name ;
  int    Age ;
  int    Sex ;
  int    Height ;
  double Weight ;
  int    Activity ;

public:

/* DEFINING SETTERS. ( MUTATORS )
------------------------------------------------------------------------------*/
  void setName(std::string) ;
  void setAge(int) ;
  void setSex(int) ;
  void setHeight(int) ;
  void setWeight(double) ;
  void setActivity(int) ;

/* DEFINE GETTERS. ( ACCESSORS )
------------------------------------------------------------------------------*/
  std::string getName() const ;
  int getAge() const ;
  int getSex() const ;
  double getHeight() const ;
  double getWeight() const ;
  int getActivity() const ;

/* DEFINE EQUATIONS. ( ACCESSORS )
------------------------------------------------------------------------------*/
  int getC_Carbs() const ;
  int getG_Carbs() const ;
  int getC_Pro() const ;
  int getG_Pro() const ;
  int getC_Fat() const ;
  int getG_Fat() const ;
  double getBMI() const ;
  std::string getCondition() const ;
  double getFat() const ;
  int getBMR() const ;
  int getDailyEnergy() const ;

};

#endif // BODY_H
