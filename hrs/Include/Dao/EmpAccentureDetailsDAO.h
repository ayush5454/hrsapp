// EmpAccentureDetailsDAO.h : The DAO layer responsible for direct interaction with the
// database for EmpAccentureDetails related issues.

#ifndef EMPACCENTUREDETAILSDAO_H
#define EMPACCENTUREDETAILSDAO_H

/**@file EmpAccentureDetailsDAO.h
 * @brief Delares Data Access Object for EmpAccentureDetails.
* <BR>NAME: EmpAccentureDetailsDAO
* 
* <BR>BASE CLASSES: No Parent
* 
* <BR>PURPOSE: This class is responsible for direct interaction with the
*  database for EmpAccentureDetails related issues.
*
* <BR>AUTHOR: Arun Veeramany
* <BR>$Revision: 9th Dec'05
* 
* <BR>$Log: 9th Dec'05
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


#include<string>
#include<vector>

#include <dao/DAO.h>
#include <common/HRSObject.h>
#include <common/AccentureDetails.h>


namespace dao {

 class ODBCConnection;
  class ODBCResultSet;
  class EmployeeInfo;
  /**@class EmpAccentureDetailsDAO EmpAccentureDetailsDAO.h ./EmpAccentureDetailsDAO.h
   * @brief EmpAccentureDetailsDAO is the layer closest to the database.
   * The EmpAccentureDetails Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert an EmpAccentureDetails in to EmpAccentureDetails Table
   *               2. Delete an EmpAccentureDetails from the EmpAccentureDetails Table
   *		   3. Update an EmpAccentureDetails's details
   *		   4. Find EmpAccentureDetailss with specific search criteria
   * </PRE> 
   */
  class EmpAccentureDetailsDAO : public DAO
  {
         
  public:

    /**@fn EmpAccentureDetailsDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */     
    EmpAccentureDetailsDAO();

    virtual ~EmpAccentureDetailsDAO(){}

    
    /**@fn create(EmpAccentureDetailsInfo& EmpAccentureDetailsInfo)
      * @brief Insert an EmpAccentureDetails into EmpAccentureDetails table
      * This method gets an instance of the connection from
      * DBAccess and inserts data from the EmpAccentureDetailsInfo object
      * into the EmpAccentureDetails table.
      * @param A reference to EmpAccentureDetailsInfo object containing EmpAccentureDetails data
      * @return none
      */         
    void create(HRSObject& employeeInfo);
       
               
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of EmpAccentureDetailsInfo matching the criteria
     */              
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the EmpAccentureDetails table
     * @param none
     * @return A vector of all EmpAccentureDetailsInfo found in the table 
     */           
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK(std::string pkValue)
      * @brief Fetch EmpAccentureDetailss whose primary key value matches the passed one
      * @param pkValue - Value of the primary key (EmpAccentureDetails No.)
      * @return EmpAccentureDetailsInfo - Record Matching the pkValue 
      */          
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove(std::string pkValue)
      * @brief Remove the project from the EmpAccentureDetails table given the EmpAccentureDetailsId
      * @param pkValue - Delete the record corresponding to pkValue
      * @return bool - Status of deletion
      */            
    bool remove(std::string pkValue);       
      
    /**@fn update(EmpAccentureDetailsInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */              
    bool update(HRSObject& piSet);      
  };

}	// namespace dao
#endif     //EmpAccentureDetailsDAO_H
