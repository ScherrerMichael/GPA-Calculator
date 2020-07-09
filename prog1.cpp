/*Name: Michael Scherrer
 *Class: CS162
 *Instructor: Karla Fant
 *
 *Program Name: Program #1, GPA calculator

 welcome user
1 prompt the user for number of terms
2 prompt the user for number of classes taken for the term
3 ask the user for the letter grade for a class
4 prompt the user for the input of credit hours for that class
5 repeat step 4 until all classes are accounted for
6 repeat step 2 until all terms are accounted for
7 calculate GPA
8 calculate cululative GPA 
9 print out results
10 show options to the user after calculations are made






 
*/

#include <iostream>
using namespace std;

int main()
{// begin main

	char response;              //  response that the user will give
	int terms;                  //  number of terms the user will have
	int classes;                //  number of classes taken a terms
	char grade;                 //  grade as a character
	double grade_value;         //  grade value to be used in calculation
	double hours;               //  hours to display credit hours
	double gpa;                 //  gpa calculations to use for display
	double term_qualityPoints;  //  total quality points for a term
	double term_hours;          //  total hours for a term
	double total_qualityPoints; //  total quality points for all terms
	double total_hours;         //  total hours for all terms
 do
 {// begin welcome loop & also initialize variables to default values (in case the user resets)


	 response = '\0';
	 terms = '\0';           
	 classes = '\0';         
	 grade = '\0';           
	 grade_value = 0;        
	 hours = 0;              
	 gpa = 0;                
	 term_qualityPoints = 0; 
	 term_hours = 0;         
	 total_qualityPoints = 0;
	 total_hours = 0;         

  cout <<"Welcome! To the GPA calculator" << endl;
 
  do
  { // beginning of response loop
  
   cout <<"Please enter the amount of terms you are ";
   cout <<"taking or plan to take (positive whole number): ";
   
   cin  >> response;
   cin.ignore(100,'\n');

   while(response < 1 ||  isalpha(response))
   { // beginning of term response error loop
    cout <<"Please enter a valid number terms!";
    cin >> response;
    cin.ignore(100,'\n');
   } // end of term response error loop

   cout <<"You entered: " << response << " terms. Is this correct? (y/n): ";

   terms = (int)response - 48;
   cin >> response;
   cin.ignore(100,'\n');
   cout<<endl;

  }while('y' != response); // end of response loop
  
  	//begin asking for term information//

  response = '\0';

  for(int i=0; i < terms; ++i)
  {// begin term information loop
   cout << "///////////////////////" <<endl;
   cout << "      Term "<< i+1 <<" " <<endl;
   cout << "///////////////////////" <<endl;
   do
   {// begin class information loop
    cout <<"How many classes are you taking for term " << i+1 << "?: ";
    
    cin  >> response;
    cin.ignore(100,'\n');
    while(response < 1 ||  isalpha(response))
    { // begin class response loop
     cout <<"Please enter a valid number classes!";
     cin >> response;
     cin.ignore(100,'\n');
    } // end of class response loop
    cout <<"You entered: " << response << " classes. Is this correct? (y/n): ";
    classes = (int)response - 48; // this changes the char value to an integer
    cin >> response;
    cin.ignore(100,'\n');
    cout<<endl;
   }while('y' != response);// end of class information loop

	//begin asking for grade information ie amount, letter grade etc.//

   for(int k = 0; k < classes; ++k)
   {// begin class grade information loop
    do
    {// begin class grade response loop
      cout << "What is the letter grade for class " << k+1 << " term " << i+1 <<"? (type \"h\" for help):";

      cin  >>response;
      cin.ignore(100,'\n');
      response = toupper(response);
      grade = toupper(response);
      cout<<endl;


      if(response == 'A')
       grade_value = 4.00;
      else if(response == 'B')
       grade_value = 3.00;
      else if(response == 'C')
       grade_value = 2.00;
      else if(response == 'D')
       grade_value = 1.00;
      else if(response == 'F')
       grade_value = 0.00;
      else if(response == 'H')
      {
       cout <<"               HELP:" <<endl;
       cout <<"you may enter the values: A, B, C, D, F"<<endl;
       cout <<"also you may enter N or P for pass/no pass."<<endl;
       cout <<"NOTE: pass/no pass grades are not included in"<<endl;
       cout <<"the calculation of gpa!"<<endl;
       cout <<"(grades are not case sensitive)." <<endl <<endl;
      }
      else if(response == 'P')
       grade_value = -1;
      else if(response == 'N')
       grade_value = -2;
      else
       cout <<"Please enter a valid input ex. (A,B,C,D,F,P,N) also \"h\" for help" << endl;
      
    }while(response != 'A' && response != 'B' && response != 'C'
      		  && response != 'D' && response != 'F' 
      		  && response != 'N' && response != 'P');// end of class grade response loop
      
    if(grade_value >= 0)
    {
     cout <<"Is there a + or - ?   (indicate +,-,n): ";
     cin >> response;
     cin.ignore(100,'\n');
     cout <<endl;
    if(response == '+' && grade_value < 4.00)
     grade_value = grade_value + 0.33;
    else if(response == '-' && grade_value > 0.00)
     grade_value = grade_value - 0.33;
    else
     cout <<"No extra grade value detected" <<endl;
    }
    
     cout <<"How many credit hours for this class? (positive whole number): ";
     cin >> hours;
     cin.ignore(100,'\n');
    
    if(grade_value == -1)
    {
     cout <<endl;
     cout <<"****************" <<endl;
     cout <<"CLASS#  " << k+1 <<endl;
     cout<<"TERM:   " << i+1 <<endl;
     cout<<"GRADE:  Pass" <<endl;
     cout <<"HOURS:  " << hours <<endl;
     cout <<"****************" <<endl;
    }
    else if(grade_value == -2)
    {
     cout<<endl;	 
     cout <<"****************" <<endl;
     cout <<"CLASS#  " << k+1 <<endl;
     cout<<"TERM:   " << i+1 <<endl;
     cout<<"GRADE:  No Pass"<<endl;
     cout <<"HOURS:  " << hours <<endl;
     cout <<"****************" <<endl;
    }
    else
    {
     cout<<endl;
     cout <<"****************" <<endl;
     cout <<"CLASS#  " << k+1 <<endl;
     cout<<"TERM:   " << i+1 <<endl;
     cout<<"GRADE:  " << grade_value <<endl;
     cout <<"HOURS:  " << hours <<endl;
     cout <<"****************" <<endl;
    }
    
    if(grade_value >= 0)
    {
     term_qualityPoints += (double)(grade_value * hours);
     term_hours += hours;
    }
      	
   }// end of class grade information loop
   
    total_qualityPoints+= (double)term_qualityPoints;
    total_hours+= term_hours;
   
   
    cout<<endl <<"Term " << i+1 <<" GPA: " << (term_qualityPoints / term_hours);
    cout <<endl;
    cout <<endl;
    
    term_qualityPoints = 0;
    term_hours = 0;

  }// end term information loop

  if(terms > 1)
  {
   cout <<endl <<"Cumulatitive GPA: " << (total_qualityPoints / total_hours) <<endl;
   cout<<endl;
  }
  
  cout <<"Would you like to restart the program? (type r to restart): ";
  cin >> response;
  response = toupper(response);
  cin.ignore(100,'\n');

  // create blank spaces for next calculator//
  for(int i = 0; i < 200; ++i) 
  {
   cout <<endl;
  }


 }while(response == 'R');// end of welcome loop
  cout<<"                           Goodbye!  " <<endl;
  cout<< endl;
  return 0;
}// end main
