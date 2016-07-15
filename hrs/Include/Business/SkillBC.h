#ifndef SKILLBC_H
#define SKILLBC_H
#include <string>
#include <vector>

class SkillsInformation;

#include<dao/SkillDAO.h>

/**@file SkillBC.h
* @brief HRS Application : Declares the SkillBC Class.
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

namespace bc {
/**@class SkillBC
* @brief HRS Application  Declaration of SkillBC Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class SkillBC, which will enforce encapsulation.
* 2. class SkillBC should have two private member variable. 
* 3. Declare one constructors.
* 4. Declare Destructor.
*/

class SkillBC
{
	dao::SkillDAO m_skillDAO;

 public:

  /**@fn ProjectBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  SkillBC();

  
  /**@fn ~SkillBC
   * @brief Destructor.
   * @param none
   * @return none
   */ 
  ~SkillBC();

   /**@fn createSkill
    * @brief it creats the skill 
   * It create the skill data
   * returns nothing.
   * @param a reference to the object of SkillInfo
   * @return nothing.
   */
  void createSkill(SkillsInformation& info);
  
 
  /**@fn searchProject
   * @brief it seerchs for a project 
   * @param std::string
   * @return an object of the class Projectinfo.
   */
   SkillsInformation searchSkill(std::string id);
  
  /**@fn searchProjects
   * @brief it seerchs for a collection of projects 
   * @param std::string
   * @return a set of objects to the class Projectinfo.
   */
   std::vector<SkillsInformation> searchSkills(std::string dataFind);


  /**@fn updateProject
   * @brief it updtes the project
   * This function updates the information of the project records in the database.
   * Returns nothing
   * @parama reference to the object of ProjectInfo
   * @return none
   */
  void updateSkill(SkillsInformation& info);
};

} //namespace bc
#endif //SkillBC.h


