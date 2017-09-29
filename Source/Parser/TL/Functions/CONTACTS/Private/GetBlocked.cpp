#include "../Public/GetBlocked.h"


//begin namespace block
namespace CONTACTS
{

GetBlocked::GetBlocked()
{
	this->_ConstructorID = -176409329;
	this->_ContentRelated = true;
}

GetBlocked::GetBlocked(int32 offset, int32 limit)
{
	this->_ConstructorID = -176409329;
	this->_ContentRelated = true;
	this->offset = offset;
	this->limit = limit;
}
void GetBlocked::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->limit);
}


void GetBlocked::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::Blocked*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetBlocked::~GetBlocked()
{

}
}//end namespace block
