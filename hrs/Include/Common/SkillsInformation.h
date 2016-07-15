#ifndef SKILLINFORMATION_H
#define SKILLINFORMATION_H

/**
* @file SkillInfo.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: SkillInfo
* $Header: SkillInfo.h
* BASE CLASSES:HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: SkillInfo.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class SkillInfo
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillsInformation : public HRSObject
{

	std::string m_SkillDescription;

	std::string m_SkillId;
	
	std::string m_SkillCategoryId;

	std::string m_SkillName; 

	std::string m_status;

public:
	SkillsInformation() 
	{
	  m_className = "SkillsInformation"; 
	}

//Getters
	const std::string getClassName()const {return m_className;}

	std::string getCategoryId() { return m_SkillCategoryId;}
           
	std::string  getSkillDescription() { return m_SkillDescription; }
            
	std::string  getSkillId() { return m_SkillId; } 
            
	std::string  getSkillName() { return m_SkillName; } 

	std::string getStatus() { return m_status; }

//Setters
            
 void setSkillDescription(std::string  SkillDescription) { m_SkillDescription = SkillDescription; } 
            
 void setSkillId(std::string  SkillId) { m_SkillId = SkillId; } 
            
 void setSkillName(std::string  SkillName) { m_SkillName = SkillName; } 

 void setStatus(std::string  status) { m_status = status; }  

 void setCategoryId(std::string SkillCategoryId){ m_SkillCategoryId = SkillCategoryId; }


};

#endif  //SkillINFO_H
