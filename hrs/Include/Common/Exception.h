#ifndef EXCEPTION_H
#define EXCEPTION_H

/**
* @file Exception.h
* This interface is responsible for all the exceptions that arise from the ADBC component.
* 
* NAME: Exception
* $Header: Exception.h
* BASE CLASSES: None
* 
* PURPOSE: This class is responsible for all the exceptions that arise from 
*		the ADBC component. 
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.10 $
* 
* $Log: Exception.h,v $
* Revision 1.10  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.9  2005/08/30 05:21:26  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* Revision 1.8  2005/08/23 04:34:09  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.6  2005/08/12 12:31:37  Jignesh.Kanchanlal
* Added for the first time after integration
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

///////////////////////////////////////////////////////////////
//Includes
#include <string>
using std::string;

	
	/* @code
	 * Catch the Exception or GeneralException object and retrieve the string to check the reason.
	 * <BR>	
	 * try
	 * {
	 *  //ADBC code
	 * }
	 * catch(GeneralException* obj)
	 * {
	 * 	cout << obj->getMessage();
	 * }
	 * catch(Exception* obj)
	 * {
	 * 	cout << obj->getMessage();
	 * }
	 * @endcode
	 */
	
	/**@class Exception
	 * @brief This is an abstract base class for all the exceptions generated by HRS.
	 * */

 	class Exception
	{
	//Constructor and destructor
	public:		

		/** Overloaded default Constructor.
		* <BR>NAME: Exception
		* <BR>DESCRIPTION: Constructor for the Exception Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		Exception();

		/** Default Destructor.
		* <BR>NAME: ~Exception
		* <BR>DESCRIPTION: Destructor for the Exception Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		virtual ~Exception();

		/** Overloaded constructor
		* <BR>NAME: Exception(const string)
		* <BR>DESCRIPTION: Overloaded constructor to set the exception string.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* <BR>	@param const string - exception string
		* 
		*/
		Exception(const string);
		
		/** Gets the exception message
		* <BR>NAME: string getMessage(void)
		* <BR>DESCRIPTION: Getter function to retrieve the exception message
		* <BR>SIDE EFFECTS: Nil
		* <BR>RETURN: 
		* <BR>	@return const string - exception string
		* 
		*/
		virtual const string Exception::getMessage(void) const;
		
		/** Sets the exception message
		* <BR>NAME: void setMessage(const string str)
		* <BR>DESCRIPTION: Setter function to fill in the exception message
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* <BR>	@param const string - exception string
		* 
		*/
		virtual void Exception::setMessage(const string);
		
	//Private Variables
	private:		
		string errorMessage_; ///<String that stores the description of the exception generated.

	
	//Protected Functions
	protected:	

		/** Overloaded copy constructor.
		* <BR>NAME: Exception(const Exception &)
		* <BR>DESCRIPTION: Copy Constructor for the Exception Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param Const reference to Exception object
		* 
		*/
		Exception(const Exception & other);

		/** Overloaded assignment operator.
		* <BR>NAME: Exception & operator=(const Exception &)
		* <BR>DESCRIPTION: Assignment operator overload for the Exception Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param const reference to Exception object
		* <BR>RETURN: 
		* 	@return Reference to Exception Object
		* 
		*/
		Exception & operator =(const Exception & other);

	}; //class Exception
#endif  //EXCEPTION_H