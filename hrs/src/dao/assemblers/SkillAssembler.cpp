#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillAssembler.h>
#include<common/SkillsInformation.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillAssembler::assemble(SkillsInformation& skills,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),	  
				      skills.getSkillDescription().c_str(),
					  skills.getSkillId().c_str(),
					  skills.getSkillName().c_str(),
					  skills.getStatus().c_str());

	return std::string(buf);
}


  SkillsInformation SkillAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillsInformation skl;

	
	   skl.setSkillDescription( rs->getString( rs->getColNum("DESCRIPTION")) );             
	   skl.setSkillId( rs->getString( rs->getColNum("ID")) );
	   skl.setSkillName( rs->getString( rs->getColNum("SKILLNAME")) );
	   skl.setStatus( rs->getString( rs->getColNum("STATUS") ));      


	   return skl;
  }

