#ifndef ALISTINT_H
#define ALISTINT_H

class AListInt
{
 public:
  int* list;


//****************************** constructors*********************************
  AListInt();   
  AListInt(int cap);
 
  //*************************** Destructor**************************************
  ~AListInt();

  //****************** Returns the current number of items in the list *********
 
  int size() const;
  
  // *****************Returns true if the list is empty, false otherwise********
   
  bool empty() const;

  //********************** Inserts val so it appears at index, pos**************
   
  void insert (int pos, const int& val);

  //***********************Removes the value at index, pos*******************
 
  void remove (int pos);

  /****************Overwrites the old value at index, pos, with val********** */

  void set (int position, const int& val);

  /************************ Returns the value at index, pos***********************/

  int& get (int position) ;

  /*************************** Returns the value at index, pos**************/
  int const & get (int position) const;

   int is_filled();
  
 private:
  /***************Should double the size of the list maintaining its contents****/
  void resize(); 
   
  /* Add necessary data members here */
  int size_;
  int filled;
  
  
};

#endif
