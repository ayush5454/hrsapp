#include<business/EmployeeBC.h> 
#ifndef NULL
#define NULL 0
#include<common/EmployeeInfo.h>
#include<common/AccentureDetails.h>
#include<common/GeneralException.h>

#include<dao/EmployeeDAO.h>
#include<dao/EmpAccentureDetailsDAO.h>

#include<business/idgen/EmpIdGen.h>

#include<string>
#include<vector>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif


namespace bc{


  EmployeeBC::EmployeeBC()
  {
/*	  m_empDAO = NULL;
	 m_empAccDAO = NULL;
  
*/
}

  EmployeeBC::~EmployeeBC()
  {
/*	  m_empDAO = NULL;
	m_empAccDAO = NULL;
  */
}
		    


 

//..................................................
  void EmployeeBC::createEmployee(EmployeeInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::EmpIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setEmpNo(id);
    m_empDAO.create(info); 

	AccentureDetails a_details;
//a_details=info.getAccentureDetails();info is an instance of the class EmployeeInfo and id is a string
	a_details.setEnterpriseId(id);
	m_empAccDAO.create(a_details);


#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
	
	
  }
	
//......................................................
  
EmployeeInfo EmployeeBC::searchEmployee(std::string empno)
  {
    EmployeeInfo eInfo;
    EmployeeInfo* eInfoPtr = NULL;
	

#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, empno.c_str() );
#endif	
    eInfoPtr = static_cast<EmployeeInfo*>(m_empDAO.findByPK(empno));//we may overload == operator in projectInfo

    eInfo = *eInfoPtr;
    delete eInfoPtr;
	
	AccentureDetails acc_obj;
	AccentureDetails* acc_ptr = NULL;
	
	acc_ptr = static_cast<AccentureDetails*>(m_empAccDAO.findByPK(empno));
	acc_obj = *acc_ptr;
	delete acc_ptr;
	
   eInfo.setAccentureDetails(acc_obj);
   return eInfo;
	
  }

 



//....................................................

std::vector<EmployeeInfo> EmployeeBC::searchEmployees(std::string info)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<EmployeeInfo> empList;

    std::vector<HRSObject*> empListPtr;

    empListPtr = m_empDAO.find(info);

    int size = empListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	empList.push_back( *(static_cast<EmployeeInfo*>(empListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete empListPtr[i];
    empListPtr.clear();

	std::vector<AccentureDetails> accList;
	std::vector<AccentureDetails*> accListPtr;

	accListPtr = m_empAccDAO.find(info);

	int size = accListPtr.size();
	for(int j=0; j<size;j++)
		accList.push_back( *(static_cast<AccentureDetails*>(accListPtr[j])) );
	
	for(int j=0; j < size;j++)
		delete accListPtr[j];
	
accListPtr.clear();


    return empList;

}


   
  
  

//........................................................
void EmployeeBC::updateEmployee(EmployeeInfo& piSet)

  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
//logger::Logger::getInstance().info("EmployeeBC:: updateEmployee::About to updatet the Employee");
#endif	

    m_empDAO.update(piSet);
    AccentureDetails acc=piset.getAccentureDetails();
	m_empAccDAO.update(acc);
	

  }

}//namespace bc
#endif
