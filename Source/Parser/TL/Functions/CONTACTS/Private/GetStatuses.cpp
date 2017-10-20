#include "../Public/GetStatuses.h"


//begin namespace block
namespace CONTACTS
{

GetStatuses::GetStatuses()
{
	this->_ConstructorID = -995929106;
	this->_ContentRelated = true;
}
void GetStatuses::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetStatuses::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
GetStatuses::~GetStatuses()
{
}
}//end namespace block
