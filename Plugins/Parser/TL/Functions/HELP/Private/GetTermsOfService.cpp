#include "../Public/GetTermsOfService.h"


//begin namespace block
namespace HELP
{

GetTermsOfService::GetTermsOfService()
{
	this->_ConstructorID = -210763467;
	this->_ContentRelated = true;
}
void GetTermsOfService::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetTermsOfService::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::TermsOfService*>(Reader.TGReadObject());
}
GetTermsOfService::~GetTermsOfService()
{

}
}//end namespace block
