#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillCategoryAssembler.h>
#include<common/SkillCategory.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillCategoryAssembler::assemble(SkillCategory& skillCategorys,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				      skillCategorys.getCategoryId().c_str(),
					  skillCategorys.getCategoryName().c_str(),
					  skillCategorys.getCategoryDescription().c_str(),
					  skillCategorys.getStatus().c_str());

	return std::string(buf);
}


  SkillCategory SkillCategoryAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillCategory skillcat;


	   skillcat.setCategoryId( rs->getString( rs->getColNum("ID")) );
	   skillcat.setCategoryName( rs->getString( rs->getColNum("NAME")) );
	   skillcat.setCategoryDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   skillcat.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return skillcat;
  }
