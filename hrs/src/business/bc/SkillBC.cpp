#include<business/SkillBC.h>
#include<common/SkillsInformation.h>
#include<dao/SkillDAO.h>
#include<business/idgen/SkillIdGen.h>
#ifndef NULL
#define NULL 0
/**@file SkillBC.cpp
* @brief HRS Application : Defines the SkillBC Class.
*
* <BR>NAME:SkillBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillDAO class
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $6/12/2005
* 
* <BR>$Log:6/12/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/
#ifdef ALOGGER
#include<logger/Logger.h>
#endif


namespace bc{

 /**@fn ProjectBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */

  SkillBC::SkillBC()
  {
  //	m_skillDAO = NULL;
  }
  

  SkillBC::~SkillBC()
  {
  //	m_skillDAO = NULL;
  }
		    


 /**@fn createProject
   * @brief it creats the project 
   * It create the project data
   * returns nothing.
   * @param reference to the objectof ProjectInfo
   * @return nothing.
   */
  void SkillBC::createSkill(SkillsInformation& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::SkillIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setSkillId(id);//proj is an instance of the class ProjectInfo and id is a string
    m_skillDAO.create(info); 

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
	
	
  }
	


  /**@fn searchProject
   * @brief it seerchs for a project 
   * @param std::string id
   * @return an object of the class Projectinfo.
   */
   SkillsInformation SkillBC::searchSkill(std::string id)
  {
    SkillsInformation sInfo;
    SkillsInformation* sInfoPtr = NULL;
	

#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif	
    sInfoPtr = static_cast<SkillsInformation*>(m_skillDAO.findByPK(id));//we may overload == operator in projectInfo

    sInfo = *sInfoPtr;
    delete sInfoPtr;

    return sInfo;
  }

 /**@fn searchProjects
   * @brief it seerchs for a collection of projects 
   * @param an reference to the object of ProjectInfo.
   * @return a set of objects to the class Projectinfo.
   */
  std::vector<SkillsInformation> SkillBC::searchSkills(std::string dataFind)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<SkillsInformation> sklList;

    std::vector<HRSObject*> sklListPtr;
    sklListPtr = m_skillDAO.find(dataFind);

    int size = sklListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	sklList.push_back( *(static_cast<SkillsInformation*>(sklListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete sklListPtr[i];
    sklListPtr.clear();
	
    return sklList;
  }


   
  /**@fn updateProject
   * @brief it updtes the project
   * This function updates the information of the project records in the database.
   * Returns nothing
   * @param an reference to the object of Projectinfo
   * @return none
   */
   void SkillBC::updateSkill(SkillsInformation& info);
 {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif	
    m_skillDAO.update(info);
  }
  
}//namespace bc

#endif