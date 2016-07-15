#ifndef SKILLCATEGORY_H
#define SKILLCATEGORY_H

/**
* @file SkillCategory.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: SkillCategory
* $Header: SkillCategory.h
* BASE CLASSES:HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.                                                                                                  
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: SkillCategory.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class SkillCategory
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillCategory : public HRSObject
{

	std::string m_SkillCategoryDescription;

	std::string m_SkillCategoryId;

	std::string m_SkillCategoryName; 

	std::string m_status;

public:
	SkillCategory() 
	{
	  m_className = "SkillCategory"; 
	}

//Getters
	const std::string getClassName()const {return m_className;}

           
	std::string  getCategoryDescription( ) { return m_SkillCategoryDescription; }
            
	std::string  getCategoryId() { return m_SkillCategoryId; } 
            
	std::string  getCategoryName() { return m_SkillCategoryName; } 

	std::string getStatus() { return m_status; }

//Setters
            
 void setCategoryDescription(std::string  SkillCategoryDescription) { m_SkillCategoryDescription = SkillCategoryDescription; } 
            
 void setCategoryId(std::string  SkillCategoryId) { m_SkillCategoryId = SkillCategoryId; } 
            
 void setCategoryName(std::string  SkillCategoryName) { m_SkillCategoryName = SkillCategoryName; } 

 void setStatus(std::string  status) { m_status = status; }           


};

#endif  //SkillCategoryINFO_H
