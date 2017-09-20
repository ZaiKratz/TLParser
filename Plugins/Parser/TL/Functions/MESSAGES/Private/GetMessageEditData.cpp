#include "../Public/GetMessageEditData.h"


//begin namespace block
namespace MESSAGES
{

GetMessageEditData::GetMessageEditData()
{
	this->_ConstructorID = 915252989;
	this->_ContentRelated = true;
}

GetMessageEditData::GetMessageEditData(PRIVATE::InputPeer* peer, int32 id)
{
	this->_ConstructorID = 915252989;
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
}
GetMessageEditData::~GetMessageEditData()
{

}
}//end namespace block
