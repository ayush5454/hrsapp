#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/EmployeeAssembler.h>
#include<common/EmployeeInfo.h>
#include<dbaccess/ODBCResultSet.h>


std::string EmployeeAssembler::assemble(EmployeeInfo& employee,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),	  
				      employee.getEducationalAttainment().c_str(),
					  employee.getCitizenship().c_str(),
					  employee.getCity().c_str(),
					  employee.getCountry().c_str(),
					  employee.getDOB().c_str(),
					  employee.getEmployeeNo().c_str(),
					  employee.getFirstName().c_str(),
					  employee.getLastName().c_str(),
					  employee.getMiddleName().c_str(),
					  employee.getHomePhoneNo().c_str(),
					  employee.getGender().c_str(),
					  employee.getSSSNo().c_str(),
					  employee.getMobilePhoneNo().c_str(),
					  employee.getRecognitions().c_str(),
					  employee.getState().c_str(),
					  employee.getStreet1().c_str(),
					  employee.getStreet2().c_str(),
					  employee.getTinNo().c_str(),
					  employee.getCivilStatus().c_str());

	return std::string(buf);
}


  EmployeeInfo EmployeeAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  EmployeeInfo emp;

	
	   emp.setEducationalAttainment( rs->getString( rs->getColNum("EDUCATION")) );             
	   emp.setCitizenship( rs->getString( rs->getColNum("CITIZEN")) );
	   emp.setCity( rs->getString( rs->getColNum("CITY")) );
	   emp.setCountry( rs->getString( rs->getColNum("COUNTRY") ));      
	   emp.setDOB( rs->getString( rs->getColNum("DOB")) );        
	   emp.setFirstName( rs->getString( rs->getColNum("FIRSTNAME")) );    
	   emp.setLastName( rs->getString( rs->getColNum("LASTNAME") ));
		emp.setMiddleName( rs->getString( rs->getColNum("MIDDLENAME")) );             
	   emp.setHomePhoneNo( rs->getString( rs->getColNum("HOMEPHONE")) );
	   emp.setGender( rs->getString( rs->getColNum("GENDER")) );
	   emp.setSSSNo( rs->getString( rs->getColNum("SSNNO") ));      
	   emp.setMobilePhoneNo( rs->getString( rs->getColNum("MOBILEPHONE")) );        
	   emp.setRecognitions( rs->getString( rs->getColNum("RECOGNITION")) );    
	   emp.setState( rs->getString( rs->getColNum("STATE") ));
	   	   emp.setStreet1( rs->getString( rs->getColNum("STREET1")) );
	   emp.setStreet2( rs->getString( rs->getColNum("STREET2")) );
	   emp.setTinNo( rs->getDate( rs->getColNum("TINNO") ));      
	   emp.setCivilStatus( rs->getDate( rs->getColNum("CIVILSTATUS")) );            

	   return emp;
  }

