
#include<string>
#include<dbaccess/ODBCResultSet.h>

class SkillsInformation;

class SkillAssembler
{
	
  public:

	  static std::string assemble(SkillsInformation& skills,std::string query);
				   

	  static SkillsInformation disAssemble(dbaccess::ODBCResultSet* rs);

	 
};
