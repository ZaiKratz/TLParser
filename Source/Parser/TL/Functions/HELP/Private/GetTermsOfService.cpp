#include "../Public/GetTermsOfService.h"


//begin namespace block
namespace HELP
{

GetTermsOfService::GetTermsOfService()
{
	this->_ConstructorID = 889286899;
	this->_ContentRelated = true;
}
void GetTermsOfService::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetTermsOfService::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::TermsOfService*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetTermsOfService::~GetTermsOfService()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
