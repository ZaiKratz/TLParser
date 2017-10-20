#include "../Public/GetMessageEditData.h"


//begin namespace block
namespace MESSAGES
{

GetMessageEditData::GetMessageEditData()
{
	this->_ConstructorID = -39416522;
	this->_ContentRelated = true;
}

GetMessageEditData::GetMessageEditData(TLBaseObject*  peer, int32 id)
{
	this->_ConstructorID = -39416522;
	this->_ContentRelated = true;
	this->peer = peer;
	this->id = id;
}
void GetMessageEditData::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(this->id);
}


void GetMessageEditData::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::MessageEditData*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetMessageEditData::~GetMessageEditData()
{
	if(this->peer)
	{
		delete this->peer;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
