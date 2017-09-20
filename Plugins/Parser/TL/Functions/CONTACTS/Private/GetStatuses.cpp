#include "../Public/GetStatuses.h"


//begin namespace block
namespace CONTACTS
{

GetStatuses::GetStatuses()
{
	this->_ConstructorID = -296508476;
	this->_ContentRelated = true;
}
void GetStatuses::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetStatuses::OnResponce(BinaryReader& Reader)
{
}
GetStatuses::~GetStatuses()
{

}
}//end namespace block
