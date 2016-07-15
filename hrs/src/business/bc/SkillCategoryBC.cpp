#include<business/SkillCategoryBC.h>
#include<common/SkillCategory.h>
#include<dao/SkillCategoryDAO.h>
#include<business/idgen/CategoryIdGen.h>
#ifndef NULL
#define NULL 0
/**@file ProjectBC.cpp
* @brief HRS Application : Defines the ProjectBC Class.
*
* <BR>NAME:ProjectBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the ProjectDAO class
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

  SkillCategoryBC::SkillCategoryBC()
  {
 // 	m_catDAO=NULL;
  }
  
  
  SkillCategoryBC::~SkillCategoryBC()
  {
 // 	m_catDAO=NULL;
  }

		    


 /**@fn createProject
   * @brief it creats the project 
   * It create the project data
   * returns nothing.
   * @param reference to the objectof ProjectInfo
   * @return nothing.
   */
   void SkillCategoryBC::createCategory(SkillCategory& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::CategoryIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setSkillCategoryId(id);//proj is an instance of the class ProjectInfo and id is a string
    m_catDAO.create(info); 

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
	
	
  }
	


  /**@fn searchProject
   * @brief it seerchs for a project 
   * @param std::string id
   * @return an object of the class Projectinfo.
   */
   SkillCategory SkillCategoryBC::searchSkillCategory(std::string id);
 
  {
    SkillCategory cInfo;
    SkillCategory* cInfoPtr = NULL;
	

#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif	
    cInfoPtr = static_cast<SkillCategory*>(m_catDAO.findByPK(id));

    cInfo = *cInfoPtr;
    delete cInfoPtr;

    return cInfo;
  }

 /**@fn searchProjects
   * @brief it seerchs for a collection of projects 
   * @param an reference to the object of ProjectInfo.
   * @return a set of objects to the class Projectinfo.
   */
  std::vector<SkillCategory> SkillCategoryBC::searchSkillCategories(std::string dataFind)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<SkillCategory> catList;

    std::vector<HRSObject*> catListPtr;
    catListPtr = m_catDAO.find(dataFind);

    int size = catListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	catList.push_back( *(static_cast<SkillCategory*>(catListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete catListPtr[i];
    catListPtr.clear();
	
    return catList;
  }


   
  /**@fn updateProject
   * @brief it updtes the project
   * This function updates the information of the project records in the database.
   * Returns nothing
   * @param an reference to the object of Projectinfo
   * @return none
   */
    void SkillCategoryBC::updateCategory(SkillCategory& info)
	  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif	
    m_catDAO.update(info);
  }
  
}//namespace bc
#endif