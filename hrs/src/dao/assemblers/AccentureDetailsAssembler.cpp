#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/AccentureDetailsAssembler.h>
#include<common/AccentureDetails.h>
#include<dbaccess/ODBCResultSet.h>

std::string AccentureDetailsAssembler::assemble(AccentureDetails& AccDetails,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				    AccDetails.getEmployeeNo().c_str(),
					  AccDetails.getEnterpriseId().c_str(),
						AccDetails.getEnterpriseAddress().c_str(),
						AccDetails.getLevel().c_str(),
					  AccDetails.getLMU().c_str(),
						AccDetails.getStatus().c_str(),
					  AccDetails.getDateHired().c_str(),
					  AccDetails.getGMU().c_str(),
						AccDetails.getWorkGroup().c_str(),
						AccDetails.getSpecialty().c_str(),
					  AccDetails.getServiceLine().c_str());





	return std::string(buf);
}


  AccentureDetails AccentureDetailsAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	   AccentureDetails Acc;


	   Acc.setEmployeeNo( rs->getString( rs->getColNum("EMPNO")) );
	   Acc.setEnterpriseId( rs->getString( rs->getColNum("ENTERPRISEID")) );
	   Acc.setDateHired( rs->getString( rs->getColNum("DATEHIRED")) );
	   Acc.setEnterpriseAddress( rs->getDate( rs->getColNum("EMAILADD") ));
	   Acc.setGMU( rs->getDate( rs->getColNum("GMU")) );
	   Acc.setLevel( rs->getString( rs->getColNum("EMPLEVEL")) );
	   Acc.setLMU( rs->getString( rs->getColNum("LMU") ));
     Acc.setServiceLine( rs->getString( rs->getColNum("SERVICELINE")));
     Acc.setSpecialty( rs->getString( rs->getColNum("SPECIALTY")));
     Acc.setStatus( rs->getString( rs->getColNum("STATUS")));
     Acc.setWorkGroup( rs->getString( rs->getColNum("WORKGROUP")));

	   return Acc;
  }
