/**
* @file $Header: DBException.cpp
* 
* NAME: DBException
* 
* BASE CLASSES: Exception
* 
* PURPOSE: For exceptions generated by ODBC connectivity and other general exceptions.
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.9 $
* 
* $Log: DBException.cpp,v $
* Revision 1.9  2005/09/01 05:40:48  Jignesh.Kanchanlal
* Documentation modified for the Release
*
* Revision 1.8  2005/08/30 05:23:25  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* Revision 1.7  2005/08/23 11:57:15  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.6  2005/08/23 04:35:17  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.4  2005/08/12 12:29:56  Jignesh.Kanchanlal
* Added for the first time
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


///////////////////////////////////////////////////////////////
// Includes
#include <dbaccess/DBException.h>
#ifdef ALOGGER
	#include <logger/Logger.h> ///<logging comments
#endif

namespace dbaccess {
	
	/** Overloaded default Constructor.
	* <BR>NAME: Error
	* <BR>DESCRIPTION: Constructor for the DBException Object.
	* <BR>SIDE EFFECTS: Nil
	* <BR>@param Nil
	*/
	DBException::DBException()
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
	}

	/** Overloaded constructor.
	* <BR>NAME: DBException(const string)
	* <BR>DESCRIPTION: constructor for the DBException Object.
	* <BR>SIDE EFFECTS: Nil
	* <BR>@param Nil
	*/
	DBException::DBException(const string str)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Overloaded constructor with string");
		#endif
		setMessage(str);
	}

	/** Default Destructor.
	* <BR>NAME: ~DBException
	* <BR>DESCRIPTION: Destructor for the DBException Object.
	* <BR>SIDE EFFECTS: Nil
	* <BR>@param Nil
	*/
	DBException::~DBException()
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
	}

	/** Overloaded copy constructor.
	* <BR>NAME: DBException(const DBException &)
	* <BR>DESCRIPTION: Copy Constructor for the DBException Object.
	* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
	* <BR>@param Const reference to DBException object
	*/
	DBException::DBException(const DBException&)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Copy Constructor");
		#endif
	}

	/** Overloaded assignment operator.
	* <BR>NAME: DBException & operator=(const DBException &)
	* <BR>DESCRIPTION: Assignment operator overload for the DBException Object.
	* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
	* <BR>@param const Reference to DBException object
	* <BR>RETURN: 
	* 	@return Reference to DBException Object
	*/
	DBException& DBException::operator =(const DBException&)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Overloaded Assignment operator");
		#endif
		return *this;
	}

}	//namespace dbaccess
