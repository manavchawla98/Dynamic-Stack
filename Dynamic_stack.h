/*****************************************
 * Instructions
 *  - Replace 'm6chawla' with your uWaterloo User ID
 *  - Select the current calendar term and enter the year
 *  - List students with whom you had discussions and who helped you
 *
 * uWaterloo User ID:  m6chawla@uwaterloo.ca
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Fall) 2017
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *
 * The following is a list of uWaterloo User IDs of those students
 * I had discussions with in preparing this project:
 *    -
 *
 * The following is a list of uWaterloo User IDs of those students
 * who helped me with this project (describe their help; e.g., debugging):
 *    -
 *****************************************/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif

#include "Exception.h"
#include <iostream>

using namespace std;




class Dynamic_stack {

	private:
		int *array;
		int count;		
		int array_size;
		int initial_size;
	
	public:
		Dynamic_stack(int = 10);
		~Dynamic_stack();

		int top() const;			// returns the first element of the stack
		int size() const;			// returns the number of elements that are in the stack
		bool empty() const;			// returns true/false depending on whether the stack is empty or not
		int capacity() const;		// returns the capacity (array_size) of the array
			
		void push( int const & );	// adds integer provided as argument to the top of the stack
		int pop();					// deletes the first element of the stack/throws underflow exception if called when stack is empty
		void clear();				// clears the stack
};

Dynamic_stack::Dynamic_stack( int n ):	// Constructor - creates the array to hold the stack; initiliazes other fields with appropriate values
count( 0 ),
array_size( n ),
initial_size(n)
{

	if(n<1){
		array=new int[1];			// if a negative parameter (or 0) is provided for size of stack, the default size is set to 1
		array_size=1;
		initial_size=1;
	}
	else
		array = new int[array_size];	
}


Dynamic_stack::~Dynamic_stack() { 			// Destructor- dellocate memory occupied by array pointed to by 'array'
	delete [] array;
}


int Dynamic_stack::top() const {
	
	if(count==0)
		throw underflow();		// if stack is empty, the top has no element and underflow exception is thrown
	else 
		return *array;
}


int Dynamic_stack::size() const {
	return count;
}


bool Dynamic_stack::empty() const {

	if(count==0)
		return true;
	else
		return false;
}


int Dynamic_stack::capacity() const {
	return array_size;
}


void Dynamic_stack::push( int const &obj ) {

	count++;
	


	if(count>array_size){

		
		int* temp_array;
		temp_array=new int[array_size*2];
		temp_array[0]=obj;

		for(int m=0; m<=count-2; m++){
			temp_array[m+1]=array[m];
		}
		delete [] array;			//previous array pointed to by 'array' has to be deleted, so that 'array' can now point to the new array of double capacity
		array_size=array_size*2;
		array=temp_array;
		
		temp_array=nullptr;
		delete [] temp_array;

	}
	else if(count==1){
		array[0]=obj;
	}
	else{
		for(int i=count-2; i>=0; i--){ //count-2 as count becomes the new value at the start of the function; shifting the elements of the array to the right
			array[i+1]=array[i];
		}

		array[0]=obj;

	}
	

}


int Dynamic_stack::pop() {

	int element;
	if(count==0){
		throw underflow();		// underflow exception thrown if pop is called when the stack is empty
	}
	else{
		element=array[0];
		for(int i=0;i<=count-1;i++)
			array[i]=array[i+1];
	}
	
	count--;
	return element;
}

void Dynamic_stack::clear() {

	if(array_size!=initial_size){
		delete [] array;
		array = new int[initial_size];
		array_size=initial_size;
		count=0;
    	}
	else{										// the size of array will remain same. next push() will overwrite previously stored values
		count=0;
	}

	
}
#endif